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
	uint8_t current_value = CUR_VALUE_INVALID; /* Start the local variable in one imposible value*/
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
	int8_t result = current_set_value(1);
    TEST_ASSERT_EQUAL(CUR_ERROR_NONE, result);
    TEST_ASSERT_EQUAL(1, current_get_value());
}

