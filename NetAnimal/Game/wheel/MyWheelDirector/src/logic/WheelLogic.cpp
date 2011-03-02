
#include "MyWheelDirectorStableHeaders.h"
#include "Logic/WheelLogic.h"
#include "Logic/AllLogic.h"
//#include "Logic/AllLogic.h"
using namespace Orz;

bool WheelLogic::onKeyPressed(const KeyEvent & evt)
{

	switch(evt.getKey())
	{
	case Orz::KC_F1:
			
		getStateMachine().process_event(LogicEvent::ClickButton(0,0));
		break;
	case Orz::KC_F2:
			
		getStateMachine().process_event(LogicEvent::ClickButton(0,1));
		break;
	case Orz::KC_F3:
			
		getStateMachine().process_event(LogicEvent::ClickButton(0,2));
		break;
	}

	return false;
}

bool WheelLogic::onKeyReleased(const KeyEvent & evt)
{

	
	return true;
}



sc::result WheelLogic::react(const LogicEvent::WheelStart & evt)
{
	evt.execute(getOwner());//.getHardware().received_WheelStart(true);
	return forward_event();
}


sc::result WheelLogic::react(const LogicEvent::SetTime & evt)
{
	evt.execute(getOwner());
	return forward_event();
}

WheelLogic::WheelLogic(void)
{
	Orz::IInputManager::getSingleton().addKeyListener(this);
}
WheelLogic::~WheelLogic(void)
{

	Orz::IInputManager::getSingleton().removeKeyListener(this);
}