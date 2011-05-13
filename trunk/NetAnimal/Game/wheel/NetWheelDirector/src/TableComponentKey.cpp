#include "NetWheelDirectorStableHeaders.h"
#include "TableComponentKey.h"
#include "F5TableInterface.h"
#include "F5Table.h"
#include "F6Table.h"
using namespace Orz;

TableComponentKey::~TableComponentKey(void)
{
	Orz::IInputManager::getSingleton().removeKeyListener(this);
}


bool TableComponentKey::onKeyPressed(const KeyEvent & evt)
{
	//switch(evt.getKey())
	//{
	//case Orz::KC_P:
	//	F5Table::getInstancePtr()->pushCoin(F5TableInterface::_1,1);
	//	break;
	//case Orz::KC_L:
	//	F5Table::getInstancePtr()->popCoin(F5TableInterface::_1,1);
	//	break;

	//}
	return false;
}
bool TableComponentKey::onKeyReleased(const KeyEvent & evt)
{

	return false;
}

TableComponentKey::TableComponentKey(void)
{
	
	Orz::IInputManager::getSingleton().addKeyListener(this);
}

ComponentInterface * TableComponentKey::_queryInterface(const TypeInfo & info)
{
	return NULL;
}

