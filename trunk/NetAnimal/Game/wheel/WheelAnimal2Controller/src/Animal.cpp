#include "WheelAnimalControllerStableHeaders.h"
#include "Animal.h"

using namespace Orz;

void Animal::insertAnimation(WheelEnum::ACTION_TYPE action, Ogre::AnimationState* anim)
{

	_actions[action] = anim;

}

Animal::Animal(WheelEnum::AnimalType type, Ogre::SceneNode * sn, Ogre::Entity * ent, const std::string & materialName, const std::string & goldMaterialName):_type(type),_sn(sn),_ent(ent),_curAnim(),
_materialName(materialName), _goldMaterialName(goldMaterialName)
{

}
void Animal::gold(bool enable)
{
	if(enable)
	{
		_ent->setMaterialName(_goldMaterialName);
	}else
	{
		_ent->setMaterialName(_materialName);
	}
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

WheelEnum::AnimalType	Animal::getType(void)
{
	return	_type;
}


