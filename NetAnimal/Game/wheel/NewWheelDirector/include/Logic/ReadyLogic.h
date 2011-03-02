#ifndef __Orz_ReadyLogic_h__
#define __Orz_ReadyLogic_h__	

#include "WheelLogic.h"
#include "TasksManager.h"
#include "GameLogic.h"
#include "WheelAnimalProcess.h"
namespace Orz
{


	//ÓÎÏ·µÄlogo
	class ReadyLogic: public FSM::LogicAdv<ReadyLogic, GameLogic>
	{
	public:
		ReadyLogic(my_context ctx);
		~ReadyLogic(void);
		
		typedef boost::mpl::list<sc::custom_reaction< UpdateEvt> ,sc::custom_reaction<LogicEvent::FindSC> ,  sc::custom_reaction< LogicEvent::AskTime > > reactions;
		sc::result react(const LogicEvent::AskTime & evt);

		sc::result react(const UpdateEvt & evt);
		sc::result react(const LogicEvent::FindSC & evt);

	private:
		ProcessPtr _process;
	};
}
#endif