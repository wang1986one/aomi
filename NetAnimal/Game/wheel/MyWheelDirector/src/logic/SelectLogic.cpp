
#include "MyWheelDirectorStableHeaders.h"
#include "logic/AllLogic.h"
#include "WheelEvents.h"
using namespace Orz;
	
SelectLogic::SelectLogic(my_context ctx):LogicAdv(ctx),_allTime(0.f)
{

	ORZ_LOG_NORMAL_MESSAGE("State In: SelectLogic!");
	getOwner()->setSelectVisible(false);

}

sc::result SelectLogic::react(const UpdateEvt & evt)
{
	_allTime -= evt.getInterval();
	if(_allTime <= 0.f)
	{
		
		getOwner()->enableScene("HunterScene", false);
		return transit<GameLogic>();
	}

	return forward_event();
}
sc::result SelectLogic::react(const LogicEvent::ClickButton & evt)
{
	

	
	if(evt.getButton() == 0)
	{
		getOwner()->enableScene("WheelScene2", true);
		
		return transit<GameLogic>();
	}	
	
	if(evt.getButton() == 1)
	{
		getOwner()->enableScene("HunterScene", false);
		
		return transit<GameLogic>();
	}

	return forward_event();
}

SelectLogic::~SelectLogic(void)
{
}
	