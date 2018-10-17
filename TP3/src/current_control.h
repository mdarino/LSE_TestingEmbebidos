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
#define CUR_VALUE_MAX 0x05 /**< Max current value */
#define CUR_VALUE_MIN 0x00 /**< Min current value */
#define CUR_VALUE_INIT CUR_VALUE_MIN /**< Start current value */

/* ERROR */
#define CUR_ERROR_NONE          (0) /**< Not error */
#define CUR_ERROR_INVALID_VALUE (-1) /**< Error when someone try to set an invalid value */
/*------------------------------------------------------------*/
/* TYOEDEF */
/*------------------------------------------------------------*/

/** Type for the current values */
typedef uint8_t curr_values_t;
/** Type for the current error */
typedef int8_t curr_error_t;
/** Type of the possible status of the current module */
typedef enum
{
	CUR_STATUS_NORMAL = 0, /**< Everithing is OK the values read and set are OK */
	CUR_STATUS_OVERCURRENT = 1 /**< The current is upper than the set */	
}curr_status_t;


/*------------------------------------------------------------*/
/* FUNCTIONS */
/*------------------------------------------------------------*/

curr_values_t current_get_value(void);
curr_error_t current_set_value(curr_values_t value);
curr_error_t current_read_value(void);
curr_error_t current_read_output_status(void);

void current_update_status(void);
curr_status_t current_get_status(void);