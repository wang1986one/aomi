#include "logic/AllLogic.h"
#include "WheelEvents.h"
using namespace Orz;

sc::result EndLogic::react(const  LogicEvent::AskState & evt)
{	
	
	if(_allTime < 3.f)
		evt.execute(getOwner(), 0x03);
	else
		evt.execute(getOwner(), 0x04);
	return forward_event();
}
EndLogic::EndLogic(my_context ctx):LogicAdv(ctx), _allTime(0.f)
{

	ORZ_LOG_NORMAL<<"State In: EndLogic!";
	_process.reset( new Process( getOwner()->getWorld(), WheelEvents::PROCESS_END_ENABLE, WheelEvents::PROCESS_END_DISABLE, 10.f));
	getOwner()->setEndUIVisible(true);
}


sc::result EndLogic::react(const UpdateEvt & evt)
{

	if(_process->update(evt.getInterval()))
		return forward_event();
		//return forward_event();
	return transit<LogoLogic>();	

	
}

EndLogic::~EndLogic(void)
{
	ORZ_LOG_NORMAL<<"State Out: EndLogic!";
	getOwner()->setEndUIVisible(false);
}


