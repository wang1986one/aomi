#include "logic/AllLogic.h"
#include "WheelEvents.h"
using namespace Orz;



WinLogic::WinLogic(my_context ctx):LogicAdv(ctx)
{
	ORZ_LOG_NORMAL<<"State In: WinLogic!";
	
	//WheelUI::getSingleton().runZXH(Hardware::getSingleton().getWinType()->getBanker());
	_process.reset( new Process( getOwner()->getWorld(), WheelEvents::PROCESS_WIN_ENABLE, WheelEvents::PROCESS_WIN_DISABLE));
}

WinLogic::~WinLogic(void)
{
	ORZ_LOG_NORMAL<<"State Out: WinLogic!";
	
}

sc::result WinLogic::react(const UpdateEvt & evt)
{
	if(_process->update(evt.getInterval()))
		return forward_event();
		//return forward_event();
	return transit<PlayLogic>();	
}


sc::result WinLogic::react(const LogicEvent::AskState & evt)
{	
	evt.execute(getOwner(), 0x02);
	//Hardware::getSingleton().answerState(0x01);
	return forward_event();
}
