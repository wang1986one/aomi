
#ifndef __Orz_TimeLogic_h__
#define __Orz_TimeLogic_h__	

#include "WheelLogic.h"
#include "TasksManager.h"
#include "StartLogic.h"
#include "WheelAnimalProcess.h"
#include "CommunicateInterface.h"
namespace Orz
{


	class TimeLogic: public FSM::LogicAdv<TimeLogic, StartLogic >
	{
	public:
		TimeLogic(my_context ctx);
		~TimeLogic(void);
		typedef boost::mpl::list< sc::custom_reaction< UpdateEvt > ,  sc::custom_reaction< LogicEvent::Dan1 >, sc::custom_reaction< LogicEvent::Dan2 >/* *//*, sc::custom_reaction< SetMode> ,sc::custom_reaction< HowWin >, sc::custom_reaction< AskTime > , */> reactions;
		sc::result react(const UpdateEvt & evt)	;
		sc::result react(const LogicEvent::Dan1 & evt);
		sc::result react(const LogicEvent::Dan2 & evt);
		void exit(void);
	private:

		
		SoundPlayerPtr _startMusic; 
		//ProcessPtr _process;
		bool _gotoDan;
		CommunicateInterface * _communicate;
		int _second;
	
	};
}
#endif