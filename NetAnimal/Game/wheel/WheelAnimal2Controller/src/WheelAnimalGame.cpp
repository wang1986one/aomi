#include "WheelAnimalControllerStableHeaders.h"

#include "WheelAnimalGame.h"
#include "WheelAnimalSceneObj.h"
#include "WheelAnimalProcessManager.h"
#include "ObjectLights.h"
#include "AnimalChange.h"
#include "RotateAnimation.h"
#include "ColorChange.h"
#include "TV.h"
#include "Gold.h"
#include "WinEffect.h"
#include "AnimalManager.h"
#include <orz/View_OGRE3D/OgreGraphicsManager.h>
using namespace Orz;
namespace Orz
{

	typedef  boost::shared_ptr<RotateAnimation> RotateAnimationPtr;
	typedef  boost::shared_ptr<AnimalChange> AnimalChangePtr;
	typedef  boost::shared_ptr<ColorChange> ColorChangePtr;
	typedef  boost::shared_ptr<TV> TVPtr;
	typedef  boost::shared_ptr<Gold> GoldPtr;
	typedef  boost::shared_ptr<ObjectLights> ObjectLightsPtr;
	typedef  boost::shared_ptr<WinEffect> WinEffectPtr;

}
WheelAnimalGame::WheelAnimalGame(void)
{
	_scene.reset(new WheelAnimalSceneObj(OgreGraphicsManager::getSingleton().getSceneManager(), OgreGraphicsManager::getSingleton().getRenderWindow()));
	try
	{
		_scene->load("test.osm");
	}
	catch(std::exception & e)
	{
		std::cout<<e.what()<<std::endl;
	}
	Ogre::Root::getSingleton().getAutoCreatedWindow()->getViewport(0)->setCamera(_scene->getCamera());
	


	ObjectLightsPtr objLights(new ObjectLights(_scene));

	AnimalManagerPtr am = _scene->getAnimalManager();
	Ogre::SceneNode * node = Orz::OgreGraphicsManager::getSingleton().getSceneManager()->getRootSceneNode()->createChildSceneNode(_scene->getCenterPoint());

	AnimalChangePtr ac(
		new AnimalChange(
		am->createAnimal(WheelEnum::AnimalType(WheelEnum::LION, WheelEnum::PEOPLE), 
		node

		),
		node
		)
		);

	ac->insertAnimal(
		am->createAnimal(
		WheelEnum::AnimalType(WheelEnum::RABBIT, WheelEnum::PEOPLE), 
		node)
		);

	ac->insertAnimal(
		am->createAnimal(
		WheelEnum::AnimalType(WheelEnum::MONKEY, WheelEnum::PEOPLE), 
		node	
		)
		);

	ac->insertAnimal(
		am->createAnimal(
		WheelEnum::AnimalType(WheelEnum::PANDA, WheelEnum::PEOPLE), 
		node
		)
		);



	node =  Orz::OgreGraphicsManager::getSingleton().getSceneManager()->getRootSceneNode()->createChildSceneNode(_scene->getCenterPoint());
	node->setScale(0.65f,0.65f,0.65f);
	ColorChangePtr cc(new ColorChange(node));

	node =  Orz::OgreGraphicsManager::getSingleton().getSceneManager()->getRootSceneNode()->createChildSceneNode(_scene->getCenterPoint());
	TVPtr tv(new TV(node));

	node =  Orz::OgreGraphicsManager::getSingleton().getSceneManager()->getRootSceneNode()->createChildSceneNode(_scene->getCenterPoint());
	GoldPtr gold(new Gold(node));



	//node =  Orz::OgreGraphicsManager::getSingleton().getSceneManager()->getRootSceneNode()->createChildSceneNode(_scene->getCenterPoint());
	WinEffectPtr effect(new WinEffect(_scene));


	RotateAnimationPtr needle(new RotateAnimation("_needle", _scene->getNeedle(),Orz::OgreGraphicsManager::getSingleton().getSceneManager(), true ));
	RotateAnimationPtr rotate(new RotateAnimation("_rotate", _scene->getBaseCenter(),Orz::OgreGraphicsManager::getSingleton().getSceneManager(), false ));




	for(int i =0; i<24; ++i)
	{
		_scene->getAnimal(i)->play(WheelEnum::ACTION1);
	}

	//ObjectLightsPtr objLights(new ObjectLights(_scene));

	/*	
	boost::shared_ptr<RotateAnimation> _rotate;
	boost::shared_ptr<RotateAnimation> _needle;

	boost::shared_ptr<AnimalChange> _ac;
	boost::shared_ptr<ColorChange> _cc;
	boost::shared_ptr<TV> _tv;

	boost::shared_ptr<Gold> _gold;
	ObjectLightsPtr _objLights;
	WinEffectPtr _effect;*/


	_processManager.reset(new WheelAnimalProcessManager(
		_scene,
		rotate,
		needle,
		ac,
		cc,
		tv,
		gold,
		objLights,
		effect));
}
WheelAnimalGame::~WheelAnimalGame(void)
{

}


void WheelAnimalGame::notice(Event * evt)
{
	_processManager->notice(evt);
}
void WheelAnimalGame::update(TimeType interval)
{
	for(int i=0; i< 24; ++i)
	{
		_scene->getAnimal(i)->update(interval);
	}

	_scene->update(interval);
	_processManager->update(interval);
}