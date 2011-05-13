#ifndef __Orz_PlayLogic_h__
#define __Orz_PlayLogic_h__	

#include "WheelLogic.h"
#include "TasksManager.h"
#include "GameLogic.h"
#include "WheelAnimalProcess.h"
namespace Orz
{

	//²¥·ÅÊ¤Àû¶¯»­
	class PlayLogic: public FSM::LogicAdv<PlayLogic, GameRunLogic>
	{
	public:
		PlayLogic(my_context ctx);
		~PlayLogic(void);

		typedef boost::mpl::list< sc::custom_reaction< UpdateEvt > > reactions;
		sc::result react(const UpdateEvt & evt);
	
	private:
		ProcessPtr _process;


	};
}
#endif