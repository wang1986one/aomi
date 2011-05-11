#ifndef __Orz_LogoLogic_h__
#define __Orz_LogoLogic_h__	

#include "WheelLogic.h"
#include "TasksManager.h"
#include "GameLogic.h"
#include "WheelAnimalProcess.h"
#include "WMHardwareInterface.h"
namespace Orz
{


	//ÓÎÏ·µÄlogo
	class LogoLogic: public FSM::LogicAdv<LogoLogic, GameLogic>//, public UpdateToEnable<LogiLogo>
	{
	public:
		
		LogoLogic(my_context ctx);
		~LogoLogic(void);
		typedef boost::mpl::list< sc::custom_reaction< UpdateEvt >, sc::custom_reaction< LogicEvent::AskTime  > > reactions;
		
		
		sc::result react(const UpdateEvt & evt);
		sc::result react(const LogicEvent::AskTime & evt);
	
		void exit(void);

	private:
		ProcessPtr _process;
		bool _gotoReady;
		
		bool _ret;
	/*	WMHardwareInterface * _hardware;
		bool _updateHardware;*/
	};
}
#endif