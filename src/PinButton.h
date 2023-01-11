#pragma once
#include "VirtualButton.h"

#include <Arduino.h>

class PinButton : public VirtualButton {
public:
    PinButton(int pin, int mode = INPUT_PULLUP, bool invert = false);

private:
    int pin_;

    bool read(void) override;
};
