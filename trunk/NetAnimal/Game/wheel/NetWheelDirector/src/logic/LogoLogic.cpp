
#include "NetWheelDirectorStableHeaders.h"
#include "logic/AllLogic.h"
#include "WheelEvents.h"
#include "CommunicateInterface.h"
#include "GameLevelInterface.h"
using namespace Orz;

LogoLogic::LogoLogic(my_context ctx):LogicAdv(ctx),_gotoReady(true)//,_ret(true)
{


	using namespace std;
	using namespace boost::posix_time;  
	
	ORZ_LOG_NORMAL_MESSAGE("State In: LogoLogic!");
	context<WheelLogic>().ui()->setLogoShow(true);
	_process.reset( new Process( context<WheelLogic>().game()->getWorld(), WheelEvents::PROCESS_LOGO_ENABLE, WheelEvents::PROCESS_LOGO_DISABLE, 5.f));
	
	
	context<WheelLogic>().game()->enableState(WheelEvents::PROCESS_LOGO_ENABLE ,_process->reference());

	ptime now = second_clock::local_time(); 
	
	ORZ_LOG_NORMAL_MESSAGE(to_simple_string(now));

	
}
sc::result LogoLogic::react(const UpdateEvt & evt)
{

	
	if(_process->update(evt.getInterval()))
		return forward_event();

	/*if(_ret)
		return forward_event();*/


	if(_gotoReady)
		return transit<ReadyLogic>();
	else
		return transit<StartLogic>();
}

LogoLogic::~LogoLogic(void)
{
}

sc::result LogoLogic::react(const LogicEvent::AskTime & evt)
{


	evt.resetClock(context<WheelLogic>().clock());
	_gotoReady = false;
	return forward_event();
	//return transit<StartLogic>();
}

void LogoLogic::exit(void)
{

	context<WheelLogic>().ui()->setLogoShow(false);
	ORZ_LOG_NORMAL_MESSAGE("State Out: LogoLogic!");
	
	context<WheelLogic>().game()->disableState(WheelEvents::PROCESS_LOGO_DISABLE);
}
