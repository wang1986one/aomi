#include "WheelAnimalControllerStableHeaders.h"
#include "BaseSceneImpl.h"
//#include "Test1SceneCallback.h"
#include "AnimalSceneCallback.h"
#include "AnimalManager.h"
#include "ThirdParty/Ofusion/OgreOSMScene.h"
#include <orz/View_OGRE3D/OgreGraphicsManager.h>
//#include "WheelDB.h"
using namespace Orz;



AnimalManagerPtr BaseSceneImpl::getAnimalManager(void) const
{
	return _animMgr;
}

boost::shared_ptr<BaseSceneImpl> BaseSceneImpl::create(boost::shared_ptr<OSMScene> osm, const std::string & filename)
{

	AnimalManagerPtr am = AnimalManager::create(filename);

	boost::shared_ptr<BaseSceneImpl> base_scene;
	boost::shared_ptr<OSMSceneCallbacks> osm_cb;
	if(filename == "animal.osm")
	{

		boost::shared_ptr<AnimalSceneCallback> callback(new AnimalSceneCallback());
		osm_cb = callback;
		base_scene = callback;
	}

	
	osm->initialise(filename.c_str(), osm_cb.get());
	base_scene->setAnimalManager(am);
	return base_scene;

}


bool BaseSceneImpl::empty(void)
{
	return _cameras.empty() && _sceneNodes.empty() && _entitis.empty(); 
}


void BaseSceneImpl::push_back(SceneItemMark mark, Ogre::Camera * camera)
{   
	_cameras[mark] = camera;
}
void BaseSceneImpl::push_back(SceneItemMark mark, Ogre::SceneNode * node)
{

	_sceneNodes[mark] = node;
}
void BaseSceneImpl::push_back(SceneItemMark mark, Ogre::Entity * entity)
{
	_entitis[mark] = entity;
}

 
void BaseSceneImpl::push_back(SceneItemMark mark, Ogre::AnimationState * animation)
{
	_animations[mark] = animation;
}

Ogre::Camera * BaseSceneImpl::getCamera(SceneItemMark mark)
{
	return _cameras[mark];
}
Ogre::SceneNode * BaseSceneImpl::getSceneNode(SceneItemMark mark)
{
	return _sceneNodes[mark];
}
Ogre::Entity * BaseSceneImpl::getEntity(SceneItemMark mark)
{
	EntityMap::iterator it = _entitis.find(mark);
	if(it == _entitis.end() )
		return getNullEntity();
	return _entitis[mark];
}


std::string BaseSceneImpl::getLight(int i)
{

	switch(i)
	{
	case 0:
		return std::string("zp_cj_sans01");
	case 1:
		return std::string("zp_cj_sans02");
	case 2:
		return std::string("zp_cj_sans03");
	}
	return std::string("zp_cj_sans01");

}


AnimalPtr BaseSceneImpl::getAnimal(int n)
{
	assert(n<24 && n>=0);
	if(!_animals[n])
	{
		WheelEnum::ANIMAL_TYPE type = getAnimalType(n);
	   _animals[n] = _animMgr->createAnimal(type, getSceneNode(SceneItemMark(BASE_0+n)));
	}
	return _animals[n];
}

void BaseSceneImpl::setAnimalManager(AnimalManagerPtr animMgr)
{


	 _animMgr = animMgr;
}

  
Ogre::AnimationState * BaseSceneImpl::getSceneAnimation(SceneItemMark mark)
{
	
	AnimationMap::iterator it = _animations.find(mark);
	if(it == _animations.end())
	{
		Ogre::AnimationState * animation = NULL; 
		if(hasSceneAnimationName(mark))
		{
			animation = Orz::OgreGraphicsManager::getSingleton().getSceneManager()->createAnimationState(getSceneAnimationName(mark));
			
		}
		_animations[mark] = animation;
		return animation;
	}
	
	return it->second;
}

