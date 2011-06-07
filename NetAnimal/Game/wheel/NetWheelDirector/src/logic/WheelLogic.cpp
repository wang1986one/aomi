
#include "NetWheelDirectorStableHeaders.h"
#include "Logic/WheelLogic.h"
#include "Logic/AllLogic.h"
//#include "Logic/AllLogic.h"
using namespace Orz;




sc::result WheelLogic::react(const LogicEvent::WheelStart & evt)
{
	//evt.execute(context<WheelLogic>().clock());//.getHardware().received_WheelStart(true);
	return forward_event();
}


sc::result WheelLogic::react(const LogicEvent::SetTime & evt)
{
	evt.execute(context<WheelLogic>().clock());
	return forward_event();
}


RouletteGameInterfaces * WheelLogic::game(void)
{
	if(!_game)
	{
		_game = (*getOwner())->queryInterface<RouletteGameInterfaces>();
	}
	return _game;
}
RouletteClockInterface * WheelLogic::clock(void)
{
	if(!_clock)
	{
		_clock = (*getOwner())->queryInterface<RouletteClockInterface>();
	}
	return _clock;
}
RouletteUIInterface * WheelLogic::ui(void) 
{
	if(!_ui)
	{
		_ui = (*getOwner())->queryInterface<RouletteUIInterface>();
	}
	return _ui;

}

WheelLogic::WheelLogic(void):_game(NULL),_ui(NULL),_clock(NULL)
{

	ORZ_LOG_NORMAL_MESSAGE("State In: WheelLogic!");
}
WheelLogic::~WheelLogic(void)
{
	ORZ_LOG_NORMAL_MESSAGE("State Out: WheelLogic!");
}