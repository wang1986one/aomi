#include "logic/AllLogic.h"
using namespace Orz;

sc::result MenuLogic::react(const LogicEvent::GoOutMenu & evt)
{
	return transit<GameLogic>();
}


sc::result MenuLogic::react(const LogicEvent::DataMenu & evt)
{
	evt.execute(getOwner());
	//Hardware::getSingleton().refresh(this);
	//
	//WheelUI::getSingleton().showMenu(true);
	return forward_event();
}


sc::result MenuLogic::react(const LogicEvent::HardwareReturn & evt)
{
	evt.execute(getOwner());
	return forward_event();
}


sc::result MenuLogic::react(const LogicEvent::ActionOne & evt)
{
	evt.execute(getOwner());
	return forward_event();
}

/*
sc::result react(const KeyF4 & evt);*/

//void push_data(int id, ACCOUNTS_ITEM item, unsigned long data);
//void push_total(ACCOUNTS_ITEM item, unsigned long data );


MenuLogic::MenuLogic(my_context ctx):LogicAdv(ctx)
{}
MenuLogic::~MenuLogic(void)
{
	getOwner()->setMenuDataVisible(false);
}
