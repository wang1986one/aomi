#ifndef __Orz_SelectLogic_h__
#define __Orz_SelectLogic_h__

#include "MyWheelDirectorStableHeaders.h"
#include "WheelLogic.h"
namespace Orz
{
class LogoLogic;
class SelectLogic: public FSM::LogicAdv<SelectLogic, WheelLogic> 
{
public:
	
		SelectLogic(my_context ctx);
		~SelectLogic(void);
		typedef boost::mpl::list< sc::custom_reaction< LogicEvent::ClickButton > , sc::custom_reaction< UpdateEvt > > reactions;
		
		
		sc::result react(const LogicEvent::ClickButton & evt);
		sc::result react(const UpdateEvt & evt);
	
		
private:
	TimeType _allTime;
};


}


#endif