/******************************************************
* @file   test_current_control.c
* @brief  File to run the test of the current control module
* @author Marcos Darino
* @date OCT-2018
******************************************************/

/*------------------------------------------------------------*/
/* INCLUDES */
/*------------------------------------------------------------*/

#include "unity.h" /* Allow use assert functions */
#include "current_control.h"
#include "mock_adc.h"
/*------------------------------------------------------------*/
/* DEFINE */
/*------------------------------------------------------------*/


/*------------------------------------------------------------*/
/* LOCAL VARIABLES */
/*------------------------------------------------------------*/


/*------------------------------------------------------------*/
/* TEST FUNCTIONS */
/*------------------------------------------------------------*/


/**
 * @brief      This function run when run each test
 */
void setUp(void)
{

}

/**
 * @brief      This function run when finish the test
 */
void tearDown(void)
{

}

/**
 * @brief      Test number 1: Verify the REQ 1, Start in zero
 */
void test_initValue(void) {
    curr_values_t current_value = CUR_VALUE_INVALID; /* Start the local variable in one imposible value*/
    current_value = current_get_value();
    TEST_ASSERT_EQUAL(0, current_value); 
    /* NOTE: In this test is not necessary the local variable, I think is possible do:
       TEST_ASSERT_EQUAL(0, current_get_value());
       However, the idea is use the function in that way because is more clear.
     */
}

/**
 * @brief      Test number 2: Verify the REQ 2, Can set the current value between 0-5
 */
void test_configureDifferentsValues(void) {
    curr_error_t result;
    char mensaje[64];
    uint8_t index;
    for (index = 1; index <= CUR_VALUE_MAX; ++index)
    {
        printf("Test 2 Info: Value:%d\n", index);
        sprintf(mensaje, "Test of the value: |%d|", index);
        result = current_set_value(index);
        TEST_ASSERT_EQUAL_INT8_MESSAGE(CUR_ERROR_NONE, result, mensaje);
        TEST_ASSERT_EQUAL_UINT8_MESSAGE(index, current_get_value(),mensaje);
    }
    index = 0;
    printf("Test 2 Info: Value:%d\n", index);
    sprintf(mensaje, "Test of the value: |%d|", index);
    result = current_set_value(index);
    TEST_ASSERT_EQUAL_INT8_MESSAGE(CUR_ERROR_NONE, result, mensaje);
    TEST_ASSERT_EQUAL_UINT8_MESSAGE(index, current_get_value(),mensaje);
}

/**
 * @brief      Test number 3: Verify the REQ 3, Not negative number!
 */
void test_configureNegativeValue(void) {
    curr_error_t result;
    /* The first negative binary */
    result = current_set_value(0b10000000);
    TEST_ASSERT_EQUAL(CUR_ERROR_INVALID_VALUE, result);
    TEST_ASSERT_NOT_EQUAL(0b10000000, current_get_value());
    /* The last negative binary */
    result = current_set_value(0b11111111);
    TEST_ASSERT_EQUAL(CUR_ERROR_INVALID_VALUE, result);
    TEST_ASSERT_NOT_EQUAL(0b11111111, current_get_value());
}

/**
 * @brief      Test number 4: Verify the REQ 4, Not number bigger than 5!
 */
void test_configureBigNumbers(void) {
    curr_error_t result;
    /* Nubmer not supported */
    result = current_set_value(CUR_VALUE_MAX+1);
    TEST_ASSERT_EQUAL(CUR_ERROR_INVALID_VALUE, result);
    TEST_ASSERT_NOT_EQUAL((CUR_VALUE_MAX+1), current_get_value());
}


/**
 * @brief      Test number 5: Verify the REQ 5, Read the current from the HAL
 */
void test_readCurrentHal(void) {
    curr_error_t result;

    //adc_read_current_Expect(2); /*Example of read value */
    result = current_read_value_fun();
    TEST_ASSERT_EQUAL(CUR_ERROR_NONE, result);
}

/**
 * @brief      Test number 6: Verify the REQ 6, Read the output status
 */
void test_readOutputStatus(void) {
    curr_error_t result;

    //adc_read_current_Expect(2); /*Example of read value */
    result = current_read_output_status();
    TEST_ASSERT_EQUAL(CUR_ERROR_NONE, result);
}

/**
 * @brief      Test number 7: Verify the REQ 7 and 8, generate event if something is wrong
 */
void test_generateEvents(void) {
    
    /* The module will have a funtion to update and chech the status of the current this function in the 
     * real code is called x time per second, maybe is not the best implementation but allow me use and leard 
     * how to use mock fuctions */

    curr_status_t status;

    current_set_value(3); /* Set and example current value */
    
    /* Mock of the functions to generate a normal operation */

      /*Read current = 4  -> Must be over current */
    adc_read_current_IgnoreAndReturn(2); /*Example of read value */
    adc_read_output_IgnoreAndReturn(ADC_OUTPUT_ON);; /*Example of read value */
    current_update_status();

    TEST_ASSERT_EQUAL(CUR_STATUS_OVERCURRENT, current_get_status());    

      /*Read current = 2  -> Must be Normal */

    current_update_status();

    TEST_ASSERT_EQUAL(CUR_STATUS_NORMAL, current_get_status());    

      /*Read current = 4  -> Must be over current */

    current_update_status();

    TEST_ASSERT_EQUAL(CUR_STATUS_OVERCURRENT, current_get_status()); 

      /*Read current = 4 but the output dissable -> Must be off */

    current_update_status();

    TEST_ASSERT_EQUAL(CUR_STATUS_OFF, current_get_status()); 

}