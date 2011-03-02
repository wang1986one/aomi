#include "WheelAnimalControllerStableHeaders.h"
#include "AnimalChange.h"
#include <orz/View_OGRE3D/OgreGraphicsManager.h>
#include "ThirdParty/Ofusion/OgreOSMScene.h"
using namespace Orz;


AnimalChange::AnimalChange(AnimalPtr animal, Ogre::SceneNode * root)
{
	
	animal->getSceneNode()->yaw(Ogre::Radian(Ogre::Math::PI));
	animal->play(WheelEnum::ACTION2);
	animal->getSceneNode()->setVisible(false);
	_animals.push_back(animal);
	
	_root = root;


	_curAnimal = _animals.begin();

	_osm.reset(new OSMScene(OgreGraphicsManager::getSingleton().getSceneManager(), OgreGraphicsManager::getSingleton().getRenderWindow()));
	_osm->initialise("gh.osm");
	_sn = Orz::OgreGraphicsManager::getSingleton().getSceneManager()->getRootSceneNode()->createChildSceneNode(); 
	_osm->createScene(_sn);
	_sn->scale(Ogre::Vector3(1.0f,1.0f,1.0f)*6.5);
	
	_animation = Orz::OgreGraphicsManager::getSingleton().getSceneManager()->createAnimationState("leyuan_tx_bluehuan");
	_animation->setEnabled(true);
	reset();
}

void AnimalChange::stop(AnimalPtr animal)
{
	if(_replace)
		_replace->stop(animal->getType());
}

void AnimalChange::reset(void)
{
	
	_curAnimal = _animals.begin();
	_rise.reset();
	_replace.reset();
	
	_animation->setTimePosition(0.f);
	_sn->setVisible(false);
}

void AnimalChange::clear(void)
{
	if(_rise)
		_rise->clear();
	if(_replace)
		_replace->clear();
	 reset();		   
}
bool AnimalChange::update(TimeType interval)
{
	_sn->setPosition(_animals[0]->getSceneNode()->getPosition()+Ogre::Vector3(0.f, 240.f, 0.f));
	_animation->addTime(interval);
	return true;
}

void AnimalChange::insertAnimal(AnimalPtr animal)
{
	animal->getSceneNode()->yaw(Ogre::Radian(Ogre::Math::PI));
	animal->play(WheelEnum::ACTION2);
	animal->getSceneNode()->setVisible(false);
	_animals.push_back(animal);
	reset();
	
}	


void AnimalChange::setRingVisible(bool visible)
{
	_sn->setVisible(visible);
}



SomethingRise * AnimalChange::getRise(float speed)
{
	
	if(!_rise && _curAnimal != _animals.end())
		_rise.reset(new SomethingRise(50,speed, (*_curAnimal)->getSceneNode()));

	return _rise.get();
}


SomethingReplace * AnimalChange::getReplace(void)
{
	
	if(!_replace && _curAnimal != _animals.end())
		_replace.reset(new SomethingReplace(0.3f, _animals, _curAnimal, _root));

	return _replace.get();
	
}