
#include "NetWheelDirectorStableHeaders.h"
#include "logic/AllLogic.h"
#include "WheelEvents.h"
#include "ScoreManager.h"
#include "LockInterface.h"
#include "CodingFormatInterface.h"
#include "DataServerInterface.h"
#include "logic/Dan1Logic.h"
#include "GSMInterface.h"
using namespace Orz;
void TimeLogic::exit(void)
{
	
	
	
	

}
TimeLogic::TimeLogic(my_context ctx):LogicAdv(ctx),_gotoDan(false),_second(-1)
{
	
	ORZ_LOG_NORMAL_MESSAGE("State In: StartLogic!");
	getOwner()->setStartUIVisible(true);
	getOwner()->resetClock();

	
}
TimeLogic::~TimeLogic(void)
{
	
	getOwner()->setStartUIVisible(false);
	
	ORZ_LOG_NORMAL_MESSAGE("State Out: StartLogic!");
	
}
sc::result TimeLogic::react(const LogicEvent::Dan1 & evt)
{
	return transit<Dan1Logic>();
}


sc::result TimeLogic::react(const LogicEvent::Dan2 & evt)
{
	return transit<Dan2Logic>();
}
sc::result TimeLogic::react(const UpdateEvt & evt)
{

	
	if(_gotoDan)
	{
		return transit<Dan1Logic>();
	}
	getOwner()->updateClock(evt.getInterval());

	int now = getOwner()->answerTime();
	if(now != _second)
	{
		_second = now;
	}
	if(now <= 0)
	{

			return transit<GameRunLogic>();
		
	}
	
	

	return forward_event();

}