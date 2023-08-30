#ifndef _KL46Z_H_
#define _KL46Z_H_

#include "system_MKL46Z4.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

/****************************************************************************************
 *                               Macro definitions                                      *
 * **************************************************************************************/

typedef volatile unsigned int vol_u32_t;
typedef volatile unsigned char vol_u8_t;
typedef unsigned int u32_t;
typedef unsigned char u8_t;
typedef unsigned short u16_t;

#define DELAY_COUNT                              (1000000UL)

/* SIM */
#define SIM_SOPT2                                (*(vol_u32_t *)0x40048004u)
#define SIM_SOPT2_UART0SRC_SHIFT                 (26u)
#define SIM_SOPT2_PLLFLLSEL_SHIFT                (16u)
#define SIM_SOPT2_TPMSRC(x)                      (((x) << 24u) & 0x3000000u)

#define SIM_SOPT5                                (*(vol_u32_t *)0x40048010u)
#define SIM_SOPT5_UART0TXSRC_SHIFT               (0U)
#define SIM_SOPT5_UART0RXSRC_SHIFT               (2U)
#define SIM_SOPT5_UART0ODE_SHIFT                 (16U)
#define SIM_SCGC5_PORTC_MASK                     (0x800U)

#define SIM_SCGC4                                (*(vol_u32_t *)0x40048034u)
#define SIM_SCGC4_UART0_SHIFT                    (10U)
#define SIM_SCGC4_UART1_SHIFT                    (11U)
#define SIM_SCGC4_UART2_SHIFT                    (12U)

#define SIM_SCGC5                                (*(vol_u32_t *)0x40048038u)
#define SIM_SCGC5_SHIFT(port)                    (9U + (port))
     
#define SIM_SCGC6                                (*(vol_u32_t *)0x4004803Cu)
#define SIM_SCGC6_PIT_SHIFT                      (23U)
#define SIM_SCGC6_TPM0_MASK                      (0x1000000U)

#define SIM_CLKDIV1                              (*(vol_u32_t *)0x40048044u)
#define SIM_CLKDIV1_OUTDIV4_SHIFT                (16u)
#define SIM_CLKDIV1_OUTDIV4_MASK                 (0xF0000u)


/* SYSTICK */
#define SYST_CSR                                 (*(vol_u32_t *)0xE000E010u)
#define SYST_RVR                                 (*(vol_u32_t *)0xE000E014u)
#define SYST_CVR                                 (*(vol_u32_t *)0xE000E018u)
#define SYS_CSR_FLAG_SHIFT                       (16u)
#define SYS_CSR_CLK_SHIFT                        (2u)
#define SYS_CSR_TICKINT_SHIFT                    (1u)
#define SYS_CSR_ENABLE_SHIFT                     (0u)

/* NVIC */
#define NVIC_ISER                                (*(vol_u32_t *)0xE000E100u)
#define NVIC_ICER                                (*(vol_u32_t *)0xE000E180u)
#define NVIC_ICPR                                (*(vol_u32_t *)0xE000E280u)
#define NVIC_IPR(n)                              (*(vol_u32_t *)(0xE000E400u + 0x04*(n)))
#define NVIC_IPR_PRI_N0_SHIFT                    (6U) // 6 bits for priority
#define NVIC_IPR_PRI_N1_SHIFT                    (14U) // 6 bits for priority
#define NVIC_IPR_PRI_N2_SHIFT                    (22U)
#define NVIC_IPR_PRI_N3_SHIFT                    (30U)

#define NVIC_ICPR_IRQ(n)                         (*(vol_u32_t *)(0xE000E280u + 0x04*(n))) // Interrupt Clear Pending Register
#define NVIC_ISER_IRQ(n)                         (*(vol_u32_t *)(0xE000E100u + 0x04*(n))) // Interrupt Set Enable Register  

/* PIT */
#define PIT_MCR                                  (*(vol_u32_t *)0x40037000u)
#define PIT_MCR_MDIS_SHIFT                       (1u)
#define PIT_LDVAL(n)                             (*(vol_u32_t *)(0x40037100u + 0x10*(n)))
#define PIT_CVAL(n)                              (*(vol_u32_t *)(0x40037104u + 0x10*(n)))
#define PIT_TCTRL(n)                             (*(vol_u32_t *)(0x40037108u + 0x10*(n)))
#define PIT_TCTRL_CHN_SHIFT                      (2U)
#define PIT_TCTRL_TIE_SHIFT                      (1U)
#define PIT_TCTRL_TEN_SHIFT                      (0U)
#define PIT_TFLG(n)                              (*(vol_u32_t *)(0x4003710Cu + 0x10*(n)))
#define PIT_TFLG_TIF_SHIFT                       (0U)

/* MCG */
#define MCG_C1                                 (*(vol_u8_t *)0x40064000u)
#define MCG_C2                                 (*(vol_u8_t *)0x40064001u)
#define MCG_C3                                 (*(vol_u8_t *)0x40064002u)
#define MCG_C4                                 (*(vol_u8_t *)0x40064003u)
#define MCG_C5                                 (*(vol_u8_t *)0x40064004u)
#define MCG_C4_DMX32_SHIFT                     (7u)
#define MCG_C4_DRS_SHIFT                       (5u)

/*TPM-PWM*/
#define TPM0_SC                                  (*(vol_u32_t *)0x40038000u)
#define TPM0_MOD                                 (*(vol_u32_t *)0x40038004u)
#define TPM0_CnSC(n)                             (*(vol_u32_t *)(0x4003800Cu + 0x08*(n)))
#define TPM0_CnV(n)                              (*(vol_u32_t *)(0x40038010u + 0x08*(n)))
#define TPM_CnSC_ELSB_MASK                       (0x8U)
#define TPM_CnSC_MSB_MASK                        (0x20U)
#define TPM_SC_PS(x)                             (((x) << 0u) & 0x7u)
#define TPM_SC_CMOD(x)                           (((x) << 3u) & 0x18u)
#define TPM_SC_CPWMS(x)                          (((x) << 5u) & 0x20u)

/*UART0*/
#define UART0_BDH                              (*(vol_u8_t *)0x4006A000u)
#define UART0_BDH_LBKDIE_SHIFT                 (7u)
#define UART0_BDH_RXEDGIE_SHIFT                (6u)
#define UART0_BDH_SBNS_SHIFT                   (5u)
#define UART0_BDH_SBR_SHIFT                    (0u)

#define UART0_BDL                              (*(vol_u8_t *)0x4006A001u)

#define UART0_C1                               (*(vol_u8_t *)0x4006A002u)
#define UART0_C1_RSRC_SHIFT                    (5u)
#define UART0_C1_M_SHIFT                       (4u)
#define UART0_C1_ILT_SHIFT                     (4u)
#define UART0_C1_PE_SHIFT                      (1u)
#define UART0_C1_PT_SHIFT                      (0u)

#define UART0_C2                               (*(vol_u8_t *)0x4006A003u)
#define UART0_C2_TIE_SHIFT                      (7u)
#define UART0_C2_TCIE_SHIFT                     (6u)
#define UART0_C2_RIE_SHIFT                      (5u)
#define UART0_C2_ILIE_SHIFT                     (4u)
#define UART0_C2_TE_SHIFT                       (3u)
#define UART0_C2_RE_SHIFT                       (2u)
#define UART0_C3                               (*(vol_u8_t *)0x4006A006u)
#define UART0_C4                               (*(vol_u8_t *)0x4006A00Au)
#define UART0_C4_M10_SHIFT                     (5U)
#define UART0_C5                               (*(vol_u8_t *)0x4006A00Bu)
#define UART0_S1                               (*(vol_u8_t *)0x4006A004u)
#define UART0_S1_TDRE_SHIFT                    (7U)
#define UART0_S1_TC_SHIFT                      (6U)
#define UART0_S1_RDRF_SHIFT                    (5U)
#define UART0_S2                               (*(vol_u8_t *)0x4006A005u)
#define UART0_D                                (*(vol_u8_t *)0x4006A007u)
#define UART0_MA1                              (*(vol_u8_t *)0x4006A008u)
#define UART0_MA2                              (*(vol_u8_t *)0x4006A009u)



#define PORT_PCR_IRQC_MASK                       (0xF0000U)
#define PORT_PCR_IRQC_SHIFT                      (16U)
#define PORT_PCR_MUX_MASK                        (0x700U)
#define PORT_PCR_MUX_SHIFT                       (8U)
#define PORT_PCR_PS_MASK                         (0x1U)
#define PORT_PCR_PS_SHIFT                        (0U)
#define PORT_PCR_PE_MASK                         (0x2U)
#define PORT_PCR_PE_SHIFT                        (1U)
#define PORT_PCR_ISF_MASK                        (0x1000000U)

#define PORTA                                    (0u)
#define PORTB                                    (1u)
#define PORTC                                    (2u)
#define PORTD                                    (3u)
#define PORTE                                    (4u)

#define BASE_ADDR_PORT(port)                     (0x40049000u + 0x1000*(port))
#define BASE_ADDR_GPIO(port)                     (0x400FF000u + 0x40*(port))

/*Address: Base address + offset*/
#define GPIO_PSOR(port)                          (*(vol_u32_t *)(BASE_ADDR_GPIO(port) + 0x04))
#define GPIO_PCOR(port)                          (*(vol_u32_t *)(BASE_ADDR_GPIO(port) + 0x08))
#define GPIO_PTOR(port)                          (*(vol_u32_t *)(BASE_ADDR_GPIO(port) + 0x0C))
#define GPIO_PDIR(port)                          (*(vol_u32_t *)(BASE_ADDR_GPIO(port) + 0x10))
#define GPIO_PDDR(port)                          (*(vol_u32_t *)(BASE_ADDR_GPIO(port) + 0x14))

#define PORT_PCR(port,pin)                       (*(vol_u32_t *)(BASE_ADDR_PORT(port) + 0x04*(pin)))
#define PORT_PCR_MUX(x)                          (((x) << PORT_PCR_MUX_SHIFT) & PORT_PCR_MUX_MASK)
#define PORT_ISFR(port)                          (*(vol_u32_t *)(BASE_ADDR_PORT(port) + 0xA0))
#define PORT_PCR_IRQC_MASK                       (0xF0000U)
#define PORT_PCR_IRQC_SHIFT                      (16U)
#define PORT_PCR_IRQC(x)                         (((uint32_t)(((uint32_t)(x)) << PORT_PCR_IRQC_SHIFT)) & PORT_PCR_IRQC_MASK)
#define PORT_ISFR_ISF_MASK                       (0xFFFFFFFFU)
#define PORT_ISFR_ISF_SHIFT                      (0U)
#define PORT_ISFR_ISF(x)                         (((uint32_t)(((uint32_t)(x)) << PORT_ISFR_ISF_SHIFT)) & PORT_ISFR_ISF_MASK)

/**
 * @brief  Define the PIN number and interrupt number
 * @note   PIN number and interrupt number are different
 *         PIN number: 0-31
 *         Interrupt number: 0-127
*/

/*PIN UART0*/
#define RX_PIN                                   (1u)
#define TX_PIN                                   (2u)

/*PIN LED and SW*/
#define GREEN_LED_PIN                            (5u)
#define RED_LED_PIN                              (29u)
#define SW1_PIN                                  (3u)
#define SW2_PIN                                  (12u)

/* Interrupt number */
#define ID_INT_SW1                               (31u)
#define ID_INT_PIT                               (22u)
#define ID_INT_UART0                             (12u)



/****************************************************************************************
 *                               Function Prototypes                                    *
 * **************************************************************************************/

/**
 * @brief   Initialize LED.
 * @details Initialize RED LED and GREEN LED.
 * @param   None
 * @return  None
*/
void init_led();

/**
 * @brief   LED on.
 * @details Turn on LED.
 * @param   u8_t port: port of LED
 *          u8_t pin: pin of LED
 * @return  None
*/
void led_on(u8_t port, u8_t pin);


/**
 * @brief   LED off.
 * @details Turn off LED.
 * @param   u8_t port: port of LED
 *          u8_t pin: pin of LED
 * @return  None
*/
void led_off(u8_t port, u8_t pin);


/**
 * @brief   Toggle LED.
 * @details Toggle LED.
 * @param   u8_t port: port of LED
 *          u8_t pin: pin of LED
 * @return  None
*/
void toggle_led(u8_t port, u8_t pin);


/**
 * @brief   Config clock.
 * @details Config clock 48MHz.
 * @param   None
 * @return  None
*/
void clock_config();


/**
 * @brief   Initialize UART0.
 * @details Initialize UART0 
 * @param   u32_t uart0clk: clock source
 *          u32_t baud_rate: baud rate
 * @return  None
*/
void uart0_config(u32_t uart0clk, u32_t baud_rate);


/**
 * @brief   usart_send_byte.
 * @details send byte to UART0
 * @param   u8_t data_input: data to send
 * @return  None
*/
void usart_send_byte(u8_t data_input);


/**
 * @brief   usart_send_rx.
 * @details send string buffer via UART0
 * @param   None
 * @return  None
*/
void usart_send_rx(void);


/**
 * @brief   usart_receive_byte.
 * @details receive byte from UART0
 * @param   None
 * @return  u8_t: data received
*/
char usart_receive_byte();



/**
 * @brief   usart_send_string.
 * @details send string via UART0
 * @param   unsigned char *str: string to send
 * @return  None
*/
void usart_send_string(unsigned char *str);


/**
 * @brief   usart_receive_string.
 * @details receive string from UART0
 * @param   None
 * @return  None
*/
void usart_receive_string(void);


/**
 * @brief   Sw1_IRQHandler.
 * @details Sw1_IRQHandler change speed of fan by press button SW2(MCU)=(SW3 on board) 
 * @param   None
 * @return  None
*/
void Sw1_IRQHandler();


/**
 * @brief   UART0_IRQHandler.
 * @details UART0_IRQHandler receive data from UART0 and process data
 * @param   None
 * @return  None
*/
void UART0_IRQHandler();


#endif /* _KL46Z_H_ */