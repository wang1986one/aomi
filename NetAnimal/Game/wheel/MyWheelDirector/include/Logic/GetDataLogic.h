#ifndef __Orz_GetDataLogic_h__
#define __Orz_GetDataLogic_h__	

#include "WheelLogic.h"
#include "TasksManager.h"
#include "StartLogic.h"
#include "WheelAnimalProcess.h"
namespace Orz
{


	class GetDataLogic: public FSM::LogicAdv<GetDataLogic, StartLogic>
	{
	public:
		GetDataLogic(my_context ctx);
		~GetDataLogic(void);
		typedef boost::mpl::list< sc::custom_reaction< UpdateEvt > > reactions;
		sc::result react(const UpdateEvt & evt)	;
		void exit(void);
	private:
	};
}
#endif