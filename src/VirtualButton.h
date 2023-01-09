#pragma once

struct ButtonEvents {
    bool pressed;
    bool released;
    bool changed;
};

class VirtualButton {
public:
    VirtualButton(bool invert = false);
    virtual struct ButtonEvents update();
    virtual struct ButtonEvents update(bool reading);
    virtual bool is_pressed();
    virtual bool just_pressed();
    virtual bool just_released();
    virtual bool just_changed();

private:
    bool state_;
    bool invert_;
    bool flag_pressed_;
    bool flag_released_;

    virtual bool read();
};
