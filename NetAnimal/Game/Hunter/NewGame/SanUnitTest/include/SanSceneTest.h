#ifndef __Orz_UnitTest_SanSceneTest__
#define __Orz_UnitTest_SanSceneTest__
#include "SanUnitTestConfig.h"

#include "COgreResourceInterface.h"
#include "COgreEntityInterface.h"
#include "COgreSceneLoaderInterface.h"
#include "COgreCCSInterface.h"
#include "CUpdateInterface.h"
#include "COgreNodeDebuggerInterface.h"
#include "CCSBasicCameraModes.h"
#include "CSanSceneInterface.h"

#include "CGameActionInterface.h"
#include "CSanProcessInterface.h"

#include "CSanEffectInterface.h"
/*

#include "Engine.h"
#include "KeyToMessage.h"
#include "SingleChipToMessage.h"*/
BOOST_AUTO_TEST_CASE(SanSceneTest)
{
		using namespace Orz;


	//

	//创建一个 三国场景组建
	ComponentPtr sceneComp = ComponentFactories::getInstance().create("SanScene");
	//
	////得到三国场景组建的管理接口
	CSanSceneInterface * scene = sceneComp->queryInterface<CSanSceneInterface>();

	scene->load("DotScene");


	///////////////////////////////////////////////////

	/*Orz::CGameActionInterface * action = sceneComp->queryInterface<CGameActionInterface>();
	BOOST_CHECK(action);*/

	//if(action->activate(PROCESS_PRORUN,WIN_NOMAL))
	//{
	//	action->enable();
	//	while(action->update(0.015f))
	//	{
	//		UnitTestEnvironmen::system->run();
	//	}
	//	//action->disable();
	//}


	/*CUpdateInterface  * update = sceneComp->queryInterface<CUpdateInterface>();
	BOOST_CHECK(update);
	TimeType time = 0.f;*/

	ComponentPtr effectComp =  ComponentFactories::getInstance().create("SanEffect");
	CSanEffectInterface * effect = effectComp->queryInterface<CSanEffectInterface>();
	//Ogre::SceneNode sn = scene->getSceneNode()->createChildSceneNode(Ogre::Vector3(1015, -1482, -20));
	//Ogre::Vector3 pos = scene->getSceneNode()->convertLocalToWorldPosition(Ogre::Vector3(1015, -1482, -20));
	
	//std::cout<<pos;
	/*
	std::cout<<->getPosition();
	std::cout<<scene->getSceneNode()->createChildSceneNode(Ogre::Vector3(1015, -1482, -20))->getPosition();
	std::cout<<scene->getSceneNode()->createChildSceneNode(Ogre::Vector3(1015, -1482, -20))->getPosition();
	std::cout<<scene->getSceneNode()->createChildSceneNode(Ogre::Vector3(1015, -1482, -20))->getPosition();
	std::cout<<scene->getSceneNode()->createChildSceneNode(Ogre::Vector3(1015, -1482, -20))->getPosition();
	std::cout<<scene->getSceneNode()->createChildSceneNode(Ogre::Vector3(1015, -1482, -20))->getPosition();
	std::cout<<scene->getSceneNode()->createChildSceneNode(Ogre::Vector3(1015, -1482, -20))->getPosition();
	std::cout<<scene->getSceneNode()->createChildSceneNode(Ogre::Vector3(1015, -1482, -20))->getPosition();
	std::cout<<scene->getSceneNode()->createChildSceneNode(Ogre::Vector3(1015, -1482, -20))->getPosition();
	std::cout<<scene->getSceneNode()->createChildSceneNode(Ogre::Vector3(1015, -1482, -20))->getPosition();
	std::cout<<scene->getSceneNode()->createChildSceneNode(Ogre::Vector3(1015, -1482, -20))->getPosition();
	std::cout<<scene->getSceneNode()->createChildSceneNode(Ogre::Vector3(1015, -1482, -20))->getPosition();
	std::cout<<scene->getSceneNode()->createChildSceneNode(Ogre::Vector3(1015, -1482, -20))->getPosition();
	std::cout<<scene->getSceneNode()->createChildSceneNode(Ogre::Vector3(1015, -1482, -20))->getPosition();*/
	for(int i = 0; i<4; ++i )
	{
		if(effect->load(CSanEffectInterface::Type(i),Orz::OgreGraphicsManager::getSingleton().getSceneManager()->getRootSceneNode ()->createChildSceneNode(Ogre::Vector3(20,-1482,- 5450))))
		{
			effect->show();

			TimeType time = 0.f;
			while(effect->update(0.015f) || time <= 2.f)
			{
				time+=0.015f;
				UnitTestEnvironmen::system->run();
			}

			effect->hide();
			time = 0.f;
			while(time <= 0.5f)
			{
				time+=0.015f;
				UnitTestEnvironmen::system->run();
			}
			effect->unload();
		}
	}
}

#endif