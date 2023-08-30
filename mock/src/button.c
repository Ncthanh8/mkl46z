#include "button.h" 


/********************************************************************
 *                            Function                              *
********************************************************************/

/* Init button with interrupt */
void init_button(void){ 
    SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK; /* Enable clock for PORTC */
    PORT_PCR(PORTC,SW) &= ~PORT_PCR_MUX_MASK; /* Clear MUX */
    PORT_PCR(PORTC,SW) |= PORT_PCR_MUX(1); /* Set MUX as GPIO */
    PORT_PCR(PORTC,SW) &= ~PORT_PCR_IRQC_MASK; /* Clear IRQC */
    PORT_PCR(PORTC,SW) |= PORT_PCR_IRQC(10); /* Set IRQC as falling edge */
    PORT_PCR(PORTC,SW) |= PORT_PCR_PE_MASK; /* Enable pull resistor */
    PORT_PCR(PORTC,SW) |= PORT_PCR_PS_MASK; /* Set pull up resistor */ 
    GPIO_PDDR(PORTC)    &= ~(1 << SW); /* Set as input */

    // Enable interrupt on PORTC
    NVIC_ICPR |= (1U << ID_INT_SW1); /* Clear any pending interrupts on PORTC */
    NVIC_ISER |= (1U << ID_INT_SW1); /* Enable interrupts from PORTC */
    NVIC_IPR(1) |= (1U << NVIC_IPR_PRI_N0_SHIFT); /* Set interrupt priority to 1 */

}