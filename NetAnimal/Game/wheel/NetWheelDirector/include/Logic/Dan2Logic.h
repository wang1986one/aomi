#ifndef __Orz_Dan2Logic_h__
#define __Orz_Dan2Logic_h__	

#include "WheelLogic.h"
#include "TasksManager.h"
#include "GameLogic.h"
#include "WheelAnimalProcess.h"
namespace Orz
{


	//ÓÎÏ·µÄlogo
	class Dan2Logic: public FSM::LogicAdv<Dan2Logic, GameLogic>//, public UpdateToEnable<LogiLogo>
	{
	public:
		typedef boost::mpl::list<sc::custom_reaction< LogicEvent::Dan2 >  > reactions;
	
		Dan2Logic(my_context ctx);
		~Dan2Logic(void);
		sc::result react(const LogicEvent::Dan2 & evt);
		void exit(void);
	private:
	/*	ProcessPtr _process;
		bool _gotoReady;*/
		
	};
}
#endif