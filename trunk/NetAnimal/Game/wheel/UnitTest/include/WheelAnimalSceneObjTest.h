#ifndef __Orz_UnitTest_WheelAnimalSceneObjTest__
#define __Orz_UnitTest_WheelAnimalSceneObjTest__
#include "UnitTestConfig.h"
#include "WheelAnimalSceneObj.h"
/*

#include "Engine.h"
#include "KeyToMessage.h"
#include "SingleChipToMessage.h"*/

BOOST_AUTO_TEST_CASE(WheelAnimalSceneObjTest)
{
	using namespace Orz;

	boost::shared_ptr<WheelAnimalSceneObj> scene(new WheelAnimalSceneObj(OgreGraphicsManager::getSingleton().getSceneManager(), OgreGraphicsManager::getSingleton().getRenderWindow()));
	scene->load("test.osm");
	Ogre::Root::getSingleton().getAutoCreatedWindow()->getViewport(0)->setCamera(scene->getCamera());
    AnimalPtr animal = scene->getAnimal(0);
    scene->getAnimal(1);
	Ogre::AnimationState * as = scene->getSceneAnimation(SCENE_ANIMATION_0);
	
	BOOST_CHECK(as != NULL);
	BOOST_CHECK(animal != AnimalPtr());
	as->setEnabled(true);
	as->setLoop(false);
	UnitTestEnvironmen::system->run();

	while(!as->hasEnded())
	{

		as->addTime(0.1f);
		UnitTestEnvironmen::system->run();
	}
	
}
#endif