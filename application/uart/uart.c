/**
  **************************************************************************************************
  * @date       03.2023
  * @prefix     UART_
  * @author     GBenG
  * @brief      Custom UART functions and handlers
  **************************************************************************************************
**/
#include "uart.h"
#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"


//Local data
static struct{
	UART_HandleTypeDef *huart;
	TickType_t curr_time;		// System time
}local;


/**
  **************************************************************************************************
  * @brief      Printf support
  **************************************************************************************************
**/
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif
PUTCHAR_PROTOTYPE
{
  HAL_UART_Transmit(local.huart, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
  return ch;
}


/**
  **************************************************************************************************
  * @brief      Module periodic initialization function
  **************************************************************************************************
**/
void UART_Init( UART_HandleTypeDef *_huart ){
	local.huart = _huart;
}


/**
  **************************************************************************************************
  * @brief      Main module periodic function
  **************************************************************************************************
**/
void UART_Periodic( void )
{
	local.curr_time =  xTaskGetTickCount();			// Get the current system time in ticks
	local.curr_time *= portTICK_PERIOD_MS;;   	// Convert the tick count to milliseconds

  printf("@Willkommen@ :: %lu\r\n",local.curr_time);
}


/**
  **************************************************************************************************
  * @brief      Receive hadler
  **************************************************************************************************
**/
void UART_RxHandler( void ){

}




