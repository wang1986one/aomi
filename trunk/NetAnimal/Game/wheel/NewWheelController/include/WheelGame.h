#ifndef __Orz_WheelGame_h__
#define __Orz_WheelGame_h__	

#include "WheelClockListener.h"

#include "WheelControllerConfig.h"
#include "WheelEngineListener.h"
#include "WheelGameInterface.h"
#include "WheelClock.h"
#include "NewHardware.h"
namespace Orz
{
	class WheelEngineInterface;

	
	
	typedef boost::shared_ptr<WheelEngineInterface> WheelEngineInterfacePtr;
	//typedef boost::shared_ptr<WheelGameInterface> WheelGameInterfacePtr;


	class _OrzNewWheelControlleExport WheelGame:  public WheelGameInterface/*, public WheelEngineListener*/, public WheelClockListener
	{
	public:
		virtual ~WheelGame(void);
		WheelGame(EventWorld * world, WheelEngineInterfacePtr engine, WheelClockPtr clock);
	
	public:

		virtual void clockChanged(int second);
	
		/*void setMenuDataVisible(bool visible);*/

		void setLogoShow(bool show);
	
		void setAllSecond(int second);

		void addBottomToUI(void);

		void resetClock(void);

		void setStartUIVisible(bool visible);
		void setEndUIVisible(bool visible);
		void updateClock(TimeType interval);
		void update(TimeType interval);

		void runWinner(void);
		//bool canAction(void);

		EventWorld * getWorld(void) const;

		

		void answerTime(void);
		

	private:
		WheelEngineInterfacePtr _engine;
		EventWorld * _world;
		WheelClockPtr _clock;
	
	};

	
}

#endif


//
//#ifndef __Orz_WheelGame_h__
//#define __Orz_WheelGame_h__	
//
//
//#include "WheelControllerConfig.h"
//#include "WheelGameInterface.h"
//#include "WheelAnimalProcess.h"
//namespace Orz
//{
//	class _OrzNewWheelControlleExport WheelGame:public WheelGameInterface
//	{
//	public:
//		WheelGame();
//		~WheelGame(void);
//	private:
//		EventWorld * _world;
//	};
//}
//
//#endif

