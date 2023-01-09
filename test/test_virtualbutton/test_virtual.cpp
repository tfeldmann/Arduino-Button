#include "VirtualButton.h"
#include <unity.h>

void test_virtual()
{
    // create a button at rest
    VirtualButton btn;
    TEST_ASSERT_EQUAL(btn.is_pressed(), false);
    TEST_ASSERT_EQUAL(btn.just_pressed(), false);
    TEST_ASSERT_EQUAL(btn.just_released(), false);
    TEST_ASSERT_EQUAL(btn.just_changed(), false);

    btn.update(false);
    btn.update(); // must not change anything

    TEST_ASSERT_EQUAL(btn.is_pressed(), false);
    TEST_ASSERT_EQUAL(btn.just_pressed(), false);
    TEST_ASSERT_EQUAL(btn.just_released(), false);
    TEST_ASSERT_EQUAL(btn.just_changed(), false);

    // now we press the button
    btn.update(true);

    TEST_ASSERT_EQUAL(btn.is_pressed(), true);
    TEST_ASSERT_EQUAL(btn.just_pressed(), true);
    TEST_ASSERT_EQUAL(btn.just_released(), false);

    // reset on next query
    TEST_ASSERT_EQUAL(btn.just_pressed(), false);
    TEST_ASSERT_EQUAL(btn.just_released(), false);
}

void test_inverted()
{
    // create an inverted button at rest
    VirtualButton btn(true);
    TEST_ASSERT_EQUAL(btn.is_pressed(), false);
    TEST_ASSERT_EQUAL(btn.just_pressed(), false);
    TEST_ASSERT_EQUAL(btn.just_released(), false);
    TEST_ASSERT_EQUAL(btn.just_changed(), false);

    btn.update(true);
    btn.update(); // must not change anything

    TEST_ASSERT_EQUAL(btn.is_pressed(), false);
    TEST_ASSERT_EQUAL(btn.just_pressed(), false);
    TEST_ASSERT_EQUAL(btn.just_released(), false);
    TEST_ASSERT_EQUAL(btn.just_changed(), false);

    // now we press the button
    btn.update(false);

    TEST_ASSERT_EQUAL(btn.is_pressed(), true);
    TEST_ASSERT_EQUAL(btn.just_pressed(), true);
    TEST_ASSERT_EQUAL(btn.just_released(), false);

    // reset on next query
    TEST_ASSERT_EQUAL(btn.just_pressed(), false);
    TEST_ASSERT_EQUAL(btn.just_released(), false);
}

void test_events()
{
    VirtualButton btn;
    struct ButtonEvents evt;

    evt = btn.update(false);
    TEST_ASSERT_FALSE(evt.pressed);
    TEST_ASSERT_FALSE(evt.released);
    TEST_ASSERT_FALSE(evt.changed);

    evt = btn.update(true);
    TEST_ASSERT_TRUE(evt.pressed);
    TEST_ASSERT_FALSE(evt.released);
    TEST_ASSERT_TRUE(evt.changed);

    evt = btn.update(false);
    TEST_ASSERT_FALSE(evt.pressed);
    TEST_ASSERT_TRUE(evt.released);
    TEST_ASSERT_TRUE(evt.changed);

    evt = btn.update(false);
    TEST_ASSERT_FALSE(evt.pressed);
    TEST_ASSERT_FALSE(evt.released);
    TEST_ASSERT_FALSE(evt.changed);
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(test_virtual);
    RUN_TEST(test_inverted);
    RUN_TEST(test_events);
    return UNITY_END();
}
