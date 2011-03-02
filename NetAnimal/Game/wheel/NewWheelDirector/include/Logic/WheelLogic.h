#ifndef __Orz_WheelLogic_h__
#define __Orz_WheelLogic_h__
//#include "Engine.h"
//#include "WheelUI.h"
//#include "LogiEvent.h"
#include "NewWheelDirectorStableHeaders.h"
#include "WheelGame.h"
#include "logic/LogicEvent.h"
namespace Orz
{



	class WheelGame;
	class GameLogic;
	class LogoLogic;
	


	class WheelLogic: public FSM::MainLogic<WheelLogic, WheelGame, GameLogic/**/>//, public MyClockListener
	{
	public:
		typedef boost::mpl::list< sc::custom_reaction< LogicEvent::WheelStart >, sc::custom_reaction< LogicEvent::SetTime >  > reactions;

		sc::result react(const LogicEvent::WheelStart & evt);
		sc::result react(const LogicEvent::SetTime & evt);

	
	};






	


	


	



 


	//	class 
	//	class OTDFighterTouch;





	



	



 


	//	class 
	//	class OTDFighterTouch;
}

//#include "logic/AllLogic.h"
#endif