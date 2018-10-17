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
/** Variable to store the current module status */
static curr_status_t status = CUR_STATUS_NORMAL;
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

/**
 * @brief      Read form the HAL the current value
 * @return     Return error code
 */
curr_error_t current_read_value(void)
{
    return CUR_ERROR_NONE;
}

/**
 * @brief      Read the output status
 * @return     Return error code
 */
curr_error_t current_read_output_status(void)
{
    return CUR_ERROR_NONE;
}


/**
 * @brief      Update and validate the status, usign the read value vs set value
 * @return     Return error code
 */
void current_update_status(void)
{
    status = CUR_STATUS_NORMAL;
}
/**
 * @brief      Return the status of the current module
 * @return     Return the status of the module
 */
curr_status_t current_get_status(void)
{
    return status;
}