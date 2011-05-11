#ifndef __Orz_WheelLogic_h__
#define __Orz_WheelLogic_h__
//#include "Engine.h"
//#include "WheelUI.h"
//#include "LogiEvent.h"
#include "MyWheelDirectorStableHeaders.h"
#include "WheelGame.h"
#include "CommunicateInterface.h"
#include "logic/LogicEvent.h"
namespace Orz
{



	class WheelGame;
	class GameLogic;
	class LogoLogic;
	
	class SelectLogic;
	class WheelLogic: public FSM::MainLogic<WheelLogic, WheelGame, SelectLogic/**/> 
	{
	public:
		typedef boost::mpl::list< sc::custom_reaction< LogicEvent::WheelStart >, sc::custom_reaction< LogicEvent::SetTime >  > reactions;

		sc::result react(const LogicEvent::WheelStart & evt);
		sc::result react(const LogicEvent::SetTime & evt);

		WheelLogic(void);
		~WheelLogic(void);

	};






	


	


	



 


	//	class 
	//	class OTDFighterTouch;





	



	



 


	//	class 
	//	class OTDFighterTouch;
}

//#include "logic/AllLogic.h"
#endif