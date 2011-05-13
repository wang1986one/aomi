
#include "NetWheelDirectorStableHeaders.h"
#include "logic/AllLogic.h"
#include "WheelEvents.h"
#include "DUI/DUI.h"
using namespace Orz;



Dan2Logic::Dan2Logic(my_context ctx):LogicAdv(ctx)
{
	DUI::getSingleton().setSetupVisible(true);
	
}

void Dan2Logic::exit(void)
{
	
	DUI::getSingleton().setSetupVisible(false);
}
sc::result Dan2Logic::react(const LogicEvent::Dan2 & evt)
{

	return transit<HardwareLogic<GameLogic,
		GameLogic, 
		GameOver>
		 >();
}

Dan2Logic::~Dan2Logic(void)
{
	
}
