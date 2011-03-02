#ifndef __Orz_MenuLogic_h__
#define __Orz_MenuLogic_h__	
#include "WheelLogic.h"
#include "WheelDirectorStableHeaders.h"
namespace Orz
{


	//打出表单	
	class MenuLogic: public FSM::LogicAdv<MenuLogic, WheelLogic>//, public WheelEngineListener
	{
	public:
		typedef boost::mpl::list< sc::custom_reaction< LogicEvent::GoOutMenu >,sc::custom_reaction< LogicEvent::DataMenu >, sc::custom_reaction< LogicEvent::HardwareReturn >  , sc::custom_reaction< LogicEvent::ActionOne >/* */> reactions;
		sc::result react(const LogicEvent::GoOutMenu & evt);
		sc::result react(const LogicEvent::DataMenu & evt);
		sc::result react(const LogicEvent::HardwareReturn & evt);
		sc::result react(const LogicEvent::ActionOne & evt);
		/*sc::result react(const KeyF4 & evt);*/

		//void push_data(int id, ACCOUNTS_ITEM item, unsigned long data);
		//void push_total(ACCOUNTS_ITEM item, unsigned long data );
		MenuLogic(my_context ctx);
		~MenuLogic(void);
	
	};




}

#endif