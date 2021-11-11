#pragma once
#include <Arduino.h>

class Button
{
public:
    bool negate;

    Button()
    {
        Button(false);
    }
    Button(bool negate)
    {
        this->negate = negate;
    }

    virtual bool isPressed()
    {
        bool result = this->_read();
        return negate ? !result : result;
    }

private:
    virtual bool _read()
    {
        return false;
    }
};

class PinButton : public Button
{
public:
    PinButton(int pin)
    {
        PinButton(pin, false);
    }

    PinButton(int pin, bool enable_pullup, bool negate)
        : Button(negate)
    {
        pin_ = pin;
        if (enable_pullup)
            pinMode(pin_, INPUT_PULLUP);
        else
            pinMode(pin_, INPUT);
    }

private:
    bool _read()
    {
        return digitalRead(pin_);
    }

    int pin_;
};

class ActionButton
{
public:
    ActionButton()
    {
        this->prevState = false;
        this->pressedFlag = false;
        this->releasedFlag = false;
    }

    virtual void update(bool state)
    {
        if (state && !this->prevState)
            this->pressedFlag = true;
        if (this->prevState && !state)
            this->releasedFlag = true;
        this->prevState = state;
    }

    virtual bool isPressed()
    {
        return this->prevState;
    }

    virtual bool justPressed()
    {
        if (this->pressedFlag)
        {
            this->pressedFlag = false;
            return true;
        }
        return false;
    }

    virtual bool justReleased()
    {
        if (this->releasedFlag)
        {
            this->releasedFlag = false;
            return true;
        }
        return false;
    }

    virtual bool justChanged()
    {
        return (justPressed() || justReleased());
    }

    virtual void reset()
    {
        this->pressedFlag = false;
        this->releasedFlag = false;
    }

private:
    bool prevState;

    bool pressedFlag;
    bool releasedFlag;
};
