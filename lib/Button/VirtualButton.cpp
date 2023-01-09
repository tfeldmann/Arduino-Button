#include "VirtualButton.h"

VirtualButton::VirtualButton(bool invert)
    : prev_state_(false ^ invert)
    , flag_pressed_(false)
    , flag_released_(false)
    , invert_(invert)
{
}

void VirtualButton::update()
{
    bool val = read();
    update(val);
}

void VirtualButton::update(bool reading)
{
    bool val = reading ^ invert_;
    if (val && !prev_state_)
        flag_pressed_ = true;
    if (!val && prev_state_)
        flag_released_ = true;
    prev_state_ = val;
}

bool VirtualButton::is_pressed()
{

    return prev_state_;
}

bool VirtualButton::just_pressed()
{
    if (flag_pressed_) {
        flag_pressed_ = false;
        return true;
    }
    return false;
}

bool VirtualButton::just_released()
{
    if (flag_released_) {
        flag_released_ = false;
        return true;
    }
    return false;
}

bool VirtualButton::just_changed()
{
    return (just_pressed() || just_released());
}

void VirtualButton::reset()
{
    flag_pressed_ = false;
    flag_released_ = false;
}

bool VirtualButton::read()
{
    return false;
}
