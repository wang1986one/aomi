
#include "MyWheelDirectorStableHeaders.h"
#include "logic/AllLogic.h"
#include "WheelEvents.h"
#include "ScoreManager.h"
#include "LockInterface.h"
#include "CodingFormatInterface.h"
#include "DataServerInterface.h"
#include "logic/Dan1Logic.h"
using namespace Orz;

StartLogic::StartLogic(my_context ctx):LogicAdv(ctx)//,_gotoDan(false),_second(-1)
{
	
	_process.reset( new Process( getOwner()->getWorld(), WheelEvents::PROCESS_START_ENABLE, WheelEvents::PROCESS_START_DISABLE));
	ORZ_LOG_NORMAL_MESSAGE("State In: StartLogic!");

	context<GameLogic>().stopQueryId();


	
	ComponentPtr opComp = Orz::ComponentFactories::getInstance().create("OperatingPanel");
	OperatingPanelInterface * operation = opComp->queryInterface<OperatingPanelInterface>();
	operation->reset();
	
}

void StartLogic::exit(void)
{
	
	context<GameLogic>().startQueryId();
	
}

StartLogic::~StartLogic(void)
{
	_process.reset();
	
	
}

sc::result StartLogic::react(const UpdateEvt & evt)
{
	if(_process->update(evt.getInterval()))
		return forward_event();

	return forward_event();
}