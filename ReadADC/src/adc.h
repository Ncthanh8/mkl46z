#ifndef _ADC_H_
#define _ADC_H_

#include <stdint.h>
#include "MKL46Z4.h"

void ADC_Light_Sensor_Init(void);
uint32_t ADC_GetValue(void);

#endif // _ADC_H_
