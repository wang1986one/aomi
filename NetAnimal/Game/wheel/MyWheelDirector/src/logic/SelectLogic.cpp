
#include "MyWheelDirectorStableHeaders.h"
#include "logic/AllLogic.h"
#include "WheelEvents.h"
#include "WMHardwareInterface.h"
#include "ScoreInterface.h"
using namespace Orz;



SelectLogic::SelectLogic(my_context ctx):LogicAdv(ctx), _allTime(10.0f),_state(SelectScene)
#ifdef _GAME1
,_sceneMsg(0)
#endif
{

	ORZ_LOG_NORMAL_MESSAGE("State In: SelectLogic!");
	getOwner()->setSelectVisible(true);




}



sc::result SelectLogic::react(const UpdateEvt & evt)
{


	if(_state == SelectScene)
	{
		_allTime -= evt.getInterval();

#ifdef _GAME1
		if(_sceneMsg != 0)
		{
			getOwner()->enableScene(_sceneMsg);

#else
		if(!_sceneMsg.first.empty())
		{
			getOwner()->enableScene(_sceneMsg.first, _sceneMsg.second);

#endif
			_state = HardwareTest;
			WMHardwareInterface * hardware = getOwner()->getHardware()->queryInterface<WMHardwareInterface>();
			hardware->start(WMHardwareInterface::Step0);
			return forward_event();
		}
		if(_allTime<=0)
		{
#ifdef _GAME1
			_sceneMsg = 4;
#else
			_sceneMsg.first = "WheelScene2";
			_sceneMsg.second = true;
#endif
		}

		return forward_event();
	}else if(_state == HardwareTest)
	{
		WMHardwareInterface * hardware = getOwner()->getHardware()->queryInterface<WMHardwareInterface>();
		if(!hardware->wait(evt.getInterval()))
		{
			return transit< 
				SetupDataLogic
			>();

		}
	}


	return forward_event();

}
#ifdef _GAME1

sc::result SelectLogic::react(const LogicEvent::F1 & evt)
{

	_sceneMsg = 4;
	return forward_event();
}
sc::result SelectLogic::react(const LogicEvent::F2 & evt)
{

	_sceneMsg = 5;
	return forward_event();
}
sc::result SelectLogic::react(const LogicEvent::F3 & evt)
{
	_sceneMsg = 6;
	return forward_event();
}

#else
sc::result SelectLogic::react(const LogicEvent::F1 & evt)
{

	_sceneMsg.first = "WheelScene2";
	_sceneMsg.second = true;
	return forward_event();
}
sc::result SelectLogic::react(const LogicEvent::F2 & evt)
{

	_sceneMsg.first = "HunterScene";
	_sceneMsg.second = false;
	return forward_event();
}
sc::result SelectLogic::react(const LogicEvent::F3 & evt)
{
	return forward_event();
}

#endif

void SelectLogic::exit(void)
{
	/*CommunicateInterface * communicate = getOwner()->getHardware()->queryInterface<CommunicateInterface>();


	CommunicateInterface::Data data;

	data.setData(CommunicateInterface::SETUP_ZSF, 0);
	data.setData(CommunicateInterface::SETUP_ZXF, 0);
	data.setData(CommunicateInterface::SETUP_ZSB, 0);
	data.setData(CommunicateInterface::SETUP_ZXB, 0);
	data.setData(CommunicateInterface::SETUP_ZYF, 0);
	data.setData(CommunicateInterface::SETUP_ZTF, 0);
	data.setData(CommunicateInterface::SETUP_WHAT, 0);
	data.setData(CommunicateInterface::SETUP_TMS, 0);


	communicate->setupData(CommunicateInterface::Panel2, data);*/
	getOwner()->setSelectVisible(false);

	Orz::ComponentPtr scoreComp = Orz::ComponentFactories::getInstance().create("Score");
	ScoreInterface  * score = scoreComp->queryInterface<ScoreInterface>();
	score->clear();
	score->setDefault();

	WMHardwareInterface * hardware = getOwner()->getHardware()->queryInterface<WMHardwareInterface>();
	hardware->end();
}


SelectLogic::~SelectLogic(void)
{

}
