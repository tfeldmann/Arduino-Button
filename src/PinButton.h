#pragma once
#include <Arduino.h>

#include "VirtualButton.h"

class PinButton : public VirtualButton
{
public:
    PinButton(int pin, bool invert = false, int mode = INPUT_PULLUP);

private:
    int pin_;

    bool read(void) override;
};
