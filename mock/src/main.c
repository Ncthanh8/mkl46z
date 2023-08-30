/********************************************************************************
 * *
 * @file     main.c
 * @version  V1.00
 * $Date:    15/8/2023
 * @brief    Control Green LED by PWM using button to change duty cycle of PWM signal
 *           and change frequency of PWM signal by UART communication 
 * @note     IAR Embedded Workbench IDE 8.32.1   
 * *
*********************************************************************************/


#include "KL46z.h"
#include "pwm.h"
#include "button.h"


void main(void)
{
    init_pwm();
    clock_config();
    init_button();
    uart0_config(SystemCoreClock, 115200);
    usart_send_string("Hello World\n\r");
    while(1);
}
