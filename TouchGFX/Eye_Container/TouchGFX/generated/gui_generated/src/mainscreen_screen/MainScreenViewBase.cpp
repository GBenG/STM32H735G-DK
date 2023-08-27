/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/mainscreen_screen/MainScreenViewBase.hpp>
#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>
#include <touchgfx/Color.hpp>

MainScreenViewBase::MainScreenViewBase() :
    flexButtonCallback(this, &MainScreenViewBase::flexButtonCallbackHandler)
{
    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);
    
    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    ScreenButton.setDelay(1);
    ScreenButton.setInterval(1);
    ScreenButton.setBoxWithBorderPosition(0, 0, 480, 272);
    ScreenButton.setBorderSize(0);
    ScreenButton.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 0, 0), touchgfx::Color::getColorFromRGB(0, 0, 0), touchgfx::Color::getColorFromRGB(0, 0, 0), touchgfx::Color::getColorFromRGB(0, 0, 0));
    ScreenButton.setAction(flexButtonCallback);
    ScreenButton.setPosition(0, 0, 480, 272);
    add(ScreenButton);

    Eye_L.setPosition(52, 30, 141, 139);
    Eye_L.setVisible(false);
    circle_BL.setPosition(0, 59, 80, 80);
    circle_BL.setCenter(40, 40);
    circle_BL.setRadius(40);
    circle_BL.setLineWidth(0);
    circle_BL.setArc(180, 270);
    circle_BLPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    circle_BL.setPainter(circle_BLPainter);
    Eye_L.add(circle_BL);

    circle_TL.setPosition(0, 0, 80, 80);
    circle_TL.setCenter(40, 40);
    circle_TL.setRadius(40);
    circle_TL.setLineWidth(0);
    circle_TL.setArc(270, 360);
    circle_TLPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    circle_TL.setPainter(circle_TLPainter);
    Eye_L.add(circle_TL);

    circle_BR.setPosition(61, 59, 80, 80);
    circle_BR.setCenter(40, 40);
    circle_BR.setRadius(40);
    circle_BR.setLineWidth(0);
    circle_BR.setArc(90, 180);
    circle_BRPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    circle_BR.setPainter(circle_BRPainter);
    Eye_L.add(circle_BR);

    circle_TR.setPosition(61, 0, 80, 80);
    circle_TR.setCenter(40, 40);
    circle_TR.setRadius(40);
    circle_TR.setLineWidth(0);
    circle_TR.setArc(0, 90);
    circle_TRPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    circle_TR.setPainter(circle_TRPainter);
    Eye_L.add(circle_TR);

    box_mid.setPosition(0, 38, 141, 62);
    box_mid.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Eye_L.add(box_mid);

    box_top.setPosition(40, 0, 62, 40);
    box_top.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Eye_L.add(box_top);

    box_bot.setPosition(39, 99, 62, 40);
    box_bot.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Eye_L.add(box_bot);

    add(Eye_L);

    Eye_R.setPosition(287, 30, 141, 139);
    circle_BL_1.setPosition(0, 59, 80, 80);
    circle_BL_1.setCenter(40, 40);
    circle_BL_1.setRadius(40);
    circle_BL_1.setLineWidth(0);
    circle_BL_1.setArc(180, 270);
    circle_BL_1Painter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    circle_BL_1.setPainter(circle_BL_1Painter);
    Eye_R.add(circle_BL_1);

    circle_TL_1.setPosition(0, 0, 80, 80);
    circle_TL_1.setCenter(40, 40);
    circle_TL_1.setRadius(40);
    circle_TL_1.setLineWidth(0);
    circle_TL_1.setArc(270, 360);
    circle_TL_1Painter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    circle_TL_1.setPainter(circle_TL_1Painter);
    Eye_R.add(circle_TL_1);

    circle_BR_1.setPosition(61, 59, 80, 80);
    circle_BR_1.setCenter(40, 40);
    circle_BR_1.setRadius(40);
    circle_BR_1.setLineWidth(0);
    circle_BR_1.setArc(90, 180);
    circle_BR_1Painter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    circle_BR_1.setPainter(circle_BR_1Painter);
    Eye_R.add(circle_BR_1);

    circle_TR_1.setPosition(61, 0, 80, 80);
    circle_TR_1.setCenter(40, 40);
    circle_TR_1.setRadius(40);
    circle_TR_1.setLineWidth(0);
    circle_TR_1.setArc(0, 90);
    circle_TR_1Painter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    circle_TR_1.setPainter(circle_TR_1Painter);
    Eye_R.add(circle_TR_1);

    box_mid_1.setPosition(0, 38, 141, 62);
    box_mid_1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Eye_R.add(box_mid_1);

    box_top_1.setPosition(40, 0, 62, 40);
    box_top_1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Eye_R.add(box_top_1);

    box_bot_1.setPosition(39, 99, 62, 40);
    box_bot_1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Eye_R.add(box_bot_1);

    add(Eye_R);
}

MainScreenViewBase::~MainScreenViewBase()
{
    touchgfx::CanvasWidgetRenderer::resetBuffer();
}

void MainScreenViewBase::setupScreen()
{

}

void MainScreenViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &ScreenButton)
    {
        //ScreenButtonClicked
        //When ScreenButton clicked call virtual function
        //Call ScreenButtonClicked
        ScreenButtonClicked();
    }
}

void MainScreenViewBase::handleTickEvent()
{
    //ScreenTick
    //When every N tick call virtual function
    //Call ScreenTick
    ScreenTick();
}
