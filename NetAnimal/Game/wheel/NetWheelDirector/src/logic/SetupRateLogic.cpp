
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

	Orz::ComponentPtr opComp = Orz::ComponentFactories::getInstance().create("OperatingPanel");
	OperatingPanelInterface * operation = opComp->queryInterface<OperatingPanelInterface>();
	
	Orz::ComponentPtr dataComp = Orz::ComponentFactories::getInstance().create("DataCentre");
	Orz::DataCentreInterface * data = dataComp->queryInterface<DataCentreInterface>();
	ORZ_LOG_NORMAL_MESSAGE("State In: SetupHardwareLogic!");
	CommunicateInterface * communicate = getOwner()->getHardware()->queryInterface<CommunicateInterface>();
	_hardware = getOwner()->getHardware()->queryInterface<WMHardwareInterface>();
	
	_hardware->getData().clear();
	WheelEnum::Rate rate = WheelEnum::Rate(rand()%5+1);
	Orz::WinData::getInstance().setRate(rate);
	operation->setRate(rate);
	for(int i =0; i<3; i++)
	{
		for(int j =0; j<4; j++)
		{

			WheelEnum::AnimalItem item(static_cast<WheelEnum::TYPE>(j), static_cast<WheelEnum::LIGHT_COLOR>(i));
			int r = data->getRate(data->item2Id(item) ,rate);
			_hardware->getData().setData(communicate->getCommunicateId(item), r);
		}
	}

	
	_hardware->getData().setData(12, data->getWinnerRate(WheelEnum::Dealer));
	_hardware->getData().setData(13, data->getWinnerRate(WheelEnum::Draw));
	_hardware->getData().setData(14, data->getWinnerRate(WheelEnum::Player));
	_hardware->start(WMHardwareInterface::Step2);

}
SetupRateLogic::~SetupRateLogic(void)
{



}
void SetupRateLogic::exit(void)
{

	_hardware->end();
}

sc::result SetupRateLogic::react(const UpdateEvt & evt)
{

	if(!_hardware->wait(evt.getInterval()))
	{
		return transit<TimeLogic>();
	}

	return forward_event();

}