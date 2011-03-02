
#include "NewWheelDirectorStableHeaders.h"
#include "logic/AllLogic.h"
#include "WheelEvents.h"
#include "NewHardware.h"
using namespace Orz;


EndLogic::EndLogic(my_context ctx):LogicAdv(ctx), _allTime(0.f)
{

	ORZ_LOG_NORMAL_MESSAGE("State In: EndLogic!");
	_process.reset( new Process( getOwner()->getWorld(), WheelEvents::PROCESS_END_ENABLE, WheelEvents::PROCESS_END_DISABLE, 4.f));
	getOwner()->setEndUIVisible(true);
}


sc::result EndLogic::react(const UpdateEvt & evt)
{

	if(_process->update(evt.getInterval()))
		return forward_event();

	return transit<LogoLogic>();	

	
}

EndLogic::~EndLogic(void)
{
	ORZ_LOG_NORMAL_MESSAGE("State Out: EndLogic!");
	getOwner()->setEndUIVisible(false);
	NewHardware::getInstance().end();
}


