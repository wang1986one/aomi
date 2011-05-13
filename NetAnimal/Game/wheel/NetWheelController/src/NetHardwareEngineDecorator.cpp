#include "NetWheelControllerStableHeaders.h"
#include "NetHardwareEngineDecorator.h"
#include <orz/View_SingleChip/SingleChipManager.h>
#include "WinData.h"
#include "NetHardware.h"
#include "WheelEvents.h"
#include "F6TableInterface.h"
using namespace Orz;



NetHardwareEngineDecorator::NetHardwareEngineDecorator(WheelEngineInterfacePtr engine):_engine(engine),_currTime(0.f)
{
	//Orz::SingleChipManager::getSingleton().addListener(this);
	//NetHardwareCode::getSingleton()._callback = boost::bind(&NetHardwareEngineDecorator::dealMassage,this,_1); 
	_f6table = Orz::ComponentFactories::getInstance().create("Table");
}



NetHardwareEngineDecorator::~NetHardwareEngineDecorator(void)
{

	//Orz::SingleChipManager::getSingleton().removeListener(this);
	//NetHardwareCode::getSingleton()._callback.reset();
}


void NetHardwareEngineDecorator::startGame(size_t time)
{
	if(_engine)
		_engine->startGame(time);
}


//
//void NetHardwareEngineDecorator::clickButton(int id, int button)
//{
//	if(_engine)
//		_engine->clickButton(id, button);
//
//}
void NetHardwareEngineDecorator::runGame(void)
{
	if(_engine)
		_engine->runGame();

}

TimeType NetHardwareEngineDecorator::getTime(void) const
{
	if(_engine)
		return _engine->getTime();
	return 30.f;

}



void NetHardwareEngineDecorator::doExecute(Event * evt)
{
	if(Orz::WheelEvents::in(evt))
	{
		
		if(WheelEvents::getMsg(evt) == WheelEvents::PROCESS_READY_ENABLE)
		{

			F6TableInterface * f6table = _f6table->queryInterface<F6TableInterface>();
			int time = f6table->getData(F6TableInterface::DaoShuShiJian);
			enableUpdate();
			_currTime = 0.f;
			startGame(time);
			
		}


	}
}



void NetHardwareEngineDecorator::doEnable(void)
{
	setChannel(EventChannel::create().addUserChannel<CHANNEL_PROCESS>());
	_currTime = 0.f;
}


void NetHardwareEngineDecorator::doDisable(void)
{

}



void NetHardwareEngineDecorator::doFrame(unsigned int step)
{
	
	_currTime+=step* WORLD_UPDATE_INTERVAL;
	if(_currTime >= getTime())
	{
		runGame();
		disableUpdate();
	}
}



