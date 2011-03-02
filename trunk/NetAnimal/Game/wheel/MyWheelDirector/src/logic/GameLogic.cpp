
#include "MyWheelDirectorStableHeaders.h"

#include "logic/AllLogic.h"


#include "logic/LogoLogic.h"
using namespace Orz;


GameLogic::GameLogic(my_context ctx):LogicAdv(ctx)
{
	getOwner()->enableScene("HunterScene", false);
}
GameLogic::~GameLogic(void)
{

}