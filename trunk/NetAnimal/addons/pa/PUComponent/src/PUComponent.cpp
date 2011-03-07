#include "PUComponentStableHeaders.h"
#include "PUComponent.h"
#include "CParticleInterface.h"
using namespace Orz;

PUComponent::PUComponent(void):_interface(new CParticleInterface())
{
	_interface->enable = boost::bind(&PUComponent::enable,this, _1, _2);
	_interface->update = boost::bind(&PUComponent::update,this, _1);
	_interface->disable = boost::bind(&PUComponent::disable,this); 
}
PUComponent::~PUComponent(void)
{

}


bool PUComponent::enable(const std::string & name , Ogre::SceneNode * node)
{
	
	static int i = 0;
	i++;
	Ogre::SceneManager * sm = Orz::OgreGraphicsManager::getSingleton().getSceneManager();
	ParticleUniverse::ParticleSystemManager * particleSystemManager = ParticleUniverse::ParticleSystemManager::getSingletonPtr(); 
	_system = particleSystemManager->createParticleSystem(name +Ogre::StringConverter::toString(i), name, sm); 
	
	node->attachObject(_system); 


	_system->start();

	return true;
}
void PUComponent::disable(void)
{
	_system->stop(); 
	Ogre::SceneManager * sm = Orz::OgreGraphicsManager::getSingleton().getSceneManager();
	
	ParticleUniverse::ParticleSystemManager * particleSystemManager = ParticleUniverse::ParticleSystemManager::getSingletonPtr(); 
	particleSystemManager->destroyParticleSystem(_system, sm);
	_system = NULL;
}
bool PUComponent::update(TimeType i)
{
	return false;
}
ComponentInterface * PUComponent::_queryInterface(const TypeInfo & info)
{

	if(info == TypeInfo(typeid(CParticleInterface)))
		return _interface.get();
	return NULL;
}



