#ifndef __Orz_GameRunLogic_h__
#define __Orz_GameRunLogic_h__	

#include "WheelLogic.h"
#include "TasksManager.h"
#include "GameLogic.h"
#include "WheelAnimalProcess.h"
namespace Orz
{

	class ProRunLogic;
	//²¥·ÅÊ¤Àû¶¯»­
	class GameRunLogic: public FSM::LogicAdv<GameRunLogic, GameLogic, ProRunLogic>
	{
	public:
		GameRunLogic(my_context ctx);
		~GameRunLogic(void);

		/*typedef boost::mpl::list< sc::custom_reaction< UpdateEvt > > reactions;
		sc::result react(const UpdateEvt & evt);*/

	private:

		TimeType _time;
	};
}
#endif