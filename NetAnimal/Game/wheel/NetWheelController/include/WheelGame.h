#ifndef __Orz_WheelGame_h__
#define __Orz_WheelGame_h__	

#include "WheelClockListener.h"

#include "WheelControllerConfig.h"
#include "WheelEngineListener.h"
#include "WheelGameInterface.h"
#include "WheelClock.h"
#include "NetHardware.h"
#include <Ogre/Ogre.h>
namespace Orz
{
	class WheelEngineInterface;

	class SMS;
	
	typedef boost::shared_ptr<WheelEngineInterface> WheelEngineInterfacePtr;
	//typedef boost::shared_ptr<WheelGameInterface> WheelGameInterfacePtr;


	class _OrzNetWheelControlleExport WheelGame:  public WheelGameInterface, public WheelClockListener
	{
	public:
#ifdef _GAME1
		void enableScene(int i);
		typedef boost::function< void (int i) >  EnableSceneFunction;
#else
		void enableScene(const std::string & name, bool second);
		typedef boost::function< void (const std::string & , bool) > EnableSceneFunction;
#endif


		virtual ~WheelGame(void);
		WheelGame(EventWorld * world, WheelEngineInterfacePtr engine, WheelClockPtr clock, EnableSceneFunction  enableSceneFunction);
	
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
		//ComponentPtr getHardware(void) const;
		//ComponentPtr getGameLevel(void) const;
		//ComponentPtr getGSM(void) const;
		EventWorld * getWorld(void) const;


		int answerTime(void);

		Ogre::Overlay * getOverlay(void);
	
	//	ComponentPtr getDataServer(void);
	//	void reportEarnings(void);
	private:

		bool report(std::string & result);
		//bool extend(int coins, std::string & result);
		//bool clearData(std::string & result);
		
		//void getSms(const SMS & sms);

		Ogre::OverlayContainer* _select;
		WheelEngineInterfacePtr _engine;
		EventWorld * _world;
		WheelClockPtr _clock;


		//Orz::ComponentPtr _dataServer;
		//Orz::ComponentPtr _hardware;
		//Orz::ComponentPtr _pool;
		//ComponentPtr _gsmComp;
		//ComponentPtr _gameGsmComp;
		ComponentPtr _gameLevel;
		ComponentPtr _table;

		EnableSceneFunction _enableSceneFunction;
		boost::signals2::connection _gsmConnection;
		

	};

	
}

#endif


