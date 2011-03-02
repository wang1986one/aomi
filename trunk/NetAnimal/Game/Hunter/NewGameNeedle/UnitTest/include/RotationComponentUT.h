#ifndef __Orz_UnitTest_RotationComponentUT__
#define __Orz_UnitTest_RotationComponentUT__

#include "UnitTestConfig.h"
#include "CNewGameSceneInterface.h"
#include "CGameNeedleInterface.h"
#include "CRotationInterface.h"
BOOST_AUTO_TEST_CASE(RotationComponentUT)
{
	using namespace Orz;

	
	//
	ComponentPtr sceneComp = ComponentFactories::getInstance().create("NewGameScene");
	//
	CNewGameSceneInterface * scene = sceneComp->queryInterface<CNewGameSceneInterface>();



	
	
	ComponentPtr needleComp = ComponentFactories::getInstance().create("GameNeedle");
	CGameNeedleInterface * needle = needleComp->queryInterface<CGameNeedleInterface>();


	scene->load();
	BOOST_CHECK(needle != NULL);

	//std::cout<<scene->getHelper(24);
	needle->load(scene->getHelper(CNewGameSceneInterface::Helper24));
	//for(int i = 0; i< 25; ++i)
	//{
	//	std::cout<<scene->getHelper(CNewGameSceneInterface::HELPERS(i));
	//}




	ComponentPtr rotationComp = ComponentFactories::getInstance().create("Rotation");

	CRotationInterface * rotation = rotationComp->queryInterface<CRotationInterface>();
	BOOST_CHECK(rotation != NULL);
	rotation->init(scene->getHelper(CNewGameSceneInterface::Helper24), CRotationInterface::Clockwise, 90.f);
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

	
	rotation->reset(120.f);


	rotation->play(360 * 3, 10.f);

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