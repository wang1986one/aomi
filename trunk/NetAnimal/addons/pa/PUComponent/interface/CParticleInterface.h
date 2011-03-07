#ifndef __Orz_CParticleInterface__
#define __Orz_CParticleInterface__
#include <orz/Toolkit_Component_Task/Component/ComponentInterface.h>	


namespace Ogre
{
class SceneNode;
}
namespace Orz
{
class CParticleInterface: public ComponentInterface
{
private:
	typedef boost::function<bool (const std::string &/* name*/, Ogre::SceneNode * /* sn*/)> EnableFunction;
	typedef boost::function<bool (TimeType i)> UpdateFunction;
	typedef boost::function<void (void)> DisableFunction;

public:
	
	EnableFunction enable;
	UpdateFunction update;
	DisableFunction disable;
};
}
#endif