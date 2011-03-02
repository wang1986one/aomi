#include "MyWheelControllerStableHeaders.h"
#include "WheelClock.h"
using namespace Orz;


WheelClock::WheelClock(void):_allSecond(30),_second(0) ,_callback(NULL),_pass(0.f)
{

}
void WheelClock::reset(void)
{
	_second = 0;
	changeClock();
}
WheelClock::~WheelClock(void)
{
}

//获取剩余时间
int WheelClock::getLastSecond(void) const
{
	return _allSecond - _second;
}

//获取当前时间
int WheelClock::getSecond(void) const
{
	return _second;
}

//获取总时间
int WheelClock::getAllSecond(void) const
{
	return _allSecond;
}

//设置当前时间
void WheelClock::setSecond(int second)
{
	if(_second != second)
	{
		_second = second;
		changeClock();
	}
}

//设置总时间
void WheelClock::setAllSecond(int allSecond)
{
	_allSecond = allSecond;
}




void WheelClock::setListener(WheelClockListener * listener)
{
	_callback = listener;
}


void WheelClock::update(TimeType interval)
{
	_pass += interval;
	if(_pass>=1.f)
	{
		_pass -= 1.f;
		int second = getSecond() +1;
		if(second <= _allSecond)
			setSecond(second);
	}
}
void WheelClock::changeClock(void)
{
	if(_callback)
		_callback->clockChanged(_allSecond- _second);
}