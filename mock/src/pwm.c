#include "pwm.h"

/* initialize TPM0_CH5 as PWM output */
void init_pwm(void){
    SIM_SCGC5 |= (1U << SIM_SCGC5_SHIFT(PORTD)) ; /* enable clock to PORTD */
    PORT_PCR(PORTD, GREEN_LED_PIN)=  PORT_PCR_MUX(4); /* set PTD5 to TPM0_CH1 */
    GPIO_PDDR(PORTD) |= (1U << GREEN_LED_PIN); /* set PTD5 to output */
    SIM_SCGC6 |= SIM_SCGC6_TPM0_MASK; /* enable clock to TPM0 */
    SIM_SOPT2 |= SIM_SOPT2_TPMSRC(1); /* set TPM clock source to MCGFLLCLK or MCGPLLCLK/2 */
    TPM0_SC |= TPM_SC_PS(7); /* set prescaler to 128 */
    TPM0_SC |= TPM_SC_CMOD(1); /* set clock mode to count up */
    TPM0_SC |= TPM_SC_CPWMS(0); /* set counter to up counting mode */
    TPM0_MOD |= PWM_PERIOD; /* set PWM period in ticks */
    TPM0_CnSC(5) |= TPM_CnSC_MSB_MASK | TPM_CnSC_ELSB_MASK; /* set TPM0_CH1 to edge-aligned PWM */
    TPM0_CnV(5) = PWM_DUTY_CYCLE; /* set TPM0_CH1 duty cycle in ticks */
}


/* set duty cycle of TPM0_CH5 */
void set_duty_cycle(u16_t duty_cycle){
	TPM0_CnV(5) = duty_cycle*PWM_PERIOD/100; /* set TPM0_CH1 duty cycle in ticks */
}
