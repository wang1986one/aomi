#ifndef __Orz_WinLogic_h__
#define __Orz_WinLogic_h__	

#include "WheelLogic.h"
#include "TasksManager.h"
#include "GameLogic.h"
#include "WheelAnimalProcess.h"
namespace Orz
{

	//×°ÅÌµÄÐý×ª
	class WinLogic: public FSM::LogicAdv<WinLogic, GameRunLogic>
	{
	public:
		WinLogic(my_context ctx);
		~WinLogic(void);

		typedef boost::mpl::list< sc::custom_reaction< UpdateEvt > > reactions;
		sc::result react(const UpdateEvt & evt);
	private:
		ProcessPtr _process;


	};
}
#endif