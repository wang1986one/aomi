#include "WheelAnimalControllerStableHeaders.h"
#include "Animal.h"

using namespace Orz;

void Animal::insertAnimation(WheelEnum::ACTION_TYPE action, Ogre::AnimationState* anim)
{

	_actions[action] = anim;

}

Animal::Animal(WheelEnum::ANIMAL_TYPE type, Ogre::SceneNode * sn, Ogre::Entity * ent):_type(type),_sn(sn),_ent(ent),_curAnim()				  
{

}

Ogre::Entity * Animal::getEntity(void) const 
{
	return _ent;
}

Ogre::SceneNode * Animal::getSceneNode(void) const 
{
	return _sn;
}

bool Animal::update(TimeType interval)
{
	if(_curAnim)
		return _curAnim->update(interval);
	return false;
}

void Animal::play(WheelEnum::ACTION_TYPE action)
{
	AnimationMap::iterator it = _actions.find(action);
	if(it != _actions.end())
	{
		_curAnim.reset();
		_curAnim.reset(new TheAnimation(it->second));
	}
}

void Animal::stop(void)
{
	_curAnim.reset();
}

WheelEnum::ANIMAL_TYPE	Animal::getType(void)
{
	return	_type;
}


