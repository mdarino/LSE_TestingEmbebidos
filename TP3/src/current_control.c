/******************************************************
* @file   current_control.h
* @brief  Header of the control of the current of the power supply
* @author Marcos Darino
* @date OCT-2018
******************************************************/

/*------------------------------------------------------------*/
/* INCLUDES */
/*------------------------------------------------------------*/
#include "current_control.h"

/*------------------------------------------------------------*/
/* LOCAL VARIABLES */
/*------------------------------------------------------------*/

/** Variable to store the current value, local to the file */
static curr_values_t current_value = CUR_VALUE_INIT;

/*------------------------------------------------------------*/
/* FUNCTIONS */
/*------------------------------------------------------------*/

/**
 * @brief      Return the value of current configuration.
 * @return     Value of the current.
 */
curr_values_t current_get_value(void)
{
    return current_value;
}

/**
 * @brief      Configure the value of the current
 * @return     Return error code
 */
curr_error_t current_set_value(curr_values_t value)
{
    curr_error_t result = CUR_ERROR_NONE;
    if ((value >= CUR_VALUE_MIN) && (value <= CUR_VALUE_MAX)) /* In this case we add the validation for smaller and bigger because is an uint8, cannot be negative */
    {
        current_value = value; 
    }
    else
    {
        result = CUR_ERROR_INVALID_VALUE;
    }
    return result;
}