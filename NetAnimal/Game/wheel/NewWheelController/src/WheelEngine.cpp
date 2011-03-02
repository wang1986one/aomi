#include "NewWheelControllerStableHeaders.h"
#include "WheelEngine.h"
#include "WheelEvents.h"
//#include "Msg2Account.h"
#include "BlackBoardSystem.h"
#include "WinData.h"
#include "WheelData.h"
#include "WheelEnum.h"
#include <orz/Toolkit_Base/Exception.h>
using namespace Orz;


WheelEngine::WheelEngine(Orz::EventWorld * world):_world(world)
{

}


void WheelEngine::startGame(size_t time)
{

	EventChannel channel = EventChannel::create().addUserChannel<CHANNEL_INTERNAL>();

	Event * evt = NULL;
	

	evt = WheelEvents::createEvent(WheelEvents::SET_TIME);
	evt->setData<int>(int(time));
	evt->setChannel(channel);
	_world->broadcasting(evt);

	evt = WheelEvents::createEvent(WheelEvents::ASK_TIME);
	evt->setChannel(channel);
	_world->broadcasting(evt);

}
void WheelEngine::pushRate(void)
{

	EventChannel channel = EventChannel::create().addUserChannel<CHANNEL_INTERNAL>();

	Event * evt = NULL;
	evt = WheelEvents::createEvent(WheelEvents::SET_MODE);
	channel.addUserChannel<CHANNEL_PROCESS>();
	evt->setChannel(channel);
	_world->broadcasting(evt);
}
void WheelEngine::runGame(void)
{

	EventChannel channel = EventChannel::create().addUserChannel<CHANNEL_INTERNAL>();

	Event * evt = NULL;
	evt = WheelEvents::createEvent(WheelEvents::HOW_WINNER);
	channel.addUserChannel<CHANNEL_PROCESS>();

	evt->setChannel(channel);
	_world->broadcasting(evt);
}

void WheelEngine::findSC(void)
{

	EventChannel channel = EventChannel::create().addUserChannel<CHANNEL_INTERNAL>();

	Event * evt = NULL;
	evt = WheelEvents::createEvent(WheelEvents::FIND_SC);
	channel.addUserChannel<CHANNEL_PROCESS>();

	evt->setChannel(channel);
	_world->broadcasting(evt);
}



WheelEngine::~WheelEngine(void)
{

}