#include <VirtualButton.h>
#include <unity.h>

VirtualButton btn;

void test_virtual()
{
    btn.update();
}

void test_inverted()
{
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(test_virtual);
    RUN_TEST(test_inverted);
    return UNITY_END();
}
