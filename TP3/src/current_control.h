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
/* TYOEDEF */
/*------------------------------------------------------------*/

/** Type for the current values */
typedef uint8_t curr_values_t;
/** Type for the current error */
typedef int8_t curr_error_t;


/*------------------------------------------------------------*/
/* FUNCTIONS */
/*------------------------------------------------------------*/

curr_values_t current_get_value(void);
curr_error_t current_set_value(curr_values_t value);