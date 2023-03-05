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
#include <string.h>

//Config
#define UART_BUFFER_SIZE (64)


//Struct proto
struct urt_dt{
	char 								buffer[UART_BUFFER_SIZE];
	uint16_t 						index;
};


//Local data
static struct{
	UART_HandleTypeDef *huart;
	TickType_t 					curr_time;		// System time
	struct urt_dt				tx;						// Uart TX buffer
	struct urt_dt				rx;						// Uart RX buffer
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
	// Start the first receive
	HAL_UART_Receive_IT(local.huart, (uint8_t*) &local.rx.buffer[local.rx.index], 1);
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
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart == local.huart)
	    {
	        if (local.rx.buffer[local.rx.index] == '\n')
	        {
	            // Null-terminate the string
	        		local.rx.buffer[local.rx.index] = '\0';

	            // Echo the received string back to the sender
	            HAL_UART_Transmit(local.huart, (uint8_t*) local.rx.buffer, strlen(local.rx.buffer), HAL_MAX_DELAY);

	            // Reset the buffer index
	            local.rx.index = 0;
	        }
	        else
	        {
	            // Add the received character to the buffer
	        		local.rx.buffer[local.rx.index++] = (char) huart->Instance->RDR;

	            // Check for buffer overflow
	            if (local.rx.index >= UART_BUFFER_SIZE)
	            {
	                // Reset the buffer index
	            		local.rx.index = 0;
	            }
	        }

	        // Start a new receive
	        HAL_UART_Receive_IT(local.huart, (uint8_t*) &local.rx.buffer[local.rx.index], 1);
	    }
}



