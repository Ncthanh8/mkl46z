#include "PWM.h"
#include "MKL46Z4.h"

void PWM_Init(void){
    /* enable clock for red LED */
    SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK; /* enable clock for PORTD */
    PORTD->PCR[29] |= PORT_PCR_MUX(4); /* set PTD5 to TPM0_CH1 */
    PTD->PDDR |= (1 << 29); /* set PTD5 to output */
    PTD->PSOR |= (1 << 29); /* set PTD5 to high */
    SIM->SCGC6 |= SIM_SCGC6_TPM0_MASK; /* enable clock for TPM0 */
    SIM->SOPT2 |= SIM_SOPT2_TPMSRC(1); /* set TPM clock source to MCGFLLCLK or MCGPLLCLK/2 */
    TPM0->SC |= TPM_SC_PS(7); /* set prescaler to 128 */
    TPM0->SC |= TPM_SC_CMOD(1); /* set clock mode to count up */
    TPM0->SC |= TPM_SC_CPWMS(0); /* set counter to up counting mode */
    TPM0->MOD = PWM_PERIOD; /* set PWM period in ticks */
    TPM0->CONTROLS[1].CnSC |= TPM_CnSC_MSB_MASK | TPM_CnSC_ELSB_MASK; /* set TPM0_CH1 to edge-aligned PWM */
    TPM0->CONTROLS[1].CnV = PWM_DUTY_CYCLE; /* set TPM0_CH1 duty cycle in ticks */
}

void SetDutyCycle(uint16_t duty_cycle){ /* function to set duty cycle in ticks */
    TPM0->CONTROLS[1].CnV = duty_cycle;
}

void SetFrequency(uint32_t frequency){ /* function to set frequency in Hz */
    uint32_t modulo = 48000000 / frequency / 128;
    TPM0->MOD = modulo;
}

void SetPeriod(uint32_t period){ /* function to set period in seconds */
    uint32_t modulo = 48000000 / 128 * period;
    TPM0->MOD = modulo;
}

void SetPercentDutyCycle(uint8_t percent){ /* function to set duty cycle in percent */
    uint16_t duty_cycle = TPM0->MOD * percent / 100;
    TPM0->CONTROLS[1].CnV = duty_cycle;
}

    //TPM0->SC |= TPM_SC_PS(7); /* set prescaler to 128 */
    //TPM0->MOD = 46875; /* set modulo register to 46875 */
    //TPM0->CONTROLS[1].CnSC |= TPM_CnSC_MSB_MASK | TPM_CnSC_ELSB_MASK; /* set TPM0_CH1 to edge-aligned, high-true PWM */
    //TPM0->CONTROLS[1].CnV = 0; /* set TPM0_CH1 initial duty cycle to 0% */
    //TPM0->SC |= TPM_SC_CMOD(1); /* enable TPM0 counter */