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
#include "adc.h"
/*------------------------------------------------------------*/
/* LOCAL VARIABLES */
/*------------------------------------------------------------*/

/** Variable to store the current value, local to the file */
static curr_values_t current_value = CUR_VALUE_INIT;
/** Variable to store the current module status */
static curr_status_t status = CUR_STATUS_NORMAL;
/** Variable to store the read current value */
static curr_values_t current_read_value = CUR_VALUE_INIT;
/** Variable to store the status of the output  */
static adc_output_t read_out = ADC_OUTPUT_OFF;
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
curr_error_t current_read_value_fun(void)
{
    uint8_t read_current = adc_read_current();
    if ((read_current <= ADC_MAX_CURRENT) &&
        (read_current >= ADC_MIN_CURRENT))
    {
        current_read_value = read_current;
    }
    else
    {
        return CUR_ERROR_INVALID_VALUE;
    }
    return CUR_ERROR_NONE;
}

/**
 * @brief      Read the output status
 * @return     Return error code
 */
curr_error_t current_read_output_status(void)
{
    adc_output_t read_out_tem = adc_read_output();
    if (read_out_tem <= ADC_OUTPUT_OFF)
    {
        read_out = read_out_tem;
    }
    else
    {
        return CUR_ERROR_INVALID_VALUE;
    }
    return CUR_ERROR_NONE;
}


/**
 * @brief      Update and validate the status, usign the read value vs set value
 * @return     Return error code
 */
void current_update_status(void)
{
    current_read_value_fun();
    current_read_output_status();
    if (read_out == ADC_OUTPUT_OFF)
    {
        status = CUR_STATUS_OFF;
    }
    else
    {
        if (current_read_value <= current_value)
        {
            status = CUR_STATUS_NORMAL;
        }
        else
        {
            status = CUR_STATUS_OVERCURRENT;
        }
    }
}
/**
 * @brief      Return the status of the current module
 * @return     Return the status of the module
 */
curr_status_t current_get_status(void)
{
    return status;
}