#ifndef __Orz_GameLogic_h__
#define __Orz_GameLogic_h__

#include "NetWheelDirectorStableHeaders.h"
#include "WheelLogic.h"

#include "CommunicateInterface.h"
namespace Orz
{
	class LogoLogic;
	class SetupHardwareLogic;
	//class WMHardwareInterface;
	class GameLogic: public FSM::LogicAdv<GameLogic, WheelLogic, LogoLogic>
	{
	public:
		typedef boost::mpl::list<sc::custom_reaction< UpdateEvt  >  > reactions;
		GameLogic(my_context ctx);
		~GameLogic(void);

		sc::result react(const UpdateEvt & evt);

		void exit(void);

	private:
		TimeType _time;
		const TimeType _distance;
		int _id;

		ComponentPtr _table;
	};


}


#endif