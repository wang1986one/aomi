#ifndef __Orz_UnitTest_GameBaseComponentUT__
#define __Orz_UnitTest_GameBaseComponentUT__

#include "UnitTestConfig.h"
#include "CNewGameSceneInterface.h"
#include "CGameBaseInterface.h"
#include "CRotationInterface.h"
BOOST_AUTO_TEST_CASE(GameBaseComponentUT)
{
	using namespace Orz;

	
	//
	ComponentPtr sceneComp = ComponentFactories::getInstance().create("NewGameScene");
	//
	CNewGameSceneInterface * scene = sceneComp->queryInterface<CNewGameSceneInterface>();



	
	
	ComponentPtr baseComp = ComponentFactories::getInstance().create("GameBase");
	CGameBaseInterface * base = baseComp->queryInterface<CGameBaseInterface>();


	scene->load();
	//BOOST_CHECK(needle != NULL);
	base->init(scene->getHelper(CNewGameSceneInterface::Helper24));
	//std::cout<<scene->getHelper(24);
	
	for(int i = 0; i< 24; ++i)
	{
		base->load(i, scene->getHelper(CNewGameSceneInterface::HELPERS(i)));
		//std::cout<<scene->getHelper(CNewGameSceneInterface::HELPERS(i));
	}

	base->setColor(3,CGameBaseInterface::Red);
	base->setColor(5,CGameBaseInterface::Green);
	base->setColor(7,CGameBaseInterface::Yellow);
	//boost::array<CNewGameSceneInterface::LIGHT_COLOR, 24> lights;
	//for(int i = 0; i<24; ++i)
	//{
	//	lights[i] = CNewGameSceneInterface::Red;
	//}
	//scene->setLights(lights);
	ComponentPtr rotationComp = ComponentFactories::getInstance().create("Rotation");

	CRotationInterface * rotation = rotationComp->queryInterface<CRotationInterface>();
	BOOST_CHECK(rotation != NULL);
	rotation->init(scene->getHelper(CNewGameSceneInterface::Helper24), CRotationInterface::Eastern, 90.f);
	rotation->reset(0.f);
	rotation->play(100.f*3, 3.f);

	while( rotation->update(0.015f))
	{
		UnitTestEnvironmen::system->run();
	}


	
	TimeType time = 0.f;
	

	
	
	
	while(time<1.f)
	{
		time+= 0.015f;
		UnitTestEnvironmen::system->run();
	}


	rotation->play(100.f*3, 3.f);

	while( rotation->update(0.015f))
	{
		UnitTestEnvironmen::system->run();
	}

	
	rotation->reset(100.f);


	rotation->play(100.f*3, 3.f);

	while( rotation->update(0.015f))
	{
		UnitTestEnvironmen::system->run();
	}
	
	
	
	time = 0.f;
	while(time<3.f)
	{
		time+= 0.015f;
		UnitTestEnvironmen::system->run();
	}
	time = 0.f;
	while(time<3.f)
	{
		time+= 0.015f;
		UnitTestEnvironmen::system->run();
	}
	scene->unload();
}

#endif