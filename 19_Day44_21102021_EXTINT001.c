/*
===============================================================================
 Name        : 19_Day44_21102021_EXTINT001.c

 Description : Program demonstrate External interrupt


 TESTCASE0   : Interrupt configured for LEVEL_SENSITIVE and HIGH_LEVEL
 TESTCASE1   : Interrupt configured for LEVEL_SENSITIVE and LOW_LEVEL
 TESTCASE2   : Interrupt configured for EDGE_SENSITIVE and RISING_EDGE
 TESTCASE3   : Interrupt configured for EDGE_SENSITIVE and FALLING_EDGE

 
 Layered Architecture used for this project
 ************************************
 Application layer-19_Day44_21102021_EXTINT001.c
 ************************************
 Board layer - led.c/.h, configboard.h
 ************************************
 Low level drivers or chip level - pinmux.c/.h,extint.c/.h, gpio.c/.h
 ************************************
 Hardware
 ************************************

===============================================================================
*/

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
/* Private includes ----------------------------------------------------------*/
#include "pinmux.h"
#include "led.h"
#include "extint.h"
/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private user code ---------------------------------------------------------*/

/**
  * @brief  External Interrupt (EINT0) service routine
  * @retval none
  */
void EINT0_IRQHandler(void)
{
	/* For re enabling for next interrupt or clearing the current interrupt */
	vExtIntSel(EINT0,EXTINTENABLE);

	/* When interrupt occurs the leds will be ON */
	vLedOn(LED_0);
	vLedOn(LED_1);
	vLedOn(LED_2);

}
/**
  * @brief  Initialize all the hardware connected
  * @retval none
  */
void vAppHardwareInit(void)
{
	vPinmuxInitialize();
	vLedInitialize();
	vExtIntInitialize(EINT0);
}

/**
  * @brief  Crude Delay
  * @retval none
  */
void vAppDelay(uint32_t count)
{
	int i,j;
	for(i=0;i<count;i++)
		for(j=0;j<0xA00;j++);
}

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* MCU Configuration--------------------------------------------------------*/

  /* Initialize all configured peripherals */
   vAppHardwareInit();

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)  // for(;;)
  {
		vLedOff(LED_0);
		vLedOff(LED_1);
		vLedOff(LED_2);
  }
  /* End of Application entry point */
}




