#ifndef __Orz_OgreEntityComponent__
#define __Orz_OgreEntityComponent__
#include "SanControllerConfig.h"
namespace Ogre
{
class SceneNode;
class Entity;
class AnimationState;
}

namespace Orz
{
class COgreEntityInterface;
class COgreAnimationInterface;
class  OgreEntityComponent: public Component
{
public :
	OgreEntityComponent(void);
	virtual ~OgreEntityComponent(void);
private:
	void load(const std::string & name, const std::string & meshName, Ogre::SceneNode * sn);
	Ogre::SceneNode* getSceneNode(void) const ;
	Ogre::Entity* getEntity(void) const ;
	void printAllAnimation(void);
	bool setCurAnimation(const std::string & name, int times);
	bool setDefaultAnimation(const std::string & name);
	bool updateAnimation(TimeType interval);
	bool isExistAnimation(const std::string & name);
	void disableCurAnimation(void);
	void unload(void);
private:

	
	virtual ComponentInterface * _queryInterface(const TypeInfo & info) const;
	boost::scoped_ptr<COgreEntityInterface> _entityInterface;
	boost::scoped_ptr<COgreAnimationInterface> _animationInterface;

	Ogre::SceneNode * _sn;
	Ogre::Entity * _ent;
	Ogre::AnimationState* _animationState;  
	Ogre::AnimationState* _defaultState;  

	int _times;
	bool _isLoad;
	//std::string _groupName;
};
}
#endif