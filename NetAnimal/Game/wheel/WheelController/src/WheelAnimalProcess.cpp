#include "WheelControllerStableHeaders.h"
#include "WheelAnimalProcess.h"
#include "WheelEvents.h"
#include "ReferenceCount.h"
	
using namespace Orz;

Process::Process(EventWorld * world, Event::message_type enable,  Event::message_type disable, TimeType minTime, TimeType maxTime):
_world(world),
_disable(disable),
_minTime(minTime),
_maxTime(maxTime),
_time(0.f),
_count(new ReferenceCount())
{

	Event * evt = WheelEvents::createEvent(enable);

	evt->setChannel(EventChannel::create().addUserChannel<CHANNEL_PROCESS>());
	evt->setData<ReferenceCount*>(_count.get());
	_world->broadcasting(evt);
}
Process::~Process(void)
{
	Event * evt = WheelEvents::createEvent(_disable);
	evt->setChannel(EventChannel::create().addUserChannel<CHANNEL_PROCESS>());
	_world->broadcasting(evt);
}
bool Process::update(TimeType interval)
{
	_time+=interval;
	if(_time < _minTime)
		return true;
	if(_time > _maxTime)
		return false;
	
	if(!_count->hasReferenced())
	{
		return false;
	}
	return true;
}
//
//void Process::capture(void)
//{
//	++_captured;
//}
//void Process::release(void)
//{
//	--_captured;
//}
