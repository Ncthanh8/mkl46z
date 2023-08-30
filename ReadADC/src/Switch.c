#include "Switch.h"
#include "MKL46Z4.h"

void Systick_Init(void){
    SysTick->LOAD = SystemCoreClock/1000 - 1; // 1ms
    SysTick->VAL = 0; 
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk;
}

void Switch_Init(void){
    SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;
    SW1_GPIO->PDDR &= ~SW1_MASK;
    SW2_GPIO->PDDR &= ~SW2_MASK;
    PORTC->PCR[SW1_PIN] |= PORT_PCR_MUX(1) | PORT_PCR_IRQC(0x0A);
    PORTC->PCR[SW2_PIN] |= PORT_PCR_MUX(1) | PORT_PCR_IRQC(0x0A);
    
    NVIC_SetPriority(PORTC_PORTD_IRQn, 128);
    NVIC_ClearPendingIRQ(PORTC_PORTD_IRQn);
    NVIC_EnableIRQ(PORTC_PORTD_IRQn);
}

void SW1_Init(void){
    SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;
    SW1_GPIO->PDDR &= ~SW1_MASK;
    PORTC->PCR[SW1_PIN] |= PORT_PCR_MUX(1) | PORT_PCR_IRQC(0x0A);
    NVIC_EnableIRQ(PORTC_PORTD_IRQn);
    NVIC_SetPriority(PORTC_PORTD_IRQn,0);
}

void SW2_Init(void){
    SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;
    SW2_GPIO->PDDR &= ~SW2_MASK;
    PORTC->PCR[SW2_PIN] |= PORT_PCR_MUX(1) | PORT_PCR_IRQC(0x0A);
    NVIC_EnableIRQ(PORTC_PORTD_IRQn);
    NVIC_SetPriority(PORTC_PORTD_IRQn,0);
}

