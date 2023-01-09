#pragma once
#include "VirtualButton.h"

class PinButton : public VirtualButton {
public:
    PinButton(int pin, bool invert = false);

private:
    int pin_;

    bool read() override;
};
