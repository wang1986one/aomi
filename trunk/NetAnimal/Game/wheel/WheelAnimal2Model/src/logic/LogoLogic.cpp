#include "logic/AllLogic.h"
#include "WheelEvents.h"
using namespace Orz;
	
LogoLogic::LogoLogic(my_context ctx):LogicAdv(ctx)
{

	ORZ_LOG_NORMAL<<"State In: LogoLogic!";
	getOwner()->setLogoShow(true);
	_process.reset( new Process( getOwner()->getWorld(), WheelEvents::PROCESS_LOGO_ENABLE, WheelEvents::PROCESS_LOGO_DISABLE));

}
sc::result LogoLogic::react(const UpdateEvt & evt)
{
	if(_process->update(evt.getInterval()))
		return forward_event();
	//return forward_event();
	return transit<ReadyLogic>();
}

LogoLogic::~LogoLogic(void)
{
	
	getOwner()->setLogoShow(false);
	ORZ_LOG_NORMAL<<"State Out: LogoLogic!";
}
	

sc::result LogoLogic::react(const LogicEvent::AskState & evt)
{
	evt.execute(getOwner(), 0x05);
	return forward_event();
}