#include "NewWheelControllerStableHeaders.h"
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
	/*if(Orz::WheelEvents::in(evt))
	{
		
		if(WheelEvents::getMsg(evt) == WheelEvents::PROCESS_READY_ENABLE)
		{
			enableUpdate();
			_currTime = 0.f;

			Orz::MsgBuffer head;
			Orz::MsgBuffer msg;


			{
				
				head.clear();
				msg.clear();
				head,0,0,ASK_TIME;
				sendMsg(head, msg);
			}

			{
			
				head.clear();
				msg.clear();
				head,0,0,SET_MODE;
				msg,1,14;
				sendMsg(head, msg);
			}
			
		}


	}*/
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
void AutoEngineDecorator::pushRate(void)
{

	_engine->pushRate();
}
void AutoEngineDecorator::runGame(void)
{
	_engine->runGame();

}

void AutoEngineDecorator::findSC(void)
{
	_engine->findSC();
}

void AutoEngineDecorator::doFrame(unsigned int step)
{
	/*static int i = 0;
	_currTime+=step* WORLD_UPDATE_INTERVAL;
	if(_currTime >= 30.001f)
	{
		
		int san = i%3;
		int si = i%4;
		Orz::MsgBuffer head;
		Orz::MsgBuffer msg;
		head,0,0,HOW_WINNER;
		msg, san, _getWinMode(), rand()%100,10;
		++i;
		sendMsg(head, msg);
		_currTime = 0.f;
		this->disableUpdate();
	}*/
}

