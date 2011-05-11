
#include "MyWheelDirectorStableHeaders.h"
#include "logic/AllLogic.h"
#include "WheelEvents.h"
#include "ScoreManager.h"
#include "LockInterface.h"
#include "CodingFormatInterface.h"
#include "DataServerInterface.h"
#include "F6TableInterface.h"
#include "logic/Dan1Logic.h"
using namespace Orz;


SetupHardwareLogic::SetupHardwareLogic(my_context ctx):LogicAdv(ctx)//,_gotoDan(false),_second(-1)
{


	
	Orz::ComponentPtr table = Orz::ComponentFactories::getInstance().create("Table");
	F6TableInterface * f6 = table->queryInterface<F6TableInterface>();
	ORZ_LOG_NORMAL_MESSAGE("State In: SetupHardwareLogic!");
	_hardware = getOwner()->getHardware()->queryInterface<WMHardwareInterface>();
	context<GameLogic>().stopQueryId();

	_hardware->getData().clear();
	//f6->getData(F6TableInterface::PoTaiFenShu);
	_hardware->getData().setData(CommunicateInterface::PTFS, f6->getData(F6TableInterface::PoTaiFenShu));
	_hardware->getData().setData(CommunicateInterface::ZDYZ, f6->getData(F6TableInterface::DongWuZuiDaYaZhu));
	_hardware->getData().setData(CommunicateInterface::WHAT1,1);
	_hardware->getData().setData(CommunicateInterface::KFDW,f6->getData(F6TableInterface::KaiFenDanWei));
	_hardware->getData().setData(CommunicateInterface::KFSX,f6->getData(F6TableInterface::KaiFenShangXian));
	_hardware->getData().setData(CommunicateInterface::WHAT2,100);
	_hardware->getData().setData(CommunicateInterface::WHAT3,5);


	_hardware->getData().setData(CommunicateInterface::TBGN,f6->getDataIndex(F6TableInterface::TuiBiGongNeng));
	_hardware->getData().setData(CommunicateInterface::DWZXYZ,f6->getData(F6TableInterface::DongWuZuiXiaoYaZhu));

	_hardware->getData().setData(CommunicateInterface::WHAT4,10);
	_hardware->getData().setData(CommunicateInterface::WHAT5,10);
	_hardware->getData().setData(CommunicateInterface::WHAT6,10);
	_hardware->getData().setData(CommunicateInterface::ZXHZXYZ,1);
	_hardware->getData().setData(CommunicateInterface::ZXZDYZ,f6->getData(F6TableInterface::ZhuangXianZuiDaYaZhu));
	_hardware->getData().setData(CommunicateInterface::HZDYAZ,f6->getData(F6TableInterface::HeZuiDaYaZhu));

	
	_hardware->start(WMHardwareInterface::Step1);

}
SetupHardwareLogic::~SetupHardwareLogic(void)
{



}
void SetupHardwareLogic::exit(void)
{


	_hardware->end();
}

sc::result SetupHardwareLogic::react(const UpdateEvt & evt)
{

	if(!_hardware->wait(evt.getInterval()))
	{
		return transit<SetupRateLogic>();
	}

	return forward_event();



}