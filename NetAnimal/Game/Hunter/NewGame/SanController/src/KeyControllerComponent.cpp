#include "SanControllerBaseStableHeaders.h"
//#include "OgreNodeDebuggerComponent.h"
//#include "COgreNodeDebuggerInterface.h"
//
//using namespace Orz;
//
//
//KeyControllerComponent::KeyControllerComponent(void)
//{
//	
//}
//OgreNodeDebuggerComponent::~OgreNodeDebuggerComponent(void)
//{
//	
//}
//
//bool OgreNodeDebuggerComponent::onKeyPressed(const KeyEvent & evt)
//{
//	
//}
//bool OgreNodeDebuggerComponent::onKeyReleased(const KeyEvent & evt)
//{
//
//
//	
//}
//
//void OgreNodeDebuggerComponent::pushNode(Ogre::SceneNode * sn)
//{
//	
//}
//void OgreNodeDebuggerComponent::removeNode(Ogre::SceneNode * sn)
//{
//	_nodes.erase(std::remove(_nodes.begin(), _nodes.end(), sn), _nodes.end());
//	
//}
//ComponentInterface * OgreNodeDebuggerComponent::_queryInterface(const TypeInfo & info)
//{
//	if(info == TypeInfo(typeid(COgreNodeDebuggerInterface)))
//	{
//		return _debuggerInterface.get();
//	}
//	return NULL;
//}
//
//
//bool OgreNodeDebuggerComponent::enable(void)
//{
//
//	_num = 0;
//	IInputManager::getSingleton().addKeyListener(this);
//	return active();
//}
//
//
//bool OgreNodeDebuggerComponent::active(void)
//{
//	if(_num < _nodes.size())
//	{
//		_activeNode = _nodes.at(_num);
//		_activeNode->showBoundingBox(true);
//		return true;
//	}
//	return false;
//}
//void OgreNodeDebuggerComponent::disable(void)
//{
//	IInputManager::getSingleton().removeKeyListener(this);
//	if(_activeNode)
//		_activeNode->showBoundingBox(false);
//	_activeNode = NULL;
//	_num = 0;
//}
//void OgreNodeDebuggerComponent::next(void)
//{
//	_num ++;
//	if(_num >= _nodes.size())
//	{
//		_num = 0;
//	}
//}