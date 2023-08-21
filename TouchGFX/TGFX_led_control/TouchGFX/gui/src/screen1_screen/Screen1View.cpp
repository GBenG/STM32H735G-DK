#include <gui/screen1_screen/Screen1View.hpp>
#include "stm32h7xx_hal.h"

int guv = 50; //Gauge value - test

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}


//Toggle LED function
//PC2 RED LED
//PC3 GRN LED
void Screen1View::ToggleLED(){
	if( toggleButton.getState() == true ){
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_RESET);
	}else{
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_SET);
	}
}

void Screen1View::GuageUp(){
	if( guv<100 ){
		guv++;
		gauge_test.setValue(guv);
		Unicode::snprintf(GLabelBuffer, GLABEL_SIZE, "%u", guv);
		GLabel.invalidate();
	}
}

void Screen1View::GuageDown(){
	if( guv>0 ){
		guv--;
		gauge_test.setValue(guv);
		Unicode::snprintf(GLabelBuffer, GLABEL_SIZE, "%u", guv);
		GLabel.invalidate();
	}
}
