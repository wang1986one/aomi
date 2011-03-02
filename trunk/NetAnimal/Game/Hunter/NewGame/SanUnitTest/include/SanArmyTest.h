//#ifndef __Orz_UnitTest_SanArmyTest__
//#define __Orz_UnitTest_SanArmyTest__
//
//#include "SanUnitTestConfig.h"
//
//
//#include "OgrePlayerComponent.h"
//#include "OgreNodeDebuggerComponent.h"
//
//
////#include "KeyControllerComponent.h"
//
//#include "AllCInterface.h"
//
//#include "CSanSoldierInterface.h"
//#include "CSanSceneInterface.h"
//
//#include <OGRE/ogre.h>
//BOOST_AUTO_TEST_CASE(SanArmyTest)
//{
//
//	using namespace Orz;
//
//	using namespace Orz;
//
//	ComponentPtr comp0 = ComponentFactories::getInstance().create("SanSoldier");
//	CSanSoldierInterface * soldier = comp0->queryInterface<CSanSoldierInterface>();
//
//	COgreEntityInterface * entity = comp0->queryInterface<COgreEntityInterface>();
//
//	Ogre::SceneNode *sn =  entity->getSceneNode();
//
//
//	ComponentPtr debug = ComponentFactories::getInstance().create("OgreNodeDebugger");
//
//	COgreNodeDebuggerInterface * debugger = debug->queryInterface<COgreNodeDebuggerInterface>();
//
//	BOOST_CHECK(debugger);
//	debugger->pushNode(sn);
//	debugger->enable();
//
//	CUpdateInterface  * update = debug->queryInterface<CUpdateInterface>();
//
//
//	float i = 0;
//	//
//
//	//创建一个 三国场景组建
//	ComponentPtr sceneComp = ComponentFactories::getInstance().create("SanScene");
//	//
//	////得到三国场景组建的管理接口
//	CSanSceneInterface * scene = sceneComp->queryInterface<CSanSceneInterface>();
//
//	scene->load("DotScene");
//
//
//	///////////////////////////////////////////////////
//
//	/*Orz::CGameActionInterface * action = sceneComp->queryInterface<CGameActionInterface>();
//	BOOST_CHECK(action);*/
//
//	//if(action->activate(PROCESS_PRORUN,WIN_NOMAL))
//	//{
//	//	action->enable();
//	//	while(action->update(0.015f))
//	//	{
//	//		UnitTestEnvironmen::system->run();
//	//	}
//	//	//action->disable();
//	//}
//
//
//	/*CUpdateInterface  * update = sceneComp->queryInterface<CUpdateInterface>();
//	BOOST_CHECK(update);
//	TimeType time = 0.f;*/
//
//	ComponentPtr effectComp =  ComponentFactories::getInstance().create("SanEffect");
//	CSanEffectInterface * effect = effectComp->queryInterface<CSanEffectInterface>();
//	TimeType time = 0.f;
//	
//	CUpdateInterface  * up = debug->queryInterface<CUpdateInterface>();
//	for(int i = 0; i<4; ++i )
//	{
//		while(time <= 10000.f)
//		{
//			up->update(0.015f);
//			time+=0.015f;
//			UnitTestEnvironmen::system->run();
//		}
//
//	}
//
//
//}
//
//#endif