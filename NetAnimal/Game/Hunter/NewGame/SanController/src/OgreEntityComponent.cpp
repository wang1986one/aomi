#include "SanControllerBaseStableHeaders.h"
#include "OgreEntityComponent.h"
#include "COgreEntityInterface.h"
#include "COgreAnimationInterface.h"
using namespace Orz;
OgreEntityComponent::OgreEntityComponent(void):_entityInterface(new COgreEntityInterface()),_animationInterface(new COgreAnimationInterface()),_sn(NULL),_ent(NULL),_animationState(NULL),_defaultState(NULL),_isLoad(false),_times(1)
{
	_entityInterface->_loadEntityWithSceneNode = boost::bind(&OgreEntityComponent::load, this, _1, _2, _3);
	_entityInterface->getSceneNode = boost::bind(&OgreEntityComponent::getSceneNode, this); 
	_entityInterface->printAllAnimation = boost::bind(&OgreEntityComponent::printAllAnimation, this); 
	_entityInterface->setDefaultAnimation = boost::bind(&OgreEntityComponent::setDefaultAnimation, this, _1); 
	_entityInterface->unload = boost::bind(&OgreEntityComponent::unload, this); 
	_entityInterface->getEntity =  boost::bind(&OgreEntityComponent::getEntity, this);


	/////////////////////////////////////////////////////////////////////////////////////////////////
	_animationInterface->_enable = boost::bind(&OgreEntityComponent::setCurAnimation, this, _1, _2); 
	_animationInterface->update = boost::bind(&OgreEntityComponent::updateAnimation, this, _1); 
	_animationInterface->isExist = boost::bind(&OgreEntityComponent::isExistAnimation, this, _1);
	_animationInterface->disable = boost::bind(&OgreEntityComponent::disableCurAnimation, this);

}
OgreEntityComponent::~OgreEntityComponent(void)
{

}


Ogre::Entity* OgreEntityComponent::getEntity(void) const 
{
	return _ent;
}
Ogre::SceneNode * OgreEntityComponent::getSceneNode(void) const
{
	return _sn;
}

void OgreEntityComponent::printAllAnimation(void)
{
	if(!_ent)
		return;

	using namespace Ogre;
	AnimationStateSet * set = _ent->getAllAnimationStates();

	AnimationStateIterator iterator = set->getAnimationStateIterator();

	while(iterator.hasMoreElements())
	{
		ORZ_LOG_NOTIFICATION_MESSAGE(iterator.getNext()->getAnimationName());
	}

}

	
void OgreEntityComponent::load(const std::string & name, const std::string & meshName, Ogre::SceneNode * sn)
{

	if(_isLoad)
		unload();
	Ogre::SceneManager * sm = Orz::OgreGraphicsManager::getSingleton().getSceneManager();
	if(!sn)
	{
		sn = sm->getRootSceneNode();
	}
	if(_sn)
	{
		if(_sn->getParentSceneNode() != sn)
		{
			sm->destroySceneNode(_sn);
			_sn = NULL;
		}

	
	}
	if(_sn == NULL)
		_sn = sn->createChildSceneNode();

	_ent = sm->createEntity(name, meshName);
	_sn->attachObject(_ent);
	_isLoad = true;
}

void OgreEntityComponent::unload(void)
{

	if(!_isLoad)
		return;

	Ogre::SceneManager * sm = Orz::OgreGraphicsManager::getSingleton().getSceneManager();
	

	if(_ent)
	{
		if(_sn)
			_sn->detachObject(_ent);
		sm->destroyEntity(_ent);
		_ent= NULL;
	}
	_animationState = NULL;
	_defaultState = NULL;
	_isLoad = false;

}

ComponentInterface * OgreEntityComponent::_queryInterface(const TypeInfo & info)
{

	if(info == TypeInfo(typeid(COgreEntityInterface)))
		return _entityInterface.get();
	if(info == TypeInfo(typeid(COgreAnimationInterface)))
		return _animationInterface.get();
	return NULL;
}


void OgreEntityComponent::disableCurAnimation(void)
{
	if(_animationState)
	{
		_animationState->setEnabled(false);
		if(_defaultState)
			_defaultState->setEnabled(true);
	}
}

bool OgreEntityComponent::setDefaultAnimation(const std::string & name)
{
	
	if(isExistAnimation(name))
	{
		_defaultState = _ent->getAnimationState(name);

		if(_animationState)
			_animationState->setEnabled(false);
		_defaultState->setEnabled(true);
		return true;
	}
	return false;
}
bool OgreEntityComponent::setCurAnimation(const std::string & name, int times)
{
	_times =times;
	if(_animationInterface->_callback)
	{
		_animationInterface->_callback(_times);
	}
	if(_animationState)
		disableCurAnimation();
	if(!isExistAnimation(name))
		return false;
	_animationState = _ent->getAnimationState(name);
	_animationState->setTimePosition(0.f);
	if(_defaultState)
		_defaultState->setEnabled(false);
	_animationState->setEnabled(true);
	if(times ==0)
		_animationState->setLoop(true);
	else
		_animationState->setLoop(false);
	return true;
}
bool OgreEntityComponent::updateAnimation(TimeType interval)
{
	if(_animationState)
		_animationState->addTime(interval);
	if(_animationState->hasEnded())
	{
		_times--;
		if(_animationInterface->_callback)
		{
			_animationInterface->_callback(_times);
		}
		if(_times <= 0)
			return false;
		_animationState->setTimePosition(0.f);
	}
	return true;
}
bool OgreEntityComponent::isExistAnimation(const std::string & name)
{
	return _ent->getAnimationState(name) != NULL;
}