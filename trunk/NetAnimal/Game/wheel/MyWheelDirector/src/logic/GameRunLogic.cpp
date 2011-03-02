#include "MyWheelDirectorStableHeaders.h"
#include "logic/AllLogic.h"

using namespace Orz;

GameRunLogic::GameRunLogic(my_context ctx):LogicAdv(ctx),_time(0.f)
{

}
GameRunLogic::~GameRunLogic(void)
{

}

sc::result GameRunLogic::react(const UpdateEvt & evt)
{
	_time += evt.getInterval();
	if(_time >= 1.0f)
	{
		_time-=_time;
		MyHardware::getInstance().link();
	}

	return forward_event();
}
