#include "WheelAnimalControllerStableHeaders.h"
#include "WheelAnimalProcessManager.h"
#include "LightRunning.h"
#include "WheelEvents.h"
#include "BlackBoardSystem.h"

#include "ProcessFactory.h"
#include "DoubleProcess.h"
#include "RotateAnimalProcess.h"
#include "GlodProcess.h"
#include "TVProcess.h"
#include "AllColorProcess.h"
#include "NoneProcess.h"
#include "ReferenceCount.h"
#include <orz/Toolkit_Base/LogSystem.h>
using namespace Orz;


WheelAnimalProcessManager::WheelAnimalProcessManager(
	WheelAnimalScenePtr scene,
	RotateAnimationPtr rotate,
	RotateAnimationPtr needle,
	AnimalChangePtr ac,
	ColorChangePtr cc,
	TVPtr tv,
	GoldPtr gold,
	ObjectLightsPtr objLights,
	WinEffectPtr effect
	):
_scene(scene),
_rotate(rotate),
_needle(needle),
_ac(ac),
_cc(cc),
_tv(tv),
_gold(gold),
_objLights(objLights),
_effect(effect)
{

	_process0.reset(new LightRunning(_objLights));
	_map.insert(std::make_pair<Event::message_type, EventFunction >(
		WheelEvents::PROCESS_START_ENABLE,
		boost::bind(&WheelAnimalProcessManager::lightRunning,this,true, _1)
		));


	_map.insert(std::make_pair<Event::message_type, EventFunction >(
		WheelEvents::PROCESS_START_DISABLE,
		boost::bind(&WheelAnimalProcessManager::startDisable,this,_1)
		));

	/*_map.insert(std::make_pair<Event::message_type, EventFunction >(
	WheelEvents::HOW_WINNER,
	boost::bind(&WheelAnimalProcessManager::resetProcess,this, _1)
	));*/


	_map.insert(std::make_pair<Event::message_type, EventFunction >(
		WheelEvents::PROCESS_PRORUN_ENABLE,
		boost::bind(&WheelAnimalProcessManager::runProcess,this,WheelAnimalProcess::PROCESS1, _1)
		));


	_map.insert(std::make_pair<Event::message_type, EventFunction >(
		WheelEvents::PROCESS_RUN_ENABLE,
		boost::bind(&WheelAnimalProcessManager::runProcess,this,WheelAnimalProcess::PROCESS2, _1)
		));




	_map.insert(std::make_pair<Event::message_type, EventFunction >(
		WheelEvents::PROCESS_WIN_ENABLE,
		boost::bind(&WheelAnimalProcessManager::runProcess,this,WheelAnimalProcess::PROCESS3, _1)
		));



	_map.insert(std::make_pair<Event::message_type, EventFunction >(
		WheelEvents::PROCESS_PLAY_ENABLE,
		boost::bind(&WheelAnimalProcessManager::runProcess,this,WheelAnimalProcess::PROCESS4, _1)
		));


	_map.insert(std::make_pair<Event::message_type, EventFunction >(
		WheelEvents::PROCESS_LOGO_ENABLE,
		boost::bind(&WheelAnimalProcessManager::clearProcess,this, _1)
		));




}

void WheelAnimalProcessManager::resetProcess(Orz::Event * evt)
{

	boost::scoped_ptr<ProcessFactory> factory;

	//Orz::WinTypePtr wintype = Orz::Hardware::getSingleton().getWinType();

	switch(WinData::getInstance().getWinMode())
	{
	case WheelEnum::ALL_ANIMAL:
		factory.reset(new ProcessFactoryAllAnimal(_scene, _ac, _needle, _rotate, _objLights));
		break;
	case WheelEnum::ALL_COLOR:
		factory.reset(new ProcessFactoryAllColor( _scene, _cc, _needle, _rotate, _objLights));
		break;
	case WheelEnum::GOLD:
		factory.reset(new ProcessFactoryGold( _scene,_effect, _gold, _needle, _rotate, _objLights));
		break;
	case WheelEnum::DOUBLE:
	case WheelEnum::TREBLE:
		factory.reset(new ProcessFactoryDouble( _scene, _effect,_needle, _rotate, _objLights));
		break;

	case WheelEnum::MANY:
		/*case WheelEnum::TWO:
		case WheelEnum::THREE:
		case WheelEnum::FOUR:
		case WheelEnum::FIVE:*/
		factory.reset(new ProcessFactoryTV(_scene, _tv, _needle, _rotate, _objLights));
		break;

	}
	if(!factory)	
		factory.reset(new ProcessFactoryNone( _scene, _effect, _needle, _rotate, _objLights));

	for(size_t i = 0; i<_processes.size(); ++i)
	{

		_processes.at(i).reset();
		_processes.at(i) =  factory->createProcess(static_cast<WheelAnimalProcess::PROCESS>(WheelAnimalProcess::PROCESS1 + i));
		/*	it->second.reset();
		it->second =  factory->createProcess(it->first);*/
	}
}
void WheelAnimalProcessManager::update(TimeType interval)
{
	if(_updateFun)
	{
		if(!_updateFun(interval))
		{
			_updateFun.clear();
		}
	}else if(_referenced)
	{
		_referenced.reset();
	}
	_ac->update(interval);
	_cc->update(interval);
}
void WheelAnimalProcessManager::init(void)
{
}
void WheelAnimalProcessManager::shutdown(void)
{

}
void WheelAnimalProcessManager::lightRunning(bool isIn, Orz::Event * evt)
{
	if(isIn)
	{
		_process0->setMode(Orz::WinData::getInstance().getRate());
		//_process0->setMode(WinData::getInstance().getRate());
		_updateFun = boost::bind(&Process0LightRunning::update, _process0.get(), _1);
	}
	else
	{
		_updateFun.clear();
	}

}

void WheelAnimalProcessManager::startDisable(Orz::Event * evt)
{
	lightRunning(false, evt);
	resetProcess(evt);

}
WheelAnimalProcessManager::~WheelAnimalProcessManager(void)
{

}	


void WheelAnimalProcessManager::runProcess(WheelAnimalProcess::PROCESS process,Orz::Event * evt)
{
	_referenced = evt->getData<ReferenceCount *>()->reference();
	ProcessPtr pro = _processes.at(process);
	_updateFun = boost::bind(&WheelAnimalProcess::update, pro.get(), _1);
}
void WheelAnimalProcessManager::notice(Orz::Event * evt)
{

	EventFunctionMap::iterator it = _map.find(WheelEvents::getMsg(evt));
	if(it != _map.end())
	{
		it->second(evt);
	}
	sound(evt);
}

void WheelAnimalProcessManager::sound(Orz::Event * evt)
{
	switch(WheelEvents::getMsg(evt))
	{
	case WheelEvents::PROCESS_LOGO_ENABLE:
		{
			_music = ISoundManager::getSingleton().createPlayer("Start.wav", true);
			_music->load();
			_music->play(1);
		}
		break;
	case WheelEvents::PROCESS_START_ENABLE:
		{
			_music = ISoundManager::getSingleton().createPlayer("Wait.wav", true);
			_music->load();
			_music->play(0);
		}
		break;

	case WheelEvents::PROCESS_START_DISABLE:
		{
			if(_music)
				_music->unload();
			_music.reset();
			ISoundManager::getSingleton().quickPlay("Countdown_2.wav");
		}
		break;
	case WheelEvents::PROCESS_LOGO_DISABLE:
		{
			if(_music)
				_music->unload();
		
			_music.reset();
		}
		break;
	}

}
void WheelAnimalProcessManager::clearProcess(Orz::Event * evt)
{


	for(size_t i = 0; i<_processes.size(); ++i)
	{
		if(_processes.at(i))
			_processes.at(i)->clear();	
	}



	_ac->clear();
	_cc->clear();
	_tv->clear();
	_gold->clear();
}