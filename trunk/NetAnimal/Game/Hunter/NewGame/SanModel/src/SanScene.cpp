#include "SanModelBaseStableHeaders.h"
#include "SanScene.h"
#include "CCSCameraControlSystem.h"
#include "CCSBasicCameraModes.h"
#include "CSanSceneInterface.h"
#include "GameTranslate.h"
#include "CGameBallInterface.h"
#include "SanUI.h"
#include <WheelGobal/WheelEvents.h>
#include <WheelGobal/WheelUIInterface.h>
#include <WheelGobal/WheelGameUIRegister.h>
#include "CSanProcessInterface.h"
#include "CWheelPlaceInterface.h"
#include "COgreEntityInterface.h"
#include "CNeedleProcessInterface.h"
#include "CGameRotationInterface.h"
#include "CAnimalProcessInterface.h"
#include "CGameBaseInterface.h"
#include "CNewGameSceneInterface.h"setTheTime
#include "CGameDiamondInterface.h"
#include "UIProcessInterface.h"
#include "CGameTranslateInterface.h"
#include "CDiamondProcessInterface.h"
#include "CRotationInterface.h"
#include "CGameColourInterface.h"
using namespace Orz;
const int SanScene::_size = 24;

void SanScene::processDisable( Event * evt)
{


	CSanProcessInterface * process = _process->queryInterface<CSanProcessInterface>();
	process->disableProcess();
}

void SanScene::setWinner(int winner)
{
	CAnimalProcessInterface * animal = _actors.at(winner)->queryInterface<CAnimalProcessInterface>();
	animal->setIsWinner(true);
}
void SanScene::processEnable(Event * evt)
{
	int msg = WheelEvents::getMsg(evt);

	CSanProcessInterface * process = _process->queryInterface<CSanProcessInterface>();
	process->enableProcess(static_cast<SanProcess>(msg), /*WinData::getInstance(), */evt->getData<ReferenceCount *>()->reference());

}

void SanScene::processEnableProRun(Event * evt)
{

	//WinData::getInstance().load();

	//int color = _translate->getRandomSoldierLocation(CSanSoldierInterface::Soldier(WinData::getInstance().getLightColor()));

	CNeedleProcessInterface * needle = _needleComp->queryInterface<CNeedleProcessInterface>();
	needle->setTranslate(_translate_c/*, WinData::getInstance()*/);
	for(int i=0; i<24; ++i)
	{
		CAnimalProcessInterface * animal = _actors.at(i)->queryInterface<CAnimalProcessInterface>();
		animal->setIsWinner(false);
	}
	processEnable(evt);
}

void SanScene::_needleAngle(float angle, bool isEnd)
{
	int n = (int(angle / 15.f) + 6) % 24;
	
	CNewGameSceneInterface * scene = _sceneComp->queryInterface<CNewGameSceneInterface>();
	if(isEnd && _gLight != n)
	{
		_gLight = n;
		scene->glitter(n);
		Orz::ISoundManager::getSingleton().quickPlay("get.wav");
	}else if(n != _hLight)
	{
		
		_gLight = -1;
		scene->setOneLight(_hLight , false);
		_hLight = n;
		scene->setOneLight(_hLight , true);
	}
}
void SanScene::processEnableLogo(Event * evt)
{

	//_translate->getSoldierList();
	//WinData::getInstance().loadRate();
	CGameTranslateInterface * translate = _translate_c->queryInterface<CGameTranslateInterface>();
	translate->resetRate(WheelEnum::RATE(0));
	
	CNewGameSceneInterface * scene = _sceneComp->queryInterface<CNewGameSceneInterface>();
	scene->setLights(translate->getColorList(), 3);
	//for(int i=0; i<3; ++i)
	//{
	//	CSanSoldierInterface * soldier = _actors.at(i)->queryInterface<CSanSoldierInterface>();
	//	soldier->setSoldierType(CSanSoldierInterface::Soldier(i) ,true);
	//	soldier->fadein(0.f,0.f);
	//}
	//for(int i=3; i<24; ++i)
	//{
	//	CSanSoldierInterface * soldier = _actors.at(i)->queryInterface<CSanSoldierInterface>();
	//	soldier->setSoldierType(_translate->getSoldier(i-3) ,false);
	//	soldier->fadein((0.05f * (i-3)*5)+ 0.5 , 0.5f );
	//}
	processEnable(evt);
}/*
 void SanScene::setType()*/
SanScene::SanScene(const std::string & name, parameter_type pt):Scene(name)
{
	_translate_c = Orz::ComponentFactories::getInstance().create("GameTranslate");//.reset(new GameTranslate());
	Orz::NameValueList nvl;
	nvl["pos"] = Orz::VariantData<Ogre::Vector3>::set(Ogre::Vector3(0.712143f, -908.334f, -5500.09f));
	nvl["radian"] = Orz::VariantData<float>::set(0.f);
	nvl["scale"] = Orz::VariantData<Ogre::Vector3>::set(Ogre::Vector3(4.808f, 4.808f, 4.808f));

	_process  = ComponentFactories::getInstance().create("SanProcess");
	/*nvl["process"] =  Orz::VariantData<ComponentPtr>::set(_process);*/




	//_zhuge = Orz::GameFactories::getInstance().createActor("SanZhugeActor", IDManager::BLANK, &nvl);
	//_zhuge = ComponentFactories::getInstance().create("SanZhuGe");
	//COgreEntityInterface * entity = _zhuge->queryInterface<COgreEntityInterface>();

	/*Ogre::SceneNode *sn =  entity->getSceneNode();
	sn->setPosition(Ogre::Vector3(0.712143f, -908.334f, -5500.09f));
	sn->setScale(Ogre::Vector3(4.808f, 4.808f, 4.808f));*/



	//_process->queryInterface<CSanProcessInterface>()->addObject(_zhuge);

	setChannel(Orz::EventChannel::create().clear());
	//ComponentPtr place = ComponentFactories::getInstance().create("WheelPlace");
	//CWheelPlaceInterface *pi = place->queryInterface<CWheelPlaceInterface>();



	


	CSanProcessInterface * processInterface = _process->queryInterface<CSanProcessInterface>();
	_messgaeMap[WheelEvents::PROCESS_LOGO_DISABLE] = boost::bind(&SanScene::processDisable, this, _1);
	_messgaeMap[WheelEvents::PROCESS_READY_DISABLE] =boost::bind(&SanScene::processDisable, this, _1);
	_messgaeMap[WheelEvents::PROCESS_START_DISABLE] = boost::bind(&SanScene::processDisable, this, _1);
	_messgaeMap[WheelEvents::PROCESS_PRORUN_DISABLE] = boost::bind(&SanScene::processDisable, this, _1);
	_messgaeMap[WheelEvents::PROCESS_RUN_DISABLE] = boost::bind(&SanScene::processDisable, this, _1);
	_messgaeMap[WheelEvents::PROCESS_WIN_DISABLE] =boost::bind(&SanScene::processDisable, this, _1);
	_messgaeMap[WheelEvents::PROCESS_END_DISABLE] = boost::bind(&SanScene::processDisable, this, _1);
	_messgaeMap[WheelEvents::PROCESS_PLAY_DISABLE] = boost::bind(&SanScene::processDisable, this, _1);

	_messgaeMap[WheelEvents::PROCESS_READY_ENABLE] = boost::bind(&SanScene::processEnable, this, _1);
	_messgaeMap[WheelEvents::PROCESS_START_ENABLE] = boost::bind(&SanScene::processEnable, this, _1);
	_messgaeMap[WheelEvents::PROCESS_RUN_ENABLE] = boost::bind(&SanScene::processEnable, this, _1);
	_messgaeMap[WheelEvents::PROCESS_WIN_ENABLE] = boost::bind(&SanScene::processEnable, this, _1);
	_messgaeMap[WheelEvents::PROCESS_PLAY_ENABLE] = boost::bind(&SanScene::processEnable, this, _1);
	_messgaeMap[WheelEvents::PROCESS_END_ENABLE] = boost::bind(&SanScene::processEnable, this, _1);

	_messgaeMap[WheelEvents::PROCESS_LOGO_ENABLE] = boost::bind(&SanScene::processEnableLogo, this,  _1);
	_messgaeMap[WheelEvents::PROCESS_PRORUN_ENABLE] = boost::bind(&SanScene::processEnableProRun, this, _1);

}
SanScene::~SanScene(void)
{
	//_zhuge.reset();
}


///重载，被用于处理消息调用
void SanScene::doExecute(Event * evt)
{
	if(Orz::WheelEvents::in(evt))
	{

		CSanProcessInterface * processInterface = _process->queryInterface<CSanProcessInterface>();
		int msg = WheelEvents::getMsg(evt);
		MessageMap::iterator it = _messgaeMap.find(msg);
		if(it != _messgaeMap.end())
		{
			(it->second)(evt);
		}

	}

}


///重载，被用于进入消息管理调用
void SanScene::doEnable(void)
{
	_hLight = 6;
	_gLight = -1;

	CSanProcessInterface * proc = _process->queryInterface<CSanProcessInterface>();

	_sceneComp = ComponentFactories::getInstance().create("SceneProcess");
	_needleComp = ComponentFactories::getInstance().create("NeedleProcess");
	_diamondComp = ComponentFactories::getInstance().create("DiamondProcess"); 
	_uiComp  = ComponentFactories::getInstance().create("UIProcess");  
	CGameRotationInterface * rotation =	_needleComp->queryInterface<CGameRotationInterface>();
	rotation->init(_sceneComp);
	
	CGameDiamondInterface * diamond = _diamondComp->queryInterface<CGameDiamondInterface>();
#ifdef _BALL_
	CGameBallInterface * ball = _diamondComp->queryInterface<CGameBallInterface>();
#endif

	CNewGameSceneInterface * scene = _sceneComp->queryInterface<CNewGameSceneInterface>();
	 CGameColourInterface * colour = _needleComp->queryInterface<CGameColourInterface>();
	colour->load(scene->getHelper(CNewGameSceneInterface::Helper24));
	diamond->load(scene->getHelper(CNewGameSceneInterface::Helper24));
	//scene->setOneLight(_hLight , true);
#ifdef _BALL_
	ball->load(scene->getHelper(CNewGameSceneInterface::Helper24));
#endif
	//scene->load("DotScene");
	proc->addObject(_diamondComp);
	proc->addObject(_sceneComp);
	proc->addObject(_needleComp);
	proc->addObject(_uiComp);
	CGameBaseInterface * base =	_needleComp->queryInterface<CGameBaseInterface>();
	for(int i = 0; i<_size; i++)
	{
		
		ComponentPtr actorComp = ComponentFactories::getInstance().create("AnimalProcess");

		CAnimalProcessInterface * actor = actorComp->queryInterface<CAnimalProcessInterface>();
		CGameTranslateInterface * translate = _translate_c->queryInterface<CGameTranslateInterface>();

		actor->init(translate->getAnimalList()[i], base->getSceneNode(i));
		_actors.push_back(actorComp);
		proc->addObject(actorComp);

	}

	
	enableUpdate();
	setChannel(EventChannel::create().addUserChannel<CHANNEL_PROCESS>());

	
	UIProcessInterface * ui = _uiComp->queryInterface<UIProcessInterface>();
	WheelGameUIRegister::getSingleton().active(boost::shared_ptr<WheelUIInterface>(ui, nodeleter()));//激活这个ui
	CNeedleProcessInterface * needle = _needleComp->queryInterface<CNeedleProcessInterface>();
	needle->_callback = boost::bind(&SanScene::setWinner, this, _1);

	
	CDiamondProcessInterface * dp = _diamondComp->queryInterface<CDiamondProcessInterface>();
	needle->_numberCallback = dp->step;
#ifdef _BALL_
	needle->_numberCallback = ball->addNumber;
#endif




	CRotationInterface * r = _needleComp->queryInterface<CRotationInterface>();
	r->_callback = boost::bind(&SanScene::_needleAngle, this, _1, _2);
}



///重载，被用于离开消息管理调用
void SanScene::doDisable(void)
{

	WheelGameUIRegister::getSingleton().active(WheelUIInterfacePtr());
	//_sceneComp.reset();
}


///重载，被用于更新调用
void SanScene::doFrame(unsigned int step)
{

	CSanProcessInterface * proc = _process->queryInterface<CSanProcessInterface>();
	proc->update(step * WORLD_UPDATE_INTERVAL);

}
