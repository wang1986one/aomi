#ifndef __Orz_UnitTest_OgrePlayerUnitTest__
#define __Orz_UnitTest_OgrePlayerUnitTest__
#include "SanUnitTestConfig.h"

#include "OgrePlayerComponent.h"
#include "COgreResourceInterface.h"
#include "COgreEntityInterface.h"
#include "COgreAnimationInterface.h"
/*

#include "Engine.h"
#include "KeyToMessage.h"
#include "SingleChipToMessage.h"*/
#include <OGRE/ogre.h>
BOOST_AUTO_TEST_CASE(OgrePlayerUnitTest)
{

	using namespace Orz;
	ComponentPtr comp = ComponentFactories::getInstance().create("OgrePlayer");
	/*
	COgreResourceInterface * rf = comp->queryInterface<COgreResourceInterface>();
	BOOST_CHECK(rf);


	BOOST_CHECK(rf->createGroup("ABC"));
	BOOST_CHECK(rf->addLocation("../../media/san/ZhugeLiang", "FileSystem"));
	rf->init();*/

	COgreEntityInterface * face = comp->queryInterface<COgreEntityInterface>();
	BOOST_CHECK(face);
	Ogre::SceneManager * sm = Orz::OgreGraphicsManager::getSingleton().getSceneManager();
	Ogre::SceneNode * root =  sm->getRootSceneNode()->createChildSceneNode();
	
	face->load("ms_01_4.mesh",  "ms_01_4.mesh", root);
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
	

}

#endif