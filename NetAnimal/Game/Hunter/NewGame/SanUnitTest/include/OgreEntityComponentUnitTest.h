#ifndef __Orz_UnitTest_OgreEntityComponentUnitTest__
#define __Orz_UnitTest_OgreEntityComponentUnitTest__
#include "SanUnitTestConfig.h"

#include <orz/Toolkit_Component_Task/Component/ComponentFactories.h>
#include "OgreEntityComponent.h"
#include "COgreEntityInterface.h"
#include "COgreAnimationInterface.h"
#include "COgreResourceInterface.h"

#include <OGRE/Ogre.h>
/*

#include "Engine.h"
#include "KeyToMessage.h"
#include "SingleChipToMessage.h"*/

BOOST_AUTO_TEST_CASE(OgreEntityComponentUnitTest)
{

	using namespace Orz;

	ComponentPtr res = ComponentFactories::getInstance().create("OgreResource");
	/*COgreResourceInterface * f = res->queryInterface<COgreResourceInterface>();
	
	
	
	f->createGroup("ZhugeLiang");
	f->addLocation("../../media/san/ZhugeLiang", "FileSystem");
	f->init();*/


	ComponentPtr comp = ComponentFactories::getInstance().create("OgreEntity");
	COgreEntityInterface * face = comp->queryInterface<COgreEntityInterface>();
	BOOST_CHECK(face);
	Ogre::SceneManager * sm = Orz::OgreGraphicsManager::getSingleton().getSceneManager();
	Ogre::SceneNode *root =  sm->getRootSceneNode()->createChildSceneNode();

	face->load("ms_01_4.mesh", "ms_01_4.mesh", root);
	//face->play("");
	Ogre::SceneNode * sn = face->getSceneNode();
	sn->scale(0.1f, 0.1f, 0.1f);
	face->printAllAnimation();
	BOOST_CHECK(sn->getParentSceneNode() == root);

	COgreAnimationInterface * animation = comp->queryInterface< COgreAnimationInterface >();
	BOOST_CHECK(animation->isExist("first"));
	BOOST_CHECK(animation->enable("first", 1));
	while(animation->update(0.015f))
	{
		UnitTestEnvironmen::system->run();
	}
	UnitTestEnvironmen::system->run();
	UnitTestEnvironmen::system->run();
	//
	//face->
	/*COgreResourceInterface * face = comp->queryInterface<COgreResourceInterface>();
	
	
	BOOST_CHECK(face->initResourceGroup("testRG"));
	BOOST_CHECK(face->load(".", "FileSystem"));
	BOOST_CHECK_EQUAL(face->getResourceGroup(), "testRG");*/

	/*using namespace Orz;
	BlackBoardSystem::getInstance().write<int>("key", 123);
	int i = BlackBoardSystem::getInstance().read<int>("key");
	ORZ_LOG_NOTIFICATION<<i;*/
}

#endif