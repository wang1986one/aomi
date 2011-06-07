#include "GameDiamondComponentStableHeaders.h"
//#include "GameAnimalComponent.h"
//#include "COgreEntityInterface.h"
////#include "CCSBasicCameraModes.h"
//using namespace Orz;
//
//GameAnimalComponent::GameAnimalComponent(void)
//{
//
//	_entityComp = Orz::ComponentFactories::getInstance().create("OgreEntity");
//	COgreEntityInterface * entity = _entityComp->queryInterface<COgreEntityInterface>();
//	
//	Ogre::SceneManager * sm = Orz::OgreGraphicsManager::getSingleton().getSceneManager();
//	Ogre::SceneNode *root =  sm->getRootSceneNode()->createChildSceneNode();
//
//	static int i = 0;
//	i++;
//	entity->load("ms_01_4.mesh" + boost::lexical_cast<std::string>(i), "ms_01_4.mesh", root);
//}
//
//GameAnimalComponent::~GameAnimalComponent(void)
//{
//	
//}
//
//
//
//ComponentInterface * GameAnimalComponent::_queryInterface(const TypeInfo & info) const
//{
//
//	//if(info == TypeInfo(typeid(CGameBaseInterface)))
//	//	return _baseInterface.get();
//	return NULL;
//	
//}
