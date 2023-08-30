#include "adc.h"
#include "MKL46Z4.h"

/* Function to initialize ADC */
void ADC_Light_Sensor_Init(void){
    SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK; /* enable clock for PORTE */ 
    PORTE->PCR[22] |= PORT_PCR_MUX(0); /* enable analog input for PTE22 */
    ADC0->SC2 &= ~ADC_SC2_ADTRG_MASK; /* software trigger */
    ADC0->CFG1 |= ADC_CFG1_MODE(3) | ADC_CFG1_ADICLK(0) | ADC_CFG1_ADIV(2) | ADC_CFG1_ADLSMP_MASK; /* set 16 bit mode, bus clock, divide by 4, long sample time */
}

/* function to read ADC value from chanel */
uint32_t ADC_GetValue(void){
    ADC0->SC1[0] = ADC_SC1_ADCH(22); /* start conversion on channel 22 */
    while(!(ADC0->SC1[0] & ADC_SC1_COCO_MASK)); /* wait for conversion to complete */
    return ADC0->R[0]; /* return ADC value */
}
