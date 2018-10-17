/******************************************************
* @file   current_control.h
* @brief  Header of the control of the current of the power supply
* @author Marcos Darino
* @date OCT-2018
******************************************************/

/*--- INCLUDES ---*/
#include "current_control.h"

/*--- LOCAL VARIABLES ---*/
static uint8_t current_value = 0;

/*--- FUNCTIONS---*/

/**
 * @brief      Return the value of current configuration.
 * @return     Value of the current.
 */
uint8_t current_get_value(void)
{
    return current_value;
}