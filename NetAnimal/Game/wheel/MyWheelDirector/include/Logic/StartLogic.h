#ifndef __Orz_StartLogic_h__
#define __Orz_StartLogic_h__	

#include "WheelLogic.h"
#include "TasksManager.h"
#include "GameLogic.h"
#include "WheelAnimalProcess.h"
namespace Orz
{


	class StartLogic: public FSM::LogicAdv<StartLogic, GameLogic>//, public UpdateToEnable<LogiLogo>
	{
	public:
		StartLogic(my_context ctx);
		~StartLogic(void);
		typedef boost::mpl::list< sc::custom_reaction< UpdateEvt > , sc::custom_reaction< LogicEvent::ClickButton > , sc::custom_reaction< LogicEvent::Dan1 >, sc::custom_reaction< LogicEvent::Dan2 >/* *//*, sc::custom_reaction< SetMode> ,sc::custom_reaction< HowWin >, sc::custom_reaction< AskTime > , */> reactions;
		sc::result react(const UpdateEvt & evt)	;
	 /*   sc::result react(const LogicEvent::HowWin & evt);*/
	//	sc::result react(const LogicEvent::AskTime & evt);
		sc::result react(const LogicEvent::ClickButton & evt);
		sc::result react(const LogicEvent::Dan1 & evt);
		sc::result react(const LogicEvent::Dan2 & evt);
		void exit(void);
	private:

		
		SoundPlayerPtr _startMusic; 
		ProcessPtr _process;
		//Orz::ComponentPtr _table;
		//Orz::ComponentPtr _lock;
		//
		//Orz::ComponentPtr _format;//Comp = Orz::ComponentFactories::getInstance().create("Format");
		bool _gotoDan;
	
	};
}
#endif