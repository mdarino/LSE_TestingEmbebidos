#include <stdint.h>

/** Type of the possible status of the current module */
typedef enum
{
	ADC_OUTPUT_ON = 0, /**< The output is ON */
	ADC_OUTPUT_OFF = 1 /**< The output is OFF */	
}adc_output_t;

#define ADC_MAX_CURRENT 	10	/**< Max value that the system can read */
#define ADC_MIN_CURRENT 	0   /**< Min value that the system can read */

uint8_t adc_read_current();
adc_output_t adc_read_output();