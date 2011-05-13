
#include "NetWheelDirectorStableHeaders.h"
#include "logic/AllLogic.h"
#include "WheelEvents.h"
using namespace Orz;

PlayLogic::PlayLogic(my_context ctx):LogicAdv(ctx)
{
	
	ORZ_LOG_NORMAL_MESSAGE("State In: PlayLogic!");
	//WheelUI::getSingleton().runZXH(Hardware::getSingleton().getWinType()->getBanker());
	_process.reset( new Process( getOwner()->getWorld(), WheelEvents::PROCESS_PLAY_ENABLE, WheelEvents::PROCESS_PLAY_DISABLE));
}



PlayLogic::~PlayLogic(void)
{
	
	ORZ_LOG_NORMAL_MESSAGE("State Out: PlayLogic!");
}

sc::result PlayLogic::react(const UpdateEvt & evt)
{
	if(_process->update(evt.getInterval()))
		return forward_event();

		return transit<HardwareLogic<GameRunLogic,
				EndLogic, 
				GameOver>
				 >();
}

