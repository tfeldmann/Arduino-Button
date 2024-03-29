#include "PinButton.h"

PinButton::PinButton(int pin, bool invert, int mode)
    : VirtualButton(invert)
    , pin_(pin)
{
    pinMode(pin, mode);
}

bool PinButton::read(void)
{
    return digitalRead(pin_);
}
