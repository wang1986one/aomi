#include "WheelGobalStableHeaders.h"
#include "WheelUIInterface.h"


using namespace Orz;




//void WheelUIInterface::addListener(WheelUIListener * listener)
//{
//	_listener = listener;
//}
//void WheelUIInterface::removeListener(WheelUIListener * listener)
//{
//	_listener = NULL;
//}
WheelUIInterface::WheelUIInterface(void):_listener(NULL)
{

}
WheelUIInterface::~WheelUIInterface(void)
{}


void WheelNullUI::setTheTime(int second){}
//
//void WheelNullUI::setSetupVisible(bool visible){}
//void WheelNullUI::setMenuDataVisible(bool visible){}
//void WheelNullUI::menuResult(bool result){}
//void WheelNullUI::writeMenuXY(int x, int y, unsigned long n){}
void WheelNullUI::setLogoShow(bool show){}
void WheelNullUI::setStartUIVisible(bool visible){}
void WheelNullUI::runWinner(void){}
void WheelNullUI::setEndUIVisible(bool visible){}

void WheelNullUI::update(TimeType interval){}
void WheelNullUI::addBottom(void){}