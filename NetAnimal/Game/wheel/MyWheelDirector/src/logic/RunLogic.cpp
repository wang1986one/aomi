
#include "MyWheelDirectorStableHeaders.h"
#include "logic/AllLogic.h"
#include "WheelEvents.h"
using namespace Orz;



RunLogic::RunLogic(my_context ctx):LogicAdv(ctx)
{
	ORZ_LOG_NORMAL_MESSAGE("State In: RunLogic!");
//	getOwner()->runWinner();
	//WheelUI::getSingleton().runZXH(Hardware::getSingleton().getWinType()->getBanker());
	_process.reset( new Process( getOwner()->getWorld(), WheelEvents::PROCESS_RUN_ENABLE, WheelEvents::PROCESS_RUN_DISABLE));
}
RunLogic::~RunLogic(void)
{
	ORZ_LOG_NORMAL_MESSAGE("State Out: RunLogic!");
}

sc::result RunLogic::react(const UpdateEvt & evt)
{
	if(_process->update(evt.getInterval()))
		return forward_event();
		//return forward_event();
	return transit<WinLogic>();	
}


//sc::result RunLogic::react(const LogicEvent::AskState & evt)
//{	
//	evt.execute(getOwner(), 0x02);
//	//Hardware::getSingleton().answerState(0x01);
//	return forward_event();
//}
