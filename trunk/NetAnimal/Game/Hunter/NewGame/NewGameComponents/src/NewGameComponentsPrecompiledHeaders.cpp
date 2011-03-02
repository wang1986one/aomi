#include "NewGameComponentsStableHeaders.h"

namespace Orz
{
	
	bool ___enable(void)
	{
		return true;
	}
	bool ___update(TimeType t)
	{
		return false;
	}
	void ___disable(void)
	{}

	
	bool ___updateEventQueue(TimeType t, TimeType & currTime, EventQueue & eventQueue)
	{
		currTime += t;
		if(eventQueue.empty())
			return false;

		
		if(currTime >= eventQueue.front().first)
		{
			eventQueue.front().second();
			eventQueue.pop();
			currTime = 0.0f;
		}
		
		return true;
	
	}


	
}