#ifndef __Orz_SetupRateLogic_h__
#define __Orz_SetupRateLogic_h__	

#include "WheelLogic.h"
#include "TasksManager.h"
#include "StartLogic.h"
#include "WheelAnimalProcess.h"
#include "WMHardwareInterface.h"
namespace Orz
{


	//ÓÎÏ·µÄlogo
	class SetupRateLogic: public FSM::LogicAdv<SetupRateLogic, StartLogic>//, public UpdateToEnable<LogiLogo>
	{
	public:
		
		SetupRateLogic(my_context ctx);
		~SetupRateLogic(void);
		typedef boost::mpl::list< sc::custom_reaction< UpdateEvt > > reactions;
		
		
		sc::result react(const UpdateEvt & evt);
	
		void exit(void);

	private:
		
		WMHardwareInterface * _hardware;
		bool _updateHardware;
	};
}
#endif