#ifndef __GPIO_H__
#define __GPIO_H__

#include <stdint.h>

/*
 * Peripheral register access macro 
 */

/* Permission types for peripheral registers */
#ifdef __cplusplus
    #define __R   volatile       /*Read only*/
#else
    #define __R   volatile const /*Read only*/  
#endif
#define __W   volatile           /*Write only*/
#define __RW  volatile           /*Read write*/
/* Structure member permissions */ 
#define __RM        volatile const     /*Read only memory*/
#define __WM        volatile           /*Write only memory*/
#define __RWM       volatile           /*Read write memory*/


/* GPIO - General-Purpose Input/OuT Type Register */
/** GPIO - Register Layout Typedef */
typedef struct
{ 
    __RW uint32_t PDOR; /* Port Data OuTypeut Register */
    __W  uint32_t PSOR; /* Port Set OuTypeut Register */
    __W  uint32_t PCOR; /* Port Clear OuTypeut Register */
    __W  uint32_t PTOR; /* Port Toggle OuTypeut Register */
    __R  uint32_t PDIR; /* Port Data Input Register */
    __RW uint32_t PDDR; /* Port Data Direction Register */

} GPIO_Tp;

/* GPIO - Peripheral instance base addresses */
/** Peripheral GPIOA base address */
#define GPIOA_BASE_ADDRESS          0x400FF000u
#define GPIOA                       ((GPIO_Tp *)GPIOA_BASE_ADDRESS)
/** Peripheral GPIOB base address */
#define GPIOB_BASE_ADDRESS          0x400FF040u
#define GPIOB                       ((GPIO_Tp *)GPIOB_BASE_ADDRESS)
/** Peripheral GPIOC base address */
#define GPIOC_BASE_ADDRESS          0x400FF080u
#define GPIOC                       ((GPIO_Tp *)GPIOC_BASE_ADDRESS)
/** Peripheral GPIOD base address */
#define GPIOD_BASE_ADDRESS          0x400FF0C0u
#define GPIOD                       ((GPIO_Tp *)GPIOD_BASE_ADDRESS)
/** Peripheral GPIOE base address */
#define GPIOE_BASE_ADDRESS          0x400FF100u
#define GPIOE                       ((GPIO_Tp *)GPIOE_BASE_ADDRESS)

/*GPIO Register Masks*/
/** GPIOx_PDDR - Port Data Direction Register */
#define GPIO_PDDR_MASK          0xFFFFFFFFu
#define GPIO_PDDR_SHIFT         0u
#define GPIO_PDDR(x)            (((uint32_t)(((uint32_t)(x))<<GPIO_PDDR_SHIFT))&GPIO_PDDR_MASK)

/** GPIOx_PDOR - Port Data OuTypeut Register */
#define GPIO_PDOR_MASK          0xFFFFFFFFu
#define GPIO_PDOR_SHIFT         0u
#define GPIO_PDOR(x)            (((uint32_t)(((uint32_t)(x))<<GPIO_PDOR_SHIFT))&GPIO_PDOR_MASK)

/** GPIOx_PSOR - Port Set OuTypeut Register */
#define GPIO_PSOR_MASK          0xFFFFFFFFu
#define GPIO_PSOR_SHIFT         0u
#define GPIO_PSOR(x)            (((uint32_t)(((uint32_t)(x))<<GPIO_PSOR_SHIFT))&GPIO_PSOR_MASK)

/** GPIOx_PCOR - Port Clear OuTypeut Register */
#define GPIO_PCOR_MASK          0xFFFFFFFFu
#define GPIO_PCOR_SHIFT         0u
#define GPIO_PCOR(x)            (((uint32_t)(((uint32_t)(x))<<GPIO_PCOR_SHIFT))&GPIO_PCOR_MASK)

/** GPIOx_PTOR - Port Toggle OuTypeut Register */
#define GPIO_PTOR_MASK          0xFFFFFFFFu
#define GPIO_PTOR_SHIFT         0u
#define GPIO_PTOR(x)            (((uint32_t)(((uint32_t)(x))<<GPIO_PTOR_SHIFT))&GPIO_PTOR_MASK)

/** GPIOx_PDIR - Port Data Input Register */
#define GPIO_PDIR_MASK          0xFFFFFFFFu
#define GPIO_PDIR_SHIFT         0u
#define GPIO_PDIR(x)            (((uint32_t)(((uint32_t)(x))<<GPIO_PDIR_SHIFT))&GPIO_PDIR_MASK)

/* PORT - Port Control and Interrupts */
/** PORT - Register Layout Typedef */
typedef struct
{ 
    __RW uint32_t PCR[32]; /* Pin Control Register n */
    __WM uint32_t GPCLR;   /* Global Pin Control Low Register */
    __WM uint32_t GPCHR;   /* Global Pin Control High Register */
    __RW uint32_t ISFR;    /* Interrupt Status Flag Register */

} PORT_Tp;

/* PORT - Peripheral instance base addresses */
/** Peripheral PORTA base address */
#define PORTA_BASE_ADDRESS          0x40049000u
#define PORTA                       ((PORT_Tp *)PORTA_BASE_ADDRESS)
/** Peripheral PORTB base address */
#define PORTB_BASE_ADDRESS          0x4004A000u
#define PORTB                       ((PORT_Tp *)PORTB_BASE_ADDRESS)
/** Peripheral PORTC base address */
#define PORTC_BASE_ADDRESS          0x4004B000u
#define PORTC                       ((PORT_Tp *)PORTC_BASE_ADDRESS)
/** Peripheral PORTD base address */
#define PORTD_BASE_ADDRESS          0x4004C000u
#define PORTD                       ((PORT_Tp *)PORTD_BASE_ADDRESS)
/** Peripheral PORTE base address */
#define PORTE_BASE_ADDRESS          0x4004D000u
#define PORTE                       ((PORT_Tp *)PORTE_BASE_ADDRESS)

/* PORT Register Masks */
/** PORT - Pin Control Register Masks */
#define PORT_PCR_PS_MASK                         (0x1U)
#define PORT_PCR_PS_SHIFT                        (0U)
#define PORT_PCR_PS(x)                           (((uint32_t)(((uint32_t)(x)) << PORT_PCR_PS_SHIFT)) & PORT_PCR_PS_MASK)
#define PORT_PCR_PE_MASK                         (0x2U)
#define PORT_PCR_PE_SHIFT                        (1U)
#define PORT_PCR_PE(x)                           (((uint32_t)(((uint32_t)(x)) << PORT_PCR_PE_SHIFT)) & PORT_PCR_PE_MASK)
#define PORT_PCR_SRE_MASK                        (0x4U)
#define PORT_PCR_SRE_SHIFT                       (2U)
#define PORT_PCR_SRE(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_PCR_SRE_SHIFT)) & PORT_PCR_SRE_MASK)
#define PORT_PCR_PFE_MASK                        (0x10U)
#define PORT_PCR_PFE_SHIFT                       (4U)
#define PORT_PCR_PFE(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_PCR_PFE_SHIFT)) & PORT_PCR_PFE_MASK)
#define PORT_PCR_DSE_MASK                        (0x40U)
#define PORT_PCR_DSE_SHIFT                       (6U)
#define PORT_PCR_DSE(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_PCR_DSE_SHIFT)) & PORT_PCR_DSE_MASK)
#define PORT_PCR_MUX_MASK                        (0x700U)
#define PORT_PCR_MUX_SHIFT                       (8U)
#define PORT_PCR_MUX(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_PCR_MUX_SHIFT)) & PORT_PCR_MUX_MASK)
#define PORT_PCR_IRQC_MASK                       (0xF0000U)
#define PORT_PCR_IRQC_SHIFT                      (16U)
#define PORT_PCR_IRQC(x)                         (((uint32_t)(((uint32_t)(x)) << PORT_PCR_IRQC_SHIFT)) & PORT_PCR_IRQC_MASK)
#define PORT_PCR_ISF_MASK                        (0x1000000U)
#define PORT_PCR_ISF_SHIFT                       (24U)
#define PORT_PCR_ISF(x)                          (((uint32_t)(((uint32_t)(x)) << PORT_PCR_ISF_SHIFT)) & PORT_PCR_ISF_MASK)


/** PORTx_ISFR - Interrupt Status Flag Register */
#define PORT_ISFR_MASK          0xFFFFFFFFu
#define PORT_ISFR_SHIFT         0u
#define PORT_ISFR(x)            (((uint32_t)(((uint32_t)(x))<<PORT_ISFR_SHIFT))&PORT_ISFR_MASK)

/* SIM - System Integration Module */
/** SIM - Register Layout Typedef */
typedef struct 
{
    __W uint32_t SCGC5;     /** System Clock Gating Control Register 5, offset: 0x1038 */
} SIM_Tp;

/* SIM - Peripheral instance base addresses */
/** Peripheral SIM base address */
#define SIM_BASE                 0x40047000u
#define SIM                      ((SIM_Tp *)SIM_BASE)

/* SIM Register Masks */
/**SCGC5 - System Clock Gating Control Register 5 */
#define SIM_SCGC5_PORTA_MASK                     (0x200U)
#define SIM_SCGC5_PORTA_SHIFT                    (9U)
#define SIM_SCGC5_PORTA(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTA_SHIFT)) & SIM_SCGC5_PORTA_MASK)
#define SIM_SCGC5_PORTB_MASK                     (0x400U)
#define SIM_SCGC5_PORTB_SHIFT                    (10U)
#define SIM_SCGC5_PORTB(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTB_SHIFT)) & SIM_SCGC5_PORTB_MASK)
#define SIM_SCGC5_PORTC_MASK                     (0x800U)
#define SIM_SCGC5_PORTC_SHIFT                    (11U)
#define SIM_SCGC5_PORTC(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTC_SHIFT)) & SIM_SCGC5_PORTC_MASK)
#define SIM_SCGC5_PORTD_MASK                     (0x1000U)
#define SIM_SCGC5_PORTD_SHIFT                    (12U)
#define SIM_SCGC5_PORTD(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTD_SHIFT)) & SIM_SCGC5_PORTD_MASK)
#define SIM_SCGC5_PORTE_MASK                     (0x2000U)
#define SIM_SCGC5_PORTE_SHIFT                    (13U)
#define SIM_SCGC5_PORTE(x)                       (((uint32_t)(((uint32_t)(x)) << SIM_SCGC5_PORTE_SHIFT)) & SIM_SCGC5_PORTE_MASK)

#endif // __GPIO_H__

