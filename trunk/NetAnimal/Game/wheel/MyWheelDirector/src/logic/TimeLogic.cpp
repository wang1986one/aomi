
#include "MyWheelDirectorStableHeaders.h"
#include "logic/AllLogic.h"
#include "WheelEvents.h"
#include "ScoreManager.h"
#include "LockInterface.h"
#include "CodingFormatInterface.h"
#include "DataServerInterface.h"
#include "logic/Dan1Logic.h"

#include "GameInterface.h"
using namespace Orz;

void TimeLogic::exit(void)
{
	

	getOwner()->addBottomToUI();
	GameInterface<0> * game = getOwner()->getJs()->queryInterface<GameInterface<0> >();
	game->setButtonEnable(false);

}
TimeLogic::TimeLogic(my_context ctx):LogicAdv(ctx),_gotoDan(false),_time(-1)
{
	
	ORZ_LOG_NORMAL_MESSAGE("State In: StartLogic!");
	_process.reset( new Process( getOwner()->getWorld(), WheelEvents::PROCESS_START_ENABLE, WheelEvents::PROCESS_START_DISABLE));
	getOwner()->setStartUIVisible(true);
	getOwner()->resetClock();
	GameInterface<0> * game = getOwner()->getJs()->queryInterface<GameInterface<0> >();
	game->setButtonEnable(true);
	
}
TimeLogic::~TimeLogic(void)
{
	
	getOwner()->setStartUIVisible(false);
	
	ORZ_LOG_NORMAL_MESSAGE("State Out: StartLogic!");
	
}
sc::result TimeLogic::react(const LogicEvent::Dan1 & evt)
{
	return transit<Dan1Logic>();
}


sc::result TimeLogic::react(const LogicEvent::Dan2 & evt)
{
	return transit<Dan2Logic>();
}

sc::result TimeLogic::react(const UpdateEvt & evt)
{

	getOwner()->updateClock(evt.getInterval());
	int time = getOwner()->answerTime();

	if(_time != time)
	{
		_time = time;
			
		GameInterface<0> * game = getOwner()->getJs()->queryInterface<GameInterface<0> >();
		game->setTime(_time);
		if(_time <= 0)
		{
			return transit<GameRunLogic>();
		}
	
	}
	if(_process->update(evt.getInterval()))
		return forward_event();


	return forward_event();



}