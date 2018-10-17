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
static uint8_t current_value = CUR_VALUE_INIT;

/*------------------------------------------------------------*/
/* FUNCTIONS */
/*------------------------------------------------------------*/

/**
 * @brief      Return the value of current configuration.
 * @return     Value of the current.
 */
uint8_t current_get_value(void)
{
    return current_value;
}

/**
 * @brief      Configure the value of the current
 * @return     Return error code
 */
int8_t current_set_value(uint8_t value)
{
    
}