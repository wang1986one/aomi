#ifndef __Orz_UnitTest_GameColourComponentUT__
#define __Orz_UnitTest_GameColourComponentUT__

#include "UnitTestConfig.h"
#include "CNewGameSceneInterface.h"
#include "CGameNeedleInterface.h"
#include "CGameRotationInterface.h"
#include "CGameColourInterface.h"
#include "CGameDiamondInterface.h"
BOOST_AUTO_TEST_CASE(GameColourComponentUT)
{
	using namespace Orz;


	//
	ComponentPtr sceneComp = ComponentFactories::getInstance().create("NewGameScene");
	//
	CNewGameSceneInterface* scene=sceneComp->queryInterface<CNewGameSceneInterface>();

	ComponentPtr ColourComp = ComponentFactories::getInstance().create("GameColour");
	CGameColourInterface * Colour = ColourComp->queryInterface<CGameColourInterface>();

	//ComponentPtr gameRotationComp = ComponentFactories::getInstance().create("GameRotation");
	//CGameRotationInterface * gameRotation = gameRotationComp->queryInterface<CGameRotationInterface>();



	scene->load();
	//Diamond->load(scene->getHelper(CNewGameSceneInterface::Helper24));
	Colour->load(scene->getHelper(CNewGameSceneInterface::Helper24));

	//gameRotation->init(sceneComp);
	//gameRotation->play(150, 15.f,150, 20.f);
	Colour->enable(CGameColourInterface::Fatein);
	TimeType time=0.f;
	time = 0.f;
	float i=0;
	while( time<14.f)
	{
		Colour->update(0.015f);
		time += 0.015f;
		//Colour->setColour(i,0,0);
		i+=0.01;
		if (i>0.9)
		{
			i=0;
		}
		UnitTestEnvironmen::system->run();
	}
	//Colour->enable(CGameColourInterface::Rotate);
	//time = 0.f;

	//while( time<5.f)
	//{Colour->update(0.015f)

	//	time += 0.015f;
	//	UnitTestEnvironmen::system->run();
	//}
	Colour->enable(CGameColourInterface::Stop);
	time=0.f;
	while(time<1.f)
	{
		time += 0.015f;
		UnitTestEnvironmen::system->run();
	}
	Colour->enable(CGameColourInterface::Fateout);
	time=0.f;
	while(Colour->update(0.015f) || time<1.f)
	{
		time += 0.015f;
		UnitTestEnvironmen::system->run();
	}


	scene->unload();
}

#endif