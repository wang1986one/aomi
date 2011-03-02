#ifndef __Orz_GameLogic_h__
#define __Orz_GameLogic_h__

#include "MyWheelDirectorStableHeaders.h"
#include "WheelLogic.h"
namespace Orz
{
class LogoLogic;
class GameLogic: public FSM::LogicAdv<GameLogic, WheelLogic, LogoLogic>
{
public:
	GameLogic(my_context ctx);
	~GameLogic(void);
};


}


#endif