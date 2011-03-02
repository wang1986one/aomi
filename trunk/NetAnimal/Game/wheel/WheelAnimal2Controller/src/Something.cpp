#include "WheelAnimalControllerStableHeaders.h"
#include "Something.h"

using namespace Orz;



SomethingRise::SomethingRise(float high, float speed, Ogre::SceneNode * sn):_high(high),_speed(speed), _sn(sn)
{
	_sn->setVisible(true);
	_from = _sn->getPosition();

}
SomethingRise::~SomethingRise(void)
{
}

void SomethingRise::clear(void)
{
	_sn->setPosition(_from);
}
bool SomethingRise::update(TimeType interval)
{
	_sn->translate(Ogre::Vector3(0.f, _speed, 0.f) * interval);

	
	if((_sn->getPosition() - _from).y >= _high)
		return false;
		
	return true;	
}


SomethingReplace::SomethingReplace(TimeType interval, std::vector<AnimalPtr> & animals, std::vector<AnimalPtr>::iterator & curAnimal,
	Ogre::SceneNode * node)
:_animals(animals), _curAnimal(curAnimal),_interval(interval),_time(0.f),_node(node)
{
	_dir = _node->getOrientation();
}


void SomethingReplace::stop(WheelEnum::AnimalType  type)
{
	_node->setOrientation(_dir);
	 if(_curAnimal == _animals.end())
		_curAnimal = _animals.begin();
	 for(std::vector<AnimalPtr>::iterator it = _animals.begin(); it != _animals.end(); ++it)
	 {
		if((*it)->getType() == type)
		{
			Ogre::Vector3 pos = (*_curAnimal)->getSceneNode()->getPosition();
			(*_curAnimal)->getSceneNode()->setVisible(false);
			_curAnimal = it;
			(*_curAnimal)->getSceneNode()->setPosition(pos);
			(*_curAnimal)->getSceneNode()->setVisible(true);
			return;
		}
	 }
}
void SomethingReplace::update(TimeType interval)
{
	_node->yaw(Ogre::Radian(-0.4f));
	_time+=interval;
	if(_time > _interval)
	{
		_time = 0;
		 jump();
	}

}
void SomethingReplace::clear(void)
{
	if(_curAnimal == _animals.end())
		_curAnimal = _animals.begin();
	(*_curAnimal)->getSceneNode()->setVisible(false);
}
SomethingReplace::~SomethingReplace(void)
{
	
}

void SomethingReplace::jump(void)
{

	if(_curAnimal == _animals.end())
		_curAnimal = _animals.begin();
	Ogre::Vector3 pos = (*_curAnimal)->getSceneNode()->getPosition();
	(*_curAnimal)->getSceneNode()->setVisible(false);

	++_curAnimal;

	if(_curAnimal == _animals.end())
		_curAnimal = _animals.begin();			   

	(*_curAnimal)->getSceneNode()->setPosition(pos);
	(*_curAnimal)->getSceneNode()->setVisible(true);
}