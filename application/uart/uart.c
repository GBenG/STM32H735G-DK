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
#include <string.h>
#include <stdlib.h>
#include "task.h"
#include <stdbool.h>


//Config
#define UART_BUFFER_SIZE (64)


//Struct proto
struct urt_dt{
	char 								buffer[UART_BUFFER_SIZE];
	uint16_t 						index;
	bool 								compleate;
};


//Local data
static struct{
	UART_HandleTypeDef *huart;
	osMessageQueueId_t *queue;
	osSemaphoreId_t 	 *semap;
	struct urt_dt				tx;						// Uart TX buffer
	struct urt_dt				rx;						// Uart RX buffer
}local = {
	.huart = NULL,
	.queue = NULL,
	.semap = NULL,
	.tx.buffer = {0},
	.tx.index = 0,
	.tx.compleate = false,
	.rx.buffer = {0},
	.rx.index = 0,
	.rx.compleate = false,
};





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
void UART_Init( UART_HandleTypeDef *_huart,
								osMessageQueueId_t *_queue,
								osSemaphoreId_t 	 *_semap ){
	local.huart = _huart;
	local.queue = _queue;
	local.semap = _semap;

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
	if( local.rx.compleate == true ){
		// Echo the received string back to the sender
		printf(">echo:\"%s\"\r\n",local.rx.buffer);

		// Get income string length
		uint32_t length = strlen(local.rx.buffer);
		printf(">length:\"%lu\"\r\n", length);

		// Put income string to heap
		uint32_t *income_data = malloc(sizeof(length+1));
		memcpy(income_data, local.rx.buffer, local.rx.index+1);

		// Put income string to queue
		osMessageQueuePut(local.queue, &income_data, 0, 0);

		uint32_t qsize = osMessageQueueGetCount(local.queue);
		uint32_t qspce = osMessageQueueGetSpace(local.queue);
		printf(">qsize:%lu|qspce:%lu\r\n", qsize, qspce);

		//--DBG--------------------------------------------------->
		for( uint8_t i = 0; i<local.rx.index; i++ ){
			printf(">[%u][0x%2.X]\r\n", i,local.rx.buffer[i]);
		}
		//--DBG--------------------------------------------------->

		// Reset the buffer index
		memset(local.rx.buffer, 0x00, UART_BUFFER_SIZE);
		local.rx.index = 0;
		local.rx.compleate = false;
		osSemaphoreRelease(local.semap);
	}
}


/**
  **************************************************************************************************
  * @brief      Receive hadler
  **************************************************************************************************
**/
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart == local.huart && local.rx.compleate == false)
	    {
	        if (local.rx.buffer[local.rx.index] == '\n')
	        {
	            // Null-terminate the string
	        		local.rx.buffer[local.rx.index] = '\0';
	        		local.rx.compleate = true;
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



