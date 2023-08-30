/* ###################################################################
**     Filename    : gpio.c
**     Project     : Uart
**     Processor   : MKL46Z256VLL4
** ###################################################################*/

#include "gpio.h"

/**
 * @brief   GPIO Initialization
 * @details Initializes the GPIO
 * @param[in]     void
 * @param[in,out] void
 * @return        void
 */

void GPIO_Init(void)
{
    /* Enable PORTA clock gate */
    SIM->SCGC5 |= (1U <<  9); /* Enable PORTA clock gate */
    /* Enable PORTB clock gate */
    SIM->SCGC5 |= (1U << 10); /* Enable PORTB clock gate */
    /* Enable PORTC clock gate */
    SIM->SCGC5 |= (1U << 11); /* Enable PORTC clock gate */
    /* Enable PORTD clock gate */
    SIM->SCGC5 |= (1U << 12); /* Enable PORTD clock gate */
    /* Enable PORTE clock gate */
    SIM->SCGC5 |= (1U << 13); /* Enable PORTE clock gate */
}