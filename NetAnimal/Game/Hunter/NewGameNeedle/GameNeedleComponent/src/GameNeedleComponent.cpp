#include "GameNeedleComponentStableHeaders.h"
#include "GameNeedleComponent.h"
#include "COgreSceneLoaderInterface.h"
#include "COgreCCSInterface.h"
#include "CGameNeedleInterface.h"
#include "CGameFlowerInterface.h"
#include "SubEntityMaterialInstance.h"
using namespace Orz;

GameNeedleComponent::GameNeedleComponent(void):_needleInterface(new CGameNeedleInterface)
{

	_needleInterface->load = boost::bind(&GameNeedleComponent::load, this,  _1);
	_needleInterface->setLeafVisible = boost::bind(&GameNeedleComponent::setLeafVisible, this,  _1);

	_flowerComp = Orz::ComponentFactories::getInstance().create("GameFlower");

	
}

GameNeedleComponent::~GameNeedleComponent(void) 
{
	
}

bool GameNeedleComponent::load(Ogre::SceneNode * node)
{

	using namespace Ogre;
	Ogre::SceneManager * sm = Orz::OgreGraphicsManager::getSingleton().getSceneManager();
	Ogre::Entity * needle = sm->createEntity("needle", "poniter.mesh");
	node->createChildSceneNode(Ogre::Vector3(0, 0 , 0))->attachObject(needle);
	_semi.reset(new SubEntityMaterialInstance(needle->getSubEntity(1)));
	
	//needle->getSubEntity(1)->getMaterial()->addListener;
	CGameFlowerInterface * flower = _flowerComp->queryInterface<CGameFlowerInterface>();
	/*Ogre::SceneNode * sn = node->createChildSceneNode(Ogre::Vector3(310, 180, 0));
	Light* light;

	light = sm->createLight();
	light->setType(Ogre::Light::LT_POINT);
	light->setAttenuation(80, 1, 0, 0);
	light->setDiffuseColour(Ogre::ColourValue::White);
	sn->attachObject(light);*/
	//sn->attachObject(sm->createEntity("ogrehe", "ogrehead.mesh"));
	flower->load(node);

	return true;
}


void GameNeedleComponent::setLeafVisible(bool visible)
{
	if(visible)
	{
		_semi->setTransparency(0.f);
	}
	else
	{
		_semi->setTransparency(0.1f);
	}
}

ComponentInterface * GameNeedleComponent::_queryInterface(const TypeInfo & info)
{

	if(info == TypeInfo(typeid(CGameNeedleInterface)))
		return _needleInterface.get();

	return _flowerComp->_queryInterface(info);
	
}
