#ifndef __Orz_UnitTest_OgreDotSceneLoaderUnitTest__
#define __Orz_UnitTest_OgreDotSceneLoaderUnitTest__
#include "SanUnitTestConfig.h"

#include "OgrePlayerComponent.h"
#include "COgreResourceInterface.h"
#include "COgreEntityInterface.h"
#include "COgreSceneLoaderInterface.h"
#include "COgreCCSInterface.h"
#include "CUpdateInterface.h"
#include "COgreNodeDebuggerInterface.h"
#include "CCSBasicCameraModes.h"
/*

#include "Engine.h"
#include "KeyToMessage.h"
#include "SingleChipToMessage.h"*/
BOOST_AUTO_TEST_CASE(OgreDotSceneLoaderUnitTest)
{
	using namespace Orz;

	/*ComponentPtr resComp = ComponentFactories::getInstance().create("OgreResource");
	COgreResourceInterface * resource = resComp->queryInterface<COgreResourceInterface>();
	
	
	
	resource->createGroup("ZhugeLiang");
	resource->addLocation("../../media/san/DotScene", "FileSystem");
	resource->init();*/



	ComponentPtr dotComp = ComponentFactories::getInstance().create("OgreDotSceneLoader");
	COgreSceneLoaderInterface * loader = dotComp->queryInterface<COgreSceneLoaderInterface>();


	Ogre::SceneManager * sm = Orz::OgreGraphicsManager::getSingleton().getSceneManager();
	sm->setSkyDome( true, "Examples/CloudySky", 5, 8 );
	Ogre::SceneNode * node =  sm->getRootSceneNode()->createChildSceneNode();
	node->yaw(Ogre::Radian(Ogre::Math::PI));
	node->setPosition(0.f, 0.f, -6465.f);
	node->setOrientation(-0.7f, 0.f, 0.7f, 0.f);
	loader->load("scene.scene", "ZhugeLiang", node);



	ComponentPtr comp = ComponentFactories::getInstance().create("OgreCCS");
	BOOST_CHECK(comp.get());
	COgreCCSInterface  * cif = comp->queryInterface<COgreCCSInterface>();
	BOOST_CHECK(cif);
	cif->print();



	ComponentPtr debug = ComponentFactories::getInstance().create("OgreNodeDebugger");
	
	COgreNodeDebuggerInterface * debugger = debug->queryInterface<COgreNodeDebuggerInterface>();

	BOOST_CHECK(debugger);
	debugger->pushNode(node);
	debugger->enable();

	CUpdateInterface  * update2 = debug->queryInterface<CUpdateInterface>();


	CCS::CameraControlSystem * ccs = cif->getCCS();
	BOOST_CHECK(ccs);
	boost::scoped_ptr<CCS::FixedCameraMode> _fixed(new CCS::FixedCameraMode(ccs));
	
	_fixed->setCameraPosition(Ogre::Vector3(0.48142f, 905.455f, -10-6.727f));
	_fixed->setCameraOrientation(Ogre::Quaternion(0.992081f, -0.125593f, -0.00112548f, -0.000142481f));
	ccs->setCurrentCameraMode(_fixed.get());
	CUpdateInterface  * update = comp->queryInterface<CUpdateInterface>();
	BOOST_CHECK(update);
	TimeType time = 0.f;
	while(time <= 130.f&&update->update(0.015f))
	{
		time+=0.015f;
		UnitTestEnvironmen::system->run();
	}

}

#endif