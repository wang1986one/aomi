#include "WheelAnimalControllerStableHeaders.h"
#include "BaseSceneImpl.h"
//#include "Test1SceneCallback.h"
#include "AnimalSceneCallback.h"
#include "AnimalManager.h"
#include "WheelData.h"
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
	if(filename == "test.osm")
	{

		boost::shared_ptr<AnimalSceneCallback> callback(new AnimalSceneCallback(WheelData::getInstance().getLions()));
		osm_cb = callback;
		base_scene = callback;
		
		osm->initialise(filename.c_str(), osm_cb.get());
	//	osm->createScene(Orz::OgreGraphicsManager::getSingleton().getSceneManager()->getRootSceneNode());
	}

	
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
		return std::string("sanse_hong");
	case 1:
		return std::string("sanse_huang");
	case 2:
		return std::string("sanse_lv");
	}
	return std::string("sanse_hong");

}


	
std::string BaseSceneImpl::getLightAn(int i)
{

	switch(i)
	{
	case 0:
		return std::string("sanse_hong_an");
	case 1:
		return std::string("sanse_huang_an");
	case 2:
		return std::string("sanse_lv_an");
	}
	return std::string("sanse_hong_an");

}
std::string BaseSceneImpl::getLightLiang(int i)
{

	switch(i)
	{
	case 0:
		return std::string("sanse_hong_liang");
	case 1:
		return std::string("sanse_huang_liang");
	case 2:
		return std::string("sanse_lv_liang");
	}
	return std::string("sanse_hong_liang");

}
std::string BaseSceneImpl::getTable(int i)
{

	switch(i)
	{
	case -1:
		return std::string("ercikaijiang_00b");
	case 0:
		return std::string("ercikaijiang_01b");
	case 1:
		return std::string("ercikaijiang_02b");
	case 2:
		return std::string("ercikaijiang_03b");
	case 3:
		return std::string("ercikaijiang_04b");
	case 4:
		return std::string("ercikaijiang_05b");
	case 5:
		return std::string("ercikaijiang_06b");
	case 6:
		return std::string("ercikaijiang_07b");
	case 7:
		return std::string("ercikaijiang_08b");
	}
	return std::string("ercikaijiang_00b");

}


std::string BaseSceneImpl::getTableLiang(int i)
{

	switch(i)
	{
	case -1:
		return std::string("ercikaijiang_00a");
	case 0:
		return std::string("ercikaijiang_01a");
	case 1:
		return std::string("ercikaijiang_02a");
	case 2:
		return std::string("ercikaijiang_03a");
	case 3:
		return std::string("ercikaijiang_04a");
	case 4:
		return std::string("ercikaijiang_05a");
	case 5:
		return std::string("ercikaijiang_06a");
	case 6:
		return std::string("ercikaijiang_07a");
	case 7:
		return std::string("ercikaijiang_08a");
	}
	return std::string("ercikaijiang_00a");

}

std::string BaseSceneImpl::getTableAn(int i)
{

	switch(i)
	{
	case -1:
		return std::string("ercikaijiang_00");
	case 0:
		return std::string("ercikaijiang_01");
	case 1:
		return std::string("ercikaijiang_02");
	case 2:
		return std::string("ercikaijiang_03");
	case 3:
		return std::string("ercikaijiang_04");
	case 4:
		return std::string("ercikaijiang_05");
	case 5:
		return std::string("ercikaijiang_06");
	case 6:
		return std::string("ercikaijiang_07");
	case 7:
		return std::string("ercikaijiang_08");
	}
	return std::string("ercikaijiang_00");

}


AnimalPtr BaseSceneImpl::getAnimal(int n)
{
	assert(n<24 && n>=0);
	if(!_animals[n])
	{
		WheelEnum::AnimalType type = getAnimalType(n);
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
		std::string animationName = getSceneAnimationName(mark);
		if(Orz::OgreGraphicsManager::getSingleton().getSceneManager()->hasAnimation(animationName))
		{
			animation = Orz::OgreGraphicsManager::getSingleton().getSceneManager()->createAnimationState(animationName);

		}else
		{
			animation = NULL;
		}
			
		
		_animations[mark] = animation;
		return animation;
	}
	
	return it->second;
}

