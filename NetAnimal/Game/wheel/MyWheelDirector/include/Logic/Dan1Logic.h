#ifndef __Orz_Dan1Logic_h__
#define __Orz_Dan1Logic_h__	

#include "WheelLogic.h"
#include "TasksManager.h"
#include "GameLogic.h"
#include "WheelAnimalProcess.h"
namespace Orz
{


	//ÓÎÏ·µÄlogo
	class Dan1Logic: public FSM::LogicAdv<Dan1Logic, GameLogic>//, public UpdateToEnable<LogiLogo>
	{
	public:
		typedef boost::mpl::list<sc::custom_reaction< LogicEvent::Dan1 > > reactions;
	
		Dan1Logic(my_context ctx);
		~Dan1Logic(void);
		sc::result react(const LogicEvent::Dan1 & evt);
		void exit(void);
	private:
	/*	ProcessPtr _process;
		bool _gotoReady;*/
		
	};
}
#endif