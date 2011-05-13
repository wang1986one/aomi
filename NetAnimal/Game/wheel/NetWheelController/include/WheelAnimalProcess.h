#ifndef __Orz_Process_h__
#define __Orz_Process_h__
#include "WheelControllerConfig.h"
namespace Orz
{

class ReferenceCount;
typedef boost::shared_ptr<ReferenceCount> ReferenceCountPtr;
class _OrzNetWheelControlleExport Process
{
public:
	Process(EventWorld * world, Event::message_type enable,  Event::message_type disable, TimeType minTime = 0.5f, TimeType maxTime = 1000.0f);
	~Process(void);
	bool update(TimeType interval);

	//void capture(void);
	//void release(void);
private:
	EventWorld * _world;
	//int _captured;
	const TimeType _minTime;
	const TimeType _maxTime;
	TimeType _time;
	Event::message_type _disable;

	boost::scoped_ptr<ReferenceCount>  _count;
};
typedef  boost::shared_ptr<Process > ProcessPtr;
}

	

#endif