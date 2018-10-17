/******************************************************
* @file   current_control.h
* @brief  Header of the control of the current of the power supply
* @author Marcos Darino
* @date OCT-2018
******************************************************/

/*------------------------------------------------------------*/
/* INCLUDES */
/*------------------------------------------------------------*/
#include <stdint.h>

/*------------------------------------------------------------*/
/* DEFINE */
/*------------------------------------------------------------*/

#define CUR_VALUE_INVALID 0xFF /**< Invalid current value */
#define CUR_VALUE_INIT 0x00 /**< Start current value */
#define CUR_VALUE_MAX 0x05 /**< Max current value */

/* ERROR */
#define CUR_ERROR_NONE 0x00 /**< Not error */


/*------------------------------------------------------------*/
/* FUNCTIONS */
/*------------------------------------------------------------*/

uint8_t current_get_value(void);
int8_t current_set_value(uint8_t value);