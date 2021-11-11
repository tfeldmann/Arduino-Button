#include <Button.h>
#define SerPort Serial

PinButton btn1(14);
PinButton btn2(15);

void setup()
{
    SerPort.begin(9600);
}

void loop()
{
    btn1.update();
    btn2.update();

    if (btn1.justPressed())
        SerPort.println("Pressed");
    if (btn1.justReleased())
        SerPort.println("Released");

    if (btn2.justPressed())
        SerPort.println("Pressed");
    if (btn2.justReleased())
        SerPort.println("Released");
}
