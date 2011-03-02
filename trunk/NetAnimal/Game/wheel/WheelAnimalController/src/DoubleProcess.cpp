#include "WheelAnimalControllerStableHeaders.h"
#include "DoubleProcess.h"
#include "RotateAnimation.h"
#include <orz/View_OGRE3D/OgreGraphicsManager.h>
#include "WheelAnimalUI.h"
using namespace Orz;

DoubleProRun::DoubleProRun():_time(0.f),_DoubleProRunIsEnd(false),_DoubleProRunIsPlaying(true)
{

}

DoubleProRun::~DoubleProRun(void)
{

}	

void DoubleProRun::enable(void)
{


	if(WinData::getInstance().getWinMode() == WheelEnum::DOUBLE)
		Orz::WheelAnimalUI::getSingleton().x2();
	if(WinData::getInstance().getWinMode() == WheelEnum::TREBLE)
		Orz::WheelAnimalUI::getSingleton().x3();
}

bool DoubleProRun::update(TimeType interval)
{
	if(_DoubleProRunIsEnd == false)
	{
		_DoubleProRunMusic = ISoundManager::getSingleton().createPlayer("lightning.wav",true);
		_DoubleProRunMusic->load();
		_DoubleProRunMusic->play();
		_DoubleProRunIsEnd = true;
	}
	bool DoubleProRunMusicIsPlaying = _DoubleProRunMusic->playing();

	if( DoubleProRunMusicIsPlaying == false && _DoubleProRunIsPlaying == true )
	{
		ISoundManager::getSingleton().quickPlay("prize_double.wav");
		_DoubleProRunIsPlaying = false;
	}

	_update2enable();
	_time += interval;
	bool ret = Orz::WheelAnimalUI::getSingleton().updateLight(interval);
	if(_time > 7.5f)
	{
		if(!ret)
			return false;
	}
	return true;
}

void DoubleProRun::clear(void)
{

	if(_DoubleProRunMusic!= NULL)
	{
		_DoubleProRunMusic->unload();
	}

	Orz::WheelAnimalUI::getSingleton().clearLight();
}


//////////////////////////////////////////////////////////////////

DoubleShowWinner::DoubleShowWinner(  boost::shared_ptr<WheelAnimalSceneObj> scene, int winner, const Ogre::Degree & angle):_scene(scene),_winner(winner)
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
	_winnerAnim.reset(new WinnerAnimation("test_1", _scene->getBase(_winner), _end));
	_winnerAnim->play();
}

DoubleShowWinner::~DoubleShowWinner(void)
{

}

void DoubleShowWinner::enable(void)
{
	ISoundManager::getSingleton().quickPlay("sucess.wav");
	ISoundManager::getSingleton().quickPlay("Fly.wav");
	_scene->showBaseLight(_winner, WinData::getInstance().getLightColor(), true);
	_scene->clearLight();
	_scene->addLight( WinData::getInstance().getLightColor());
	_scene->addLight( WinData::getInstance().getLightColor());
	_scene->addLight( WinData::getInstance().getLightColor());
	_scene->addLight(WheelEnum::Blue);
	_scene->addLight(WheelEnum::Blue);
}

bool DoubleShowWinner::update(TimeType interval)
{

	_update2enable();
	if(!_winnerAnim)
		return false;
	_animation->addTime(interval);
	_camAnimation->addTime(interval);
	return _winnerAnim->update(interval) || (!_animation->hasEnded()) || (!_camAnimation->hasEnded());
}

void DoubleShowWinner::clear()
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


/////////////////////////////////////////////////////////////////////////////////////


DoubleGameRotate::DoubleGameRotate(boost::shared_ptr<WheelAnimalSceneObj> scene, 
								   boost::shared_ptr<RotateAnimation> needle,
								   boost::shared_ptr<RotateAnimation> rotate,
								   int nAngle,
								   int rAngle
								   ):_scene(scene), _needle(needle), _rotate(rotate) 
{
	_needle->play(RotateAnimation::getStartAll(needle->getAngle(), nAngle),15.f);
	_rotate->play(RotateAnimation::getStartAll(_rotate->getAngle(), rAngle),20.f);
}
DoubleGameRotate::~DoubleGameRotate(void)
{

}

void DoubleGameRotate::clear(void)
{

		if(_DoubleGameRotateMusic)
	{
		_DoubleGameRotateMusic->unload();
		
	}
	for(int i =0; i<24; ++i)
	{
		_scene->getAnimal(i)->play(WheelEnum::ACTION1);
	}

}

void DoubleGameRotate::enable(void)
{

	_DoubleGameRotateMusic = ISoundManager::getSingleton().createPlayer("Win_4.wav",true);
	_DoubleGameRotateMusic->load();
	_DoubleGameRotateMusic->play(0);
	_DoubleGameRotateMusic->setVolume(0.3f);

	for(int i =0; i<24; ++i)
	{
		_scene->getAnimal(i)->play(WheelEnum::ACTION2);
	}

}

bool DoubleGameRotate::update(TimeType interval)
{
	_update2enable();
	bool a = _needle->update(interval);
	bool b = _rotate->update(interval); 
	bool ret = (b||a);
	if(ret)
	return true ;

	return false;
}


//////////////////////////////////////////////////////////////////////////////////

DoublePlayAnimation::DoublePlayAnimation(boost::shared_ptr<WheelAnimalSceneObj> scene,  WinEffectPtr effect , int winner):_scene(scene),_effect(effect),_winner(winner) ,_time(0.f)
{

	int ov = WinData::getInstance().getRate(0);//WheelData::getInstance().getOverride(WinData::getInstance().getRate(), WinData::getInstance().getAnimalItem());


	if(WinData::getInstance().getWinMode() == WheelEnum::DOUBLE)
		ov *=2;
	else if(WinData::getInstance().getWinMode() == WheelEnum::TREBLE)
		ov *=3;
	if(ov >= 10 && ov <25)
	{				
		_effect->show(WinEffect::Effect1);
	}else if(ov >= 25 && ov <30)
	{				
		_effect->show(WinEffect::Effect2);
	}else if(ov >= 30 && ov <45)
	{

		_effect->show(WinEffect::Effect3); 
	}else if(ov >= 45)
	{
		_effect->show(WinEffect::Effect4);
	}else 
	{
		_effect->show(WinEffect::None);
	}
}
DoublePlayAnimation::~DoublePlayAnimation(void)
{
}

void DoublePlayAnimation::clear(void)
{
	_effect->clear();
}
void DoublePlayAnimation::enable(void)
{
	switch(WinData::getInstance().getType())
	{
	case WheelEnum::LION:
		_DoublePlayAnimationMusic = ISoundManager::getSingleton().createPlayer("Lion.wav",true);
		_DoublePlayAnimationMusic->load();
		_DoublePlayAnimationMusic->play(0);
		break;
	case WheelEnum::RABBIT:
		_DoublePlayAnimationMusic = ISoundManager::getSingleton().createPlayer("Rabbit.wav",true);
		_DoublePlayAnimationMusic->load();
		_DoublePlayAnimationMusic->play(0);
		break;
	case WheelEnum::MONKEY:
		_DoublePlayAnimationMusic = ISoundManager::getSingleton().createPlayer("Monkey.wav",true);
		_DoublePlayAnimationMusic->load();
		_DoublePlayAnimationMusic->play(0);
		break;
	case WheelEnum::PANDA:
		_DoublePlayAnimationMusic = ISoundManager::getSingleton().createPlayer("Panda.wav",true);
		_DoublePlayAnimationMusic->load();
		_DoublePlayAnimationMusic->play(0);
		break;
	}
	_effect->enable();
	_time = 0.f;
	_scene->getAnimal(_winner)->play(WheelEnum::ACTION3);
}
bool DoublePlayAnimation::update(Orz::TimeType interval)
{
	bool ret = _effect->update(interval);
	_update2enable();
	_time+= interval;
	if(_time >=5.0)
	{
		if(_DoublePlayAnimationMusic != NULL)
		{
			_DoublePlayAnimationMusic->unload();
		}
		if(!ret)
		{
			return false;
		}
	}
	return true;
}
////////////////////////////////////////////////////////////////////////



DoubleProcess5::DoubleProcess5():_time(0.f)
{

}


DoubleProcess5::~DoubleProcess5(void)
{

}

void DoubleProcess5::enable(void)
{

	_time = 0.f;
}

bool DoubleProcess5::update(Orz::TimeType interval)
{

	return false;
}

void DoubleProcess5::clear(void)
{

}


class DoubleAllProcess: public WheelAnimalProcess
{
public:
	DoubleAllProcess(  boost::shared_ptr<WheelAnimalSceneObj> scene, int winner, const Ogre::Degree & angle,WinEffectPtr effect)
	{
		_first.reset(new DoubleShowWinner( scene,winner, angle));
		_second.reset(new DoublePlayAnimation(scene, effect, winner));
	}

	
	virtual void clear(void)
	{
		_first->clear();
		_second->clear();

	}
	virtual bool update(TimeType interval)
	{
		if(!_first->update(interval))
		{
			if(!_second->update(interval))
				return false;
		}
		return  true;
	}
private:
	
	ProcessPtr _first;
	ProcessPtr _second;
};
///////////////////////////////////////////////////////////////////////////////////


ProcessFactoryDouble::ProcessFactoryDouble(
	 

	boost::shared_ptr<WheelAnimalSceneObj> scene,

	WinEffectPtr effect,
	boost::shared_ptr<RotateAnimation> needle,
	boost::shared_ptr<RotateAnimation> rotate,
	ObjectLightsPtr objLights
	):ProcessFactory(scene, objLights),_effect(effect),
	_needle(needle),_rotate(rotate)
{
}
ProcessFactoryDouble::~ProcessFactoryDouble(void)
{

}
Process0Ptr ProcessFactoryDouble::createProcess0(void)
{
	return Process0Ptr();
}
ProcessPtr ProcessFactoryDouble::createProcess1(void)
{
	return ProcessPtr(new DoubleProRun());
}
ProcessPtr ProcessFactoryDouble::createProcess2(void)
{
	return ProcessPtr(new DoubleGameRotate(_scene, _needle, _rotate, _nAngle, _rAngle));

}
ProcessPtr ProcessFactoryDouble::createProcess3(void)
{
	return ProcessPtr(new DoubleProcess5());

}
ProcessPtr ProcessFactoryDouble::createProcess4(void)
{
	return ProcessPtr(new DoubleAllProcess( _scene,_winner, Ogre::Degree(_rAngle), _effect));
}
//ProcessPtr ProcessFactoryDouble::createProcess5(void)
//{
//	return ProcessPtr(new DoubleProcess5());
//}
