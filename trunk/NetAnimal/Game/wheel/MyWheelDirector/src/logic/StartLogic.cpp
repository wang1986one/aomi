
#include "MyWheelDirectorStableHeaders.h"
#include "logic/AllLogic.h"
#include "WheelEvents.h"
#include "ScoreManager.h"
#include "LockInterface.h"
#include "CodingFormatInterface.h"
#include "DataServerInterface.h"
#include "logic/Dan1Logic.h"
using namespace Orz;
void StartLogic::exit(void)
{
	
	
	ComponentPtr dataServer = getOwner()->getDataServer();

	CodingFormatInterface * format = dataServer->queryInterface<CodingFormatInterface>();
	LockInterface * lock = dataServer->queryInterface<LockInterface>();


	std::string code = format->encode10(60, 20);
	lock->setLockCode(code);
	DataServerInterface * data = dataServer->queryInterface<DataServerInterface>();
	data->save();

}
StartLogic::StartLogic(my_context ctx):LogicAdv(ctx),_gotoDan(false)
{
	
	ORZ_LOG_NORMAL_MESSAGE("State In: StartLogic!");
	_process.reset( new Process( getOwner()->getWorld(), WheelEvents::PROCESS_START_ENABLE, WheelEvents::PROCESS_START_DISABLE));
	getOwner()->setStartUIVisible(true);
	getOwner()->resetClock();

	ComponentPtr dataServer = getOwner()->getDataServer();
	LockInterface * lock = dataServer->queryInterface<LockInterface>();
	
	CodingFormatInterface * format = dataServer->queryInterface<CodingFormatInterface>();
	DataServerInterface * data = dataServer->queryInterface<DataServerInterface>();
	if(lock->check())
	{
			
		std::string code = lock->getLockCode();
		if(!format->decode10(code, 60))
		{
			srand(time(NULL));
			format->clear();
			format->setLockTimes(0);
			format->setLockID(rand()%256);
			format->setLockLeavings(0);
			format->setLockPass(0);
			
		}
		if(!data->hasLevings())
		{
			_gotoDan = true;
		}


	}else
	{
		_gotoDan = true;
	}
}
StartLogic::~StartLogic(void)
{
	
	getOwner()->setStartUIVisible(false);
	
	ORZ_LOG_NORMAL_MESSAGE("State Out: StartLogic!");
	
}
sc::result StartLogic::react(const LogicEvent::Dan1 & evt)
{
	return transit<Dan1Logic>();
}


sc::result StartLogic::react(const LogicEvent::Dan2 & evt)
{
	return transit<Dan2Logic>();
}

sc::result StartLogic::react(const LogicEvent::ClickButton & evt)
{
	ScoreManager::getInstance().clickButton(evt.getID(), evt.getButton());
	return forward_event();
}
sc::result StartLogic::react(const UpdateEvt & evt)
{

	//
	//if(_gotoDan)
	//{
	//	return transit<Dan1Logic>();
	//}
	getOwner()->updateClock(evt.getInterval());

	if(getOwner()->answerTime() <= 0)
	{
		ScoreManager::getInstance().go();
		getOwner()->addBottomToUI();
		return transit<GameRunLogic>();
	}
	
	
	if(_process->update(evt.getInterval()))
		return forward_event();

	//std::cout<<getOwner()->answerTime() <<std::endl;

	return forward_event();



}