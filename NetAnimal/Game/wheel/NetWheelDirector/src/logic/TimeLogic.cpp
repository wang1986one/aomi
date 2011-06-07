
#include "NetWheelDirectorStableHeaders.h"
#include "logic/AllLogic.h"
#include "WheelEvents.h"
#include "ScoreManager.h"
#include "LockInterface.h"
#include "CodingFormatInterface.h"
#include "DataServerInterface.h"
#include "logic/Dan1Logic.h"
#include "GSMInterface.h"
#include "WheelGameUIRegister.h"
using namespace Orz;
void TimeLogic::exit(void)
{
	
	
	
	

}
TimeLogic::TimeLogic(my_context ctx):LogicAdv(ctx),_gotoDan(false),_second(-1)
{
	
	ORZ_LOG_NORMAL_MESSAGE("State In: TimeLogic!");
	context<WheelLogic>().ui()->setStartVisible(true);
	context<WheelLogic>().clock()->reset();

	WinData::getInstance().waitFor(true);
}
TimeLogic::~TimeLogic(void)
{
	
	context<WheelLogic>().ui()->setStartVisible(false);
	
	ORZ_LOG_NORMAL_MESSAGE("State Out: TimeLogic!");
	
}
//sc::result TimeLogic::react(const LogicEvent::Dan1 & evt)
//{
//	return transit<Dan1Logic>();
//}
//
//
//sc::result TimeLogic::react(const LogicEvent::Dan2 & evt)
//{
//	return transit<Dan2Logic>();
//}
sc::result TimeLogic::react(const UpdateEvt & evt)
{

	
	/*if(_gotoDan)
	{
		return transit<Dan1Logic>();
	}*/
	//context<WheelLogic>().clock()->update(evt.getInterval());

	int now = context<WheelLogic>().clock()->time();
	if(now != _second)
	{
		_second = now;
		context<WheelLogic>().ui()->setTheTime(_second);
	}
	if(!WinData::getInstance().waitFor())
	{
		return transit<GameRunLogic>();
		
	}
	
	

	return forward_event();

}