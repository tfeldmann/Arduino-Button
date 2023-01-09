#include <PinButton.h>

PinButton btn1(14);
PinButton btn2(15);

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    btn1.update();
    btn2.update();

    if (btn1.just_pressed())
        Serial.println("Pressed");
    if (btn1.just_released())
        Serial.println("Released");

    if (btn2.just_pressed())
        Serial.println("Pressed");
    if (btn2.just_released())
        Serial.println("Released");
}
