#ifndef __PWM_H__
#define __PWM_H__

#include <stdint.h>

#define PWM_PERIOD 1000 /* PWM period in ticks */
#define PWM_DUTY_CYCLE 500 /* PWM duty cycle in percent */

void PWM_Init(void);
void SetFrequency(uint32_t frequency);
void SetPeriod(uint32_t period);
void SetPercentDutyCycle(uint8_t percent);
void SetDutyCycle(uint16_t dutyCycle);


#endif // __PWM_H__
