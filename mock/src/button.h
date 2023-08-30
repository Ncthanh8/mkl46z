#include "KL46z.h"

#ifndef BUTTON_H_
#define BUTTON_H_

/*******************************************************************************
 *                               Definitions                                   *
 ******************************************************************************/
#define SW            12

/*******************************************************************************
 *                                Prototypes                                   * 
 ******************************************************************************/

/**
 * @brief Initialize the button
 * @details Initialize the button by setting the corresponding pin as input and enabling the interrupt
*/
void init_button(void);

#endif /* BUTTON_H_ */