#include <gui/mainscreen_screen/MainScreenView.hpp>
#include <touchgfx/hal/OSWrappers.hpp>
#include <stdint.h>
#include <stdlib.h>


//local data
static 	uint16_t _x_vect = 3;
static	uint16_t _y_vect = 1;
static	uint16_t _x = 287;
static	uint16_t _y = 30;

//Display borders size
#define DISP_WIDTH 480
#define DISP_HIGHT 272


MainScreenView::MainScreenView()
{

}

void MainScreenView::setupScreen()
{
    MainScreenViewBase::setupScreen();
}

void MainScreenView::tearDownScreen()
{
    MainScreenViewBase::tearDownScreen();
}

void MainScreenView::ScreenButtonClicked(){
	//Generate new direction
	if( _y < DISP_HIGHT-Eye_R.getHeight() && _y > 0 ){
		_y_vect = rand() % 11;
	}
	if( _x < DISP_WIDTH-Eye_R.getWidth() && _x > 0 ){
		_x_vect = rand() % 11;
	}
}


void MainScreenView::ScreenTick(){
	//Calculate movement
	_x=_x+_x_vect;
	_y=_y+_y_vect;

	//Calculate edge bounce
	if( _y >= DISP_HIGHT-Eye_R.getHeight() || _y <= 0 ){
		_y_vect =- _y_vect;
	}
	if( _x >= DISP_WIDTH-Eye_R.getWidth() || _x <= 0 ){
		_x_vect =- _x_vect;
	}

	//Draw
	Eye_R.invalidate();
	Eye_R.setXY(_x, _y);
	Eye_R.invalidate();

	OSWrappers::taskDelay(10);
}
