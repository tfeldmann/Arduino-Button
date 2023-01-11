# Arduino-Button

## API

```cpp
struct ButtonEvents {
    bool pressed;
    bool released;
    bool changed;
};

class VirtualButton {
    VirtualButton(bool invert = false);
    struct ButtonEvents update(bool reading);
    bool is_pressed();
    bool just_pressed();
    bool just_released();
    bool just_changed();
}

class PinButton : public VirtualButton {
    PinButton(int pin, int mode = INPUT_PULLUP, bool invert = false);
};
```

## Button Events Example

```cpp
#include <PinButton.h>

PinButton btn(12);

void setup() {
  Serial.begin(9600);
}

void loop() {
  struct ButtonEvents evnt = btn.update();

  if (evnt.pressed) Serial.println("Btn pressed");
  if (evnt.released) Serial.println("Btn released");
  if (evnt.changed) Serial.println("Btn changed");
}
```

## PinButton Example

Toggles a LED on pin 13 when the button is released.

```cpp
#include <PinButton.h>

PinButton btn(12, INPUT_PULLUP);
bool led_state = LOW;

void setup()
{
    pinMode(13, OUTPUT); // LED
    digitalWrite(13, led_state);
}

void loop()
{
    btn.update();
    if (btn.just_released()) {
        led_state = !led_state;
        digitalWrite(13, led_state);
    }
}
```
