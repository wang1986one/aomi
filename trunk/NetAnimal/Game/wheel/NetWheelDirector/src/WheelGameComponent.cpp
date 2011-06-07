#include "NetWheelDirectorStableHeaders.h"

#include "WheelGameUIRegister.h"
#include "WheelGameComponent.h"
#include "WheelClock.h"
#include "RouletteGameInterfaces.h"
using namespace Orz;

WheelGameComponent::WheelGameComponent(void):_gameInterface(new RouletteGameInterfaces())
,_clockInterface(new RouletteClockInterface())
,_uiInterface(new RouletteUIInterface())
{

	_query.add(_clockInterface.get());
	_query.add(_uiInterface.get());
	_query.add(_gameInterface.get());

	
	_gameInterface->update =boost::bind(&WheelGameComponent::update, this, _1);
	_gameInterface->enableState =boost::bind(&WheelGameComponent::enableState, this, _1, _2);
	_gameInterface->disableState =boost::bind(&WheelGameComponent::disableState, this, _1);

	_clockInterface->reset =boost::bind(&WheelClock::reset, &_clock);
	_clockInterface->update =boost::bind(&WheelClock::update, &_clock, _1);
	_clockInterface->time =boost::bind(&WheelClock::getLastSecond, &_clock);


	

	_uiInterface->setTheTime =boost::bind(&WheelGameUIRegister::setTheTime, &_uiRegister, _1);
	_uiInterface->setStartVisible =boost::bind(&WheelGameUIRegister::setStartVisible, &_uiRegister, _1);
	_uiInterface->setEndVisible =boost::bind(&WheelGameUIRegister::setEndVisible, &_uiRegister, _1);
	_uiInterface->runWinner =boost::bind(&WheelGameUIRegister::runWinner, &_uiRegister);
	_uiInterface->setLogoShow =boost::bind(&WheelGameUIRegister::setLogoShow, &_uiRegister, _1);
	_uiInterface->addBottom =boost::bind(&WheelGameUIRegister::addBottom, &_uiRegister);
	_uiInterface->update =boost::bind(&WheelGameUIRegister::update, &_uiRegister, _1);


}

void WheelGameComponent::disableState(Event::message_type evt)
{
	std::cout<<int(evt)<<std::endl;
	//switch(evt)
	//{}
}
void WheelGameComponent::enableState(Event::message_type evt, RouletteGameInterfaces::Referenced referenced)
{
	std::cout<<int(evt)<<std::endl;
	//switch(evt)
	//{}
}
WheelGameComponent::~WheelGameComponent(void)
{

}


bool WheelGameComponent::update(TimeType i)
{
	_uiRegister.update(i);
	return true;
}