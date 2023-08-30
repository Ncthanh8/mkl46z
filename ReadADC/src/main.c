#include <stdint.h>
#include "PWM.h"
#include "Led.h"
#include "adc.h"

int main(void)
{
    uint16_t adc_result;
    RED_LED_Init();
    ADC_Light_Sensor_Init();
    PWM_Init();

    while(1){
        adc_result = ADC_GetValue();
        SetPercentDutyCycle(adc_result * 100 / 65535);  /* set duty cycle in percent */
    }
}
