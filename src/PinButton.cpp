#include "PinButton.h"

PinButton::PinButton(int pin, int mode, bool invert)
    : VirtualButton(invert)
    , pin_(pin)
{
    pinMode(pin, mode);
}

bool PinButton::read()
{
    return digitalRead(pin_);
}
