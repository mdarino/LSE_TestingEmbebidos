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
