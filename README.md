Date: 2017-Week-38  
Status: Working.  

# Blink the LED when User Button is pressed on the STM32 NUCLEO-F411RE board (STM32F411RET6)  

## Introduction:  
Getting started with the STM32 NUCLEO-F411RE board using the free [EmBitz IDE](https://www.embitz.org/) on Windows.
To blink the LED when the User Button is pressed.
Based on [this article](./User Manuals/isildak_en.pdf) and used [this article](http://www.firmcodes.com/stm32f407-discovery-gpio-tu) to get it working.
Flashed firmware hex file using [ST-Link Utility](http://www.st.com/en/development-tools/stsw-link004.html).

##I did the following to get the clock working correctly:  
system_stm32f4xx.c - System Clock Configuration file.  
We are using the internal oscillator (HSI) which is 16Mhz  
We are using PLLCLK Mux  

###Setup In stm32f4xx.h:  
1. Uncomment the line: #define USE_STDPERIPH_DRIVER  
2. set this: #define HSE_VALUE    ((uint32_t)16000000)  
3. set this: #define HSI_VALUE    ((uint32_t)16000000)  

###Setup In system_stm32f4xx.c:  
1. #define PLL_M      16  
2. #define PLL_N      336  
3. #define PLL_P      4  
4. #define PLL_Q      7  
5. uint32_t SystemCoreClock = 84000000;  

###Setup In fm_stm32F4_delay.c:  
1. fac_us=SystemCoreClock/16000000;

---

##Cannot connect to device: "old st-link firmware/st-link already used"
First time I thought that the problem was caused by a brief short-circuit caused by hot-plugging the SIM. This was not the cause. After some research, I found out that I was setting PA14 as output and high, and SWDIO is connected to this pin. This is why there were those problems, and why ["Connect under reset"](https://github.com/adam-dej/adam-dej.github.io/blob/master/_drafts/2014-08-05-stm32-quick-fix.md) worked, and why the problem went away after erasing the flash.  

---

## Useful Links:  
https://os.mbed.com/platforms/ST-Nucleo-F411RE/
    [STM32F411RE microcontroller](http://www.st.com/web/catalog/mmc/FM141/SC1169/SS1577/LN1877/PF260049?s_searchtype=partnumber)  
    [Nucleo board](http://www.st.com/content/st_com/en/products/evaluation-tools/product-evaluation-tools/mcu-eval-tools/stm32-mcu-eval-tools/stm32-mcu-nucleo/nucleo-f411re.html)  
    [SDK changes log](https://os.mbed.com/teams/ST/wiki/SDK-changes-log)  
    [Limitations](https://os.mbed.com/teams/ST/wiki/Use-of-D0D1-Arduino-pins)  
    [Good Info on board](https://jpralves.net/post/2015/08/25/nucleo-f411re.html#.WcVwLLIjFQI)  
    [Nucleo boards Information](http://www.emcu.it/NUCLEOevaBoards/NUCLEOevaBoards.html) *Good  
    [Automatic Sliding Gate Example](http://www.emcu.it/NUCLEOevaBoards/Nucleo-L152RE-AutomaticSlidingGate/AutomSlidGate.html)  
    [Main site for cool links and info](http://www.emcu.it/index.html)  
    [ST Youtube channel](https://www.youtube.com/channel/UCjnmZw3h4XnpK3e5D2jvIGA)  
    [STM32F4-Library explanation and usage](http://www.emcu.it/STM32F4xx/STM32F4-Library/STM32F4-Library.html)  
    [Clock setup](https://stm32f4-discovery.net/2015/01/properly-set-clock-speed-stm32f4xx-devices/)  

