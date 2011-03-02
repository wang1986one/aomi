#include "SanControllerBaseStableHeaders.h"
#include "SanSceneComponent.h"
#include "CSanSceneInterface.h"
#include "COgreSceneLoaderInterface.h"
#include "COgreCCSInterface.h"
#include "CCSBasicCameraModes.h"
#include "CGameActionInterface.h"
#include "COgreNodeDebuggerInterface.h"
#include "CUpdateInterface.h"
#include <orz/PUComponent/CParticleInterface.h>
using namespace Orz;
SanSceneComponent::SanSceneComponent(void):_interface(new CSanSceneInterface()), _actionInterface(new CGameActionInterface()),_system(NULL), _node(NULL)
{
	_interface->load = boost::bind(&SanSceneComponent::load,this, _1); //boost::bind();
	_interface->getSceneNode = boost::bind(&SanSceneComponent::getSceneNode,this); 
	_dotSceneComp = ComponentFactories::getInstance().create("OgreDotSceneLoader");
	
	_ccsComp = ComponentFactories::getInstance().create("OgreCCS");
	/*_debugger = ComponentFactories::getInstance().create("OgreNodeDebugger");*/

	//_pComp	 = ComponentFactories::getInstance().create("PUComponent");//创建一个粒子组件

	
	COgreCCSInterface  * cif = _ccsComp->queryInterface<COgreCCSInterface>();
	CCS::CameraControlSystem * ccs = cif->getCCS();
	_fixed.reset(new CCS::FixedCameraMode(ccs));

	_actionInterface->activate = boost::bind(&SanSceneComponent::activate, this, _1);
}

Ogre::SceneNode * SanSceneComponent::getSceneNode(void) const 
{
	return _node;
}
SanSceneComponent::~SanSceneComponent(void)
{
	
	
}

//bool SanSceneComponent::enableParticle(const std::string & name, Ogre::SceneNode * node)
//{
//
//	Ogre::SceneManager * sm = Orz::OgreGraphicsManager::getSingleton().getSceneManager();
//	ParticleUniverse::ParticleSystemManager * particleSystemManager = ParticleUniverse::ParticleSystemManager::getSingletonPtr(); 
//	_system = particleSystemManager->createParticleSystem("mySystem", name, sm); 
//	
//	node->attachObject(_system); 
//
//
//	_system->start();
//
//	return true;
//}
//
//
//bool SanSceneComponent::updateParticle(TimeType i)
//{
//	return false;
//}
inline bool enable(CParticleInterface * particle,const std::string & name, Ogre::SceneNode * node)
{
	return particle->enable(name, node);
}
//void SanSceneComponent::disableParticle(void)
//{
//	_system->stop(); 
//	Ogre::SceneManager * sm = Orz::OgreGraphicsManager::getSingleton().getSceneManager();
//	
//	ParticleUniverse::ParticleSystemManager * particleSystemManager = ParticleUniverse::ParticleSystemManager::getSingletonPtr(); 
//	particleSystemManager->destroyParticleSystem(_system, sm);
//	_system = NULL;
//}
bool SanSceneComponent::activate(SanProcess process)
{
	//if(process == PROCESS_PRORUN)
	//{
	//	CParticleInterface * particle= _pComp->queryInterface<CParticleInterface>();//从组件中得到粒子接口
	//	Ogre::SceneNode * newNode = _node->createChildSceneNode(Ogre::Vector3(1015, -1482, -20));
	//	/////Orz::OgreGraphicsManager::getSingleton().getCamera()->lookAt(Ogre::Vector3(1015, -1482, -20));
	//	_actionInterface->enable = boost::bind(&enable, particle, "san/fire", newNode);//boost::bind(&SanSceneComponent::enableParticle, this, "explosionSystem", newNode);
	//	_actionInterface->disable =  particle->disable;//boost::bind(&SanSceneComponent::disableParticle, this);
	//	_actionInterface->update = particle->update;//boost::bind(&SanSceneComponent::updateParticle, this,  _1);
	//	return true;
	//}	


	return false;
}
bool SanSceneComponent::load(const std::string & gName)
{


	COgreSceneLoaderInterface * loader = _dotSceneComp->queryInterface<COgreSceneLoaderInterface>();
	Ogre::SceneManager * sm = Orz::OgreGraphicsManager::getSingleton().getSceneManager();
	sm->setSkyDome( true, "Examples/CloudySky", 5, 8 );
	_node =  sm->getRootSceneNode()->createChildSceneNode();
	_node->yaw(Ogre::Radian(Ogre::Math::PI));
	_node->setPosition(0.f, 0.f, -6465.f);
	_node->setOrientation(-0.7f, 0.f, 0.7f, 0.f);
	loader->load("scene.scene", gName, _node);



	

	COgreCCSInterface  * cif = _ccsComp->queryInterface<COgreCCSInterface>();
	cif->print();




	CCS::CameraControlSystem * ccs = cif->getCCS();
	
	
	_fixed->setCameraPosition(Ogre::Vector3(0.48142f, 905.455f, -10-6.727f));
	_fixed->setCameraOrientation(Ogre::Quaternion(0.992081f, -0.125593f, -0.00112548f, -0.000142481f));
	ccs->setCurrentCameraMode(_fixed.get());


	return true;
}
ComponentInterface * SanSceneComponent::_queryInterface(const TypeInfo & info)
{


	//if(info == TypeInfo(typeid(CUpdateInterface)))
	//{
	//	return _debugger->queryInterface<CUpdateInterface>();
	//}
	if(info == TypeInfo(typeid(CSanSceneInterface)))
	{
		return _interface.get();
	}	
	if(info == TypeInfo(typeid(CGameActionInterface)))
	{
		return _actionInterface.get();
	}

	ComponentInterface * iface =  _dotSceneComp->_queryInterface(info);
	if(iface)
	{
		return iface;
	}
	iface =  _ccsComp->_queryInterface(info);
	if(iface)
	{
		return iface;
	}
	return NULL;
}

