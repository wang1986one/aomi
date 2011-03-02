#include "WheelAnimalControllerStableHeaders.h"
#include "GameRotate.h"
#include "RotateAnimalProcess.h"
#include "RotateAnimation.h"

using namespace Orz;

RotateAnimalProRun::RotateAnimalProRun(boost::shared_ptr<WheelAnimalSceneObj> scene, boost::shared_ptr<AnimalChange> ac):_time(0.f),_scene(scene),_ac(ac)//,_ProRunMusicIsEnd(false),_isMusicPlaying(false)
{




}

void RotateAnimalProRun::enable(void)
{                           
	_RotateAnimalProRunMusic = ISoundManager::getSingleton().createPlayer("barM.wav",true);
	_RotateAnimalProRunMusic->load();
	_RotateAnimalProRunMusic->play(1);

	_scene->clearLight();
	_scene->addLight(WheelEnum::Red);
	_scene->addLight(WheelEnum::Green);
	_scene->addLight(WheelEnum::Yellow);
	_scene->addLight(WheelEnum::Blue);
	_scene->addLight(WheelEnum::DeepBlue);
}

bool RotateAnimalProRun::update(TimeType interval)
{
	_update2enable();
	_time += interval;
	if(_time > 7.5f)
	{
		if(_RotateAnimalProRunMusic)
			_RotateAnimalProRunMusic->unload();
		return false;
	}

	return true;
}

RotateAnimalProRun::~RotateAnimalProRun(void)
{

}

void RotateAnimalProRun::clear(void)
{

	_scene->clearLight();

}


///////////////////////////////////////////////////////////////////

RotateAnimalGameRotate::RotateAnimalGameRotate(boost::shared_ptr<WheelAnimalSceneObj> scene, boost::shared_ptr<AnimalChange> ac,  boost::shared_ptr<RotateAnimation> needle, 
											   boost::shared_ptr<RotateAnimation> rotate,
											   int winner,
											   float rAngle,
											   float nAngle

											   ):_scene(scene), 
											   _ac(ac), 
											   _needle(needle), 
											   _rotate(rotate) ,
											   _winner(winner),
											   _isContiue(false)
{
	_as= scene->getSceneAnimation(SCENE_ANIMATION_0);

	_as->setEnabled(true);
	_as->setLoop(false);

	_needle->play(RotateAnimation::getStartAll(needle->getAngle(),  static_cast<float>(nAngle)),15.f);
	_rotate->play(RotateAnimation::getStartAll(_rotate->getAngle(),  static_cast<float>(rAngle)),20.f);
}

void RotateAnimalGameRotate::clear(void)
{

	if(RotateAnimalGameRotateMusic)
		RotateAnimalGameRotateMusic->unload();
	_as->setEnabled(false);

	for(int i =0; i<24; ++i)
	{
		_scene->getAnimal(i)->play(WheelEnum::ACTION1);
	}
	/*_needle->reset();
	_rotate->reset(); */
}

RotateAnimalGameRotate::~RotateAnimalGameRotate(void)
{


}

void RotateAnimalGameRotate::enable(void)
{
	RotateAnimalGameRotateMusic = ISoundManager::getSingleton().createPlayer("Win_5.wav",true);
	RotateAnimalGameRotateMusic->load();
	RotateAnimalGameRotateMusic->play(0);
	RotateAnimalGameRotateMusic->setVolume(0.3f);

	for(int i =0; i<24; ++i)
	{
		_scene->getAnimal(i)->play(WheelEnum::ACTION2);
	}
}


bool RotateAnimalGameRotate::update(TimeType interval)
{

	_update2enable();

	_as->addTime(interval);

	if(_isContiue == false)
	{
		bool ret = _ac->getRise(30.0f)->update(interval);

		if(!_as->hasEnded() || ret )
		{
			return true;
		}
		else
		{
			_isContiue = true;
		}
	}

	if(_isContiue == true)
	{

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
	return true;
}


/////////////////////////////////////////////////////////////


RotateAnimalShowWinner::RotateAnimalShowWinner(boost::shared_ptr<WheelAnimalSceneObj> scene, int winner, ObjectLightsPtr objLights, float nAngle):
_scene(scene),
_winner(winner),
_n(0),
_playanimtion(false),
_objLights(objLights),
_nAngle(nAngle),
ShowWinnerMusicIsEnd(false)
{

}

RotateAnimalShowWinner::~RotateAnimalShowWinner(void)
{


}

void RotateAnimalShowWinner::clear(void)
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

bool RotateAnimalShowWinner::update(TimeType interval)
{

	WheelEnum::AnimalType type = _scene->getAnimal(_winner)->getType();

	if(ShowWinnerMusicIsEnd == false)
	{
		ShowWinnerMusicIsEnd = true;
		switch(type.first)
		{
		case WheelEnum::LION:
			ISoundManager::getSingleton().quickPlay("ani_lion.wav");
			break;
		case WheelEnum::RABBIT:
			ISoundManager::getSingleton().quickPlay("ani_rabbit.wav");
			break;
		case WheelEnum::MONKEY:
			ISoundManager::getSingleton().quickPlay("ani_monkey.wav");
			break;
		case WheelEnum::PANDA:
			ISoundManager::getSingleton().quickPlay("ani_panda.wav");
			break;
		}
	}

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
		ISoundManager::getSingleton().quickPlay("Poniter.wav");
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


////////////////////////////////////////////////////////////////

RotateAnimalPlayAnimation::RotateAnimalPlayAnimation():_time(0.f)
{
}

RotateAnimalPlayAnimation::~RotateAnimalPlayAnimation(void)
{

}

void RotateAnimalPlayAnimation::enable(void)
{

	_time = 0.f;
}

bool RotateAnimalPlayAnimation::update(Orz::TimeType interval)
{
	_update2enable();
	_time+= interval;
	if(_time >=3.0)
		return false;
	return true;
}
void RotateAnimalPlayAnimation::clear(void)
{

}

//////////////////////////////////////////////////////

RotateAnimalProcess5::RotateAnimalProcess5():_time(0.f)
{

}


RotateAnimalProcess5::~RotateAnimalProcess5(void)
{

}

void RotateAnimalProcess5::enable(void)
{

	_time = 0.f;
}

bool RotateAnimalProcess5::update(Orz::TimeType interval)
{

	return false;
}

void RotateAnimalProcess5::clear(void)
{

}

/////////////////////////////////////////////////////////

ProcessFactoryAllAnimal::ProcessFactoryAllAnimal(

	boost::shared_ptr<WheelAnimalSceneObj> scene,
	boost::shared_ptr<AnimalChange> ac,
	boost::shared_ptr<RotateAnimation> needle,
	boost::shared_ptr<RotateAnimation> rotate,
	ObjectLightsPtr objLights
	):ProcessFactory( scene, objLights),_ac(ac),
	_needle(needle),_rotate(rotate)
{

}

ProcessFactoryAllAnimal::~ProcessFactoryAllAnimal(void)
{

}

Process0Ptr ProcessFactoryAllAnimal::createProcess0(void)
{

	return Process0Ptr();
}

ProcessPtr ProcessFactoryAllAnimal::createProcess1(void)
{

	return ProcessPtr(new RotateAnimalProRun(_scene, _ac));	

}

ProcessPtr ProcessFactoryAllAnimal::createProcess2(void)
{
	return ProcessPtr(new RotateAnimalGameRotate(_scene, _ac, _needle, _rotate,_winner, _nAngle, _rAngle));	
}

ProcessPtr ProcessFactoryAllAnimal::createProcess3(void)
{
	return ProcessPtr(new RotateAnimalShowWinner(_scene, _winner, _objLights, _nAngle));

}

ProcessPtr ProcessFactoryAllAnimal::createProcess4(void)
{

	return ProcessPtr(new RotateAnimalPlayAnimation());			
}
//ProcessPtr ProcessFactoryAllAnimal::createProcess5(void)
//{
//
//	return ProcessPtr(new RotateAnimalProcess5());			
//}