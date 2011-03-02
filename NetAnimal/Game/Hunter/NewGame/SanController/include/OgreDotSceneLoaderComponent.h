#ifndef __Orz_OgreDotSceneLoaderComponent__
#define __Orz_OgreDotSceneLoaderComponent__
#include "SanControllerConfig.h"	
namespace Ogre
{
class DotSceneLoader;
}
namespace Orz
{

class COgreSceneLoaderInterface;
class  OgreDotSceneLoaderComponent: public Component
{
public :
	OgreDotSceneLoaderComponent(void);
	virtual ~OgreDotSceneLoaderComponent(void);
	
private:
	bool loadScene(const std::string & sceneName,const std::string & groupName, Ogre::SceneNode * node);
	virtual ComponentInterface * _queryInterface(const TypeInfo & info);
	//ComponentPtr _resourceComp;
	boost::scoped_ptr<COgreSceneLoaderInterface> _sceneLoaderInterface;
	boost::scoped_ptr<Ogre::DotSceneLoader> _dotSceneLoader;
};
}
#endif