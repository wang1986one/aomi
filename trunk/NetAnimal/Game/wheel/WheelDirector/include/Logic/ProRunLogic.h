#ifndef __Orz_ProRunLogic_h__
#define __Orz_ProRunLogic_h__	

#include "WheelLogic.h"
#include "TasksManager.h"
#include "GameLogic.h"
#include "WheelAnimalProcess.h"
namespace Orz
{

//转庄闲和，动物升起，打雷，彩灯升起等……
class ProRunLogic: public FSM::LogicAdv<ProRunLogic, GameLogic>
{
public:
	ProRunLogic(my_context ctx);
	~ProRunLogic(void);
	
	typedef boost::mpl::list< sc::custom_reaction< UpdateEvt > , sc::custom_reaction< LogicEvent::AskState > > reactions;
	sc::result react(const UpdateEvt & evt);
	sc::result react(const LogicEvent::AskState & evt);
	
private:
	ProcessPtr _process;
};
}
#endif