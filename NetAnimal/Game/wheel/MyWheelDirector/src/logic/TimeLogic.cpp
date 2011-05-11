
#include "MyWheelDirectorStableHeaders.h"
#include "logic/AllLogic.h"
#include "WheelEvents.h"
#include "ScoreManager.h"
#include "LockInterface.h"
#include "CodingFormatInterface.h"
#include "DataServerInterface.h"
#include "logic/Dan1Logic.h"
#include "GSMInterface.h"
using namespace Orz;
void TimeLogic::exit(void)
{
	
	
	ComponentPtr dataServer = getOwner()->getDataServer();

	CodingFormatInterface * format = dataServer->queryInterface<CodingFormatInterface>();
	LockInterface * lock = dataServer->queryInterface<LockInterface>();


	std::string code = format->encode10(60, 20);
	lock->setLockCode(code);
	DataServerInterface * data = dataServer->queryInterface<DataServerInterface>();
	data->save();

	
	context< GameLogic >().startQueryId();
	
	

}
TimeLogic::TimeLogic(my_context ctx):LogicAdv(ctx),_gotoDan(false),_second(-1)
{
	
	ORZ_LOG_NORMAL_MESSAGE("State In: StartLogic!");
	getOwner()->setStartUIVisible(true);
	getOwner()->resetClock();

	ComponentPtr dataServer = getOwner()->getDataServer();
	LockInterface * lock = dataServer->queryInterface<LockInterface>();
	
	CodingFormatInterface * format = dataServer->queryInterface<CodingFormatInterface>();
	DataServerInterface * data = dataServer->queryInterface<DataServerInterface>();
	if(lock->check())
	{
		lock->update();
		std::string code = lock->getLockCode();
		if(!format->decode10(code, 60))
		{
			_gotoDan = true;
			
		}
		if(!data->hasLevings())
		{
			_gotoDan = true;
		}


	}else
	{
		_gotoDan = true;
	}
	GSMInterface * gsm = getOwner()->getGSM()->queryInterface<GSMInterface>();
	assert(gsm == NULL);
	if(gsm->failsOver(3))
	{
		_gotoDan = true;
	}
	_communicate = getOwner()->getHardware()->queryInterface<CommunicateInterface>();
	context<GameLogic>().stopQueryId();
	
	_communicate->notifyState(CommunicateInterface::State1);
	
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

//sc::result StartLogic::react(const LogicEvent::F1 & evt)
//{
////	ScoreManager::getInstance().clickButton(evt.getID(), evt.getButton());
//	return forward_event();
//}
sc::result TimeLogic::react(const UpdateEvt & evt)
{

	
	if(_gotoDan)
	{
		return transit<Dan1Logic>();
	}
	getOwner()->updateClock(evt.getInterval());

	int now = getOwner()->answerTime();
	if(now != _second)
	{
		_second = now;
		_communicate->setTime(_second);
	}
	if(now <= 0)
	{
		//ScoreManager::getInstance().go();

			return transit<HardwareLogic<StartLogic,
				HardwareLogic<StartLogic, GameRunLogic, SetWinMsg>, 
				GetWinMsg>
				 >();
		
	}
	
	

	return forward_event();

}