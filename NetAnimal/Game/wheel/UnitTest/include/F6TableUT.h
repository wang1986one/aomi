#ifndef __Orz_UnitTest_F6TableUT__
#define __Orz_UnitTest_F6TableUT__
#include "UnitTestConfig.h"
#include "UnitTestConfig.h"
#include "F6TableInterface.h"
/*

#include "Engine.h"
#include "KeyToMessage.h"
#include "SingleChipToMessage.h"*/

BOOST_AUTO_TEST_CASE(F6TableUT)
{

	
	Orz::ComponentPtr comp = Orz::ComponentFactories::getInstance().create("F5Table");
	F6TableInterface * f6 = comp->queryInterface<F6TableInterface>();
	BOOST_CHECK(f6 != NULL);
	BOOST_CHECK(f6->setDataIndex(F6TableInterface::PoTaiFenShu, 1));
	BOOST_CHECK(f6->getDataIndex(F6TableInterface::PoTaiFenShu) == 1);
	BOOST_CHECK(f6->getData(F6TableInterface::PoTaiFenShu) == 10000);
	f6->load();
	f6->save();

	/*using namespace Orz;
	BlackBoardSystem::getInstance().write<int>("key", 123);
	int i = BlackBoardSystem::getInstance().read<int>("key");
	ORZ_LOG_NOTIFICATION<<i;*/
}

#endif