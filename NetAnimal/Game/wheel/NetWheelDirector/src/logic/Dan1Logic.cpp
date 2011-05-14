
#include "NetWheelDirectorStableHeaders.h"
#include "logic/AllLogic.h"
#include "WheelEvents.h"
#include "DUI/DUI.h"
using namespace Orz;



Dan1Logic::Dan1Logic(my_context ctx):LogicAdv(ctx)
{
	DUI::getSingleton().setMenuDataVisible(true);
	
}

void Dan1Logic::exit(void)
{
	
	DUI::getSingleton().setMenuDataVisible(false);
}
sc::result Dan1Logic::react(const LogicEvent::Dan1 & evt)
{
		return transit<GameLogic>();
}

Dan1Logic::~Dan1Logic(void)
{
	
}
