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

//��ȡʣ��ʱ��
int WheelClock::getLastSecond(void) const
{
	return _allSecond - _second;
}

//��ȡ��ǰʱ��
int WheelClock::getSecond(void) const
{
	return _second;
}

//��ȡ��ʱ��
int WheelClock::getAllSecond(void) const
{
	return _allSecond;
}

//���õ�ǰʱ��
void WheelClock::setSecond(int second)
{
	if(_second != second)
	{
		_second = second;
		changeClock();
	}
}

//������ʱ��
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