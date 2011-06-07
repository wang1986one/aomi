#include "SanControllerBaseStableHeaders.h"
#include "OgreDotSceneLoaderComponent.h"
#include "COgreSceneLoaderInterface.h"
#include "COgreResourceInterface.h"
#include "DotSceneLoader.h"
using namespace Orz;

boost::scoped_ptr<COgreSceneLoaderInterface> _sceneLoaderInterface;
OgreDotSceneLoaderComponent::OgreDotSceneLoaderComponent(void):_sceneLoaderInterface(new COgreSceneLoaderInterface()),_dotSceneLoader(new Ogre::DotSceneLoader())
{
	_sceneLoaderInterface->_load = boost::bind(&OgreDotSceneLoaderComponent::loadScene, this, _1, _2, _3); 
}

bool OgreDotSceneLoaderComponent::loadScene(const std::string & sceneName, const std::string & groupName,  Ogre::SceneNode * node)
{

	_dotSceneLoader->parseDotScene(sceneName, groupName,  Orz::OgreGraphicsManager::getSingleton().getSceneManager(), node);
	return true;
}
OgreDotSceneLoaderComponent::~OgreDotSceneLoaderComponent(void)
{

}
ComponentInterface * OgreDotSceneLoaderComponent::_queryInterface(const TypeInfo & info) const
{
	if(info == TypeInfo(typeid(COgreSceneLoaderInterface)))
		return _sceneLoaderInterface.get();
	return NULL;
}
