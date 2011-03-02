#include "WheelAnimalControllerStableHeaders.h"
#include "AnimalManagerImpl.h"
#include <orz/View_OGRE3D/OgreGraphicsManager.h>
using namespace Orz;
//
//
//AnimalManagerImpl::AnimalManagerImpl(void)
//{
//
//
//}
//
//AnimalManagerImpl::~AnimalManagerImpl(void)
//{
//
//
//}
//
//AnimalPtr AnimalManagerImpl::createAnimal(WheelEnum::AnimalType type, Ogre::SceneNode * sn)
//{
//	
//	static int id = 0;
//	
//	Ogre::Entity * ent = Orz::OgreGraphicsManager::getSingleton().getSceneManager()->createEntity("AnimalManagerImpl_"+Ogre::StringConverter::toString(++id), "lion_jin.mesh");
//	Ogre::SceneNode * node = sn->createChildSceneNode(Ogre::Vector3(0.0f, 40.f, 0.f));
//	node->attachObject(ent);
//	node->yaw(Ogre::Radian(Ogre::Math::PI));
//	AnimalPtr ani(new Animal(type, node, ent));
//	/*{
//		Ogre::AnimationState* animState = ent->getAnimationState("panda_gj");
//		animState->setEnabled(false);
//		animState->setLoop(true);
//		ani->insertAnimation(WheelEnum::ACTION1, animState);
//	}*/
//	return ani;
//}
//
