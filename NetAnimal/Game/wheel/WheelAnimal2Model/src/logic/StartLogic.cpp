#include "logic/AllLogic.h"
#include "WheelEvents.h"
using namespace Orz;
	
StartLogic::StartLogic(my_context ctx):LogicAdv(ctx),_state(NONE)
{
	
	ORZ_LOG_NORMAL<<"State In: StartLogic!";
	_process.reset( new Process( getOwner()->getWorld(), WheelEvents::PROCESS_START_ENABLE, WheelEvents::PROCESS_START_DISABLE));
	getOwner()->setStartUIVisible(true);
	getOwner()->resetClock();
}
//
//sc::result StartLogic::react(const KeyF5 & evt)
//{
//
//	_event = KEY_F5;
//	return forward_event();
//
//}
//sc::result StartLogic::react(const KeyF6 & evt)
//{
//
//	_event = KEY_F6;
//	return forward_event();
//}

sc::result StartLogic::react(const LogicEvent::ActionTwo & evt)
{
	_state = ACTION2;
	return forward_event();
}
sc::result StartLogic::react(const LogicEvent::ActionThree & evt)
{
	_state = ACTION3;
	return forward_event();
}
StartLogic::~StartLogic(void)
{
	
	getOwner()->setStartUIVisible(false);
	
	ORZ_LOG_NORMAL<<"State Out: StartLogic!";
	//getOwner()->reset
}

//
//sc::result StartLogic::react(const SetMode & evt)
//{
//
//	Process0LightRunning * running = getOwner()->getLightRunningInterface();
//	running->setMode(Hardware::getSingleton().getWinType()->getLightMode());
//	return forward_event();
//}
sc::result StartLogic::react(const UpdateEvt & evt)
{

	getOwner()->updateClock(evt.getInterval());


	//TutoriaLogic  & mainLogic  = context< TutoriaLogic>();
	//if(!_init)
	//{
	//	_init = true;
	//	mainLogic.getClock().reset();//setSec(0);
	//}

	//_time += evt.getInterval();
	//MyClock& clock = mainLogic.getClock();
	//int sec = mainLogic.getSec() ;

	
	if(_process->update(evt.getInterval()))
		return forward_event();


	return forward_event();



}
sc::result StartLogic::react(const LogicEvent::AskState & evt)
{	

	evt.execute(getOwner(), 0);
	//Hardware::getSingleton().answerState(0x00);
	return forward_event();
}

sc::result StartLogic::react(const LogicEvent::AskTime & evt)
{

	//TutoriaLogic  & mainLogic  = context< TutoriaLogic>();
	//MyClock & clock = mainLogic.getClock();
	
	if(_state == ACTION2 && evt.canAction(getOwner()))
	{
		evt.actionTwo(getOwner());
		return forward_event();
	}else if(_state == ACTION3 && evt.canAction(getOwner()))
	{
		evt.actionThree(getOwner());
		return forward_event();
	}

	evt.answerTime(getOwner());
	//Hardware::getSingleton().answerTime(clock.getLastSecond());
	return forward_event();
}

sc::result StartLogic::react(const LogicEvent::HowWin & evt)
{
	return transit<ProRunLogic>();
}
//sc::result StartLogic::react(const HowWin & evt)
//{
//	WinTypePtr wintype = Hardware::getSingleton().getWinType();
//	getOwner()->resetProcess(wintype->getWinMode());
//
//	//Hardware::getSingleton().getWinnerAnimalType();
//
//	//Hardware & hardware = Hardware::getSingleton();
//
//	//AnimalType animalType = hardware.getWinnerAnimalType();
//
//	//WinData::LightColor color = hardware.getLight();
//
//	//WinData::ZXH zxh = hardware.getZXH();
//
//	//WinData::WinMode mode = hardware.getWinMode();
//
//	//UI�ײ�������
//	WheelUI::getSingleton().addBottom(wintype);
//
//	return transit<LogiPreRun>();
//}