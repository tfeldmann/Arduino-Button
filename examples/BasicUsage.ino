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
        Serial.println("Btn 1 pressed");
    if (btn1.just_released())
        Serial.println("Btn 1 released");

    if (btn2.just_pressed())
        Serial.println("Btn 2 pressed");
    if (btn2.just_released())
        Serial.println("Btn 2 released");
}
