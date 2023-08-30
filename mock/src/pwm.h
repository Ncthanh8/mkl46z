#ifndef _PWM_H_
#define _PWM_H_

#include "KL46z.h"

#define PWM_PERIOD 20000 /* PWM period in ticks */
#define PWM_DUTY_CYCLE 20000 /* PWM duty cycle in ticks */

/*******************************************************************************
 *                         FUNCTION PROTOTYPES                                *
 ******************************************************************************/

/**
 * @brief Initialize PWM
 * @details Initialize PWM for the green LED on the FRDM-KL46z board
 * @param void
 * @return void
 * @note PWM period is 1.2 ms / pin 5 / PORTD / TPM0_CH5
*/
void init_pwm(void);


/**
 * @brief Set PWM duty cycle
 * @details Set PWM duty cycle for the green LED on the FRDM-KL46z board 
 * @param duty_cycle Duty cycle in percent
 * @return void
 * @note Duty cycle is a value between 0 and 100 percent
*/
void set_duty_cycle(u16_t duty_cycle);


#endif // _PWM_H_