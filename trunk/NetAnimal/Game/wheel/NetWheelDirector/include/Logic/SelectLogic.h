#ifndef __Orz_SelectLogic_h__
#define __Orz_SelectLogic_h__

#include "NetWheelDirectorStableHeaders.h"
#include "WheelLogic.h"
namespace Orz
{
	class LogoLogic;
	class SelectLogic: public FSM::LogicAdv<SelectLogic, WheelLogic> 
	{
	public:

		SelectLogic(my_context ctx);
		~SelectLogic(void);
		typedef boost::mpl::list< sc::custom_reaction< LogicEvent::F1 >, sc::custom_reaction< LogicEvent::F2 >,sc::custom_reaction< LogicEvent::F3 > , sc::custom_reaction< UpdateEvt >  > reactions;


		sc::result react(const LogicEvent::F1 & evt);
		sc::result react(const LogicEvent::F2 & evt);
		sc::result react(const LogicEvent::F3 & evt);
		sc::result react(const UpdateEvt & evt);

		void exit(void);
	private:
		TimeType _allTime; 
#ifdef _GAME1
		
		typedef int SceneMsg;
#else
		typedef std::pair<std::string, bool> SceneMsg;
#endif
		SceneMsg _sceneMsg;

	private:
	/*	enum TheState
		{
			SelectScene,
			HardwareTest,
		};
	private:
		TheState _state;*/
	};


}


#endif