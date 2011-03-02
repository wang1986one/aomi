#ifndef __Orz_UnitTest_GameBallComponentUT__
#define __Orz_UnitTest_GameBallComponentUT__

#include "UnitTestConfig.h"
#include "CNewGameSceneInterface.h"
#include "CGameNeedleInterface.h"
#include "CGameRotationInterface.h"
#include "CGameBallInterface.h"
#include "CGameDiamondInterface.h"
BOOST_AUTO_TEST_CASE(GameBallComponentUT)
{
	using namespace Orz;


	//
	ComponentPtr sceneComp = ComponentFactories::getInstance().create("NewGameScene");
	//
	CNewGameSceneInterface * scene = sceneComp->queryInterface<CNewGameSceneInterface>();
	ComponentPtr DiamondComp = ComponentFactories::getInstance().create("GameDiamond");
	//
	CGameDiamondInterface * Diamond = DiamondComp->queryInterface<CGameDiamondInterface>();

	ComponentPtr BallComp = ComponentFactories::getInstance().create("GameBall");
	CGameBallInterface * Ball = BallComp->queryInterface<CGameBallInterface>();

	ComponentPtr gameRotationComp = ComponentFactories::getInstance().create("GameRotation");
	CGameRotationInterface * gameRotation = gameRotationComp->queryInterface<CGameRotationInterface>();



	scene->load();
	Diamond->load(scene->getHelper(CNewGameSceneInterface::Helper24));
	Ball->load(scene->getHelper(CNewGameSceneInterface::Helper24));

	gameRotation->init(sceneComp);
	gameRotation->play(150, 15.f,150, 20.f);
	Ball->enable(CGameBallInterface::Fatein);
	TimeType time=0.f;

	//Ball->enable(CGameBallInterface::Rotate);
	Ball->addNumber(0);
		Ball->addNumber(0);
	Ball->addNumber(9);	Ball->addNumber(9);
	Ball->addNumber(8);Ball->addNumber(8);
	Ball->addNumber(7);Ball->addNumber(7);
	Ball->addNumber(6);Ball->addNumber(6);
	Ball->addNumber(5);Ball->addNumber(5);
	Ball->addNumber(4);Ball->addNumber(4);
	Ball->addNumber(3);Ball->addNumber(3);
	Ball->addNumber(2);
	Ball->addNumber(1);
	time = 0.f;
	int i=0;
	while(Ball->update(0.015f) || time<10.f)
	{
		//Ball->setNumber(i);
		//i++;
		//if (i>9)
		//{
		//	i=0;
		//}
		time += 0.015f;
		UnitTestEnvironmen::system->run();
	}
	Ball->enable(CGameBallInterface::Stop);
	time=0.f;
	while(Ball->update(0.015f) || time<1.f)
	{
		time += 0.015f;
		UnitTestEnvironmen::system->run();
	}
	Ball->enable(CGameBallInterface::Fateout);
	time=0.f;
	while(Ball->update(0.015f) || time<1.f)
	{
		time += 0.015f;
		UnitTestEnvironmen::system->run();
	}


	scene->unload();
}

#endif