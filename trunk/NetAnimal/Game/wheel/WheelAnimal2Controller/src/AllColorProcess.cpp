#include "WheelAnimalControllerStableHeaders.h"
#include "AllColorProcess.h"
#include "RotateAnimation.h"
using namespace Orz;

/////////////////////////////////预旋转过程/////////////////////////////////////////////

ColorProRun::ColorProRun(boost::shared_ptr<WheelAnimalSceneObj> scene, boost::shared_ptr<ColorChange> cc):_time(0.f),_scene(scene),_cc(cc),_ProRunMusicIsEnd(false)
{
	std::cout<<"ColorProRun is Start!!!!!!!!!"<<std::endl;

	_allColorProRunMusic = ISoundManager::getSingleton().createPlayer("Pre_1.wav", true);
	_allColorProRunMusic->load();
	_allColorProRunMusic->play(1);

	//_as = scene->getSceneAnimation(SCENE_ANIMATION_0);
	//_as->setEnabled(true);
	//_as->setLoop(false);
}

bool ColorProRun::update(TimeType interval)
{
	_update2enable();
	//_as->addTime(interval);
	//bool ret = _cc->getRise()->update(interval);
	
	bool isPlayingMusic = _allColorProRunMusic->playing();
	if( isPlayingMusic == false && _allColorProRunMusic != NULL && _ProRunMusicIsEnd == false)
	{
		_allColorProRunMusic->unload();
		ISoundManager::getSingleton().quickPlay("Pre_2.wav");
		_ProRunMusicIsEnd = true;
	}
	
	_time += interval;
	if(_time > 7.5f)
		return false;

	/*if(!_as->hasEnded() || ret || !_ProRunMusicIsEnd)
		return true;
	return false;*/
	return true;
}

ColorProRun::~ColorProRun(void)
{
	
}

void ColorProRun::clear(void)
{
		
	//_as->setEnabled(true);
	//_as->setTimePosition(0.f);
	_scene->clearLight();
}
		
void ColorProRun::enable(void)
{
	_scene->clearLight();
	_scene->addLight(WheelEnum::Red);
	_scene->addLight(WheelEnum::Green);
	_scene->addLight(WheelEnum::Yellow);
	_scene->addLight(WheelEnum::Blue);
	_scene->addLight(WheelEnum::DeepBlue);
}


//////////////////////////////////旋转过程//////////////////////////////////////////////////

ColorGameRotate::ColorGameRotate( boost::shared_ptr<WheelAnimalSceneObj> scene, boost::shared_ptr<ColorChange> cc, 
								 boost::shared_ptr<RotateAnimation> needle, 
								 boost::shared_ptr<RotateAnimation> rotate,
								 int winner,
								 float nAngle,
								 float rAngle
								 ):
_scene(scene), _cc(cc), _needle(needle), _rotate(rotate),_color(WinData::getInstance().getLightColor()),_winner(winner),_isContinue(false)
{

	_as = scene->getSceneAnimation(SCENE_ANIMATION_0);
	_as->setEnabled(true);
	_as->setLoop(false);

	_needle->play(RotateAnimation::getStartAll(needle->getAngle(), nAngle),15.f);
	_rotate->play(RotateAnimation::getStartAll(_rotate->getAngle(), rAngle),20.f);



}

void ColorGameRotate::clear(void)
{		  
	
		if( _allColorGameRotateMusic)
				_allColorGameRotateMusic->unload();
	for(int i =0; i<24; ++i)
	{
		_scene->getAnimal(i)->play(WheelEnum::ACTION1);
	}

	_as->setEnabled(true);
	_as->setTimePosition(0.f);

	//_needle->reset();
	//_rotate->reset(); 
}

ColorGameRotate::~ColorGameRotate(void)
{		  

}

void ColorGameRotate::enable(void)
{


	_allColorGameRotateMusic = ISoundManager::getSingleton().createPlayer("Win_1.wav", true);
	_allColorGameRotateMusic->load();
	_allColorGameRotateMusic->play(0);
	_allColorGameRotateMusic->setVolume(0.7f);

	for(int i =0; i<24; ++i)
	{
		_scene->getAnimal(i)->play(WheelEnum::ACTION2);
	}
}


bool ColorGameRotate::update(TimeType interval)
{

	_update2enable();
	
	_as->addTime(interval);
	
	if(_isContinue == false)
	{
		bool ret = _cc->getRise(50.0f)->update(interval);

		if(!_as->hasEnded() || ret )
		{
			return true;
		}
		else
		{
			_isContinue = true;
		}
	}
	
	if(_isContinue == true)
	{
		bool a = _needle->update(interval);
		bool b = _rotate->update(interval);
	
		if( b||a )
			return true;
		else
		{
			_cc->stop(_color);
			
		
			return false;
		}
	}
	return true;
}


///////////////////////////////////显示胜利者////////////////////////////////////////////////

ColorShowWinner::ColorShowWinner( boost::shared_ptr<WheelAnimalSceneObj> scene,  ObjectLightsPtr objLights ,int winner, int offset):
_scene(scene),
_offset(offset),
_n(0), 
_playanimtion(false),
_color(WinData::getInstance().getLightColor()), 
_objLights(objLights),
_winner(winner)
{
	
	
}

ColorShowWinner::~ColorShowWinner(void)
{

	
}

void ColorShowWinner::clear(void)
{
	_scene->clearLight();
	_animation = _scene->getSceneAnimation(SCENE_ANIMATION_0);
	_animation->setEnabled(true);
	_animation->setTimePosition(0.f);
	if(_winnerAnim)
		_winnerAnim->reset();

	_winner = -1;
	_playanimtion = false;
	_n = 0;
	std::vector<int>::iterator it;
	for(it = _ns.begin(); it != _ns.end(); ++it)
	{
		_scene->showBaseLight(*it, _color,false);
	}
	_ns.clear();
}

void ColorShowWinner::enable(void)
{
	switch( _color )
	{
	case 0:
			ISoundManager::getSingleton().quickPlay("color_r.wav");
		break;
	case 1:
			ISoundManager::getSingleton().quickPlay("color_y.wav");
		break;
	case 2:
			ISoundManager::getSingleton().quickPlay("color_g.wav");
		break;
	}
	

	_scene->clearLight();
	_scene->addLight(_color);
	_scene->addLight(_color);
	_scene->addLight(_color);
	_scene->addLight(WheelEnum::DeepBlue);
}

bool ColorShowWinner::update(TimeType interval)
{
	_update2enable();
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

	if(_objLights->getLight((_n+_offset+24)%24) == _color)
	{
		int winner = (_n+_winner)%24;	

		if(_scene->getAnimal(winner)->getType().second != WheelEnum::KING )
		{
			ISoundManager::getSingleton().quickPlay("Poniter.wav");
			_winnerAnim.reset();
			_winnerAnim.reset(new WinnerAnimationNoMove("test", _scene->getBase(winner)));
			_scene->showBaseLight(winner, _color);
			_ns.push_back(winner);
			_winnerAnim->play();
			_playanimtion = true;
		}

	}
	_n++;
	return true;
}


///////////////////////////////////播放送颜色的动作////////////////////////////////////////////////
	
ColorPlayAnimation::ColorPlayAnimation():_time(0.f)
{

}

ColorPlayAnimation::~ColorPlayAnimation(void)
{

}

void ColorPlayAnimation::enable(void)
{
	
	_time = 0.f;
}

bool ColorPlayAnimation::update(Orz::TimeType interval)
{
	_update2enable();
	_time+= interval;
	if(_time >=3.0)
		return false;
	return true;
}

void ColorPlayAnimation::clear(void)
{

}
////////////////////////////////////////////////////////////////////////



ColorProcess5::ColorProcess5():_time(0.f)
{

}


ColorProcess5::~ColorProcess5(void)
{

}

void ColorProcess5::enable(void)
{

	_time = 0.f;
}

bool ColorProcess5::update(Orz::TimeType interval)
{

	return false;
}

void ColorProcess5::clear(void)
{

}

///////////////////////////////////送颜色的工厂////////////////////////////////////////////////

ProcessFactoryAllColor::ProcessFactoryAllColor(
	 
	boost::shared_ptr<WheelAnimalSceneObj> scene,
	boost::shared_ptr<ColorChange> cc,
	boost::shared_ptr<RotateAnimation> needle,
	boost::shared_ptr<RotateAnimation> rotate,
	ObjectLightsPtr objLights
	):ProcessFactory(scene, objLights),_cc(cc),
	_needle(needle),_rotate(rotate)//,_color(color)
{

}

ProcessFactoryAllColor::~ProcessFactoryAllColor(void)
{

}

Process0Ptr ProcessFactoryAllColor::createProcess0(void)
{

	return Process0Ptr();
}

ProcessPtr ProcessFactoryAllColor::createProcess1(void)
{

	return ProcessPtr(new ColorProRun(_scene, _cc));	
}

ProcessPtr ProcessFactoryAllColor::createProcess2(void)
{
	return ProcessPtr(new ColorGameRotate(_scene, _cc, _needle, _rotate, _winner, _nAngle, _rAngle));	
}

ProcessPtr ProcessFactoryAllColor::createProcess3(void)
{
	return ProcessPtr(new ColorShowWinner(_scene, _objLights, _winner, _offset));

}

ProcessPtr ProcessFactoryAllColor::createProcess4(void)
{
	return ProcessPtr(new ColorPlayAnimation());

}
//
//ProcessPtr ProcessFactoryAllColor::createProcess5(void)
//{
//	return ProcessPtr(new ColorProcess5());
//
//}