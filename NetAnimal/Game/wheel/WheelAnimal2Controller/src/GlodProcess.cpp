#include "WheelAnimalControllerStableHeaders.h"
#include "GlodProcess.h"
#include "RotateAnimation.h"
#include <orz/View_OGRE3D/OgreGraphicsManager.h>
#include "WheelAnimalUI.h"
using namespace Orz;


GlodProRun::GlodProRun(boost::shared_ptr<WheelAnimalSceneObj> scene, boost::shared_ptr<AnimalChange> ac):_scene(scene),_ac(ac),_time(0.f),_GlodProRunIsEnd(false),_GlodProRunIsPlaying(true)
{

}

GlodProRun::~GlodProRun(void)
{

}	

bool GlodProRun::update(TimeType interval)
{
	_update2enable();
	if(_GlodProRunIsEnd == false)
	{
		_GlodProRunMusic = ISoundManager::getSingleton().createPlayer("barM.wav",true);
		_GlodProRunMusic->load();
		_GlodProRunMusic->play();
		_GlodProRunIsEnd = true;
	}
	bool GlodProRunMusicIsPlaying = _GlodProRunMusic->playing();

	if( GlodProRunMusicIsPlaying == false && _GlodProRunIsPlaying == true )
	{
		ISoundManager::getSingleton().quickPlay("prize_bonus.wav");
		_GlodProRunIsPlaying =	false;
	}
	_time += interval;
	if(_time > 7.5f)
		return false;
	return true;
}

void GlodProRun::clear(void)
{
	if(_GlodProRunMusic != NULL)
	{
		_GlodProRunMusic->unload();
	}
	_scene->clearLight();
}

void GlodProRun::enable(void)
{
	_scene->clearLight();
	_scene->addLight(WheelEnum::Red);
	_scene->addLight(WheelEnum::Green);
	_scene->addLight(WheelEnum::Yellow);
	_scene->addLight(WheelEnum::Blue);
	_scene->addLight(WheelEnum::DeepBlue);
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void GlodShowWinner::clear()
{



	_scene->showBaseLight(_winner, WinData::getInstance().getLightColor(), false);
	_animation->setEnabled(true);
	_animation->setTimePosition(0.f);
	if(_winnerAnim)
		_winnerAnim->reset();
	_effect->clear();
	_camAnimation->setEnabled(true);   
	_camAnimation->setTimePosition(0.f);
	_scene->getAnimal(_winner)->gold(false);
	_scene->clearLight();
}

GlodShowWinner::~GlodShowWinner(void)
{


}


GlodShowWinner::GlodShowWinner( boost::shared_ptr<WheelAnimalSceneObj> scene, WinEffectPtr effect, int winner, const Ogre::Degree & angle):_scene(scene),_effect(effect), _winner(winner)
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
	_end->yaw(angle);
	_winnerAnim.reset(new WinnerAnimation("test_2", _scene->getBase(_winner), _end));
	_winnerAnim->play();



}

bool GlodShowWinner::update(TimeType interval)
{

	_update2enable();
	if(!_winnerAnim)
		return false;
	_animation->addTime(interval);

	_camAnimation->addTime(interval);
	bool ret = _winnerAnim->update(interval);
	bool r = true;
	if(!ret)
	{
		r = _effect->update(interval);
		//_sceneAnimation->addTime(interval);
	}
	return ret || (!_animation->hasEnded()) || r|| (!_camAnimation->hasEnded());
}

void GlodShowWinner::enable(void)
{
	
	_scene->getAnimal(_winner)->gold(true);
	Orz::WheelAnimalUI::getSingleton().setGold(WinData::getInstance().getBonus().bonus);
	_effect->show(WinEffect::Effect4);
	_scene->showBaseLight(_winner, WinData::getInstance().getLightColor(), true);
	_scene->clearLight();
	_scene->addLight(WheelEnum::Red);
	_scene->addLight(WheelEnum::Green);
	_scene->addLight(WheelEnum::Yellow);
	_scene->addLight(WheelEnum::Blue);
	_scene->addLight(WheelEnum::DeepBlue);

}

////////////////////////////////////////////////////////////////////////



GlodPlayAnimation::GlodPlayAnimation( boost::shared_ptr<WheelAnimalSceneObj> scene, GoldPtr gold, int winner):_scene(scene), _winner(winner) ,_gold(gold),_time(0.f)
{
}

GlodPlayAnimation::~GlodPlayAnimation(void)
{
}

void GlodPlayAnimation::clear(void)
{

	Orz::WheelAnimalUI::getSingleton().setGold(0);
	Orz::WheelAnimalUI::getSingleton().setWinnerShow(true);
	_gold->hide();

}
void GlodPlayAnimation::enable(void)
{
	Orz::WheelAnimalUI::getSingleton().setWinnerShow(false);
	_gold->setNumber(WinData::getInstance().getBonus().bonus);
	_gold->show();
	_time = 0.f;
	_scene->getAnimal(_winner)->play(WheelEnum::ACTION3);
}
bool GlodPlayAnimation::update(Orz::TimeType interval)
{
	_update2enable();
	_gold->update(interval);
	_time+= interval;
	if(_time >= 25.0)
		return false;
	return true;
}



/////////////////////////////////////////////////////////////////////////////////////


GlodGameRotate::GlodGameRotate(boost::shared_ptr<WheelAnimalSceneObj> scene, 
							   boost::shared_ptr<RotateAnimation> needle,
							   boost::shared_ptr<RotateAnimation> rotate,
							   int nAngle,
							   int rAngle
							   ):_scene(scene), _needle(needle), _rotate(rotate) 
{
	_needle->play(RotateAnimation::getStartAll(needle->getAngle(), nAngle),15.f);
	_rotate->play(RotateAnimation::getStartAll(_rotate->getAngle(), rAngle),20.f);
}
GlodGameRotate::~GlodGameRotate(void)
{

}

void GlodGameRotate::clear(void)
{
	if(_GlodGameRotateMusic != NULL)
	{
		_GlodGameRotateMusic->unload();
	}

	for(int i =0; i<24; ++i)
	{
		_scene->getAnimal(i)->play(WheelEnum::ACTION1);
	}
}

void GlodGameRotate::enable(void)
{
	_GlodGameRotateMusic = ISoundManager::getSingleton().createPlayer("Bonus.wav",true);
	_GlodGameRotateMusic->load();
	_GlodGameRotateMusic->play(0);
	_GlodGameRotateMusic->setVolume(0.3f);


	for(int i =0; i<24; ++i)
	{
		_scene->getAnimal(i)->play(WheelEnum::ACTION2);
	}


}

bool GlodGameRotate::update(TimeType interval)
{
	_update2enable();
	bool a = _needle->update(interval);
	bool b = _rotate->update(interval); 
	return b||a ;
}
////////////////////////////////////////////////////////////////////////



GlodProcess5::GlodProcess5():_time(0.f)
{

}


GlodProcess5::~GlodProcess5(void)
{

}

void GlodProcess5::enable(void)
{

	_time = 0.f;
}

bool GlodProcess5::update(Orz::TimeType interval)
{

	return false;
}

void GlodProcess5::clear(void)
{

}




/////////////////////////////////////////////////////////////////////////////////////

class GlodAllProcess: public WheelAnimalProcess
{
public:
	GlodAllProcess(  boost::shared_ptr<WheelAnimalSceneObj> scene, int winner, const Ogre::Degree & angle,   GoldPtr gold, WinEffectPtr effect)
	{
		_first.reset(new GlodShowWinner( scene, effect ,winner, angle));
		

		_second.reset(new GlodPlayAnimation(scene, gold,winner));
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


ProcessFactoryGold::ProcessFactoryGold(
									    
									   boost::shared_ptr<WheelAnimalSceneObj> scene,
									   WinEffectPtr effect,
									   GoldPtr gold,
									   boost::shared_ptr<RotateAnimation> needle,
									   boost::shared_ptr<RotateAnimation> rotate,
									   ObjectLightsPtr objLights
									   ):ProcessFactory( scene, objLights),
									   _needle(needle),_rotate(rotate),_gold(gold),_effect(effect)
{
}
ProcessFactoryGold::~ProcessFactoryGold(void)
{

}
Process0Ptr ProcessFactoryGold::createProcess0(void)
{
	return Process0Ptr();
}
ProcessPtr ProcessFactoryGold::createProcess1(void)
{
	return ProcessPtr(new GlodProRun(_scene,_ac));
}
ProcessPtr ProcessFactoryGold::createProcess2(void)
{
	return ProcessPtr(new GlodGameRotate(_scene, _needle, _rotate, _nAngle, _rAngle));

}
ProcessPtr ProcessFactoryGold::createProcess3(void)
{
	return ProcessPtr(new GlodProcess5());

}
ProcessPtr ProcessFactoryGold::createProcess4(void)
{ 
	return ProcessPtr(new GlodAllProcess( _scene, _winner, Ogre::Degree(_rAngle), _gold, _effect));
}
//ProcessPtr ProcessFactoryGold::createProcess5(void)
//{ 
//	return ProcessPtr(new GlodProcess5());
//}