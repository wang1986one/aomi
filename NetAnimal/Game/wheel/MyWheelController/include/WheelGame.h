#ifndef __Orz_WheelGame_h__
#define __Orz_WheelGame_h__	

#include "WheelClockListener.h"

#include "WheelControllerConfig.h"
#include "WheelEngineListener.h"
#include "WheelGameInterface.h"
#include "WheelClock.h"
#include "MyHardware.h"
#include <Ogre/Ogre.h>
namespace Orz
{
	class WheelEngineInterface;

	
	
	typedef boost::shared_ptr<WheelEngineInterface> WheelEngineInterfacePtr;
	//typedef boost::shared_ptr<WheelGameInterface> WheelGameInterfacePtr;


	class _OrzMyWheelControlleExport WheelGame:  public WheelGameInterface, public WheelClockListener
	{
	public:
		//typedefounction<> ;
	public:
		virtual ~WheelGame(void);
		WheelGame(EventWorld * world, WheelEngineInterfacePtr engine, WheelClockPtr clock, boost::function< void (const std::string & , bool) >  enableSceneFunction);
	
	public:

		virtual void clockChanged(int second);


		void setLogoShow(bool show);
	
		void setAllSecond(int second);

		void addBottomToUI(void);
		void setSelectVisible(bool visible);
		void resetClock(void);

		void setStartUIVisible(bool visible);
		void setEndUIVisible(bool visible);
		void updateClock(TimeType interval);
		void update(TimeType interval);
		
		void runWinner(void);

		EventWorld * getWorld(void) const;
		Orz::ComponentPtr getJs(void) const;
		
		void enableScene(const std::string & name, bool second);
		int answerTime(void);

		Ogre::Overlay * getOverlay(void);
	
	//	ComponentPtr getDataServer(void);
	private:

		Ogre::OverlayContainer* _select;
		WheelEngineInterfacePtr _engine;
		EventWorld * _world;
		WheelClockPtr _clock;
		boost::function< void (const std::string & , bool) >  _enableSceneFunction;
		//Orz::ComponentPtr _dataServer;
		Orz::ComponentPtr _jsComp;
		
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
//	class _OrzMyWheelControlleExport WheelGame:public WheelGameInterface
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

