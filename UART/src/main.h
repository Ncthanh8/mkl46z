#ifndef _MAIN_H_
#define _MAIN_H_

#include "gpio.h"
#include "uart.h"
#include <string.h>

/*******************************************************************************
 *                          Function Declaration                               *
 *******************************************************************************/

/**
 * @brief      Delay function
 * @details   This function is used to delay the program execution
 * @param[in]     nCount: specifies the delay time length
 * @param[in,out] None
 * @return        None
 */

void Delay(uint32_t nCount);


#endif // _MAIN_H_
