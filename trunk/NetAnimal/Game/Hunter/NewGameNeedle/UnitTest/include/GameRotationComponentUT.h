#ifndef __Orz_UnitTest_GameRotationComponentUT__
#define __Orz_UnitTest_GameRotationComponentUT__

#include "UnitTestConfig.h"
#include "CNewGameSceneInterface.h"
#include "CGameNeedleInterface.h"
#include "CGameRotationInterface.h"
BOOST_AUTO_TEST_CASE(GameRotationComponentUT)
{
	using namespace Orz;

	
	//
	ComponentPtr sceneComp = ComponentFactories::getInstance().create("NewGameScene");
	//
	CNewGameSceneInterface * scene = sceneComp->queryInterface<CNewGameSceneInterface>();
	
	ComponentPtr gameRotationComp = ComponentFactories::getInstance().create("GameRotation");
	CGameRotationInterface * gameRotation = gameRotationComp->queryInterface<CGameRotationInterface>();



	scene->load();
	gameRotation->init(sceneComp);
	//gameRotation->play(150, 15.f,150, 20.f);

	//while(gameRotation->update(0.015f))
	//{
	//	UnitTestEnvironmen::system->run();
	//}

	gameRotation->winner(1, true);
	while(gameRotation->update(0.015f))
	{
		UnitTestEnvironmen::system->run();
	}

	gameRotation->reset();
	////BOOST_CHECK(needle != NULL);

	////std::cout<<scene->getHelper(24);
	//needle->load(scene->getHelper(CNewGameSceneInterface::Helper24));
	//for(int i = 0; i< 25; ++i)
	//{
	//	std::cout<<scene->getHelper(CNewGameSceneInterface::HELPERS(i));
	//}

	////boost::array<CNewGameSceneInterface::LIGHT_COLOR, 24> lights;
	////for(int i = 0; i<24; ++i)
	////{
	////	lights[i] = CNewGameSceneInterface::Red;
	////}
	////scene->setLights(lights);

	TimeType time = 0.f;
	//

	
	while(time<3.f)
	{
		time+= 0.015f;
		UnitTestEnvironmen::system->run();
	}
	
	
	
	scene->unload();
}

#endif