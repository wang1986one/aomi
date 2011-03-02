#ifndef __Orz_UnitTest_BlackBoardTest__
#define __Orz_UnitTest_BlackBoardTest__
#include "UnitTestConfig.h"
#include "BlackBoardSystem.h"
/*

#include "Engine.h"
#include "KeyToMessage.h"
#include "SingleChipToMessage.h"*/

BOOST_AUTO_TEST_CASE(BlackBoardTest)
{
	using namespace Orz;
	BlackBoardSystem::getInstance().write<int>("key", 123);
	int i = BlackBoardSystem::getInstance().read<int>("key");
	ORZ_LOG_NOTIFICATION<<i;
}

#endif