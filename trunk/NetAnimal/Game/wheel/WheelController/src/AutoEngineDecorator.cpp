#include "WheelControllerStableHeaders.h"
#include "AutoEngineDecorator.h"
#include "MsgHandler.h"
#include "WheelEnum.h"
#include "WheelEvents.h"

using namespace Orz;

void AutoEngineDecorator::addListener(WheelEngineListener * listener)
{
	_engine->addListener(listener);
}
void AutoEngineDecorator::removeListener(WheelEngineListener * listener)
{
	_engine->removeListener(listener);

}
AutoEngineDecorator::AutoEngineDecorator(WheelEngineInterfacePtr engine):_engine(engine)
{
	/*Orz::IInputManager::getSingleton().addKeyListener(this);*/
}
AutoEngineDecorator::~AutoEngineDecorator(void)
{
	/*Orz::IInputManager::getSingleton().removeKeyListener(this);*/
}

void AutoEngineDecorator::pushMessage(MsgBuffer & buffer)
{
	if(_engine)
		_engine->pushMessage(buffer);
}

void AutoEngineDecorator::refreshMenuData(void)
{
	if(_engine)
		_engine->refreshMenuData();
}


void  AutoEngineDecorator::sendMsg(const Orz::MsgBuffer & head, const Orz::MsgBuffer & msg)
{
	
		MsgHandler handler;


		Orz::MsgBuffer out = handler.encode(head, msg);
		for(size_t i=0; i< out.size(); ++i)
		{
			handler.push(out.at(i));
		}
		if(!handler.empty())
		{
			Orz::MsgBuffer buffer = handler.pop();

			pushMessage(buffer);
		}

}
void AutoEngineDecorator::doExecute(Event * evt)
{
	if(Orz::WheelEvents::in(evt))
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

unsigned char _getWinMode(void)
{

	static unsigned char win[14] ={


		

		
		WheelEnum::GREEN_MONKEY,//hb
		WheelEnum::DOUBLE_GREEN_RABBIT,
		WheelEnum::YELLOW_MONKEY_YELLOW_RABBIT_GREEN_PANDA_YELLOW_LION,//3
		WheelEnum::ALL_MONKEY,
		WheelEnum::G_RED_PANDA,
		WheelEnum::YELLOW_RABBIT ,//lm
		WheelEnum::ALL_GREEN,


		WheelEnum::GREEN_MONKEY,//hb

		WheelEnum::ALL_PANDA,
		WheelEnum::RED_RABBIT_YELLOW_PANDA,//1
		
		WheelEnum::ALL_LION,
		WheelEnum::G_YELLOW_RABBIT,//lm
		WheelEnum::G_GREEN_MONKEY,

		WheelEnum::G_RED_PANDA,

	};
	static unsigned char winmode = 0;
	winmode = winmode%14;
	return win[winmode++];
}
void AutoEngineDecorator::doFrame(unsigned int step)
{
	static int i = 0;
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
	}
}

