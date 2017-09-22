// Adapted from the STM32F4-Discovery project

/***************************************************************
* File     : fm_stm32f4_led.h
* website  : www.firmcodes.com
* email_id : support@firmcodes.com
* IDE used : The files are Compiled in coocox ide and
			 tested on stm32f4 discovery board.
***************************************************************/

#ifndef __FM_STM32F4_LED_H
#define __FM_STM32F4_LED_H

/***************************************************************
// Header Files Includes
***************************************************************/
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"

/***************************************************************
* List of All LED
***************************************************************/
typedef enum
{
  LED_1 = 0,  // Green Led on STM32F4-Discovery
  LED_2 = 1, // Orange Led on STM32F4-Discovery
  LED_3 = 2,    // Red Led on STM32F4-Discovery
  LED_4 = 3    // Blue Led on STM32F4-Discovery
}LED_NAME;

#define  TOTAL_LED   4 // Anzahl von LED_NAME_t


/***************************************************************
* Status einer LED
***************************************************************/
typedef enum {
  LED_OFF = 0,  // LED AUS
  LED_ON        // LED EIN
}LED_STATUS;


/***************************************************************
* Strcture of  LED
***************************************************************/
typedef struct {
  LED_NAME LED_NAME;    // Name
  GPIO_TypeDef* LED_PORT; // Port
  const uint16_t LED_PIN; // Pin
  const uint32_t LED_CLK; // Clock
  LED_STATUS LED_INIT;  // status
}LED_struct;


/***************************************************************
* Gloable Function
***************************************************************/
void FM_Led_Init(void);
void FM_Led_Off(LED_NAME led_name);
void FM_Led_On(LED_NAME led_name);
void FM_Led_Toggle(LED_NAME led_name);


/***************************************************************/
#endif // __FM_STM32F4_LED_H
