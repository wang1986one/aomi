
#include "WheelDirectorStableHeaders.h"

#include "logic/AllLogic.h"


#include "logic/LogoLogic.h"
using namespace Orz;

sc::result GameLogic::react(const LogicEvent::ComeInMenu & evt)
{
	return transit<MenuLogic>();
//	return forward_event();
}



sc::result GameLogic::react(const LogicEvent::ComeInSetup & evt)
{
	return transit<SetupLogic>();
	//return forward_event();
}