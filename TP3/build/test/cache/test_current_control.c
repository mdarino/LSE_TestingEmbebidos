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

 uint8_t current_value = CUR_VALUE_INVALID;

 current_value = current_get_value();

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((current_value)), (

   ((void *)0)

   ), (UNITY_UINT)(52), UNITY_DISPLAY_STYLE_INT);









}









void test_configureDifferentsValues(void) {

 int8_t result = current_set_value(0);

    UnityAssertEqualNumber((UNITY_INT)((CUR_ERROR_NONE)), (UNITY_INT)((result)), (

   ((void *)0)

   ), (UNITY_UINT)(64), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((current_get_value())), (

   ((void *)0)

   ), (UNITY_UINT)(65), UNITY_DISPLAY_STYLE_INT);

}
