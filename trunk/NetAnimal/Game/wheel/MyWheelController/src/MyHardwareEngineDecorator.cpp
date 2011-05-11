#include "MyWheelControllerStableHeaders.h"
#include "MyHardwareEngineDecorator.h"
#include <orz/View_SingleChip/SingleChipManager.h>
#include "WinData.h"
#include "MyHardware.h"
#include "WheelEvents.h"
#include "F6TableInterface.h"
using namespace Orz;



MyHardwareEngineDecorator::MyHardwareEngineDecorator(WheelEngineInterfacePtr engine):_engine(engine),_currTime(0.f)
{
	//Orz::SingleChipManager::getSingleton().addListener(this);
	//MyHardwareCode::getSingleton()._callback = boost::bind(&MyHardwareEngineDecorator::dealMassage,this,_1); 
	_f6table = Orz::ComponentFactories::getInstance().create("Table");
}



MyHardwareEngineDecorator::~MyHardwareEngineDecorator(void)
{

	//Orz::SingleChipManager::getSingleton().removeListener(this);
	//MyHardwareCode::getSingleton()._callback.reset();
}


void MyHardwareEngineDecorator::startGame(size_t time)
{
	if(_engine)
		_engine->startGame(time);
}


//
//void MyHardwareEngineDecorator::clickButton(int id, int button)
//{
//	if(_engine)
//		_engine->clickButton(id, button);
//
//}
void MyHardwareEngineDecorator::runGame(void)
{
	if(_engine)
		_engine->runGame();

}

TimeType MyHardwareEngineDecorator::getTime(void) const
{
	if(_engine)
		return _engine->getTime();
	return 30.f;

}



void MyHardwareEngineDecorator::doExecute(Event * evt)
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



void MyHardwareEngineDecorator::doEnable(void)
{
	setChannel(EventChannel::create().addUserChannel<CHANNEL_PROCESS>());
	_currTime = 0.f;
}


void MyHardwareEngineDecorator::doDisable(void)
{

}



void MyHardwareEngineDecorator::doFrame(unsigned int step)
{
	
	_currTime+=step* WORLD_UPDATE_INTERVAL;
	if(_currTime >= getTime())
	{
		runGame();
		disableUpdate();
	}
}



