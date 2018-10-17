#include "build/temp/_test_current_control.c"
#include "current_control.h"
#include "unity.h"
void setUp(void)

{



}









void tearDown(void)

{



}









void test_initValue(void) {

    uint8_t current_value = 0xFF;

    current_value = current_get_value();

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((current_value)), (

   ((void *)0)

   ), (UNITY_UINT)(52), UNITY_DISPLAY_STYLE_INT);









}









void test_configureDifferentsValues(void) {

    int8_t result;

    char mensaje[64];

    uint8_t index;

    for (index = 1; index <= 0x05; ++index)

    {

        printf("Test 2 Info: Value:%d\n", index);

        sprintf(mensaje, "Test of the value: |%d|", index);

        result = current_set_value(index);

        UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x00)), (UNITY_INT)(UNITY_INT8 )((result)), ((mensaje)), (UNITY_UINT)(71), UNITY_DISPLAY_STYLE_INT8);

        UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((index)), (UNITY_INT)(UNITY_UINT8 )((current_get_value())), ((mensaje)), (UNITY_UINT)(72), UNITY_DISPLAY_STYLE_UINT8);

    }

    index = 0;

    printf("Test 2 Info: Value:%d\n", index);

    sprintf(mensaje, "Test of the value: |%d|", index);

    result = current_set_value(index);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0x00)), (UNITY_INT)(UNITY_INT8 )((result)), ((mensaje)), (UNITY_UINT)(78), UNITY_DISPLAY_STYLE_INT8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((index)), (UNITY_INT)(UNITY_UINT8 )((current_get_value())), ((mensaje)), (UNITY_UINT)(79), UNITY_DISPLAY_STYLE_UINT8);

}
