#ifndef __Orz_OgrePlayerComponent__
#define __Orz_OgrePlayerComponent__
#include "SanControllerConfig.h"
namespace Ogre
{
class SceneNode;
class Entity;
}

namespace Orz
{
//class COgreMeshInterface;
class  OgrePlayerComponent: public Component
{
public :
	OgrePlayerComponent(void);
	virtual ~OgrePlayerComponent(void);
private:
private:
	virtual ComponentInterface * _queryInterface(const TypeInfo & info) const;

	ComponentPtr _meshComp;
};
}
#endif