#ifndef __Orz_BaseSceneObj__
#define __Orz_BaseSceneObj__	
 
#include "WheelAnimalControllerConfig.h"
#include <Ogre/Ogre.h>
#include <Ogre/OgreSharedPtr.h>
#include <TinyXML/tinyxml.h>
#include "AnimalManager.h"
#include "ThirdParty/Ofusion/IOSMSceneCallbacks.h"
#include <orz/View_OGRE3D/OgreGraphicsManager.h>
class OSMScene;
namespace Orz
{
class BaseSceneImpl
{
public:
	static boost::shared_ptr<BaseSceneImpl> create(boost::shared_ptr<OSMScene> osm, const std::string & filename);
	bool empty(void);
	BaseSceneImpl(void)
	{
		 Ogre::SceneManager * sm = Orz::OgreGraphicsManager::getSingleton().getSceneManager();
		_nullSceneNode = sm->createSceneNode();
		_nullEntity = sm->createEntity("NullEntity", "panda_jin.mesh");
		Ogre::Animation * anim = sm->createAnimation("NullAnimation", 4);
		_nullAnimationState  = sm->createAnimationState("NullAnimation");
	}


	
	virtual ~BaseSceneImpl(void){}
	Ogre::Camera * getCamera(SceneItemMark mark);
	Ogre::SceneNode * getSceneNode(SceneItemMark mark);
	Ogre::Entity * getEntity(SceneItemMark mark);
	virtual std::string getLight(int i);

	void setAnimalManager(AnimalManagerPtr animMgr);
	AnimalPtr getAnimal(int n);
	Ogre::AnimationState * getSceneAnimation(SceneItemMark mark);
	
	
	virtual std::string getSceneAnimationName(SceneItemMark mark) = 0;
	virtual bool hasSceneAnimationName(SceneItemMark mark) = 0;
	virtual WheelEnum::ANIMAL_TYPE getAnimalType(int n) = 0;
	
	//œ‘ æπ‚ª∑
	virtual void showBaseLight(int n, WheelEnum::LIGHT_COLOR id, bool show = true){}

	
	AnimalManagerPtr getAnimalManager(void) const;


protected:
	typedef std::map<SceneItemMark, Ogre::Camera *> CameraMap;
	typedef std::map<SceneItemMark, Ogre::SceneNode *> SceneNodeMap;
	typedef std::map<SceneItemMark, Ogre::Entity *> EntityMap;
	typedef std::map<SceneItemMark, Ogre::AnimationState *> AnimationMap;


	void push_back(SceneItemMark mark, Ogre::Camera * camera);
	void push_back(SceneItemMark mark, Ogre::SceneNode * node);
	void push_back(SceneItemMark mark, Ogre::Entity * entity);
	void push_back(SceneItemMark mark, Ogre::AnimationState * animation);
    
	CameraMap _cameras;
	SceneNodeMap _sceneNodes;
	EntityMap _entitis;
	AnimationMap _animations;

	AnimalManagerPtr _animMgr;

	boost::array<AnimalPtr, 24> _animals;
/// Null Object

	Ogre::AnimationState * _nullAnimationState; 
	Ogre::SceneNode * _nullSceneNode;	 
	Ogre::Entity * _nullEntity;
public:
	inline Ogre::SceneNode * getNullSceneNode(void)
	{
		return _nullSceneNode;
	}
	inline Ogre::Entity * getNullEntity(void)
	{
		return _nullEntity;
	}

	inline Ogre::AnimationState * getNullAnimationState(void)
	{
		return _nullAnimationState;
	}


};

}


#endif