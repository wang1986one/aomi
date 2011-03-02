
#include "NewWheelDirectorStableHeaders.h"
#include "logic/AllLogic.h"
#include "WheelEvents.h"

using namespace Orz;
	
StartLogic::StartLogic(my_context ctx):LogicAdv(ctx)
{
	
	ORZ_LOG_NORMAL_MESSAGE("State In: StartLogic!");
	_process.reset( new Process( getOwner()->getWorld(), WheelEvents::PROCESS_START_ENABLE, WheelEvents::PROCESS_START_DISABLE));
	getOwner()->setStartUIVisible(true);
	getOwner()->resetClock();
}
StartLogic::~StartLogic(void)
{
	
	getOwner()->setStartUIVisible(false);
	
	ORZ_LOG_NORMAL_MESSAGE("State Out: StartLogic!");
	//getOwner()->reset
}

//
//sc::result StartLogic::react(const SetMode & evt)
//{
//
//	Process0LightRunning * running = getOwner()->getLightRunningInterface();
//	running->setMode(Hardware::getSingleton().getWinType()->getRate());
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
//sc::result StartLogic::react(const LogicEvent::AskState & evt)
//{	
//
//	evt.execute(getOwner(), 0);
//	//Hardware::getSingleton().answerState(0x00);
//	return forward_event();
//}

sc::result StartLogic::react(const LogicEvent::AskTime & evt)
{

	//TutoriaLogic  & mainLogic  = context< TutoriaLogic>();
	//MyClock & clock = mainLogic.getClock();
	
	
	//evt.answerTime(getOwner());
	//Hardware::getSingleton().answerTime(clock.getLastSecond());
	return forward_event();
}

sc::result StartLogic::react(const LogicEvent::HowWin & evt)
{
	getOwner()->addBottomToUI();
	return transit<GameRunLogic/*ProRunLogic*/>();
}
//sc::result StartLogic::react(const HowWin & evt)
//{
//	const WinData & WinData::getSingleton() = Hardware::getSingleton().getWinType();
//	getOwner()->resetProcess(WinData::getInstance().getWinMode());
//
//	//Hardware::getSingleton().getWinnerAnimalType();
//
//	//Hardware & hardware = Hardware::getSingleton();
//
//	//WheelEnum::ANIMAL_TYPE animalType = hardware.getWinnerAnimalType();
//
//	//WheelEnum::LIGHT_COLOR color = hardware.getLight();
//
//	//WheelEnum::ZXH zxh = hardware.getZXH();
//
//	//WheelEnum::WinMode mode = hardware.getWinMode();
//
//	//UI底部的类型
//	WheelUI::getSingleton().addBottom(WinData::getSingleton());
//
//	return transit<LogiPreRun>();
//}