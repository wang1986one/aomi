#ifndef __Orz_UnitTest_GameFlowerComponentUT__
#define __Orz_UnitTest_GameFlowerComponentUT__

#include "UnitTestConfig.h"
#include "CNewGameSceneInterface.h"
#include "CGameNeedleInterface.h"
#include "CGameFlowerInterface.h"
BOOST_AUTO_TEST_CASE(GameFlowerComponentUT)
{
	using namespace Orz;

	
	ComponentPtr sceneComp = ComponentFactories::getInstance().create("NewGameScene");

	CNewGameSceneInterface * scene = sceneComp->queryInterface<CNewGameSceneInterface>();

	
	
	ComponentPtr needleComp = ComponentFactories::getInstance().create("GameNeedle");
	CGameNeedleInterface * needle = needleComp->queryInterface<CGameNeedleInterface>();

	CGameFlowerInterface * flower = needleComp->queryInterface<CGameFlowerInterface>();

	
	scene->load();
	needle->load(scene->getHelper(CNewGameSceneInterface::Helper24));
	/*flower->enable(CGameFlowerInterface::SetGreen);
	flower->enable(CGameFlowerInterface::GoUp);*/

	TimeType time = 0.f;
	
	
	while(time<3.f)
	{
		//flower->update(0.015f);
		//flower->update(0.015f);
		time+= 0.015f;
		UnitTestEnvironmen::system->run();
	}
	
    time = 0.f;
	
	scene->glitter(2);
	
	while(time<3.f)
	{
		//flower->update(0.015f);
		//flower->update(0.015f);
		time+= 0.015f;
		UnitTestEnvironmen::system->run();
	}
	
     time = 0.f;
	
	scene->glitter(2);
	
	while(time<3.f)
	{
		//flower->update(0.015f);
		//flower->update(0.015f);
		time+= 0.015f;
		UnitTestEnvironmen::system->run();
	}
	scene->glitter(2);
	/*flower->reset();
	flower->enable(CGameFlowerInterface::SetYellow);
	flower->enable(CGameFlowerInterface::GoUp);*/

     time = 0.f;
	
	
	while(time<5.f)
	{
		
		//flower->update(0.015f);
		time+= 0.015f;
		UnitTestEnvironmen::system->run();
	}
	scene->unload();
}

#endif