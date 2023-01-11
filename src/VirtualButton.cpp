#include "VirtualButton.h"

VirtualButton::VirtualButton(bool invert)
    : state_(false)
    , invert_(invert)
    , flag_pressed_(false)
    , flag_released_(false)
{
}

struct ButtonEvents VirtualButton::update(void)
{
    bool reading = read();
    return update(reading);
}

struct ButtonEvents VirtualButton::update(bool reading)
{
    bool new_state = reading ^ invert_;

    bool pressed = new_state && !state_;
    bool released = !new_state && state_;

    if (pressed)
        flag_pressed_ = true;
    if (released)
        flag_released_ = true;

    state_ = new_state;

    struct ButtonEvents result = {
        .pressed = pressed,
        .released = released,
        .changed = pressed || released,
    };
    return result;
}

bool VirtualButton::is_pressed(void)
{
    return state_;
}

bool VirtualButton::just_pressed(void)
{
    if (flag_pressed_) {
        flag_pressed_ = false;
        return true;
    }
    return false;
}

bool VirtualButton::just_released(void)
{
    if (flag_released_) {
        flag_released_ = false;
        return true;
    }
    return false;
}

bool VirtualButton::just_changed(void)
{
    return (just_pressed() || just_released());
}

bool VirtualButton::read(void)
{
    return state_ ^ invert_;
}
