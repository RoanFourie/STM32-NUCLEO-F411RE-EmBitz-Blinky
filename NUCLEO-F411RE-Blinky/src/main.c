/*
**
**                           Main.c
**
**
**********************************************************************/
/*
   AUTHOR:          Roan Fourie
   DATE CREATED:    2017-Week-38
   DATE CHANGED:    2017-Week-38

**********************************************************************/
#include "stm32f4xx_conf.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "fm_stm32f4_led.h"
#include "fm_stm32f4_delay.h"

static void button_setup(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;

	// Clock Enable
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

    // Config as digital output
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

int main(void)
{
    // initialize the system frequency
    SystemInit();
    // Delay initialize
    delay_init();
    // all LED initialize
    FM_Led_Init();
    // Initialize the button
    button_setup();

  while(1)
  {
      if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13))
      {
        FM_Led_Off(LED_1);
      } else {
        FM_Led_Toggle(LED_1);
      }
        // Delay for half second
       delay_ms(500);
  }
}
