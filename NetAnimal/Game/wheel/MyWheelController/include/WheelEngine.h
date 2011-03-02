#ifndef __Orz_WheelEngine_h__
#define __Orz_WheelEngine_h__	


#include "WheelControllerConfig.h"
#include "WheelEngineInterface.h"
namespace Orz
{
	class _OrzMyWheelControlleExport WheelEngine:public WheelEngineInterface
	{
	public:
		WheelEngine(Orz::EventWorld * world);
		virtual ~WheelEngine(void);
	private:
	
		
		virtual void startGame(size_t time);
		//virtual void pushRate(void);
		virtual void runGame(void);
		virtual void clickButton(int id, int button);
		virtual TimeType getTime(void) const;
		

		Orz::EventWorld * _world;
	
		WheelEngineListener * _listener;
		TimeType _time;
	//	Accounts _acc;
	};
}

#endif

