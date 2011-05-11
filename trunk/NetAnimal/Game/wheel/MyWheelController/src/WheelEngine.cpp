#include "MyWheelControllerStableHeaders.h"
#include "WheelEngine.h"
#include "WheelEvents.h"
//#include "Msg2Account.h"
#include "BlackBoardSystem.h"
#include "WinData.h"
#include "WheelData.h"
#include "WheelEnum.h"
#include <orz/Toolkit_Base/Exception.h>
using namespace Orz;


WheelEngine::WheelEngine(Orz::EventWorld * world):_world(world),_time(30.f)
{

}


void WheelEngine::startGame(size_t time)
{

	_time = time;
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


//void WheelEngine::clickButton(int id, int button)
//{
//	EventChannel channel = EventChannel::create().addUserChannel<CHANNEL_INTERNAL>();
//
//	Event * evt = NULL;
//	evt = WheelEvents::createEvent(WheelEvents::CLICK_BUTTON);
//	channel.addUserChannel<CHANNEL_PROCESS>();
//	evt->setChannel(channel);
//	evt->setData<intX2>(intX2(id, button));
//	_world->broadcasting(evt);
//}
//void WheelEngine::pushRate(void)
//{
//
//	EventChannel channel = EventChannel::create().addUserChannel<CHANNEL_INTERNAL>();
//
//	Event * evt = NULL;
//	evt = WheelEvents::createEvent(WheelEvents::SET_MODE);
//	channel.addUserChannel<CHANNEL_PROCESS>();
//	evt->setChannel(channel);
//	_world->broadcasting(evt);
//}
void WheelEngine::runGame(void)
{

	/*EventChannel channel = EventChannel::create().addUserChannel<CHANNEL_INTERNAL>();

	Event * evt = NULL;
	evt = WheelEvents::createEvent(WheelEvents::HOW_WINNER);
	channel.addUserChannel<CHANNEL_PROCESS>();

	evt->setChannel(channel);
	_world->broadcasting(evt);*/
}

TimeType WheelEngine::getTime(void) const
{
	return _time;
}



WheelEngine::~WheelEngine(void)
{

}