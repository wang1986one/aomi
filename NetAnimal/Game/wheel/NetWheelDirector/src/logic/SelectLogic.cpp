
#include "NetWheelDirectorStableHeaders.h"
#include "logic/AllLogic.h"
#include "WheelEvents.h"
#include "WMHardwareInterface.h"
#include "ScoreInterface.h"
using namespace Orz;



SelectLogic::SelectLogic(my_context ctx):LogicAdv(ctx), _allTime(0.0f)
#ifdef _GAME1
,_sceneMsg(0)
#endif
{

	ORZ_LOG_NORMAL_MESSAGE("State In: SelectLogic!");
	//context<WheelLogic>().game()->setSelectVisible(true);


	
	_sceneMsg.first = "HunterScene";
	_sceneMsg.second = false;
}



sc::result SelectLogic::react(const UpdateEvt & evt)
{
	

	//_allTime -= evt.getInterval();

#ifdef _GAME1
	if(_sceneMsg != 0)
	{
		context<WheelLogic>().game()->enableScene(_sceneMsg);

#else
	if(!_sceneMsg.first.empty())
	{
		context<WheelLogic>().game()->enableScene(_sceneMsg.first, _sceneMsg.second);

#endif
		return transit< GameLogic>();
	}
	if(_allTime<=0)
	{
#ifdef _GAME1
		_sceneMsg = 4;
#else
		_sceneMsg.first = "HunterScene";
		_sceneMsg.second = false;
#endif
		
		context<WheelLogic>().game()->enableScene(_sceneMsg.first, _sceneMsg.second);
		return transit< GameLogic>();
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

	ORZ_LOG_NORMAL_MESSAGE("const LogicEvent::F2 & evt");
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

	//context<WheelLogic>().game()->setSelectVisible(false);



}


SelectLogic::~SelectLogic(void)
{

}
