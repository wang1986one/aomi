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
		typedef boost::mpl::list< sc::custom_reaction< UpdateEvt > , sc::custom_reaction< LogicEvent::AskState >, sc::custom_reaction< LogicEvent::AskTime >, sc::custom_reaction<  LogicEvent::ActionTwo >,sc::custom_reaction<  LogicEvent::ActionThree >, sc::custom_reaction< LogicEvent::HowWin > /*, sc::custom_reaction< SetMode> ,sc::custom_reaction< HowWin >, sc::custom_reaction< AskTime > , */> reactions;
		sc::result react(const UpdateEvt & evt)	;
	    sc::result react(const LogicEvent::AskState & evt);
	    sc::result react(const LogicEvent::AskTime & evt);
	    sc::result react(const LogicEvent::ActionTwo & evt);
	    sc::result react(const LogicEvent::ActionThree & evt);
	    sc::result react(const LogicEvent::HowWin & evt);

	//	void exit(void);

	private:

		enum TheEvent
		{
			NONE,
			ACTION2,
			ACTION3
		};
		TheEvent _state;
		ProcessPtr _process;
	
	};
}
#endif