
#include "NewGameComponentsStableHeaders.h"	
#include "SceneProcessComponent.h"	
#include "CNewGameSceneInterface.h"
#include "CGameActionInterface.h"

#include "ParticleUniverse/ParticleUniverseSystemManager.h"
#include "ParticleUniverse/ParticleUniverseSystem.h"

using namespace Orz;
SceneProcessComponent::SceneProcessComponent(void):_actionInterface(new CGameActionInterface())
{
	_sceneComponent = Orz::ComponentFactories::getInstance().create("NewGameScene");
	CNewGameSceneInterface * scene = _sceneComponent->queryInterface<CNewGameSceneInterface>();
	scene->load();
	_actionInterface->activate = boost::bind(&SceneProcessComponent::activate, this, _1);

	scene->reset();
	_light =  Orz::ISoundManager::getSingleton().createPlayer("LightLoop.wav");
	_light->load();
	_rain =  Orz::ISoundManager::getSingleton().createPlayer("Rain_Loop06.wav");
	_rain->load();


	ParticleUniverse::ParticleSystemManager* psm  = ParticleUniverse::ParticleSystemManager::getSingletonPtr(); 

	_system = psm->createParticleSystem("winnomove", "newgame_winnomove", Orz::OgreGraphicsManager::getSingletonPtr()->getSceneManager());
	Orz::OgreGraphicsManager::getSingleton().getSceneManager()->getRootSceneNode()->attachObject(_system); 

}
SceneProcessComponent::~SceneProcessComponent(void)
{
	ParticleUniverse::ParticleSystemManager* psm  = ParticleUniverse::ParticleSystemManager::getSingletonPtr(); 

	if(_system!=NULL)
	{
		psm->destroyParticleSystem(_system,
			Orz::OgreGraphicsManager::getSingleton().getSceneManager());
		_system = NULL;
	}
	_rain->unload();
	_light->unload();
}

bool SceneProcessComponent::enable(void)
{
	_light->play(-1);
	CNewGameSceneInterface * scene = _sceneComponent->queryInterface<CNewGameSceneInterface>();
	_actionInterface->update = boost::bind(&SceneProcessComponent::update, this, _1);//scene->update;

	return true;
}
void SceneProcessComponent::disable(void)
{
	_light->stop();
}
bool _no_update(TimeType i)
{
	return false;
}
bool SceneProcessComponent::update(TimeType i)
{
	CNewGameSceneInterface * scene = _sceneComponent->queryInterface<CNewGameSceneInterface>();
	bool ret = scene->update(i);
	if(!ret)
	{
		_light->stop();
		_actionInterface->update = boost::bind(&_no_update, _1);
	}
	return ret;
}
bool SceneProcessComponent::winUpdate(TimeType time)
{


	if(_time <=0.f)
	{
		CNewGameSceneInterface * scene = _sceneComponent->queryInterface<CNewGameSceneInterface>();
		return scene->update(time);
	}
	else
	{
		_time -= time;
		return true;
	}
}
bool SceneProcessComponent::winEnable(CNewGameSceneInterface::CAM_DIRECTION camDirection, TimeType passtime, TimeType time, bool effect)
{

	if(effect)
		_system->start();
	_time = time;
	CNewGameSceneInterface * scene = _sceneComponent->queryInterface<CNewGameSceneInterface>();
	scene->moveCamera_win(camDirection,passtime);
	_actionInterface->update = boost::bind(&SceneProcessComponent::winUpdate, this, _1);
	return true;
}

//void SceneProcessComponent::winDisable(void)
//{
//
//	//();
//}

//bool playUpdate(TimeType i)
//{
//	return false;
//}



bool SceneProcessComponent::playEnable(void)
{
	return true;
}
void SceneProcessComponent::playDisable(void)
{	
	_system->stopFade();
}

bool SceneProcessComponent::enableLighting()
{

	CNewGameSceneInterface * scene = _sceneComponent->queryInterface<CNewGameSceneInterface>();
	scene->enableLightningStorm(true);
	_rain->play(-1);
	Orz::OgreGraphicsManager::getSingleton().getSceneManager()->setAmbientLight(Ogre::ColourValue(0.7f,0.8f, 0.7f));
	_time = 2.0;
	_actionInterface->update = boost::bind(&SceneProcessComponent::winUpdate, this, _1);
	//_actionInterface->update = scene->update;
	return true;
}
bool SceneProcessComponent::activate(SanProcess process)
{
	if(process == PROCESS_START)
	{
		_actionInterface->enable = boost::bind(&SceneProcessComponent::enable, this);
		_actionInterface->disable = boost::bind(&SceneProcessComponent::disable, this);
		return true;
	}

	if(process == PROCESS_PRORUN)
	{
		if(WinData::getInstance().getWinMode() == Orz::WheelEnum::DOUBLE || WinData::getInstance().getWinMode() == Orz::WheelEnum::TREBLE)
		{
			_actionInterface->enable =  boost::bind(&SceneProcessComponent::enableLighting, this);
			_actionInterface->disable = boost::bind(&___disable);

			return true;
		}

	}



	if(process == PROCESS_WIN)
	{

		switch(WinData::getInstance().getWinMode())
		{

		case Orz::WheelEnum::GOLD:
			{
				CNewGameSceneInterface * scene = _sceneComponent->queryInterface<CNewGameSceneInterface>();
				scene->enableGoldWineffect(true, WinData::getInstance().getBonus());
				_actionInterface->enable = boost::bind(&SceneProcessComponent::winEnable, this, CNewGameSceneInterface::Farward, 2, 3.f, true);
				_actionInterface->disable = boost::bind(&___disable);
				return true;
			}
			break;
		case Orz::WheelEnum::MANY:
			return false;
			break;
		case Orz::WheelEnum::ALL_COLOR:

			return false;
			break;
		case Orz::WheelEnum::ALL_ANIMAL:
			return false;
			break;


		default:
			_actionInterface->enable = boost::bind(&SceneProcessComponent::winEnable, this, CNewGameSceneInterface::Farward, 2, 3.f, false);
			_actionInterface->disable = boost::bind(&___disable);
		}




		return true;
	}

	if(process == PROCESS_PLAY)
	{

		switch(WinData::getInstance().getWinMode())
		{

		case Orz::WheelEnum::MANY:
		case Orz::WheelEnum::ALL_COLOR:
		case Orz::WheelEnum::ALL_ANIMAL:
			_actionInterface->disable = boost::bind(&___disable);
			break;


		default:
			_actionInterface->disable = boost::bind(&SceneProcessComponent::playDisable, this);
		}



		_actionInterface->enable = boost::bind(&SceneProcessComponent::playEnable, this);
		_actionInterface->update = boost::lambda::constant(false);


		return true;
	}
	if(process == PROCESS_END)
	{
		switch(WinData::getInstance().getWinMode())
		{

		case Orz::WheelEnum::DOUBLE:
		case Orz::WheelEnum::TREBLE:
			{
				CNewGameSceneInterface * scene = _sceneComponent->queryInterface<CNewGameSceneInterface>();
				scene->enableLightningStorm(false);
				_rain->stop();
				Orz::OgreGraphicsManager::getSingleton().getSceneManager()->setAmbientLight(Ogre::ColourValue(1,1,1));
			}
			break;
		case Orz::WheelEnum::MANY:

		case Orz::WheelEnum::ALL_COLOR:


		case Orz::WheelEnum::ALL_ANIMAL:
			_actionInterface->enable = boost::lambda::constant(true);
			_actionInterface->update = boost::lambda::constant(false);
			break;


		default:
			_actionInterface->enable = boost::bind(&SceneProcessComponent::winEnable, this, CNewGameSceneInterface::Backoff, 1, 0.f,false);
		}

		CNewGameSceneInterface * scene = _sceneComponent->queryInterface<CNewGameSceneInterface>();
		_actionInterface->disable = scene->reset;


		//t;boost::bind(&SceneProcessComponent::winDisable, this);
		return true;
	}

	if(process == PROCESS_LOGO)
	{
		switch(WinData::getInstance().getWinMode())
		{
		case Orz::WheelEnum::GOLD:
			{
				CNewGameSceneInterface * scene = _sceneComponent->queryInterface<CNewGameSceneInterface>();
				scene->enableGoldWineffect(false, WinData::getInstance().getBonus());
			}
			break;
		case Orz::WheelEnum::DOUBLE:
		case Orz::WheelEnum::TREBLE:
			{
				CNewGameSceneInterface * scene = _sceneComponent->queryInterface<CNewGameSceneInterface>();
				scene->enableLightningStorm(false);
				_rain->stop();
				Orz::OgreGraphicsManager::getSingleton().getSceneManager()->setAmbientLight(Ogre::ColourValue(1,1,1));
			}
			break;
		}
		return false;
	}

	return false;
}

ComponentInterface * SceneProcessComponent::_queryInterface(const TypeInfo & info)
{

	if(info == TypeInfo(typeid(CGameActionInterface)))
		return _actionInterface.get();

	if(info == TypeInfo(typeid(CNewGameSceneInterface)))
		return _sceneComponent->_queryInterface(info);

	return NULL;
}
