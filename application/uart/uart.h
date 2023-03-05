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


//API
void UART_Init( UART_HandleTypeDef *_huart );
void UART_Periodic( void );
void UART_RxHandler( void );

#endif /* UART_UART_H_ */
