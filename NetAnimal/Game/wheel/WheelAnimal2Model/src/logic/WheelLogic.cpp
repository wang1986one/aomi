#include "Logic/WheelLogic.h"
#include "Logic/AllLogic.h"
//#include "Logic/AllLogic.h"
using namespace Orz;


sc::result WheelLogic::react(const LogicEvent::WheelStart & evt)
{
	evt.execute(getOwner());//.getHardware().received_WheelStart(true);
	return forward_event();
}


sc::result WheelLogic::react(const LogicEvent::SetTime & evt)
{
	evt.execute(getOwner());
	return forward_event();
}
sc::result WheelLogic::react(const LogicEvent::ResetGame & evt)
{
	return transit<GameLogic>();
	//return forward_event();
}