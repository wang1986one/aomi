#ifndef __Orz_EndLogic_h__
#define __Orz_EndLogic_h__	

#include "WheelLogic.h"
#include "TasksManager.h"
#include "GameLogic.h"
#include "WheelAnimalProcess.h"
namespace Orz
{

	//×°ÅÌµÄÐý×ª
	class EndLogic: public FSM::LogicAdv<EndLogic, GameLogic>
	{
	public:
		EndLogic(my_context ctx);
		~EndLogic(void);
		typedef boost::mpl::list< sc::custom_reaction< UpdateEvt > , sc::custom_reaction< LogicEvent::AskState > > reactions;
		sc::result react(const UpdateEvt & evt);
		sc::result react(const LogicEvent::AskState & evt);
	private:
		ProcessPtr _process;
		TimeType _allTime;


	};
}
#endif