
#include "NetWheelDirectorStableHeaders.h"
#include "logic/AllLogic.h"
#include "WheelEvents.h"
#include "CommunicateInterface.h"
#include "GameLevelInterface.h"
using namespace Orz;

LogoLogic::LogoLogic(my_context ctx):LogicAdv(ctx),_gotoReady(true),_ret(true)
{


	WMHardwareInterface * hardware = getOwner()->getHardware()->queryInterface<WMHardwareInterface>();
	hardware->start(WMHardwareInterface::Step0);
	
	ORZ_LOG_NORMAL_MESSAGE("State In: LogoLogic!");
	getOwner()->setLogoShow(true);
	_process.reset( new Process( getOwner()->getWorld(), WheelEvents::PROCESS_LOGO_ENABLE, WheelEvents::PROCESS_LOGO_DISABLE, 5.f));


	CommunicateInterface * commun =getOwner()->getHardware()->queryInterface<CommunicateInterface>();
	commun->clearManyN();

	context<GameLogic>().stopQueryId();
	getOwner()->reportEarnings();
	GameLevelInterface * gameLevel = getOwner()->getGameLevel()->queryInterface<GameLevelInterface>();
	bool ret = gameLevel->updateFluctuate();
	if(gameLevel->nextDay() || ret)
	{
		gameLevel->save();
	}

	
}
sc::result LogoLogic::react(const UpdateEvt & evt)
{

	WMHardwareInterface * hardware = getOwner()->getHardware()->queryInterface<WMHardwareInterface>();
	if(_ret)
	{
		_ret = hardware->wait(evt.getInterval());
		if(_ret == false)
		{
			context<GameLogic>().startQueryId();
		}
	}
	
	if(_process->update(evt.getInterval()))
		return forward_event();

	if(_ret)
		return forward_event();


	if(_gotoReady)
		return transit<ReadyLogic>();
	else
		return transit<StartLogic>();
}

LogoLogic::~LogoLogic(void)
{
	//getOwner()->setLogoShow(false);
	//ORZ_LOG_NORMAL_MESSAGE("State Out: LogoLogic!";
}

sc::result LogoLogic::react(const LogicEvent::AskTime & evt)
{


	evt.resetClock(getOwner());
	_gotoReady = false;
	return forward_event();
	//return transit<StartLogic>();
}

void LogoLogic::exit(void)
{
	
	WMHardwareInterface * hardware = getOwner()->getHardware()->queryInterface<WMHardwareInterface>();
	hardware->end();
	getOwner()->setLogoShow(false);
	ORZ_LOG_NORMAL_MESSAGE("State Out: LogoLogic!");
}
