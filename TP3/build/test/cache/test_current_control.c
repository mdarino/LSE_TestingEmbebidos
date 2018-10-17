#include "build/temp/_test_current_control.c"
#include "mock_adc.h"
#include "current_control.h"
#include "unity.h"
void setUp(void)

{



}









void tearDown(void)

{



}









void test_initValue(void) {

    curr_values_t current_value = 0xFF;

    current_value = current_get_value();

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((current_value)), (

   ((void *)0)

   ), (UNITY_UINT)(52), UNITY_DISPLAY_STYLE_INT);









}









void test_configureDifferentsValues(void) {

    curr_error_t result;

    char mensaje[64];

    uint8_t index;

    for (index = 1; index <= 0x05; ++index)

    {

        printf("Test 2 Info: Value:%d\n", index);

        sprintf(mensaje, "Test of the value: |%d|", index);

        result = current_set_value(index);

        UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )(((0))), (UNITY_INT)(UNITY_INT8 )((result)), ((mensaje)), (UNITY_UINT)(71), UNITY_DISPLAY_STYLE_INT8);

        UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((index)), (UNITY_INT)(UNITY_UINT8 )((current_get_value())), ((mensaje)), (UNITY_UINT)(72), UNITY_DISPLAY_STYLE_UINT8);

    }

    index = 0;

    printf("Test 2 Info: Value:%d\n", index);

    sprintf(mensaje, "Test of the value: |%d|", index);

    result = current_set_value(index);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )(((0))), (UNITY_INT)(UNITY_INT8 )((result)), ((mensaje)), (UNITY_UINT)(78), UNITY_DISPLAY_STYLE_INT8);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_UINT8 )((index)), (UNITY_INT)(UNITY_UINT8 )((current_get_value())), ((mensaje)), (UNITY_UINT)(79), UNITY_DISPLAY_STYLE_UINT8);

}









void test_configureNegativeValue(void) {

    curr_error_t result;



    result = current_set_value(0b10000000);

    UnityAssertEqualNumber((UNITY_INT)(((-1))), (UNITY_INT)((result)), (

   ((void *)0)

   ), (UNITY_UINT)(89), UNITY_DISPLAY_STYLE_INT);

    if (((0b10000000) != (current_get_value()))) {} else {UnityFail( ((" Expected Not-Equal")), (UNITY_UINT)((UNITY_UINT)(90)));};



    result = current_set_value(0b11111111);

    UnityAssertEqualNumber((UNITY_INT)(((-1))), (UNITY_INT)((result)), (

   ((void *)0)

   ), (UNITY_UINT)(93), UNITY_DISPLAY_STYLE_INT);

    if (((0b11111111) != (current_get_value()))) {} else {UnityFail( ((" Expected Not-Equal")), (UNITY_UINT)((UNITY_UINT)(94)));};

}









void test_configureBigNumbers(void) {

    curr_error_t result;



    result = current_set_value(0x05 +1);

    UnityAssertEqualNumber((UNITY_INT)(((-1))), (UNITY_INT)((result)), (

   ((void *)0)

   ), (UNITY_UINT)(104), UNITY_DISPLAY_STYLE_INT);

    if ((((0x05 +1)) != (current_get_value()))) {} else {UnityFail( ((" Expected Not-Equal")), (UNITY_UINT)((UNITY_UINT)(105)));};

}











void test_readCurrentHal(void) {

    curr_error_t result;





    result = current_read_value_fun();

    UnityAssertEqualNumber((UNITY_INT)(((0))), (UNITY_INT)((result)), (

   ((void *)0)

   ), (UNITY_UINT)(117), UNITY_DISPLAY_STYLE_INT);

}









void test_readOutputStatus(void) {

    curr_error_t result;





    result = current_read_output_status();

    UnityAssertEqualNumber((UNITY_INT)(((0))), (UNITY_INT)((result)), (

   ((void *)0)

   ), (UNITY_UINT)(128), UNITY_DISPLAY_STYLE_INT);

}









void test_generateEvents(void) {











    curr_status_t status;



    current_set_value(3);









    adc_read_current_CMockIgnoreAndReturn(147, 2);

    adc_read_output_CMockIgnoreAndReturn(148, ADC_OUTPUT_ON);;

    current_update_status();



    UnityAssertEqualNumber((UNITY_INT)((CUR_STATUS_OVERCURRENT)), (UNITY_INT)((current_get_status())), (

   ((void *)0)

   ), (UNITY_UINT)(151), UNITY_DISPLAY_STYLE_INT);







    current_update_status();



    UnityAssertEqualNumber((UNITY_INT)((CUR_STATUS_NORMAL)), (UNITY_INT)((current_get_status())), (

   ((void *)0)

   ), (UNITY_UINT)(157), UNITY_DISPLAY_STYLE_INT);







    current_update_status();



    UnityAssertEqualNumber((UNITY_INT)((CUR_STATUS_OVERCURRENT)), (UNITY_INT)((current_get_status())), (

   ((void *)0)

   ), (UNITY_UINT)(163), UNITY_DISPLAY_STYLE_INT);







    current_update_status();



    UnityAssertEqualNumber((UNITY_INT)((CUR_STATUS_OFF)), (UNITY_INT)((current_get_status())), (

   ((void *)0)

   ), (UNITY_UINT)(169), UNITY_DISPLAY_STYLE_INT);



}
