#ifndef __Orz_StartLogic_h__
#define __Orz_StartLogic_h__	

#include "WheelLogic.h"
#include "TasksManager.h"
#include "GameLogic.h"
#include "WheelAnimalProcess.h"
#include "CommunicateInterface.h"
namespace Orz
{


	class TimeLogic;
	class SetupRateLogic;
	class StartLogic: public FSM::LogicAdv<StartLogic, GameLogic, SetupRateLogic>//, public UpdateToEnable<LogiLogo>
	{
	public:
		typedef boost::mpl::list< sc::custom_reaction< UpdateEvt > > reactions;
		sc::result react(const UpdateEvt & evt)	;
		StartLogic(my_context ctx);
		~StartLogic(void);
		void exit(void);
		
	private:

		ProcessPtr _process;
		
	};
}
#endif