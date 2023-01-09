#include "PinButton.h"
#include <ArduinoFake.h>
#include <unity.h>
using namespace fakeit;

void setUp(void)
{
    ArduinoFakeReset();
    When(Method(ArduinoFake(), pinMode)).AlwaysReturn();
}

void test_pinbutton()
{
    // create a button at rest
    PinButton btn(10, INPUT);
    Verify(Method(ArduinoFake(), pinMode).Using(10, INPUT));

    When(Method(ArduinoFake(), digitalRead)).AlwaysReturn(LOW);
    TEST_ASSERT_EQUAL(btn.is_pressed(), false);
    TEST_ASSERT_EQUAL(btn.just_pressed(), false);
    TEST_ASSERT_EQUAL(btn.just_released(), false);
    TEST_ASSERT_EQUAL(btn.just_changed(), false);

    btn.update();

    TEST_ASSERT_EQUAL(btn.is_pressed(), false);
    TEST_ASSERT_EQUAL(btn.just_pressed(), false);
    TEST_ASSERT_EQUAL(btn.just_released(), false);
    TEST_ASSERT_EQUAL(btn.just_changed(), false);

    // now we press the button
    When(Method(ArduinoFake(), digitalRead)).AlwaysReturn(HIGH);
    btn.update();

    TEST_ASSERT_EQUAL(btn.is_pressed(), true);
    TEST_ASSERT_EQUAL(btn.just_pressed(), true);
    TEST_ASSERT_EQUAL(btn.just_released(), false);

    // reset on next query
    TEST_ASSERT_EQUAL(btn.just_pressed(), false);
    TEST_ASSERT_EQUAL(btn.just_released(), false);
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(test_pinbutton);
    return UNITY_END();
}
