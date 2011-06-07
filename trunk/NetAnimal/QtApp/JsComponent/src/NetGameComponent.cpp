#include "JsComponentStableHeaders.h"
#include "NetGameComponent.h"
#include "Js.h"
#include <WheelGobal/WheelEvents.h>
using namespace Orz;


	NetClock::NetClock(void):_allSecond(30),_second(0),_pass(0.f)
	{

	}
	void NetClock::reset(void)
	{
		_second = 0;
	}
	NetClock::~NetClock(void)
	{
	}

	//获取剩余时间
	int NetClock::getLastSecond(void) const
	{
		return _allSecond - _second;
	}

	//获取当前时间
	int NetClock::getSecond(void) const
	{
		return _second;
	}

	//获取总时间
	int NetClock::getAllSecond(void) const
	{
		return _allSecond;
	}


	void NetClock::setTime(int time)
	{
		setSecond(_allSecond - time);
	}
	//设置当前时间
	void NetClock::setSecond(int second)
	{
		if(_second != second)
		{
			_second = second;
		}
	}

	//设置总时间
	void NetClock::setAllSecond(int allSecond)
	{
		_allSecond = allSecond;
	}




	//void NetClock::setListener(NetClockListener * listener)
	//{
	//	_callback = listener;
	//}


	void NetClock::update(TimeType interval)
	{
	/*	_pass += interval;
		if(_pass>=1.f)
		{
			_pass -= 1.f;
			int second = getSecond() +1;
			if(second <= _allSecond)
				setSecond(second);
		}*/
	}
NetGameComponent::NetGameComponent(void):_gameInterface(new RouletteGameInterfaces())
,_clockInterface(new RouletteClockInterface())
,_uiInterface(new RouletteUIInterface())
{

	_query.add(_clockInterface.get());
	_query.add(_uiInterface.get());
	_query.add(_gameInterface.get());

	
	_gameInterface->update =boost::bind(&NetGameComponent::update, this, _1);
	_gameInterface->enableState =boost::bind(&NetGameComponent::enableState, this, _1, _2);
	_gameInterface->disableState =boost::bind(&NetGameComponent::disableState, this, _1);


	_clockInterface->reset =boost::bind(&NetClock::reset, &_clock);
	_clockInterface->update =boost::bind(&NetClock::update, &_clock, _1);
	_clockInterface->time =boost::bind(&NetClock::getLastSecond, &_clock);


	

	_uiInterface->setTheTime =boost::bind(&WheelGameUIRegister::setTheTime, &_uiRegister, _1);
	_uiInterface->setStartVisible =boost::bind(&WheelGameUIRegister::setStartVisible, &_uiRegister, _1);
	_uiInterface->setEndVisible =boost::bind(&WheelGameUIRegister::setEndVisible, &_uiRegister, _1);
	_uiInterface->runWinner =boost::bind(&WheelGameUIRegister::runWinner, &_uiRegister);
	_uiInterface->setLogoShow =boost::bind(&WheelGameUIRegister::setLogoShow, &_uiRegister, _1);
	_uiInterface->addBottom =boost::bind(&WheelGameUIRegister::addBottom, &_uiRegister);
	_uiInterface->update =boost::bind(&WheelGameUIRegister::update, &_uiRegister, _1);


	Js::getInstancePtr()->subscribeStartGame(boost::bind(&NetGameComponent::startGame, this));


	Js::getInstancePtr()->subscribeSetTime(boost::bind(&NetClock::setTime, &_clock, _1));
}

void NetGameComponent::disableState(Event::message_type evt)
{
//	std::cout<<int(evt)<<std::endl;
//	switch(evt)
//	{
//	case WheelEvents::PROCESS_START_DISABLE:
//		//Js::getInstancePtr()->setButtonEnable(false);
//		break;
//	}
}
void NetGameComponent::enableState(Event::message_type evt, RouletteGameInterfaces::Referenced referenced)
{
	switch(evt)
	{
		
	case WheelEvents::PROCESS_LOGO_ENABLE:
		 _holdLogo = referenced;
		 break;
	/*case WheelEvents::PROCESS_START_ENABLE:
		Js::getInstancePtr()->setButtonEnable(true);
		
		break;*/
	}
}

void NetGameComponent::startGame(void)
{
	

	_holdLogo.reset();
}


//void NetGameComponent::stateEvent(Event::message_type evt)
//{
//	switch(evt)
//	{
//	case WheelEvents::PROCESS_START_ENABLE:
//		Js::getInstancePtr()->setButtonEnable(true);
//		break;
//	case WheelEvents::PROCESS_START_DISABLE:
//		Js::getInstancePtr()->setButtonEnable(false);
//		break;
//	}
//	std::cout<<int(evt)<<std::endl;
//}
NetGameComponent::~NetGameComponent(void)
{

}


void NetGameComponent::setTime(int time)
{


}
bool NetGameComponent::update(TimeType i)
{
	_uiRegister.update(i);
	return true;
}