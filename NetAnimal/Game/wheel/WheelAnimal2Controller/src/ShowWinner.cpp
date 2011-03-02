#include "WheelAnimalControllerStableHeaders.h"
#include "ShowWinner.h"
#include "WheelAnimalSceneObj.h"
#include "WinnerAnimation.h"
#include <orz/View_OGRE3D/OgreGraphicsManager.h>
using namespace Orz;


void ShowWinner::clear()
{


	_scene->clearLight();


	_scene->showBaseLight(_winner, WinData::getInstance().getLightColor(), false);
	_animation->setEnabled(true);
	_animation->setTimePosition(0.f);
	_camAnimation->setEnabled(true);
	_camAnimation->setTimePosition(0.f);
	if(_winnerAnim)
		_winnerAnim->reset();




}
ShowWinner::~ShowWinner(void)
{


}


ShowWinner::ShowWinner( boost::shared_ptr<WheelAnimalSceneObj> scene, int winner, const Ogre::Degree & angle):_scene(scene),_winner(winner)
{

	_end = OgreGraphicsManager::getSingleton().getSceneManager()->getRootSceneNode()->createChildSceneNode();  
	_animation = _scene->getSceneAnimation(SCENE_ANIMATION_0);
	_animation->setLoop(false);
	_animation->setEnabled(true);

	_camAnimation = _scene->getSceneAnimation(SCENE_ANIMATION_2);
	_camAnimation->setLoop(false);	
	_camAnimation->setEnabled(true);

	_winnerAnim.reset();
	_end->setOrientation(OgreGraphicsManager::getSingleton().getSceneManager()->getRootSceneNode()->getOrientation());
	_end->yaw(Ogre::Radian(Ogre::Math::PI));
	_end->yaw(angle) ;
	_winnerAnim.reset(new WinnerAnimation("test_4", _scene->getBase(_winner), _end));
	_winnerAnim->play();
}
void ShowWinner::enable(void)
{
	_scene->showBaseLight(_winner, WinData::getInstance().getLightColor(), true);

	_scene->clearLight();
	_scene->addLight(WinData::getInstance().getLightColor());
	_scene->addLight(WinData::getInstance().getLightColor());
	_scene->addLight(WinData::getInstance().getLightColor());
	_scene->addLight(WheelEnum::Blue);
	_scene->addLight(WheelEnum::Blue);
}
bool ShowWinner::update(TimeType interval)
{

	_update2enable();
	if(!_winnerAnim)
		return false;
	_animation->addTime(interval);
	_camAnimation->addTime(interval);
	return _winnerAnim->update(interval) || (!_animation->hasEnded()) || (!_camAnimation->hasEnded());
}


////////////////////////////





AnimalShowWinner::AnimalShowWinner(boost::shared_ptr<WheelAnimalSceneObj> scene, int winner, ObjectLightsPtr objLights, float nAngle):
_scene(scene),
_winner(winner),
_n(0),
_playanimtion(false),
_objLights(objLights),
_nAngle(nAngle)
{

}
AnimalShowWinner::~AnimalShowWinner(void)
{


}

void AnimalShowWinner::clear(void)
{
	_animation = _scene->getSceneAnimation(SCENE_ANIMATION_0);
	_animation->setEnabled(true);
	_animation->setTimePosition(0.f);


	_winner = -1;
	_playanimtion = false;
	_n = 0;
	std::vector<int>::iterator it;
	for(it = _ns.begin(); it != _ns.end(); ++it)
	{
		_scene->showBaseLight(*it, Orz::WheelEnum::Red, false);
	}
	_ns.clear();
}

bool AnimalShowWinner::update(TimeType interval)
{

	WheelEnum::AnimalType type = _scene->getAnimal(_winner)->getType();



	if(_playanimtion)
	{
		if(!_winnerAnim->update(interval)) 
		{	

			_playanimtion = false;
		}
		return true;
	}


	if(_n >= 24)
		return false;

	int winner = (_n+_winner)%24;
	int cha =24 - int(_nAngle /15) %24; 

	if(_scene->getAnimal(winner)->getType() == type)
	{
		_ns.push_back(winner);
		_scene->showBaseLight(winner, Orz::WheelEnum::LIGHT_COLOR(_objLights->getLight((winner + cha)%24)));
		_winnerAnim.reset();
		_winnerAnim.reset(new WinnerAnimationNoMove("test12", _scene->getBase(winner)));
		_winnerAnim->play();
		_playanimtion = true;

	}
	_n++;
	return true;
}
