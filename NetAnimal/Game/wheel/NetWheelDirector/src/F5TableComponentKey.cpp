#include "NetWheelDirectorStableHeaders.h"
#include "F5TableComponentKey.h"
#include "F5TableInterface.h"
#include "F5Table.h"
using namespace Orz;

F5TableComponentKey::~F5TableComponentKey(void)
{
	Orz::IInputManager::getSingleton().removeKeyListener(this);
}


bool F5TableComponentKey::onKeyPressed(const KeyEvent & evt)
{
	/*switch(evt.getKey())
	{
	case Orz::KC_P:
		F5Table::getInstancePtr()->pushCoin(F5TableInterface::_1,1);
		break;
	case Orz::KC_L:
		F5Table::getInstancePtr()->popCoin(F5TableInterface::_1,1);
		break;

	}*/
	return false;
}
bool F5TableComponentKey::onKeyReleased(const KeyEvent & evt)
{

	return false;
}

F5TableComponentKey::F5TableComponentKey(void)
{
	
	Orz::IInputManager::getSingleton().addKeyListener(this);
}

