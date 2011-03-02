#include "SanControllerBaseStableHeaders.h"
#include "OgreResourceComponent.h"
#include "COgreResourceInterface.h"
#include <OGRE/ogre.h>
using namespace Orz;

OgreResourceComponent::OgreResourceComponent(void):_resourceInterface(new COgreResourceInterface()),_groupName(Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME)
{
	_resourceInterface->addLocation = boost::bind(&OgreResourceComponent::addResourceLocation, this, _1, _2);
	_resourceInterface->init = boost::bind(&OgreResourceComponent::initResourceGroup, this);
	_resourceInterface->createGroup = boost::bind(&OgreResourceComponent::createResourceGroup, this, _1);
	_resourceInterface->getGroup = boost::bind(&OgreResourceComponent::getResourceGroup, this);
	

}
OgreResourceComponent::~OgreResourceComponent(void)
{

}



bool OgreResourceComponent::addResourceLocation(const std::string & path, const std::string & type)
{
	using namespace Ogre;
    ResourceGroupManager& rgm = ResourceGroupManager::getSingleton();
	bool exists = rgm.resourceGroupExists(_groupName);
	if(!exists)
		return false;
	ResourceGroupManager::getSingleton().addResourceLocation(path, type, _groupName, true);
	
	
	return true;
}
bool OgreResourceComponent::initResourceGroup(void)
{
	using namespace Ogre;
    ResourceGroupManager& rgm = ResourceGroupManager::getSingleton();

    rgm.initialiseResourceGroup(_groupName);
	
	return true;
}

bool OgreResourceComponent::createResourceGroup(const std::string & groupName)
{
	_groupName = groupName;
	using namespace Ogre;
    ResourceGroupManager& rgm = ResourceGroupManager::getSingleton();
    rgm.createResourceGroup(_groupName);
	
	return true;
}
std::string OgreResourceComponent::getResourceGroup(void)
{
	return _groupName;
}
ComponentInterface * OgreResourceComponent::_queryInterface(const TypeInfo & info)
{
	if(info == TypeInfo(typeid(COgreResourceInterface)))
		return _resourceInterface.get();
	return NULL;
}