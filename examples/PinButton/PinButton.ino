#include <PinButton.h>

PinButton btn(12, false, INPUT_PULLUP);
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
