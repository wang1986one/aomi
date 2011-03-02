#ifndef __Orz_WinLogic_h__
#define __Orz_WinLogic_h__	

#include "WheelLogic.h"
#include "TasksManager.h"
#include "GameLogic.h"
#include "WheelAnimalProcess.h"
namespace Orz
{

	//×°ÅÌµÄÐý×ª
	class WinLogic: public FSM::LogicAdv<WinLogic, GameLogic>
	{
	public:
		WinLogic(my_context ctx);
		~WinLogic(void);

		typedef boost::mpl::list< sc::custom_reaction< UpdateEvt > , sc::custom_reaction< LogicEvent::AskState > > reactions;
		sc::result react(const UpdateEvt & evt);
		sc::result react(const LogicEvent::AskState & evt);
	private:
		ProcessPtr _process;


	};
}
#endif