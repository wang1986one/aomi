#ifndef __Orz_UnitTest_NewGameSceneComponentTestFishUT__
#define __Orz_UnitTest_NewGameSceneComponentTestFishUT__

#include "UnitTestConfig.h"
#include "CNewGameSceneInterface.h"
#include "COgreCCSInterface.h"
#include "CGameDiamondInterface.h"
#include "CGameNeedleInterface.h"|
BOOST_AUTO_TEST_CASE(NewGameSceneComponentTestFishUT)
{
	using namespace Orz;

	ComponentPtr sceneComp = ComponentFactories::getInstance().create("NewGameScene");

	
	Orz::ComponentInterface * testInterface = sceneComp->_queryInterface(TypeInfo(typeid(COgreCCSInterface)));
	BOOST_CHECK(testInterface == NULL);
	
	CNewGameSceneInterface * scene = sceneComp->queryInterface<CNewGameSceneInterface>();
	ComponentPtr diamondComp = ComponentFactories::getInstance().create("GameDiamond");
	CGameDiamondInterface * diamond = diamondComp->queryInterface<CGameDiamondInterface>();
	//ComponentPtr needleComp=ComponentFactories::getInstance().create("GameNeedle");
	//CGameNeedleInterface *needle=needleComp->queryInterface<CGameNeedleInterface>();
	
	for(int i = 0; i< 25; ++i)
	{
		Ogre::SceneNode * node  =scene->getHelper(CNewGameSceneInterface::HELPERS(i));
		//BOOST_CHECK(node == NULL);
	}

	scene->load();
	diamond->load(scene->getHelper(CNewGameSceneInterface::Helper24));
	//needle->load(scene->getHelper(CNewGameSceneInterface::Helper24));
	TimeType time = 0.f;
	while(scene->update(0.015f) || time<30.f )
	{
		time+= 0.015f;
		UnitTestEnvironmen::system->run();
	}
	scene->unload();
}

#endif