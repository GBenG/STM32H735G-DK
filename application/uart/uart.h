/**
  **************************************************************************************************
  * @date       03.2023
  * @prefix     UART_
  * @author     GBenG
  * @brief      Custom UART functions and handlers
  **************************************************************************************************
**/
#ifndef UART_UART_H_
#define UART_UART_H_

//Includes
#include "stm32h7xx_hal.h"
#include "FreeRTOS.h"
#include "cmsis_os.h"
#include "queue.h"


//API
void UART_Init( UART_HandleTypeDef *_huart,
								osMessageQueueId_t *_queue,
								osSemaphoreId_t 	 *_semap );
void UART_Periodic( void );


#endif /* UART_UART_H_ */
