#include "logic/AllLogic.h"
using namespace Orz;

sc::result SetupLogic::react(const  LogicEvent::GoOutMenu & evt)
{

	return transit<GameLogic>();
}
sc::result SetupLogic::react(const LogicEvent::HardwareReturn & evt)
{
	evt.execute(getOwner());
	return forward_event();
}


sc::result SetupLogic::react(const LogicEvent::ActionOne & evt)
{
	evt.execute(getOwner());
	return forward_event();
}


SetupLogic::SetupLogic(my_context ctx):LogicAdv(ctx)
{
	getOwner()->setSetupVisible(true);
}
SetupLogic::~SetupLogic(void)
{
	getOwner()->setSetupVisible(false);
}