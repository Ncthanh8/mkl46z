/* ###################################################################
**     Filename    : main.c
**     Project     : Uart
**     Processor   : MKL46Z256VLL4
** ###################################################################*/


#include "main.h"



int main(void)
{
    char str[] = "Hello World!\r\n";
    uint32_t baudrate = 115200U;
    
    /* Clock Configuration */
    SystemCoreClockUpdate();

    /* Pin Configuration */
    UART0_PinConfig();

    /* Initialize UART0 */
    UART0_Init(baudrate);
    
    /* Send data */
    UART0_SendString(str);
    
    while(1)
    {
        /* Receive data */
        uint8_t data;
        UART0_ReceiveString(&data);
        
        if ( strcmp((char *)&data, "Start") == 0 )
        {
            /* Send data */
            UART0_SendString(str);
        }   

        /* Delay */
        Delay(1000000); /* 1s */
    }
}

/* Delay */

void Delay(uint32_t delay)
{
    while(delay--);
}
