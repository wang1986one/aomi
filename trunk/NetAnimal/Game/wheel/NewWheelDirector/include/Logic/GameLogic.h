#ifndef __Orz_GameLogic_h__
#define __Orz_GameLogic_h__

#include "NewWheelDirectorStableHeaders.h"
#include "WheelLogic.h"
namespace Orz
{
class LogoLogic;
class GameLogic: public FSM::Logic<GameLogic, WheelLogic, LogoLogic>
{
public:
	
};


}


#endif