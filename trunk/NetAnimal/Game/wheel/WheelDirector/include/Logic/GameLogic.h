#ifndef __Orz_GameLogic_h__
#define __Orz_GameLogic_h__

#include "WheelDirectorStableHeaders.h"
#include "WheelLogic.h"
namespace Orz
{
class LogoLogic;
class GameLogic: public FSM::Logic<GameLogic, WheelLogic, LogoLogic>
{
public:
	typedef boost::mpl::list< sc::custom_reaction< LogicEvent::ComeInMenu >, sc::custom_reaction<LogicEvent::ComeInSetup> > reactions;
	sc::result react(const LogicEvent::ComeInMenu & evt);
	sc::result react(const LogicEvent::ComeInSetup & evt);
};


}


#endif