#ifndef __Orz_UnitTest_GameDiamondComponentUT__
#define __Orz_UnitTest_GameDiamondComponentUT__

#include "UnitTestConfig.h"
#include "CNewGameSceneInterface.h"
#include "CGameNeedleInterface.h"
#include "CGameRotationInterface.h"
#include "CGameDiamondInterface.h"
#include "CGameDiamondMoreWinderInterface.h"
BOOST_AUTO_TEST_CASE(GameDiamondComponentUT)
{
	using namespace Orz;

	//
	ComponentPtr sceneComp = ComponentFactories::getInstance().create("NewGameScene");
	//
	CNewGameSceneInterface * scene = sceneComp->queryInterface<CNewGameSceneInterface>();


	ComponentPtr diamondComp = ComponentFactories::getInstance().create("GameDiamond");
	CGameDiamondInterface * diamond = diamondComp->queryInterface<CGameDiamondInterface>();

	ComponentPtr gameRotationComp = ComponentFactories::getInstance().create("GameRotation");
	CGameRotationInterface * gameRotation = gameRotationComp->queryInterface<CGameRotationInterface>();



	scene->load();
	diamond->load(scene->getHelper(CNewGameSceneInterface::Helper24));
	diamond->enable(CGameDiamondInterface::Float);

	TimeType time = 0.f;

	//diamond->enable(CGameDiamondInterface::Open);
	//time = 0.f;
	//int i=0;
	//while(diamond->update(0.015f) || time<2.f)
	//{
	//	time += 0.015f;

	//	i++;
	//	if (i==4)
	//	{
	//		i=0;
	//	}
	//	diamond->changeAnimal((CGameDiamondInterface::ANIMALS)i);
	//	UnitTestEnvironmen::system->run();
	//}
	//time=0.f;
	//while(diamond->update(0.015f) || time<6.f)
	//{
	//	time += 0.015f;

	//	UnitTestEnvironmen::system->run();
	//}
	//time=0.f;
	//diamond->enable(CGameDiamondInterface::Close);
	//while(diamond->update(0.015f) || time<3.f)
	//{
	//	time += 0.015f;
	//	UnitTestEnvironmen::system->run();
	//}
	//time=0.f;
	//diamond->enable(CGameDiamondInterface::Float);
	//while(diamond->update(0.015f) || time<5.f)
	//{
	//	time += 0.015f;
	//	UnitTestEnvironmen::system->run();
	//}
	//////BOOST_CHECK(needle != NULL);

	time = 0.f;
	////

	CGameDiamondMoreWinderInterface * more = diamondComp->queryInterface<CGameDiamondMoreWinderInterface>();
	more->bigger();
	while(time<3.f)
	{
		time+= 0.015f;
		UnitTestEnvironmen::system->run();
	}


	time = 0.f;
	more->run(10);
	while(time<15.f)
	{
		time+= 0.015f;
		UnitTestEnvironmen::system->run();
	}



	time = 0.f;
	while(more->step())
	{
		time = 0.f;
		while(time<1)
		{
			time+= 0.015f;
			UnitTestEnvironmen::system->run();
		}
	}

	time = 0.f;
	more->bigger();
	while(time<3.f)
	{
		time+= 0.015f;
		UnitTestEnvironmen::system->run();
	}


	more->reset();

	scene->unload();
}

#endif