/******************************************************
* @file   test_current_control.c
* @brief  File to run the test of the current control module
* @author Marcos Darino
* @date OCT-2018
******************************************************/

/*--- INCLUDES ---*/

#include "unity.h" /* Allow use assert functions */


/*--- LOCAL VARIABLES ---*/


/*--- TEST FUNCTIONS---*/

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
 * @brief      First test to verify the REQ 1
 */
void test_initValue(void) {
	uint8_t current_value = 0xFF; /* Start the local variable in one imposible value*/
	current_value = current_get_value();
    TEST_ASSERT_EQUAL(0, current_value); 
    /* NOTE: In this test is not necessary the local variable, I think is possible do:
       TEST_ASSERT_EQUAL(0, current_get_value());
       However, the idea is use the function in that way because is more clear.
     */
}

