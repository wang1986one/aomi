
#include "NewWheelDirectorStableHeaders.h"
#include "logic/AllLogic.h"
#include "WheelEvents.h"
using namespace Orz;
	

//sc::result ReadyLogic::react(const LogicEvent::AskState & evt)
//{	
//	evt.execute(getOwner(), 0x05);
//	//Hardware::getSingleton().answerState(0x05);
//	return forward_event();
//}
ReadyLogic::ReadyLogic(my_context ctx):LogicAdv(ctx)
{
	_process.reset( new Process( getOwner()->getWorld(), WheelEvents::PROCESS_READY_ENABLE, WheelEvents::PROCESS_READY_DISABLE));
	
	ORZ_LOG_NORMAL_MESSAGE("State In: ReadyLogic!");
}

sc::result ReadyLogic::react(const LogicEvent::FindSC & evt)
{
	
	NewHardware::getInstance().findPC();
	return forward_event();
}

ReadyLogic::~ReadyLogic(void)
{
	
	ORZ_LOG_NORMAL_MESSAGE("State Out: ReadyLogic!");
	//getOwner().resetClock();
	//TutoriaLogic  & mainLogic  = context< TutoriaLogic>();
	//MyClock & clock =  mainLogic.getClock();
	//clock.reset();
	//
	//Hardware::getSingleton().answerTime(clock.getLastSecond());

}


sc::result ReadyLogic::react(const UpdateEvt & evt)
{
	if(_process->update(evt.getInterval()))
		return forward_event();


	return forward_event();



}



sc::result ReadyLogic::react(const LogicEvent::AskTime & evt)
{


	evt.resetClock(getOwner());
	//evt.answerTime(getOwner());

	/*	getOwner().resetClock();
	TutoriaLogic  & mainLogic  = context< TutoriaLogic>();
	MyClock & clock =  mainLogic.getClock();
	clock.reset();
	
	Hardware::getSingleton().answerTime(clock.getLastSecond());*/

	return transit<StartLogic>();
	//return forward_event();
}
