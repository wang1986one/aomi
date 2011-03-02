
#include "NewWheelDirectorStableHeaders.h"
#include "logic/AllLogic.h"
#include "WheelEvents.h"
using namespace Orz;



ProRunLogic::ProRunLogic(my_context ctx):LogicAdv(ctx)
{
	ORZ_LOG_NORMAL_MESSAGE("State In: ProRunLogic!");
	getOwner()->runWinner();
	//WheelUI::getSingleton().runZXH(Hardware::getSingleton().getWinType()->getBanker());
	_process.reset( new Process( getOwner()->getWorld(), WheelEvents::PROCESS_PRORUN_ENABLE, WheelEvents::PROCESS_PRORUN_DISABLE));
}

ProRunLogic::~ProRunLogic(void)
{
	ORZ_LOG_NORMAL_MESSAGE("State Out: ProRunLogic!");
}

sc::result ProRunLogic::react(const UpdateEvt & evt)
{
	if(_process->update(evt.getInterval()))
		return forward_event();
		//return forward_event();
	return transit<RunLogic>();	
}


//sc::result ProRunLogic::react(const LogicEvent::AskState & evt)
//{	
//	evt.execute(getOwner(), 0x01);
//	//Hardware::getSingleton().answerState(0x01);
//	return forward_event();
//}
