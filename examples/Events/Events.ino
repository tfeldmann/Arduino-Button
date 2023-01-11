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
