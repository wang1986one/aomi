#ifndef __Orz_SetupLogic_h__
#define __Orz_SetupLogic_h__	
#include "WheelLogic.h"
namespace Orz
{


	//打出表单	
	class SetupLogic: public FSM::LogicAdv<SetupLogic, WheelLogic>/*, public WheelEngineListener*/
	{
	public:
		typedef boost::mpl::list< sc::custom_reaction< LogicEvent::GoOutMenu >/* , sc::custom_reaction< HardwareReturn >  , sc::custom_reaction< KeyF4 >*/ > reactions;
		sc::result react(const LogicEvent::GoOutMenu & evt);

		sc::result react(const LogicEvent::HardwareReturn & evt);
		sc::result react(const LogicEvent::ActionOne & evt);
		SetupLogic(my_context ctx);
		~SetupLogic(void);
	
	};




}

#endif