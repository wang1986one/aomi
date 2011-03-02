#ifndef __Orz_UnitTest_SanProcessUnitTest__
#define __Orz_UnitTest_SanProcessUnitTest__
#include "SanUnitTestConfig.h"

#include "OgreResourceComponent.h"
#include "COgreResourceInterface.h"
#include "CSanProcessInterface.h"
#include "COgreEntityInterface.h"
#include "COgreNodeDebuggerInterface.h"
#include "CUpdateInterface.h"
/*

#include "Engine.h"
#include "KeyToMessage.h"
#include "SingleChipToMessage.h"*/

BOOST_AUTO_TEST_CASE(SanProcessUnitTest)
{

	using namespace Orz;

	//	ComponentPtr _res =  ComponentFactories::getInstance().create("OgreResource");
	//	COgreResourceInterface * res = _res->queryInterface<COgreResourceInterface>();


	////¶ÁÈë×ÊÔ´
	//res->createGroup("DotScene");
	//res->addLocation("../../media/san/DotScene", "FileSystem");
	//res->addLocation("../../media/san/ZhugeLiang", "FileSystem");
	//res->init();


	ComponentPtr comp = ComponentFactories::getInstance().create("SanProcess");
	CSanProcessInterface * process = comp->queryInterface<CSanProcessInterface>();


	ComponentPtr zhuge = ComponentFactories::getInstance().create("SanZhuGe");
	COgreEntityInterface * entity = zhuge->queryInterface<COgreEntityInterface>();
	entity->getSceneNode()->setPosition(0, 0 , -795);
	process->addObject(zhuge);

	process->enableProcess(PROCESS_START, WIN_NOMAL, ReferenceCount::Referenced());


	using namespace Orz;
	ComponentPtr debug = ComponentFactories::getInstance().create("OgreNodeDebugger");

	COgreEntityInterface * face = zhuge->queryInterface<COgreEntityInterface>();
	Ogre::SceneNode * sn = face->getSceneNode();
	COgreNodeDebuggerInterface * debugger = debug->queryInterface<COgreNodeDebuggerInterface>();

	debugger->pushNode(sn);
	debugger->enable();
	CUpdateInterface  * update = debug->queryInterface<CUpdateInterface>();


	TimeType time = 0;

	while(process->update(0.015f) )
	{
		update->update(0.015f);
		UnitTestEnvironmen::system->run();
	}

	process->disableProcess();
}

#endif