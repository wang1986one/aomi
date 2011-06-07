#ifndef __Orz_WheelLogic_h__
#define __Orz_WheelLogic_h__
//#include "Engine.h"
//#include "WheelUI.h"
//#include "LogiEvent.h"
#include "NetWheelDirectorStableHeaders.h"
#include "WheelGame.h"
#include "CommunicateInterface.h"
#include "logic/LogicEvent.h"
#include "RouletteGameInterfaces.h"
namespace Orz
{



	class WheelGame;
	class GameLogic;
	class LogoLogic;
	
	class SelectLogic;
	class WheelLogic: public FSM::MainLogic<WheelLogic, ComponentPtr, SelectLogic> 
	{
	public:
		typedef boost::mpl::list< sc::custom_reaction< LogicEvent::WheelStart >, sc::custom_reaction< LogicEvent::SetTime >  > reactions;

		sc::result react(const LogicEvent::WheelStart & evt);
		sc::result react(const LogicEvent::SetTime & evt);

		RouletteGameInterfaces * game(void);
		RouletteClockInterface * clock(void);
		RouletteUIInterface * ui(void);

		WheelLogic(void);
		~WheelLogic(void);
	private:
		RouletteGameInterfaces * _game;
		RouletteClockInterface * _clock;
		RouletteUIInterface * _ui;

	};






	


	


	



 


	//	class 
	//	class OTDFighterTouch;





	



	



 


	//	class 
	//	class OTDFighterTouch;
}

//#include "logic/AllLogic.h"
#endif