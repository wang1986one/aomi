#ifndef __Orz_UnitTest_CCSUnitTest__
#define __Orz_UnitTest_CCSUnitTest__
#include "SanUnitTestConfig.h"
#include "COgreCCSInterface.h"
#include "CUpdateInterface.h"

BOOST_AUTO_TEST_CASE(CCSUnitTest)
{

	using namespace Orz;
	ComponentPtr comp = ComponentFactories::getInstance().create("OgreCCS");
	BOOST_CHECK(comp.get());
	COgreCCSInterface  * cif = comp->queryInterface<COgreCCSInterface>();
	BOOST_CHECK(cif);
	CUpdateInterface  * update = comp->queryInterface<CUpdateInterface>();
	BOOST_CHECK(update);
	TimeType time = 0.f;
	while(time <= 3.f && update->update(0.015f))
	{
		time+=0.015f;
		UnitTestEnvironmen::system->run();
	}
	//cif->update(0.02);
	//cif->setCurrentCameraModeName("Free");
	//cif->getCurrentCameraModeName("Free");
	//cif->getCameraControlSystem();

}

#endif