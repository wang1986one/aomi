#include "WheelAnimalControllerStableHeaders.h"
#include "TVProcess.h"
#include "ComputeWinner.h"
#include "WheelAnimalUI.h"
using namespace Orz;
void TVShowWinner::enable()
{
	//_winnerAnim.reset(new WinnerAnimationNoMove("TVShowWinner", _scene->getBase(_winner)));

	Orz::WheelAnimalUI::getSingleton().showTVUI(true);
	_ai = WinData::getInstance().getAnimalItem();
	up(_winner, WinData::getInstance().getLightColor());
}

void TVShowWinner::clear()
{
	std::vector<int>::iterator it;
	for(it = _clear.begin(); it != _clear.end(); ++it)
	{
		_scene->showBaseLight(*it, _color, false);
	}

	_winnerAnim.reset();
	_clear.clear();
}
TVShowWinner::~TVShowWinner(void)
{


}


TVShowWinner::TVShowWinner(
						     boost::shared_ptr<WheelAnimalSceneObj> scene,  boost::shared_ptr<TV> tv, int winner, 
						   boost::shared_ptr<RotateAnimation> needle, 
						   boost::shared_ptr<RotateAnimation> rotate,
						   ObjectLightsPtr objectLights
						   ):_scene(scene), _winner(winner),
						   _needle(needle), _rotate(rotate),
						   _winNumber(0), 
						   _objectLights(objectLights),_tv(tv)
{
	switch(WinData::getInstance().getWinMode())
	{
	case WheelEnum::MANY:
		_all = _winNumber = WinData::getInstance().size() -1;
		break;
	/*case WheelEnum::TWO:
		_all = _winNumber = 2;
		break;
	case WheelEnum::THREE:
		_all = _winNumber = 3;
		break;
	case WheelEnum::FOUR:
		_all = _winNumber = 4;
		break;
	case WheelEnum::FIVE:
		_all = _winNumber = 5;
		break;*/

	}
}


void TVShowWinner::up(int winner, WheelEnum::LIGHT_COLOR color)
{		
	ISoundManager::getSingleton().quickPlay("sucess.wav");
	Orz::WheelAnimalUI::getSingleton().addTVUI(_ai);
	_winnerAnim.reset(new WinnerAnimationNoMove("TVShowWinner", _scene->getBase(winner)));
	_scene->showBaseLight(winner, color);
	_clear.push_back(winner);
}
int TVShowWinner::needleRotate(WheelEnum::ANIMAL_TYPE at, WheelEnum::LIGHT_COLOR color)
{

	int winner = _scene->findRandomAnimal(at);
	int offset = _objectLights->getRandomLight(color);

	ComputeWinner c;

	c.compute(winner, offset, 5);
	float rAngle = c.getRotate() *15.f;
	float nAngle = c.getNeedle() *15.f;

	//_needle->reset();
	//_rotate->reset();

	_needle->play(  RotateAnimation::getStartAll(_needle->getAngle(), nAngle), 15.f);
	_rotate->play(  RotateAnimation::getStartAll(_rotate->getAngle(), rAngle), 20.f);
	return winner;


}




bool TVShowWinner::update(TimeType interval)
{

	_update2enable();
	if(_winnerAnim)
	{
		if(_winnerAnim->update(interval)) 
		{
			return true;
		}
		else
		{
			if(_winNumber == 0)
			{

				return false;
			}

			 _ai = WinData::getInstance().getAnimalItem(_all - _winNumber +1);//WheelData::getInstance().getTVNext(WinData::getInstance().getWinMode(), WinData::getInstance().getAnimalItem(),_all - _winNumber +1);
			//_ai = Orz::WheelEnum::getSingleton().getTVNext();
			_winnerAnim.reset();
			_winner = needleRotate(WheelEnum::ANIMAL_TYPE(_ai.first, WheelEnum::PEOPLE), _ai.second);
			_color = _ai.second;
			_winNumber--;
			return true;
		}
	}
	else 
	{

		bool retA = _needle->update(interval);
		bool retB = _rotate->update(interval);
		if( retA || retB )
		{

			return true;
		}
		else
		{
			_tv->setNumber(_winNumber);

			up(_winner, _color);
			return true;
		}

	}



	return false;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


TVProRun::TVProRun(boost::shared_ptr<WheelAnimalSceneObj> scene, boost::shared_ptr<TV> tv):_tv(tv),_TVProRunIsEnd(false),_TVProRunIsPlaying(true),_time(0.0f)
{


}
bool TVProRun::update(TimeType interval)
{
	if(_TVProRunIsEnd == false)
	{
		_TVProRunMusic = ISoundManager::getSingleton().createPlayer("barM.wav",true);
		_TVProRunMusic->load();
		_TVProRunMusic->play(1);
		_TVProRunIsEnd = true;
	}
	bool TVProRunMusicIsPlaying = _TVProRunMusic->playing();

	if( TVProRunMusicIsPlaying == false && _TVProRunIsPlaying == true )
	{
		ISoundManager::getSingleton().quickPlay("prize_light.wav");
		_TVProRunIsPlaying = false;
	}

	_time += interval;
	if(_time > 7.5f)
		return false;
	return true;
}
TVProRun::~TVProRun(void)
{
}
void TVProRun::clear(void)
{
	if(_TVProRunMusic != NULL)
	{
		_TVProRunMusic->unload();
	}
	Orz::WheelAnimalUI::getSingleton().showTVUI(false);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////

TVGameRotate::TVGameRotate(  boost::shared_ptr<WheelAnimalSceneObj> scene, boost::shared_ptr<TV> tv, 
						   boost::shared_ptr<RotateAnimation> needle, 
						   boost::shared_ptr<RotateAnimation> rotate,
						   float nAngle,
						   float rAngle
								 ):
_scene(scene), _tv(tv), _needle(needle), _rotate(rotate),_isDown(-1.f),_downTime(0.f),_isContinue(false)
{

	_as= scene->getSceneAnimation(SCENE_ANIMATION_0);
	_as->setEnabled(true);
	_as->setLoop(false);

	_needle->play(RotateAnimation::getStartAll(needle->getAngle(), static_cast<float>(nAngle)),15.f);
	_rotate->play(RotateAnimation::getStartAll(_rotate->getAngle(), static_cast<float>(rAngle)),20.f);
}

void TVGameRotate::clear(void)
{		  
	if(_TVGameRotateMusic != NULL)
	{
		_TVGameRotateMusic->unload();
	}

	for(int i =0; i<24; ++i)
	{
		_scene->getAnimal(i)->play(WheelEnum::ACTION1);
	}
	_as->setEnabled(true);
	_as->setTimePosition(0.f);
	_scene->clearLight();
}

TVGameRotate::~TVGameRotate(void)
{		  

}
void TVGameRotate::enable(void)
{
	_TVGameRotateMusic = ISoundManager::getSingleton().createPlayer("SZ_Back.wav",true);
	_TVGameRotateMusic->load();
	_TVGameRotateMusic->play(0);
	_TVGameRotateMusic->setVolume(0.7f);

	for(int i =0; i<24; ++i)
	{
		_scene->getAnimal(i)->play(WheelEnum::ACTION2);
	}

	_downTime = 0.f;

	_scene->clearLight();
	_scene->addLight(WheelEnum::Red);
	_scene->addLight(WheelEnum::Green);
	_scene->addLight(WheelEnum::Yellow);
	_scene->addLight(WheelEnum::Blue);
	_scene->addLight(WheelEnum::DeepBlue);
}


bool TVGameRotate::update(TimeType interval)
{
	_update2enable();

	_as->addTime(interval);

	if(_isContinue == false)
	{
		bool ret = _tv->getRise(50.0f)->update(interval);

		if( !_as->hasEnded() ||ret)
		{
			return true;
		}
		else{
			_isContinue = true;
		}

	}


	if(_isContinue == true)
	{
		SomethingRise * rise = this->_tv->getRise(50.0f);

		_tv->setNumber(rand()%9 +1);

		if(_downTime >= 0.5f)
		{
			_isDown = 1.0f;
		}

		if(_isDown <=0)
		{
			_downTime +=interval;
		}else
		{
			_downTime = 0.f;
		}
		if(!rise->update(interval * _isDown))
		{
			_isDown = -1.0f;
		}

		bool a = _needle->update(interval);
		bool b = _rotate->update(interval);

		if( b||a )
			return true;
		else
		{
			switch(WinData::getInstance().getWinMode())
			{
			case WheelEnum::MANY:

				_tv->setNumber(WinData::getInstance().size() -1);
				break;
			/*case WheelEnum::TWO:

				_tv->setNumber(2);
				break;
			case WheelEnum::THREE:

				_tv->setNumber(3);
				break;
			case WheelEnum::FOUR:

				_tv->setNumber(4);
				break;
			case WheelEnum::FIVE:

				_tv->setNumber(5);
				break;*/

			}
			return false;
		}
	}
	return true;
}

///////////////////////////////////////////////////////////////////////////////////

TVPlayAnimation::TVPlayAnimation():_time(0.f)
{

}


TVPlayAnimation::~TVPlayAnimation(void)
{

}

void TVPlayAnimation::enable(void)
{

	_time = 0.f;
}

bool TVPlayAnimation::update(Orz::TimeType interval)
{
	_update2enable();
	_time+= interval;
	if(_time >=3.0)
		return false;
	return true;
}

void TVPlayAnimation::clear(void)
{

}


//////////////////////////////////////////////////////

TVProcess5::TVProcess5():_time(0.f)
{

}


TVProcess5::~TVProcess5(void)
{

}

void TVProcess5::enable(void)
{

	_time = 0.f;
}

bool TVProcess5::update(Orz::TimeType interval)
{

	return false;
}

void TVProcess5::clear(void)
{

}

//////////////////////////////////////////////////////




ProcessFactoryTV::ProcessFactoryTV(

								    
								   boost::shared_ptr<WheelAnimalSceneObj> scene,
								   boost::shared_ptr<TV> tv,
								   boost::shared_ptr<RotateAnimation> needle,
								   boost::shared_ptr<RotateAnimation> rotate,
								   ObjectLightsPtr objLights
								   ):ProcessFactory( scene, objLights),_tv(tv),
								   _needle(needle),_rotate(rotate)
{

}
ProcessFactoryTV::~ProcessFactoryTV(void)
{

}
Process0Ptr ProcessFactoryTV::createProcess0(void)
{
	return Process0Ptr();
}
ProcessPtr ProcessFactoryTV::createProcess1(void)
{
	return ProcessPtr(new TVProRun(_scene, _tv));
}
ProcessPtr ProcessFactoryTV::createProcess2(void)
{
	return ProcessPtr(new TVGameRotate(_scene, _tv, _needle, _rotate,  _nAngle, _rAngle));

}
ProcessPtr ProcessFactoryTV::createProcess3(void)
{
	return ProcessPtr(new TVShowWinner( _scene, _tv, _winner,_needle, _rotate, _objLights));

}
ProcessPtr ProcessFactoryTV::createProcess4(void)
{
	return ProcessPtr(new TVPlayAnimation());
}
//ProcessPtr ProcessFactoryTV::createProcess5(void)
//{
//	return ProcessPtr(new TVProcess5());
//}