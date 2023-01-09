#include "PinButton.h"

#include <Arduino.h>

PinButton::PinButton(int pin, bool invert)
    : VirtualButton(invert)
    , pin_(pin)
{
    pinMode(pin, OUTPUT);
}

bool PinButton::read()
{
    return digitalRead(pin_);
}
