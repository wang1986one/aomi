#include "WheelGobalStableHeaders.h"
#include "WheelUIInterface.h"


using namespace Orz;




WheelUIInterface::WheelUIInterface(void):_listener(NULL)
{

}
WheelUIInterface::~WheelUIInterface(void)
{}


void WheelNullUI::setTheTime(int second){}
void WheelNullUI::setLogoShow(bool show){}
void WheelNullUI::setStartUIVisible(bool visible){}
void WheelNullUI::runWinner(void){}
void WheelNullUI::setEndUIVisible(bool visible){}

void WheelNullUI::update(TimeType interval){}
void WheelNullUI::addBottom(void){}