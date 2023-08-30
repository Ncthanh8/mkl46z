
/* ###################################################################
**     Filename    : uart.c
**     Project     : Uart
**     Processor   : MKL46Z256VLL4
** ###################################################################*/

#include "uart.h"
#include "gpio.h"
#include <string.h>

/**
 * @brief   UART0 Pin Initialization
 * @details Initializes the UART0 pins
 * @param[in]     void
 * @param[in,out] void
 * @return        void
 */

void UART0_PinConfig(void)
{
    /* PTA : UART0_RX */
    PORTA->PCR[1] = 0x00000200UL; /* UART0_RX */
    /* PTA : UART0_TX */
    PORTA->PCR[2] = 0x00000200UL; /* UART0_TX */
}

/**
 * @brief   UART0 Initialization
 * @details Initializes the UART0
 * @param[in]     buadrate UART0 baudrate
 * @param[in,out] void
 * @return        void
 */

void UART0_Init( uint32_t baudrate)
{
    MCG->C4 |= MCG_C4_DRST_DRS(0x01); /* Set DRS to 0x01 */
    SIM->SOPT2 |= (1U << 26); /* Select PLLFLLSEL as UART0 clock source */

    SIM->SCGC4 |= (1U << 10); /* Enable UART0 clock gate */
    SIM->SCGC5 |= (1U <<  9); /* Enable PORTA clock gate */

    PORTA->PCR[1] = PORT_PCR_MUX(0x02); /* Set UART0_RX pin multiplexer to 0x02 */
    PORTA->PCR[2] = PORT_PCR_MUX(0x02); /* Set UART0_TX pin multiplexer to 0x02 */

    /* Disable UART0 before changing registers */
    UART0->C2 &= ~(UART0_C2_TE_MASK | UART0_C2_RE_MASK); /* UART0->C2 &= 0x00; */

    /* Set UART0 baudrate : Baud = CLK / (OSR * (SBR + BRFA))*/
    UART0->BDH = (uint8_t)((baudrate >> 8) & 0x1FU); /* Set top 5 bits of SBR example baudrate = 115200 : 0x01 */
    UART0->BDL = (uint8_t)(baudrate & 0xFFU); /* Set bottom 8 bits of SBR example baudrate = 115200 : 0xC2 */

    /* Set UART0 control register 1 */
    UART0->C1 = 0x00; 
    UART0->C3 = 0x00; 
    UART0->C4 = 0x0F; /* OSR = 16 */ 
    UART0->C5 = 0x00; 
}

/**
 * @brief   UART0 Send Byte
 * @details Sends a byte through UART0
 * @param[in]     data Byte to be sent
 * @param[in,out] void
 * @return        void
 */

void UART0_SendByte(uint8_t data)
{   
    while(!(UART0->S1 & UART0_S1_TDRE_MASK)); /* Wait until transmit data register is empty */
    UART0->D = data; /* Send data */
}

/**
 * @brief         UART0_PutChar
 * @param[in]     char c
 * @param[in,out] void
 * @return        void
 */
void UART0_PutChar(char c) 
{
	UART0->D   = c;
  /* Wait for transmition complete */
	while(!(UART0->S1 & (0x01 << 6))) {} /* TDRE : Transmit Data Register Empty Flag */
}


/**
 * @brief   UART0 Send String
 * @details Sends a string through UART0
 * @param[in]     str String to be sent
 * @param[in,out] void
 * @return        void
 */

void UART0_SendString(char *str)
{
    while(*str)
    {
        UART0_PutChar(*str++);
    }
}

/**
 * @brief   UART0 Receive Byte
 * @details Receives a byte through UART0
 * @param[in]     void
 * @param[in,out] void
 * @return        char Received byte
 */

uint8_t UART0_ReceiveByte(void)
{
    while(!(UART0->S1 & UART0_S1_RDRF_MASK)); /* Wait until receive data register is full */
    return UART0->D; /* Return received data */
}

/**
 * @brief   UART0 Receive String
 * @details Receives a string through UART0
 * @param[in]     str String to be received
 * @param[in,out] void
 * @return        void
 */

void UART0_ReceiveString(uint8_t *str)
{
    uint8_t i = 0;
    do
    {
        str[i] = UART0_ReceiveByte();
    }while(str[i++] != '\r'); /* Receive data until '\r' */
}
