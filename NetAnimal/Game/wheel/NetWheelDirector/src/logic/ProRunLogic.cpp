
#include "NetWheelDirectorStableHeaders.h"
#include "logic/AllLogic.h"
#include "WheelEvents.h"
#include "CommunicateInterface.h"
#include "WMHardwareInterface.h"
#include "WinData.h"
#include "OperatingPanelInterface.h"
using namespace Orz;
//
//class SetWinner
//{
//public:
//	//TimeType getWaitTime(void) const
//	//{
//	//	return 0.0f;
//	//}
//	SetWinner(void):_communicate(NULL)
//	{
//		//_opComp = Orz::ComponentFactories::getInstance().create("OperatingPanel");
//	}
//	~SetWinner(void)
//	{
//
//	}
//
//	bool send(Orz::CommunicateInterface::PanelID id)
//	{
//		WheelEnum::Winner winner = WinData::getInstance().getWinner();
//		OperatingPanelInterface * operation = //_opComp->queryInterface<OperatingPanelInterface>();
//	//	size_t score = operation->testWinner2Player(CommunicateInterface::PanelID(id), winner);
//		//operation->setScore(id, 0);
//		//operation->addScore(id, score);
//		//_communicate->setWinner( CommunicateInterface::PanelID(id), winner , operation->getScore(id));
//		return false;
//
//
//	}
//	void init(WheelGame * game)
//	{
//		assert(game);
//		_communicate = game->getHardware()->queryInterface<CommunicateInterface>();
//	}
//	//void init(CommunicateInterface * communicate)
//	//{
//	//	_communicate = 
//	//}
//	void exit(void)
//	{
//		
//	}
//
//	bool receive(CommunicateInterface::PackagePtr package, Orz::CommunicateInterface::PanelID id)
//	{
//
//		if(package->getId() == id)
//		{
//
//			return true;
//		}
//
//		return false;
//
//	}
//private:
//	//Orz::ComponentPtr //_opComp;
//	//CommunicateInterface * _communicate;
//		
//};




ProRunLogic::ProRunLogic(my_context ctx):LogicAdv(ctx),_hardware(NULL)
{
	ORZ_LOG_NORMAL_MESSAGE("State In: ProRunLogic!");

	_process.reset( new Process( getOwner()->getWorld(), WheelEvents::PROCESS_PRORUN_ENABLE, WheelEvents::PROCESS_PRORUN_DISABLE, 7.5f, 7.5f));
	
	if(WinData::getInstance().getWinMode() != WheelEnum::NONE)
	{
		//_hardware = getOwner()->getHardware()->queryInterface<WMHardwareInterface>();
		//_hardware->start(WMHardwareInterface::StepLight);
	//	context<GameLogic>().stopQueryId();
	}

	
}


ProRunLogic::~ProRunLogic(void)
{
	ORZ_LOG_NORMAL_MESSAGE("State Out: ProRunLogic!");
}

sc::result ProRunLogic::react(const UpdateEvt & evt)
{
	if(_hardware)
	{
		bool ret = _hardware->wait(evt.getInterval());
	}



	if(_process->update(evt.getInterval()))
		return forward_event();

	
	return transit<RunLogic>();
	//return transit<RunLogic>();	
}


void ProRunLogic::exit(void)
{
	/*if(_hardware)
	{
		context<GameLogic>().startQueryId();
		_hardware->end();
	}*/
}