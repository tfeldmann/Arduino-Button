#pragma once

class VirtualButton {
public:
    VirtualButton(bool invert = false);
    virtual void update();
    virtual void update(bool reading);
    virtual bool is_pressed();
    virtual bool just_pressed();
    virtual bool just_released();
    virtual bool just_changed();
    virtual void reset();

private:
    bool prev_state_;
    bool flag_pressed_;
    bool flag_released_;
    bool invert_;

    virtual bool read();
};
