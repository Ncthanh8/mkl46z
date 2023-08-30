#include"KL46z.h"
#include"button.h"

/*******************************************************************************
 *                               Definitions                                 *
 ******************************************************************************/

typedef struct
{
    int start;
    int id;
    int length;
    int data;
    int stop;
}uart_frame_rx;

uart_frame_rx frame_rx;

u8_t str[25]; 

/*******************************************************************************
 *                               Variables                                     *
 ******************************************************************************/
int lvFan = 0;
int lenStr = 0;

u8_t cmd[]="0x02 0x83 0x03 0x00 0x00 0x00 0x03"; /* cmd default to response */
u8_t undefined[]="0x02 0x83 0x01 0xFF 0x03"; /* cmd undefined */
u8_t cmd2[]="0x02 0x83 0x01 0x01 0x03"; /* cmd error */

u8_t mode= '0'; /* mode default is 0 */


/*******************************************************************************
 *                               Functions                                  *
 ******************************************************************************/


/* Init LED */
void init_led()
{
    /*config LCK*/
    SIM_SCGC5 |= (1U << SIM_SCGC5_SHIFT(PORTD)) | (1U << SIM_SCGC5_SHIFT(PORTE));

    /*config mux GPIO*/
    PORT_PCR(PORTD, GREEN_LED_PIN) = ((PORT_PCR(PORTD, GREEN_LED_PIN)) & (~PORT_PCR_MUX_MASK)) | (1U << PORT_PCR_MUX_SHIFT);
    PORT_PCR(PORTE, RED_LED_PIN) = ((PORT_PCR(PORTE, RED_LED_PIN)) & (~PORT_PCR_MUX_MASK)) | (1U << PORT_PCR_MUX_SHIFT);

    /*config output*/
    GPIO_PDDR(PORTD) |= (1U << GREEN_LED_PIN);
    GPIO_PDDR(PORTE) |= (1U << RED_LED_PIN);

    /*turn off led*/
    led_off(PORTD, GREEN_LED_PIN);
    led_off(PORTE, RED_LED_PIN);
}


/* Turn on LED */
void led_on(u8_t port, u8_t pin)
{
    GPIO_PCOR(port) |= (1U << pin);
}


/* Turn off LED */
void led_off(u8_t port, u8_t pin)
{
    GPIO_PSOR(port) |= (1U << pin);
}

/* Toggle LED */
void toggle_led(u8_t port, u8_t pin)
{
    GPIO_PTOR(port) |= (1U << pin);
}


/* Config Clock */
void clock_config()
{
    /*config clock Rx Tx*/
    SIM_SCGC5 |= (1U << SIM_SCGC5_SHIFT(PORTA));
    /*setting low clock 32kHz and FLL 1464 for clock 48MHz*/
    MCG_C4 = (MCG_C4 & 0xE0u) | (1u << MCG_C4_DMX32_SHIFT) | (1u << MCG_C4_DRS_SHIFT);
    SystemCoreClockUpdate();
    /*enable clock*/
    SIM_SCGC4 |= (1u << SIM_SCGC4_UART0_SHIFT);
}


/* Config UART0 */
void uart0_config(u32_t uart0clk, u32_t baud_rate)
{
    u32_t calculated_baud = 0;
    u32_t baud_diff = 0;
    u32_t osr_val = 0;
    u32_t sbr_val = 0;
    u32_t temp = 0;
    u8_t i = 0;

    /*config mux GPIO*/

    PORT_PCR(PORTA,RX_PIN) = ((PORT_PCR(PORTA,RX_PIN)) & (~PORT_PCR_MUX_MASK)) | (2U << PORT_PCR_MUX_SHIFT);
    PORT_PCR(PORTA,TX_PIN) = ((PORT_PCR(PORTA,TX_PIN)) & (~PORT_PCR_MUX_MASK)) | (2U << PORT_PCR_MUX_SHIFT);

    /*setting NVIC*/
    NVIC_ICPR |= (1U << ID_INT_UART0); /*clear pending interrupt*/
    NVIC_IPR(3) |= (1U << NVIC_IPR_PRI_N0_SHIFT); /*set priority interrupt*/
    NVIC_ISER |= (1U << ID_INT_UART0); /*enable interrupt*/

    /*******************************************************************/

    /*Calculate the first baud rate using the lowest OSR value possible.*/
    i = 4;
    sbr_val = (u32_t)(uart0clk / (baud_rate * (i+1)));
    calculated_baud = (uart0clk / (sbr_val * (i+1)));

    if (calculated_baud > baud_rate)
        baud_diff = calculated_baud - baud_rate; 
    else
        baud_diff = baud_rate - calculated_baud;

    osr_val = i;

    /*Select the best OSR value*/
    for (i = 5; i <= 32; i++)
    {
        sbr_val = (u32_t)(uart0clk / (baud_rate * (i+1)));
        calculated_baud = (uart0clk / (sbr_val * (i+1)));

        if (calculated_baud > baud_rate)
            temp = calculated_baud - baud_rate;
        else
            temp = baud_rate - calculated_baud;

        if (temp <= baud_diff)
        {
            baud_diff = temp;
            osr_val = i;
        }
    }
    sbr_val = (u32_t)(uart0clk / (baud_rate * (osr_val+1)));

    if (baud_diff >= (baud_rate/100)*3)
    {
        while(1);
    }
    /*disable receive and transmit*/
    UART0_C2 &= (~0x0Cu);

    /*config source clock MCGFLLCLK*/
    SIM_SOPT2 = (SIM_SOPT2 & (~(3u << SIM_SOPT2_UART0SRC_SHIFT))) | (1u << SIM_SOPT2_UART0SRC_SHIFT) | (0u << SIM_SOPT2_PLLFLLSEL_SHIFT);

    /*config pin Tx Rx*/
    SIM_SOPT5 &= ~(1u << SIM_SOPT5_UART0RXSRC_SHIFT | 3u << SIM_SOPT5_UART0TXSRC_SHIFT);

    /*Setup OSR value */
    UART0_C4 = (UART0_C4 & ~(0x1Fu | 1 << UART0_C4_M10_SHIFT)) | (osr_val&0x1Fu);

    /* Save off the current value of the uartx_BDH except for the SBR field */
    UART0_BDH = (UART0_BDH & ~(0x1Fu)) | ((sbr_val & 0x1F00u)>>8);
    UART0_BDH &= ~(1u << UART0_BDH_SBNS_SHIFT);

    UART0_BDL = (u8_t)(sbr_val & 0xFFu);

    UART0_C1= 0x00u; 

    /*clear NF flag*/
    UART0_S1 |= (1<<2u);

    /* Enable receiver and transmitter and interrupt receive*/
    UART0_C2 = 0x0Cu | 1<<UART0_C2_RIE_SHIFT;
}


/* Send a byte via UART0 */
void usart_send_byte(u8_t data_input)
{
    while (!(UART0_S1 & (1 << UART0_S1_TDRE_SHIFT)));
    UART0_D = data_input;
}


/* Receive a byte via UART0 */
char usart_receive_byte()
{
    while (!(UART0_S1 & (1 << UART0_S1_RDRF_SHIFT)));
    return UART0_D;
}


/* Send a string via UART0 */
void usart_send_rx(void)
{
  int j;
  for(j=0;j<lenStr;j++)
  {
    usart_send_byte(str[j]);
  }
}


/* Send a string via UART0 */
void usart_send_string(unsigned char *str)
{
    while(*str)
    {
        usart_send_byte(*str);
        str++;
    }
}


/* Receive a string via UART0 */
void usart_receive_string( void)
{   
    uint8_t i = 0;
    u8_t str[15];
    do
    {
        str[i] = usart_receive_byte();
    }while(str[i++] != '*'); /* Receive data until '*' */
}


/******************************************************************************
 *                             Static Functions                               *
 ******************************************************************************/

/**
 * @brief   cv: convert string to int.
 * @details convert string to int
 * @param   char str_in[]: string to convert
 *          int st: start position
 *          int en: end position
*/
static int cv(char str_in[], int st,int en)
{
	int j,out;
	for(j=st;j<en;j++)
	{
		str_in[j-st] = str[j]; 
	}
    sscanf(str_in, "%x", &out);
    return out;
}

/**
 * @brief  set_frame_rx.
 * @details set value for frame_rx
 * @param   None
 * @return  None
*/

static void set_frame_rx(void)
{
    static char tempStr[3];
    frame_rx.start = cv(tempStr,0,4);
    frame_rx.id = cv(tempStr,5,9);
    frame_rx.length = cv(tempStr,10,14);
    frame_rx.data = cv(tempStr,15,19);
    frame_rx.stop = cv(tempStr,20,24);
    if(frame_rx.length == 0 && frame_rx.data == 3 && frame_rx.id == 3){
        frame_rx.stop = frame_rx.data;
    }
}

/**
 * @brief  process_frame_rx.
 * @details process cmd from frame_rx and send response
 * @param   None
 * @return  None
*/

static void process_frame_rx(void)
{
    /* Check start and stop bit */
    if(frame_rx.start == 2 && frame_rx.stop == 3 )
    {
        switch (frame_rx.id)
        {
        case 1: /* Select mode */
            if (frame_rx.length == 1){
                if(frame_rx.data == 0)
                {
                    mode = '0' ;
                    cmd[23] = mode;
                    usart_send_string("0x02 0x81 0x01 0x00 0x03"); /* suscess */
                }
                else if(frame_rx.data == 1)
                {
                    set_duty_cycle(0);
                    mode = '1' ;
                    cmd[23] = mode;
                    usart_send_string("0x02 0x81 0x01 0x00 0x03"); /* suscess */
                }
                else
                {
                    /* Response error mode */
                    usart_send_string("0x02 0x81 0x01 0x01 0x03"); /* mode value is invalid */
                }
            }
            else
            {
                /* Response error length */
                usart_send_string("0x02 0x81 0x01 0x02 0x03");  /* length is wrong */
            }
            break;
        
        /* set speed */
        case 2: 
            if(frame_rx.length == 1 && mode == '0')
            {
                if (frame_rx.data == 0) /* set mode = 0 */
                {
                    lvFan = 0;
                    set_duty_cycle(lvFan*30);
                    cmd[28] = '0';
                    usart_send_string("0x02 0x82 0x01 0x00 0x03"); /* suscess */
                }

                else if(frame_rx.data == 1) /* set mode = 1 */
                {
                    lvFan = 1;
                    set_duty_cycle(lvFan*30);
                    cmd[28] = '1';
                    usart_send_string("0x02 0x82 0x01 0x00 0x03"); /* suscess */
                }

                else if(frame_rx.data == 2) /* set mode = 2 */
                {
                    lvFan = 2;
                    set_duty_cycle(lvFan*30);
                    cmd[28] = '2';
                    usart_send_string("0x02 0x82 0x01 0x00 0x03"); /* suscess */
                }

                else if(frame_rx.data == 3) /* set mode = 3 */
                {
                    lvFan = 3;
                    set_duty_cycle(lvFan*30);
                    cmd[28] = '3';
                    usart_send_string("0x02 0x82 0x01 0x00 0x03"); /* suscess */
                }

                else 
                {
                    usart_send_string("0x02 0x82 0x01 0x01 0x03"); /* mode value is invalid */
                }
            }

            else 
            {
                usart_send_string("0x02 0x82 0x01 0x02 0x03"); /* length is wrong */
            }
            break;  

        case 3: /* reading status */
            if(frame_rx.length == 0 && frame_rx.data == 3)  
            {
                usart_send_string(cmd); /* suscess */
            }
            else if(frame_rx.length !=0)  
            {
                usart_send_string("0x02 0x83 0x01 0x01 0x03"); /* length is wrong */
            }
            else
            {
                usart_send_string(undefined); /* undefined */
            }
            break;
        }
    }
    else
    {
        usart_send_string(undefined); /* undefined */
    }
}

/******************************************************************************
 *                             Interrupt Handlers                             *
 ******************************************************************************/

/* SW1 interrupt handler */
void Sw1_IRQHandler()
{
    PORT_ISFR(PORTC) &= ~PORT_ISFR_ISF_MASK;
    PORT_ISFR(PORTC) |= PORT_ISFR_ISF(0);
    if(mode == '1') 
    {
        if(lvFan < 3 ){
            lvFan++;
        }
        else{
            lvFan = 0;
        }
        set_duty_cycle(lvFan*30);
        cmd[28] = lvFan + '0';   
    }
}


/* UART0 interrupt handler */
void UART0_IRQHandler()
{
    u8_t ch=0;
    ch = UART0_D;

    str[lenStr] = ch;
    lenStr++;
    
    if(ch == '*')
    {
        //usart_send_string();
        lenStr = 0;
        set_frame_rx();
        process_frame_rx();
        memset(str,0,sizeof(str));
    }
    //usart_send_byte(ch);
}

