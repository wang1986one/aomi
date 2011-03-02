#ifndef __Orz_StartLogic_h__
#define __Orz_StartLogic_h__	

#include "WheelLogic.h"
#include "TasksManager.h"
#include "GameLogic.h"
#include "WheelAnimalProcess.h"
namespace Orz
{


	//ÓÎÏ·µÄlogo
	class StartLogic: public FSM::LogicAdv<StartLogic, GameLogic>//, public UpdateToEnable<LogiLogo>
	{
	public:
		StartLogic(my_context ctx);
		~StartLogic(void);
		typedef boost::mpl::list< sc::custom_reaction< UpdateEvt > , sc::custom_reaction< LogicEvent::AskTime >,sc::custom_reaction< LogicEvent::HowWin > /*, sc::custom_reaction< SetMode> ,sc::custom_reaction< HowWin >, sc::custom_reaction< AskTime > , */> reactions;
		sc::result react(const UpdateEvt & evt)	;
	    sc::result react(const LogicEvent::HowWin & evt);
		sc::result react(const LogicEvent::AskTime & evt);

	private:

		
		ProcessPtr _process;
	
	};
}
#endif