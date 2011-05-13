#include "NetWheelControllerStableHeaders.h"
#include "AutoEngineDecorator.h"
#include "WheelEnum.h"
#include "WheelEvents.h"

using namespace Orz;

//void AutoEngineDecorator::addListener(WheelEngineListener * listener)
//{
//	_engine->addListener(listener);
//}
//void AutoEngineDecorator::removeListener(WheelEngineListener * listener)
//{
//	_engine->removeListener(listener);
//
//}
AutoEngineDecorator::AutoEngineDecorator(WheelEngineInterfacePtr engine):_engine(engine)
{
	/*Orz::IInputManager::getSingleton().addKeyListener(this);*/
}
AutoEngineDecorator::~AutoEngineDecorator(void)
{
	/*Orz::IInputManager::getSingleton().removeKeyListener(this);*/
}


//void AutoEngineDecorator::clickButton(int id, int button)
//{
//	_engine->clickButton(id, button);
//}

//void AutoEngineDecorator::pushMessage(MsgBuffer & buffer)
//{
//	if(_engine)
//		_engine->pushMessage(buffer);
//}
//
//void AutoEngineDecorator::refreshMenuData(void)
//{
//	if(_engine)
//		_engine->refreshMenuData();
//}


void AutoEngineDecorator::doExecute(Event * evt)
{
	if(Orz::WheelEvents::in(evt))
	{
		
		if(WheelEvents::getMsg(evt) == WheelEvents::PROCESS_READY_ENABLE)
		{
			enableUpdate();
			_currTime = 0.f;
			startGame(14);
			
		}


	}
}



void AutoEngineDecorator::doEnable(void)
{
	setChannel(EventChannel::create().addUserChannel<CHANNEL_PROCESS>());
	_currTime = 0.f;
}


void AutoEngineDecorator::doDisable(void)
{

}

void AutoEngineDecorator::startGame(size_t time)
{
	_engine->startGame(time);
}
//void AutoEngineDecorator::pushRate(void)
//{
//
//	_engine->pushRate();
//}
void AutoEngineDecorator::runGame(void)
{
	_engine->runGame();

}

TimeType AutoEngineDecorator::getTime(void)const
{
	std::cout<<_engine->getTime();
	return _engine->getTime();
}

void AutoEngineDecorator::doFrame(unsigned int step)
{
	
	_currTime+=step* WORLD_UPDATE_INTERVAL;
	if(_currTime >= getTime())
	{
		runGame();
	}
}

