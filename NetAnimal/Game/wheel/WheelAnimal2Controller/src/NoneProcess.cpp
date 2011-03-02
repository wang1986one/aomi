#include "WheelAnimalControllerStableHeaders.h"
#include "NoneProcess.h"
#include <orz/View_OGRE3D/OgreGraphicsManager.h>
#include "WinData.h"
using namespace Orz;

NoneProRun::NoneProRun(void):_time(0.f)
{
	std::cout<<"*********************NoneProRun::NoneProRun***********************"<<std::endl;
}
bool NoneProRun::update(TimeType interval)
{

	_update2enable();
	_time += interval;
	if(_time > 7.5f)
	{

		if(_NoneGameRotateMusic )
			_NoneGameRotateMusic->unload();
		return false;
	}
	return true;
}
NoneProRun::~NoneProRun(void)
{

}	

void NoneProRun::enable(void)
{
	_NoneGameRotateMusic = ISoundManager::getSingleton().createPlayer("S_Pointer.wav",true);

	_NoneGameRotateMusic->load();
	_NoneGameRotateMusic->setVolume(0.3f);
	_NoneGameRotateMusic->play(0);
}
void NoneProRun::clear(void)
{

}


////////////////////////////////////////////////////////////////////////


NoneGameRotate::NoneGameRotate(boost::shared_ptr<WheelAnimalSceneObj> scene, 
							   boost::shared_ptr<RotateAnimation> needle,
							   boost::shared_ptr<RotateAnimation> rotate,
							   int nAngle,
							   int rAngle
							   ):_scene(scene), _needle(needle), _rotate(rotate) 
{


	_needle->play(RotateAnimation::getStartAll(needle->getAngle(), nAngle),15.f);
	_rotate->play(RotateAnimation::getStartAll(_rotate->getAngle(), rAngle),20.f);
}

NoneGameRotate::~NoneGameRotate(void)
{

}

void NoneGameRotate::clear(void)
{

	for(int i =0; i<24; ++i)
	{
		_scene->getAnimal(i)->play(WheelEnum::ACTION1);
	}
}

void NoneGameRotate::enable(void)
{


	_NoneGameRotateMusic = ISoundManager::getSingleton().createPlayer("Win_3.wav",true);

	_NoneGameRotateMusic->load();
	_NoneGameRotateMusic->setVolume(0.3f);
	_NoneGameRotateMusic->play(0);
	std::cout<<"*********************NoneGameRotate::NoneGameRotate***********************"<<std::endl;

	for(int i =0; i<24; ++i)
	{
		_scene->getAnimal(i)->play(WheelEnum::ACTION2);
	}

}

bool NoneGameRotate::update(TimeType interval)
{
	_update2enable();
	bool a = _needle->update(interval);
	bool b = _rotate->update(interval); 
	bool ret = b||a;
	if(ret)
		return true;

	if(_NoneGameRotateMusic )
		_NoneGameRotateMusic->unload();
	return false;
}

///////////////////////////////////////////////////////////////////////////


void NoneShowWinner::clear()
{

	if(_NoneGameMusic)
	{
		_NoneGameMusic->unload();

	}
	_scene->clearLight();


	_scene->showBaseLight(_winner, WinData::getInstance().getLightColor(), false);
	_animation->setEnabled(true);
	_animation->setTimePosition(0.f);
	_camAnimation->setEnabled(true);
	_camAnimation->setTimePosition(0.f);
	if(_winnerAnim)
		_winnerAnim->reset();




}

NoneShowWinner::~NoneShowWinner(void)
{


}


NoneShowWinner::NoneShowWinner(  boost::shared_ptr<WheelAnimalSceneObj> scene, int winner, const Ogre::Degree & rAngle, float nAngle):_scene(scene),_winner(winner),_nAngle(nAngle)
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
	_end->yaw(rAngle) ;
	_winnerAnim.reset(new WinnerAnimation("test_3", _scene->getBase(_winner), _end));
	_winnerAnim->play();
}

void NoneShowWinner::enable(void)
{
	std::cout<<"*********************NoneShowWinner::NoneShowWinner***********************"<<std::endl;
	std::cout<<_nAngle<<"!"<<(int((_nAngle/15))%24)<<std::endl;
	int n = (int(_nAngle/15) + 5);
	int table = WinData::getInstance().getSecondWinnerId();
	_scene->setTableLiang((n)%24, table);
	_NoneGameMusic =  ISoundManager::getSingleton().createPlayer("Win_2.wav", true);
	_NoneGameMusic->load();
	_NoneGameMusic->play(0);

	_NoneGameMusic->setVolume(0.3f);
	ISoundManager::getSingleton().quickPlay("sucess.wav");

	if( WinData::getInstance().getType() == WheelEnum::LION && WinData::getInstance().getLightColor() == WheelEnum::Red )
	{
		ISoundManager::getSingleton().quickPlay("r_lion.wav");
	}

	if( WinData::getInstance().getType() == WheelEnum::LION && WinData::getInstance().getLightColor() == WheelEnum::Green )
	{
		ISoundManager::getSingleton().quickPlay("g_lion.wav");
	}

	if( WinData::getInstance().getType() == WheelEnum::LION && WinData::getInstance().getLightColor() == WheelEnum::Yellow )
	{
		ISoundManager::getSingleton().quickPlay("y_lion.wav");
	}



	if( WinData::getInstance().getType() == WheelEnum::RABBIT && WinData::getInstance().getLightColor() == WheelEnum::Red )
	{
		ISoundManager::getSingleton().quickPlay("r_rabbit.wav");
	}

	if( WinData::getInstance().getType() == WheelEnum::RABBIT && WinData::getInstance().getLightColor() == WheelEnum::Green )
	{
		ISoundManager::getSingleton().quickPlay("g_rabbit.wav");
	}

	if( WinData::getInstance().getType() == WheelEnum::RABBIT && WinData::getInstance().getLightColor() == WheelEnum::Yellow )
	{
		ISoundManager::getSingleton().quickPlay("y_rabbit.wav");
	}



	if( WinData::getInstance().getType() == WheelEnum::MONKEY && WinData::getInstance().getLightColor() == WheelEnum::Red )
	{
		ISoundManager::getSingleton().quickPlay("r_monkey.wav");
	}

	if( WinData::getInstance().getType() == WheelEnum::MONKEY && WinData::getInstance().getLightColor() == WheelEnum::Green )
	{
		ISoundManager::getSingleton().quickPlay("g_monkey.wav");
	}

	if( WinData::getInstance().getType() == WheelEnum::MONKEY && WinData::getInstance().getLightColor() == WheelEnum::Yellow )
	{
		ISoundManager::getSingleton().quickPlay("y_monkey.wav");
	}



	if( WinData::getInstance().getType() == WheelEnum::PANDA && WinData::getInstance().getLightColor() == WheelEnum::Red )
	{
		ISoundManager::getSingleton().quickPlay("r_panda.wav");
	}

	if( WinData::getInstance().getType() == WheelEnum::PANDA && WinData::getInstance().getLightColor() == WheelEnum::Green )
	{
		ISoundManager::getSingleton().quickPlay("g_panda.wav");
	}

	if( WinData::getInstance().getType() == WheelEnum::PANDA && WinData::getInstance().getLightColor() == WheelEnum::Yellow )
	{
		ISoundManager::getSingleton().quickPlay("y_panda.wav");
	}
	/**/

	ISoundManager::getSingleton().quickPlay("Fly.wav");

	_scene->showBaseLight(_winner, WinData::getInstance().getLightColor(), true);

	_scene->clearLight();
	_scene->addLight(WinData::getInstance().getLightColor());
	_scene->addLight(WinData::getInstance().getLightColor());
	_scene->addLight(WinData::getInstance().getLightColor());
	_scene->addLight(WheelEnum::Blue);
	_scene->addLight(WheelEnum::Blue);
}

bool NoneShowWinner::update(TimeType interval)
{

	_update2enable();
	if(!_winnerAnim)
	{
		if(_NoneGameMusic)
		{
			_NoneGameMusic->unload();

		}
		return false;
	}
	_animation->addTime(interval);
	_camAnimation->addTime(interval);
	bool ret = _winnerAnim->update(interval) || (!_animation->hasEnded()) || (!_camAnimation->hasEnded());
	if(ret)
		return true;

	return false;
}


////////////////////////////////////////////////////////////////////////////


NonePlayAnimation::NonePlayAnimation(boost::shared_ptr<WheelAnimalSceneObj> scene,  WinEffectPtr effect , int winner):_scene(scene),_effect(effect),_winner(winner) ,_time(0.f)
{

	int ov = WinData::getInstance().getRate(0);//, WinData::getInstance().getAnimalItem());

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

NonePlayAnimation::~NonePlayAnimation(void)
{

}

void NonePlayAnimation::clear(void)
{



	_effect->clear();
}

void NonePlayAnimation::enable(void)
{
	std::cout<<"*********************NonePlayAnimation::NonePlayAnimation***********************"<<std::endl;

	switch(WinData::getInstance().getType())
	{
	case WheelEnum::LION:
		_NonePlayAnimationMusic = ISoundManager::getSingleton().createPlayer("Lion.wav",true);
		//	_NonePlayAnimationMusic->load();
		//	_NonePlayAnimationMusic->play(3);
		break;
	case WheelEnum::RABBIT:
		_NonePlayAnimationMusic = ISoundManager::getSingleton().createPlayer("Rabbit.wav",true);
		//	_NonePlayAnimationMusic->load();
		//	_NonePlayAnimationMusic->play(3);
		break;
	case WheelEnum::MONKEY:
		_NonePlayAnimationMusic = ISoundManager::getSingleton().createPlayer("Monkey.wav",true);
		//_NonePlayAnimationMusic->load();
		//_NonePlayAnimationMusic->play(3);
		break;
	case WheelEnum::PANDA:
		_NonePlayAnimationMusic = ISoundManager::getSingleton().createPlayer("Panda.wav",true);
		//_NonePlayAnimationMusic->load();
		//_NonePlayAnimationMusic->play(3);
		break;
	}
	_NonePlayAnimationMusic->load();
	_NonePlayAnimationMusic->play(0);

	_effect->enable();
	_time = 0.f;
	_scene->getAnimal(_winner)->play(WheelEnum::ACTION3);
}

bool NonePlayAnimation::update(Orz::TimeType interval)
{
	bool ret = _effect->update(interval);
	_update2enable();
	_time+= interval;
	if(_time >=3.0)
	{
		if(!ret)
		{
			if(_NonePlayAnimationMusic != NULL )
				_NonePlayAnimationMusic->unload();
			return false;
		}
	}
	return true;
}

////////////////////////////////////////////////////////////////////////



NoneProcess4::NoneProcess4():_time(0.f)
{

}


NoneProcess4::~NoneProcess4(void)
{

}

void NoneProcess4::enable(void)
{

	_time = 0.f;
}

bool NoneProcess4::update(Orz::TimeType interval)
{

	return false;
}

void NoneProcess4::clear(void)
{

}

////////////////////////////////////////////////////////////////////////


ProcessFactoryNone::ProcessFactoryNone( 
									   boost::shared_ptr<WheelAnimalSceneObj> scene,
									   WinEffectPtr effect,
									   boost::shared_ptr<RotateAnimation> needle,
									   boost::shared_ptr<RotateAnimation> rotate,
									   ObjectLightsPtr objLights
									   ):ProcessFactory( scene, objLights),_effect(effect),
									   _needle(needle),_rotate(rotate)
{

}

ProcessFactoryNone::~ProcessFactoryNone(void)
{

}

Process0Ptr ProcessFactoryNone::createProcess0(void)
{
	return Process0Ptr();
}

ProcessPtr ProcessFactoryNone::createProcess1(void)
{
	return ProcessPtr(new NoneProRun());
}

ProcessPtr ProcessFactoryNone::createProcess2(void)
{
	return ProcessPtr(new NoneGameRotate(_scene, _needle, _rotate, _nAngle, _rAngle));

}

ProcessPtr ProcessFactoryNone::createProcess3(void)
{
	return ProcessPtr(new NoneProcess4( ));
}

class NodeAllProcess: public WheelAnimalProcess
{
public:
	NodeAllProcess(  boost::shared_ptr<WheelAnimalSceneObj> scene, int winner, const Ogre::Degree & rAngle, float nAngle,WinEffectPtr effect)
	{
		_first.reset(new NoneShowWinner( scene,winner, rAngle, nAngle));
		_second.reset(new NonePlayAnimation(scene, effect, winner));
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
ProcessPtr ProcessFactoryNone::createProcess4(void)
{

	
	return ProcessPtr(new NodeAllProcess( _scene,_winner, Ogre::Degree(static_cast<Ogre::Real>(_rAngle)), _nAngle, _effect));

}
//ProcessPtr ProcessFactoryNone::createProcess5(void)
//{
//	return ProcessPtr();
//}