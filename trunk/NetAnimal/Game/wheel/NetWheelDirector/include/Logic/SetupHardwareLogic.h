#ifndef __Orz_SetupHardwareLogic_h__
#define __Orz_SetupHardwareLogic_h__	

#include "WheelLogic.h"
#include "TasksManager.h"
#include "StartLogic.h"
#include "WheelAnimalProcess.h"
#include "WMHardwareInterface.h"
namespace Orz
{


	////…Ë÷√”≤º˛ Ù–‘
	//class SetupHardwareLogic: public FSM::LogicAdv<SetupHardwareLogic, StartLogic>
	//{
	//public:
	//	
	//	SetupHardwareLogic(my_context ctx);
	//	~SetupHardwareLogic(void);
	//	typedef boost::mpl::list< sc::custom_reaction< UpdateEvt > > reactions;
	//	
	//	
	//	sc::result react(const UpdateEvt & evt);
	//
	//	void exit(void);

	//private:
	//	WMHardwareInterface * _hardware;
	//	Orz::ComponentPtr _table;
	//};
}
#endif