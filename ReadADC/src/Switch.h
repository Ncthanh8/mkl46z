#ifndef __SWITCH_H__
#define __SWITCH_H__

#include "Gpio.h"

#define SW1_PIN     (3)  // PORT C
#define SW2_PIN     (12) // PORT C

#define SW1_PORT    (PORTC)
#define SW2_PORT    (PORTC)

#define SW1_GPIO    (GPIOC)
#define SW2_GPIO    (GPIOC)

#define SW1_MASK    (1 << SW1_PIN)
#define SW2_MASK    (1 << SW2_PIN)

/*Turn on/off SW*/
#define SW1_ON()    (SW1_GPIO->PCOR = SW1_MASK)
#define SW1_OFF()   (SW1_GPIO->PSOR = SW1_MASK)

#define SW2_ON()    (SW2_GPIO->PCOR = SW2_MASK)
#define SW2_OFF()   (SW2_GPIO->PSOR = SW2_MASK)

#define SW1_PRESSED()   ((SW1_GPIO->PDIR & SW1_MASK) == 0) // 0 - pressed, 1 - not pressed
#define SW2_PRESSED()   ((SW2_GPIO->PDIR & SW2_MASK) == 0)

#define SW1_PRESSED_INTERRUPT()       (SW1_PORT->ISFR & SW1_MASK) 
#define SW2_PRESSED_INTERRUPT()       (SW2_PORT->ISFR & SW2_MASK) 

#define CLEAR_SW1_INTERRUPT_FLAG()    (SW1_PORT->PCR[SW1_PIN] |= PORT_ISFR_MASK)
#define CLEAR_SW2_INTERRUPT_FLAG()    (SW2_PORT->PCR[SW2_PIN] |= PORT_ISFR_MASK)

#define STATE_SW_IRQ(PORT_SW,SW)      ((PORT_SW->ISFR & (1 << SW)))
#define CLEAR_SW_IRQ(PORT_SW,SW)      ((PORT_SW->PCR[SW] |= 0x1000000U))

/*SysTick*/



/*Function*/

void Switch_Init(void);
void SW1_Init(void);
void SW2_Init(void);

#endif // __SWITCH_H__
