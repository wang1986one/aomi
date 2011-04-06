
#include "MyWheelDirectorStableHeaders.h"
#include "logic/AllLogic.h"
#include "WheelEvents.h"
#include "ScoreManager.h"
#include "LockInterface.h"
#include "CodingFormatInterface.h"
#include "DataServerInterface.h"
#include "logic/Dan1Logic.h"

#include "GameInterface.h"
using namespace Orz;

void GetDataLogic::exit(void)
{
	

}
GetDataLogic::GetDataLogic(my_context ctx):LogicAdv(ctx)
{

	
}
GetDataLogic::~GetDataLogic(void)
{
	

	
}

sc::result GetDataLogic::react(const UpdateEvt & evt)
{

	return forward_event();

}