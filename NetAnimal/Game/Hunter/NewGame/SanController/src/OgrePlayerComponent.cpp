#include "SanControllerBaseStableHeaders.h"
#include "OgrePlayerComponent.h"
using namespace Orz;


OgrePlayerComponent::OgrePlayerComponent(void)
{
	_meshComp = ComponentFactories::getInstance().create("OgreEntity");
	//_resourceComp = ComponentFactories::getInstance().create("OgreResource");
	
}

OgrePlayerComponent::~OgrePlayerComponent(void)
{
	
}

ComponentInterface * OgrePlayerComponent::_queryInterface(const TypeInfo & info)
{
	/*ComponentInterface * comp = _resourceComp->_queryInterface(info);
	if(comp)
		return comp;*/

	return _meshComp->_queryInterface(info);
}

