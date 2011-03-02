#ifndef __Orz_UnitTest_NewGameSceneComponentUT__
#define __Orz_UnitTest_NewGameSceneComponentUT__

#include "UnitTestConfig.h"
#include "CNewGameSceneInterface.h"
#include "COgreCCSInterface.h"
#include "CGameDiamondInterface.h"
BOOST_AUTO_TEST_CASE(NewGameSceneComponentUT)
{
	using namespace Orz;

	ComponentPtr sceneComp = ComponentFactories::getInstance().create("NewGameScene");

	
	Orz::ComponentInterface * testInterface = sceneComp->_queryInterface(TypeInfo(typeid(COgreCCSInterface)));
	BOOST_CHECK(testInterface == NULL);
	
	CNewGameSceneInterface * scene = sceneComp->queryInterface<CNewGameSceneInterface>();
	ComponentPtr diamondComp = ComponentFactories::getInstance().create("GameDiamond");
	CGameDiamondInterface * diamond = diamondComp->queryInterface<CGameDiamondInterface>();

	
	for(int i = 0; i< 25; ++i)
	{
		Ogre::SceneNode * node  =scene->getHelper(CNewGameSceneInterface::HELPERS(i));
		//BOOST_CHECK(node == NULL);
	}

	scene->load();
	//scene->getHelper(CNewGameSceneInterface::Helper24)->setVisible(false);
	//scene->getSceneNode()->setVisible(false);
	diamond->load(scene->getHelper(CNewGameSceneInterface::Helper24));
	boost::array<CNewGameSceneInterface::LIGHT_COLOR, 24> lights;
	for(int i = 0; i<24; ++i)
	{
		lights[i] = CNewGameSceneInterface::Red;
	}

	scene->moveCamera_win(CNewGameSceneInterface::Farward,2);
	scene->enableGoldWineffect(true,12345);
	TimeType time = 0.f;
	while(scene->update(0.015f) || time<30.f )
	{
		time+= 0.015f;
		UnitTestEnvironmen::system->run();
	}
	time=0.f;
	std::cout<<"stop"<<std::endl;
    scene->enableGoldWineffect(false,51);
	while(scene->update(0.015f) || time<6.f )
	{
		time+= 0.015f;
		UnitTestEnvironmen::system->run();
	}
	time=0.f;
	scene->enableGoldWineffect(true,11223);
	//scene->setLights(lights, 5.f);
	while(scene->update(0.015f) || time<20.f )
	{
		time+= 0.015f;
		UnitTestEnvironmen::system->run();
	}
	scene->unload();
}

#endif