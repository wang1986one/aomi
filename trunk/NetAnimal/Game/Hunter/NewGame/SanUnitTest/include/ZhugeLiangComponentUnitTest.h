#ifndef __Orz_UnitTest_ZhugeLiangComponentUnitTest__
#define __Orz_UnitTest_ZhugeLiangComponentUnitTest__
#include "SanUnitTestConfig.h"

#include <orz/Toolkit_Component_Task/Component/ComponentFactories.h>
#include "ZhugeLiangComponent.h"
#include "CGameActionInterface.h"
#include <OGRE/Ogre.h>
/*

#include "Engine.h"
#include "KeyToMessage.h"
#include "SingleChipToMessage.h"*/

BOOST_AUTO_TEST_CASE(ZhugeLiangComponentUnitTest)
{

	using namespace Orz;
	ComponentPtr comp = ComponentFactories::getInstance().create("ZhugeLiang");
	CGameActionInterface<1, 3> * action = comp->queryInterface<CGameActionInterface<1, 3>  >();
	if(action && action->enable())
	{
		while(action->update(0.015f));
		action->disable();
	}	

	UnitTestEnvironmen::system->run();
	UnitTestEnvironmen::system->run();
	UnitTestEnvironmen::system->run();
	UnitTestEnvironmen::system->run();
	UnitTestEnvironmen::system->run();
	UnitTestEnvironmen::system->run();
	UnitTestEnvironmen::system->run();
	UnitTestEnvironmen::system->run();
	UnitTestEnvironmen::system->run();
	UnitTestEnvironmen::system->run();
	UnitTestEnvironmen::system->run();
	UnitTestEnvironmen::system->run();
	UnitTestEnvironmen::system->run();
	UnitTestEnvironmen::system->run();
}

#endif