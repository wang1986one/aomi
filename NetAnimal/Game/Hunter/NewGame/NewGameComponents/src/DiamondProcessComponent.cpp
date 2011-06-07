


#include "NewGameComponentsStableHeaders.h"	
#include "DiamondProcessComponent.h"	
#include "CGameActionInterface.h"
#include "CGameDiamondInterface.h"
#include "CGameBallInterface.h"
#include "ChangeColor.h"
#include "CGameDiamondMoreWinderInterface.h"
#include "CDiamondProcessInterface.h"
#include "DiamondOpenTask.h"
using namespace Orz;
DiamondProcessComponent::DiamondProcessComponent(void):_actionInterface(new CGameActionInterface()),_allTime(0),_processInterface(new CDiamondProcessInterface)
{


	_diamondComp = Orz::ComponentFactories::getInstance().create("GameDiamond");
#ifdef _BALL_
	_ballComp  = Orz::ComponentFactories::getInstance().create("GameBall");
#endif

	_actionInterface->activate = boost::bind(&DiamondProcessComponent::activate, this, _1);
	_processInterface->step = boost::bind(&DiamondProcessComponent::step, this, _1);


	_changeColor.reset(new ChangeColor());

	_changeColor->push_back(Ogre::ColourValue(1, 1, 1));
	_changeColor->push_back(Ogre::ColourValue(1, 0.5f, 0.5f));
	_changeColor->push_back(Ogre::ColourValue(0.5f, 1, 0.5f));
	_changeColor->push_back(Ogre::ColourValue(0.9f, 0.9f, 0.3f));

	_openTask.reset(new DiamondOpenTask());

	//_allTask[std::pair<int, int>(PROCESS_RUN , WheelEnum::GOLD)] = 
}

void DiamondProcessComponent::step(int i)
{
	CGameDiamondMoreWinderInterface * more = _diamondComp->queryInterface<CGameDiamondMoreWinderInterface>();
	more->step();
}
DiamondProcessComponent::~DiamondProcessComponent(void)
{
}
ComponentInterface * DiamondProcessComponent::_queryInterface(const TypeInfo & info) const
{
#ifdef _BALL_


	if(info == TypeInfo(typeid(CGameBallInterface)))
		return _ballComp->_queryInterface(info);
#endif
	if(info == TypeInfo(typeid(CDiamondProcessInterface)))
		return _processInterface.get();
	if(info == TypeInfo(typeid(CGameDiamondInterface)))
		return _diamondComp->_queryInterface(info);
	if(info == TypeInfo(typeid(CGameActionInterface)))
		return _actionInterface.get();
	return NULL;
}
//bool yes_enable(void)
//{
//	return true;
//}
//
//bool yes_update(TimeType time)
//{
//	return false;
//}

bool DiamondProcessComponent::lightEnable(int number)
{
	CGameDiamondMoreWinderInterface * more = _diamondComp->queryInterface<CGameDiamondMoreWinderInterface>();
	more->run(number);
	_actionInterface->update =  boost::lambda::constant(false);//boost::bind(&DiamondProcessComponent::lightUpdate, this, _1);
	_allTime = 0.f;
	return true;
}

bool DiamondProcessComponent::goldEnable(void)
{
	CGameDiamondInterface * diamond = _diamondComp->queryInterface<CGameDiamondInterface>();
	diamond->enable(CGameDiamondInterface::Float);

	_actionInterface->update =  boost::bind(&DiamondProcessComponent::goldUpdate, this, _1);// diamond->update;


	return true;
}

bool DiamondProcessComponent::goldUpdate(TimeType i)
{
	CGameDiamondInterface * diamond = _diamondComp->queryInterface<CGameDiamondInterface>();
	bool ret = diamond->update(i);

	static TimeType color = 0;
	color+=i *7;

	Ogre::SceneManager * sm =Orz::OgreGraphicsManager::getSingleton().getSceneManager();
	if(color >=90)
	{
		color -= 90;
	}
	switch(int(color)%3)
	{
	case 0:
		sm->setAmbientLight(Ogre::ColourValue(1.f,0.7f,0.7f));
		diamond->setDiamondColour(1.f,0.4f,0.3f);
		break;

	case 1:
		sm->setAmbientLight(Ogre::ColourValue(0.7f,1.f,0.7f));
		diamond->setDiamondColour(0.3f,1,0.4f);
		break;
	case 2:
		sm->setAmbientLight(Ogre::ColourValue(0.7f,0.7f,1.f));
		diamond->setDiamondColour(0.3f,0.4f,1.f);
		break;
	}


	return ret;
}

bool DiamondProcessComponent::goldPreEnable(void)
{
	Orz::ISoundManager::getSingleton().quickPlay("prize_bonus.wav");
	Orz::ISoundManager::getSingleton().quickPlay("magic2.wav");
	_allTime = 0.f;

	_actionInterface->update =  boost::bind(&DiamondProcessComponent::goldPreUpdate, this, _1);// diamond->update;

	return true;
}


bool DiamondProcessComponent::lightPreUpdate(TimeType i)
{
	using namespace Ogre;
	_allTime += i;
	//CGameDiamondInterface * diamond = _diamondComp->queryInterface<CGameDiamondInterface>();
	//Ogre::Vector3 end = (Vector3(0.4f ,0.7f,1.0f) * (3-_allTime)/3) + (Vector3(1 ,1,1.0f) * (_allTime)/3);
	//diamond->setDiamondColour(end[0], end[1], end[2]);
#ifdef _BALL_
	CGameBallInterface * ball = _ballComp->queryInterface<CGameBallInterface>();

	bool ret = ball->update(i);//enable(CGameBallInterface::Fatein);
#else
	//bool  ret = false;
#endif

	return _allTime<3.0f;// || ret;
}
bool DiamondProcessComponent::lightPreEnable(void)
{
	Orz::ISoundManager::getSingleton().quickPlay("prize_light.wav");
	Orz::ISoundManager::getSingleton().quickPlay("magic2.wav");
	_allTime = 0.f;
	_actionInterface->update =  boost::bind(&DiamondProcessComponent::lightPreUpdate, this, _1);// diamond->update;
#ifdef _BALL_
	CGameBallInterface * ball = _ballComp->queryInterface<CGameBallInterface>();

	ball->enable(CGameBallInterface::Fatein);
#else
	CGameDiamondMoreWinderInterface * more = _diamondComp->queryInterface<CGameDiamondMoreWinderInterface>();
	more->bigger();
#endif

	return true;
}

bool DiamondProcessComponent::goldPreUpdate(TimeType i)
{


	using namespace Ogre;
	_allTime += i;
	CGameDiamondInterface * diamond = _diamondComp->queryInterface<CGameDiamondInterface>();
	Ogre::Vector3 end = (Vector3(0.4f ,0.7f,1.0f) * (3-_allTime)/3) + (Vector3(1 ,1,1.0f) * (_allTime)/3);
	diamond->setDiamondColour(end[0], end[1], end[2]);



	return _allTime<3.0f ;
}


void DiamondProcessComponent::goldDisable()
{
	CGameDiamondInterface * diamond = _diamondComp->queryInterface<CGameDiamondInterface>();
	diamond->setDiamondColour(0.4f,0.7f,1.0f);
	Orz::OgreGraphicsManager::getSingleton().getSceneManager()->setAmbientLight(Ogre::ColourValue(1,1, 1));
}
bool DiamondProcessComponent::activate(SanProcess process)
{


	TaskMap::iterator it = _allTask.find(std::pair<int, int>(process, WinData::getInstance().getWinMode()));
	if(it != _allTask.end())
	{
		_actionInterface->enable = boost::bind(&ITask::enable, (it->second).get());
		_actionInterface->update = boost::bind(&ITask::update, (it->second).get(), _1);
		_actionInterface->disable =boost::bind(&ITask::disable, (it->second).get());
		return true;
	}

	CGameDiamondInterface * diamond = _diamondComp->queryInterface<CGameDiamondInterface>();

	switch(process)
	{
	case PROCESS_LOGO:
		_actionInterface->enable = boost::bind(&DiamondProcessComponent::enable, this, CGameDiamondInterface::Fateout, 0.f);
		_actionInterface->disable = boost::bind(&___disable);
		return true;
	case PROCESS_READY:
		return false;
	case PROCESS_START:
		_actionInterface->enable = boost::bind(&DiamondProcessComponent::enable, this, CGameDiamondInterface::Fatein, 3.f);

		_actionInterface->disable = boost::bind(&___disable);
		return true;
	case PROCESS_PRORUN:
		switch(WinData::getInstance().getWinMode())
		{
		case WheelEnum::MANY:

			_actionInterface->enable  = boost::bind(&DiamondProcessComponent::lightPreEnable, this);
			_actionInterface->disable = boost::bind(&___disable);
			return true;
			break;
		case WheelEnum::GOLD:
			_actionInterface->enable  = boost::bind(&DiamondProcessComponent::goldPreEnable, this);
			_actionInterface->disable = boost::bind(&___disable);
			return true;
			break;
		case WheelEnum::ALL_ANIMAL:
			_actionInterface->enable  = boost::bind(&DiamondOpenTask::enable, _openTask.get(), PROCESS_PRORUN, _actionInterface.get(), diamond);


			return true;
			break;
		}


		break;
	case PROCESS_RUN :

		switch(WinData::getInstance().getWinMode())
		{
		case WheelEnum::MANY:
			_actionInterface->enable  = boost::bind(&DiamondProcessComponent::lightEnable, this, int(WinData::getInstance().size() -1));

			_actionInterface->disable = boost::bind(&___disable);
			return true;
			break;
		case WheelEnum::GOLD:
			_actionInterface->enable  = boost::bind(&DiamondProcessComponent::goldEnable, this);
			_actionInterface->disable = boost::bind(&DiamondProcessComponent::goldDisable, this);
			return true;
			break;
		case WheelEnum::ALL_COLOR:
			_changeColor->setWinner(_actionInterface.get());
			return true;
		case WheelEnum::ALL_ANIMAL:
			_actionInterface->enable  = boost::bind(&DiamondOpenTask::enable, _openTask.get(), PROCESS_RUN, _actionInterface.get(), diamond);
			return true;
			break;

		}
		_actionInterface->enable  = boost::bind(&DiamondProcessComponent::enable, this, CGameDiamondInterface::Float, 0.f);
		_actionInterface->disable = boost::bind(&___disable);

		return true;
	case PROCESS_WIN:
		switch(WinData::getInstance().getWinMode())
		{

		case WheelEnum::ALL_ANIMAL:
			_actionInterface->enable = boost::bind(&DiamondOpenTask::win, _openTask.get(), _actionInterface.get(), WinData::getInstance().getType(), diamond);
			return true;

			
		case WheelEnum::ALL_COLOR:
			switch(WinData::getInstance().getLightColor())
			{
			case WheelEnum::Red:
				diamond->setDiamondColour(1.0f, 0.6f, 0.6f);
				break;
			case WheelEnum::Green:
				diamond->setDiamondColour(0.6f, 1.0f, 0.6f);
				break;
			case WheelEnum::Yellow:
				diamond->setDiamondColour(0.9f, 0.9f, 0.5f);
				break;
			}
			//_actionInterface->enable = boost::bind(&DiamondOpenTask::win, _openTask.get(), _actionInterface.get(), WinData::getInstance().getType(), diamond);
			return false;
		}

		_actionInterface->enable = boost::bind(&DiamondProcessComponent::enable, this, CGameDiamondInterface::Fateout, 0.f);
		_actionInterface->disable = boost::bind(&___disable);
		return true;

	case PROCESS_END:
		{

			switch(WinData::getInstance().getWinMode())

			{
			case WheelEnum::MANY:
#ifdef _BALL_
				CGameBallInterface * ball = _ballComp->queryInterface<CGameBallInterface>();	
				ball->enable(CGameBallInterface::Hide);
#else
				CGameDiamondMoreWinderInterface * more = _diamondComp->queryInterface<CGameDiamondMoreWinderInterface>();
				more->reset();
#endif
				break;

			}
			diamond->reset();
		}
		break;



	}
	return false;
}


bool DiamondProcessComponent::enable(CGameDiamondInterface::STATE state, TimeType allTime)
{

	CGameDiamondInterface * diamond = _diamondComp->queryInterface<CGameDiamondInterface>();
	diamond->enable(state);
	if(allTime == 0.f)
	{

		_actionInterface->update = diamond->update;
		_allTime = 0.f;
	}else
	{
		_allTime = allTime;
		_actionInterface->update = boost::bind(&DiamondProcessComponent::update, this, _1);
	}
	return true;
}
bool DiamondProcessComponent::update(TimeType i)
{
	_allTime -= i;
	if(_allTime < 0.f)
	{
		if(_allTime +i >0.f)
			Orz::ISoundManager::getSingleton().quickPlay("diamond.wav");
		CGameDiamondInterface * diamond = _diamondComp->queryInterface<CGameDiamondInterface>();
		bool ret = diamond->update(i);
		if(ret == false)
		{
			Orz::ISoundManager::getSingleton().quickPlay("diamond2.wav");
			_actionInterface->update =  boost::lambda::constant(true);//boost::bind(&yes_update, _1);
			return true;

		}

		return true;
	}

	return true;
}

//void DiamondProcessComponent::disable(void)
//{
//
//}