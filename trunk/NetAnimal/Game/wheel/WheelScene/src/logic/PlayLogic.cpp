#include "logic/AllLogic.h"
#include "WheelEvents.h"
using namespace Orz;



PlayLogic::PlayLogic(my_context ctx):LogicAdv(ctx)
{
	
	ORZ_LOG_NORMAL<<"State In: PlayLogic!";
	//WheelUI::getSingleton().runZXH(Hardware::getSingleton().getWinType()->getBanker());
	_process.reset( new Process( getOwner()->getWorld(), WheelEvents::PROCESS_PLAY_ENABLE, WheelEvents::PROCESS_PLAY_DISABLE));
}



PlayLogic::~PlayLogic(void)
{
	
	ORZ_LOG_NORMAL<<"State Out: PlayLogic!";
}

sc::result PlayLogic::react(const UpdateEvt & evt)
{
	if(_process->update(evt.getInterval()))
		return forward_event();
		//return forward_event();
	return transit<EndLogic>();	
}


sc::result PlayLogic::react(const LogicEvent::AskState & evt)
{	
	evt.execute(getOwner(), 0x03);
	//Hardware::getSingleton().answerState(0x01);
	return forward_event();
}
