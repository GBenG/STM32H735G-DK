#include <gui/mainscreen_screen/MainScreenView.hpp>
#include <stdint.h>
#include <stdlib.h>

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

}

void MainScreenView::ScreenTick(){
	static 	uint16_t _x_dest = 339;
	static	uint16_t _y_dest = 133;
			uint16_t _x = Eye_R.getX();
			uint16_t _y = Eye_R.getY();

	//X
	if( _x != _x_dest ){
		if( _x < _x_dest ){
			_x++;
		}else{
			_x--;
		}
	}else{
		_x_dest = rand() % 339;
	}
	//Y
	if( _y != _y_dest ){
		if( _y < _y_dest ){
			_y++;
		}else{
			_y--;
		}
	}else{
		_y_dest = rand() % 133;
	}

	Eye_R.invalidate();
	Eye_R.setXY(_x, _y);
	Eye_R.invalidate();
}
