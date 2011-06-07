
#include "SanControllerBaseStableHeaders.h"
#include "OgreNodeDebuggerComponent.h"
#include "COgreNodeDebuggerInterface.h"
#include "CUpdateInterface.h"

using namespace Orz;


inline void Left(Ogre::SceneNode * sn, TimeType i)
{
	sn->translate(i * 500, 0.f, 0.f, Ogre::Node::TS_WORLD);
}	
inline void Right(Ogre::SceneNode * sn, TimeType i)
{
	sn->translate(i * -500, 0.f, 0.f, Ogre::Node::TS_WORLD);
}	
inline void Forward(Ogre::SceneNode * sn, TimeType i)
{
	sn->translate(0.f, 0.f,i * 500,  Ogre::Node::TS_WORLD);
}
inline void Backward(Ogre::SceneNode * sn, TimeType i)
{
	sn->translate(0.f, 0.f,i * -500, Ogre::Node::TS_WORLD);
}
inline void Up(Ogre::SceneNode * sn, TimeType i)
{
	sn->translate(0.f, i * 500, 0.f, Ogre::Node::TS_WORLD);
}
inline void Down(Ogre::SceneNode * sn, TimeType i)
{
	sn->translate(0.f, i * -500,  0.f, Ogre::Node::TS_WORLD);
}
inline void Big(Ogre::SceneNode * sn, TimeType i)
{
	sn->scale(Ogre::Vector3(1, 1, 1) * (1+i));
}
inline void Small(Ogre::SceneNode * sn, TimeType i)
{
	sn->scale(Ogre::Vector3(1, 1, 1) * (1-i));
}
inline void Yaw(Ogre::SceneNode * sn, TimeType i, bool forward)
{
	
	Ogre::Radian r(i );
	if(!forward)
		r *= -1;

	sn->yaw(r);
}


inline void Reset(Ogre::SceneNode * sn, Ogre::Camera * camera, const Ogre::Vector3 & vec)
{
	sn->setScale(vec);
	sn->resetOrientation();
	sn->setPosition( camera->getCameraToViewportRay(0.5f, 0.5f).getPoint(100.f));
}
inline void Print(Ogre::SceneNode * sn)
{
	ORZ_LOG_NOTIFICATION_MESSAGE("Node Debugger Message:" + boost::lexical_cast<std::string>(sn->getPosition()) +boost::lexical_cast<std::string>(sn->getScale())+boost::lexical_cast<std::string>(sn->getOrientation()));
}

OgreNodeDebuggerComponent::OgreNodeDebuggerComponent(void):KeyListener(true), _debuggerInterface(new COgreNodeDebuggerInterface()),_num(0),_activeNode(NULL),
_update(new CUpdateInterface())
{
	_debuggerInterface->pushNode = boost::bind(&OgreNodeDebuggerComponent::pushNode, this, _1); 
	_debuggerInterface->removeNode = boost::bind(&OgreNodeDebuggerComponent::removeNode, this, _1); 
	_debuggerInterface->enable = boost::bind(&OgreNodeDebuggerComponent::enable, this); 
	_debuggerInterface->disable = boost::bind(&OgreNodeDebuggerComponent::disable, this); 
	_update->update = boost::bind(&OgreNodeDebuggerComponent::update, this, _1); 
}
OgreNodeDebuggerComponent::~OgreNodeDebuggerComponent(void)
{

}

bool OgreNodeDebuggerComponent::onKeyPressed(const KeyEvent & evt)
{

	KeyMap::iterator it = _keyMap.find(evt.getKey());
	if(it != _keyMap.end())
	{
		it->second.first = true;
	}

	if(KC_P == evt.getKey())
		Print(_activeNode);
	if(Orz::KC_TAB == evt.getKey())
	{
		next();
	}
	return false;
}



bool OgreNodeDebuggerComponent::update(TimeType interval)
{

	KeyMap::iterator it;
	for(it = _keyMap.begin(); it != _keyMap.end(); ++it)
	{
		if(it->second.first)
		{
			it->second.second(interval);
		}
	}


	return true;
}
bool OgreNodeDebuggerComponent::onKeyReleased(const KeyEvent & evt)
{

	KeyMap::iterator it = _keyMap.find(evt.getKey());
	if(it != _keyMap.end())
	{
		it->second.first = false;
	}
	return false;
}

void OgreNodeDebuggerComponent::pushNode(Ogre::SceneNode * sn)
{
	_nodes.push_back(sn);
}
void OgreNodeDebuggerComponent::removeNode(Ogre::SceneNode * sn)
{
	_nodes.erase(std::remove(_nodes.begin(), _nodes.end(), sn), _nodes.end());

}
ComponentInterface * OgreNodeDebuggerComponent::_queryInterface(const TypeInfo & info) const
{
	if(info == TypeInfo(typeid(COgreNodeDebuggerInterface)))
	{
		return _debuggerInterface.get();
	}else if(info == TypeInfo(typeid(CUpdateInterface)))
	{
		return _update.get();
	}
	return NULL;
}




bool OgreNodeDebuggerComponent::enable(void)
{
	_num = 0;
	IInputManager::getSingleton().addKeyListener(this);
	if(active())
	{
		_keyMap.insert(std::make_pair(KC_A, std::make_pair(false, boost::bind(&Left, boost::cref(_activeNode), _1))  ));
		_keyMap.insert(std::make_pair(KC_D, std::make_pair(false, boost::bind(&Right,boost::cref( _activeNode), _1))  ));
		_keyMap.insert(std::make_pair(KC_W, std::make_pair(false, boost::bind(&Forward, boost::cref(_activeNode), _1))  ));
		_keyMap.insert(std::make_pair(KC_S, std::make_pair(false, boost::bind(&Backward, boost::cref(_activeNode), _1))  ));
		_keyMap.insert(std::make_pair(KC_PGUP, std::make_pair(false, boost::bind(&Up, boost::cref(_activeNode), _1))  ));
		_keyMap.insert(std::make_pair(KC_PGDOWN, std::make_pair(false, boost::bind(&Down, boost::cref(_activeNode), _1))  ));
		_keyMap.insert(std::make_pair(KC_COMMA, std::make_pair(false, boost::bind(&Big, boost::cref(_activeNode), _1))  ));
		_keyMap.insert(std::make_pair(KC_PERIOD, std::make_pair(false, boost::bind(&Small, boost::cref(_activeNode), _1))  ));
		_keyMap.insert(std::make_pair(KC_RIGHT, std::make_pair(false, boost::bind(&Yaw, boost::cref(_activeNode), _1, true))  ));
		_keyMap.insert(std::make_pair(KC_LEFT, std::make_pair(false, boost::bind(&Yaw, boost::cref(_activeNode), _1, false))  ));
	

		_keyMap.insert(std::make_pair(KC_R, std::make_pair(false, boost::bind(&Reset, boost::cref(_activeNode), Orz::OgreGraphicsManager::getSingleton().getCamera(), _scale))));
		
		return true;
	}
	return false;
}


bool OgreNodeDebuggerComponent::active(void)
{
	if(_num < _nodes.size())
	{
		_activeNode = _nodes.at(_num);
		_activeNode->showBoundingBox(true);
		_scale = _activeNode->getScale();
		return true;
	}
	return false;
}


void OgreNodeDebuggerComponent::disable(void)
{
	IInputManager::getSingleton().removeKeyListener(this);
	if(_activeNode)
		_activeNode->showBoundingBox(false);
	_activeNode = NULL;
	_keyMap.clear();
	_num = 0;
}
void OgreNodeDebuggerComponent::next(void)
{
	if(_activeNode)
		_activeNode->showBoundingBox(false);
	_activeNode = NULL;
	_num ++;
	if(_num >= _nodes.size())
	{
		_num = 0;
	}
	active();
}