#ifndef __Orz_UnitTest_OgreResourceComponentUnitTest__
#define __Orz_UnitTest_OgreResourceComponentUnitTest__
#include "SanUnitTestConfig.h"

#include "OgreResourceComponent.h"
#include "COgreResourceInterface.h"
/*

#include "Engine.h"
#include "KeyToMessage.h"
#include "SingleChipToMessage.h"*/

BOOST_AUTO_TEST_CASE(OgreResourceComponentUnitTest)
{

	using namespace Orz;
	ComponentPtr comp = ComponentFactories::getInstance().create("OgreResource");
	COgreResourceInterface * face = comp->queryInterface<COgreResourceInterface>();
	
	
	BOOST_CHECK(face->initResourceGroup("testRG"));
	BOOST_CHECK(face->load(".", "FileSystem"));
	BOOST_CHECK_EQUAL(face->getResourceGroup(), "testRG");

	/*using namespace Orz;
	BlackBoardSystem::getInstance().write<int>("key", 123);
	int i = BlackBoardSystem::getInstance().read<int>("key");
	ORZ_LOG_NOTIFICATION<<i;*/
}

#endif