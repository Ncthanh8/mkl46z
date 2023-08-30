#ifndef __LED_H__
#define __LED_H__

#include "MKL46Z4.h"

#define RED_LED_PIN     (29) // PORT E
#define GREEN_LED_PIN   (5)  // PORT D

#define RED_LED_PORT    (PORTE)
#define GREEN_LED_PORT  (PORTD)

#define RED_LED_GPIO    (GPIOE)
#define GREEN_LED_GPIO  (GPIOD)

#define RED_LED_MASK    (1 << RED_LED_PIN)
#define GREEN_LED_MASK  (1 << GREEN_LED_PIN)

/*Turn on/off LED*/
#define RED_LED_ON()    (RED_LED_GPIO->PCOR = RED_LED_MASK)
#define RED_LED_OFF()   (RED_LED_GPIO->PSOR = RED_LED_MASK)

#define GREEN_LED_ON()  (GREEN_LED_GPIO->PCOR = GREEN_LED_MASK)
#define GREEN_LED_OFF() (GREEN_LED_GPIO->PSOR = GREEN_LED_MASK)

/*Toggle LED*/
#define LED_TOGGLE(PORT_LED,PIN_LED)   ((PORT_LED-> PTOR |= (1 << PIN_LED)))
#define LED_TOGGLE_RED()               (RED_LED_GPIO->PTOR =| RED_LED_MASK)
#define LED_TOGGLE_GREEN()             (GREEN_LED_GPIO->PTOR =| GREEN_LED_MASK)

/*Function*/
void LED_Init(void);
void RED_LED_Init(void);
void GREEN_LED_Init(void);

#endif // __LED_H__
