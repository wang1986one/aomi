#include "WheelAnimalControllerStableHeaders.h"

#include "GameRotate.h"
#include "RotateAnimation.h"
#include  "WheelAnimalSceneObj.h"
#include "AnimalChange.h"
using namespace Orz;

GameRotate::GameRotate(boost::shared_ptr<WheelAnimalSceneObj> scene, 
					   boost::shared_ptr<RotateAnimation> needle,
					   boost::shared_ptr<RotateAnimation> rotate,
					   float nAngle,
					   float rAngle

					   ):_scene(scene), _needle(needle), _rotate(rotate) 
{


	_needle->play(RotateAnimation::getStartAll(needle->getAngle(), nAngle),10.f);
	_rotate->play(RotateAnimation::getStartAll(_rotate->getAngle(), rAngle),10.f);
}
GameRotate::~GameRotate(void)
{
	
}


void GameRotate::clear(void)
{
	for(int i =0; i<24; ++i)
	{
		_scene->getAnimal(i)->play(WheelEnum::ACTION1);
	}
	/*_needle->reset();
	_rotate->reset();*/
}
void GameRotate::enable(void)
{
	for(int i =0; i<24; ++i)
	{
		_scene->getAnimal(i)->play(WheelEnum::ACTION2);
	}

}


bool GameRotate::update(TimeType interval)
{
	_update2enable();
	bool a = _needle->update(interval);
	bool b = _rotate->update(interval); 
	return b||a ;
}

//Ogre::Degree GameRotate::getRotateAngle(void)
//{
//	return Ogre::Degree(_rotate->getAngle());
//}
//void GameRotate::resetRotate(void)
//{
//	for(int i =0; i<24; ++i)
//	{
//		_scene->getAnimal(i)->play(WheelEnum::ACTION1);
//	}
//	_needle->reset();
//	_rotate->reset(); 
//}




AnimalGameRotate::AnimalGameRotate(boost::shared_ptr<WheelAnimalSceneObj> scene, boost::shared_ptr<AnimalChange> ac,  boost::shared_ptr<RotateAnimation> needle, 
								   boost::shared_ptr<RotateAnimation> rotate,
								   int winner,
								   float rAngle,
								   float nAngle

								   ):_scene(scene), 
								   _ac(ac), 
								   _needle(needle), 
								   _rotate(rotate) ,
								   _winner(winner)
{

	
	_needle->play(RotateAnimation::getStartAll(needle->getAngle(), nAngle),15.f);
	_rotate->play(RotateAnimation::getStartAll(_rotate->getAngle(), rAngle),20.f);
}
void AnimalGameRotate::clear(void)
{
	for(int i =0; i<24; ++i)
	{
		_scene->getAnimal(i)->play(WheelEnum::ACTION1);
	}
	/*_needle->reset();
	_rotate->reset(); */
}
AnimalGameRotate::~AnimalGameRotate(void)
{
	

}
void AnimalGameRotate::enable(void)
{
	for(int i =0; i<24; ++i)
	{
		_scene->getAnimal(i)->play(WheelEnum::ACTION2);
	}
}


bool AnimalGameRotate::update(TimeType interval)
{
	_update2enable();
	bool a = _needle->update(interval);
	bool b = _rotate->update(interval);
	_ac->setRingVisible(true);
	_ac->getReplace()->update(interval);
	if( b||a )
		return true;
	else
	{
		_ac->stop(_scene->getAnimal(_winner));
		return false;
	}
}
