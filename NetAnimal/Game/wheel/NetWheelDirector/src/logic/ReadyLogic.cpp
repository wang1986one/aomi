
#include "NetWheelDirectorStableHeaders.h"
#include "logic/AllLogic.h"
#include "WheelEvents.h"
#include "ScoreManager.h"
using namespace Orz;
	

	
ReadyLogic::ReadyLogic(my_context ctx):LogicAdv(ctx)
{
	_process.reset( new Process( context<WheelLogic>().game()->getWorld(), WheelEvents::PROCESS_READY_ENABLE, WheelEvents::PROCESS_READY_DISABLE));
	
	ORZ_LOG_NORMAL_MESSAGE("State In: ReadyLogic!");
}

ReadyLogic::~ReadyLogic(void)
{
	
	ORZ_LOG_NORMAL_MESSAGE("State Out: ReadyLogic!");
}


sc::result ReadyLogic::react(const UpdateEvt & evt)
{
	if(_process->update(evt.getInterval()))
		return forward_event();


	return forward_event();



}



sc::result ReadyLogic::react(const LogicEvent::AskTime & evt)
{

	evt.resetClock(context<WheelLogic>().clock());

	return transit<StartLogic>();
}
