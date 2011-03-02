#ifndef __Orz_RunLogic_h__
#define __Orz_RunLogic_h__	

#include "WheelLogic.h"
#include "TasksManager.h"
#include "GameLogic.h"
#include "WheelAnimalProcess.h"
namespace Orz
{

	//×°ÅÌµÄÐý×ª
	class RunLogic: public FSM::LogicAdv<RunLogic, GameRunLogic>
	{
	public:
		RunLogic(my_context ctx);
		~RunLogic(void);

		typedef boost::mpl::list< sc::custom_reaction< UpdateEvt >  > reactions;
		sc::result react(const UpdateEvt & evt);
	private:
		ProcessPtr _process;


	};
}
#endif