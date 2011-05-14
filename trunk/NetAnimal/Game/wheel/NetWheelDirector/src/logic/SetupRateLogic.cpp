
#include "NetWheelDirectorStableHeaders.h"
#include "logic/AllLogic.h"
#include "WheelEvents.h"
#include "ScoreManager.h"
#include "LockInterface.h"
#include "CodingFormatInterface.h"
#include "DataServerInterface.h"
#include "logic/Dan1Logic.h"
#include "DataCentreInterface.h"
#include "CommunicateInterface.h"
#include "OperatingPanelInterface.h"
using namespace Orz;

SetupRateLogic::SetupRateLogic(my_context ctx):LogicAdv(ctx)//,_gotoDan(false),_second(-1)
{

	ORZ_LOG_NORMAL_MESSAGE("State In: SetupRateLogic!");

	WheelEnum::Rate rate = WheelEnum::Rate(rand()%5+1);
	Orz::WinData::getInstance().setRate(rate);
	

}
SetupRateLogic::~SetupRateLogic(void)
{



}
void SetupRateLogic::exit(void)
{

}

sc::result SetupRateLogic::react(const UpdateEvt & evt)
{

	//if(!_hardware->wait(evt.getInterval()))
	//{
	//	return transit<TimeLogic>();
	//}

	return transit<TimeLogic>();

}