#ifndef __Orz_WheelAnimalSceneObj_h__
#define __Orz_WheelAnimalSceneObj_h__	


#include "WheelAnimalControllerConfig.h"

#include <orz/Toolkit_Base/FSMLogic.h>
#include <Ogre/Ogre.h>
#include "Animal.h"
namespace Ogre
{
	class SceneManager;
	class RenderWindow;
}
namespace Orz
{
	
	class BaseSceneImpl; 
	class AnimalManager;
	typedef boost::shared_ptr<AnimalManager> AnimalManagerPtr;
	class  _OrzWheelAnimal2ControllerExport WheelAnimalSceneObj
	{
	public:
		WheelAnimalSceneObj(Ogre::SceneManager* pSceneMgr, Ogre::RenderWindow* win);
		virtual ~WheelAnimalSceneObj(void);
		void load(const std::string & filename);
		AnimalPtr getAnimal(int n);

		void setLight(int n, int light);
		void setLightLiang(int n, int light);
		void setLightAn(int n, int light);
		
		void setTable(int n, int table);
		void setTableLiang(int n, int table);
		void setTableAn(int n, int table);

		
		Ogre::SceneNode * getNeedle(void);

		Ogre::Vector3 getCenterPoint(void);

		Ogre::Camera * getCamera(void);


		///得到动画管理器
		AnimalManagerPtr getAnimalManager(void) const;
		Ogre::SceneNode * getBase(int n);
		//显示光环
		void showBaseLight(int n, WheelEnum::LIGHT_COLOR id, bool show = true);

		Ogre::SceneNode * getBaseCenter();

		Ogre::AnimationState * getSceneAnimation(SceneItemMark mark);

		int findRandomAnimal(WheelEnum::AnimalType & type);
		void addLight( WheelEnum::LIGHT_COLOR color);
		void clearLight(void);
		void update(TimeType time);
		void showSence(bool show = true ,bool show1 = false);

		
		
		
	private:
		void showLight( WheelEnum::LIGHT_COLOR time);
		boost::shared_ptr<OSMScene> _osm;
		boost::shared_ptr<BaseSceneImpl> _impl;
		Ogre::Camera * getCamera(SceneItemMark mark);
		Ogre::SceneNode * getSceneNode(SceneItemMark mark);
		Ogre::Entity * getEntity(SceneItemMark mark);


		Ogre::SceneNode * _sn;	 
		Ogre::SceneNode * _cameraSn;
		Ogre::SceneNode * _senceNode;

		Ogre::Animation * _anim;

		Ogre::AnimationState* _animState;
		std::vector< WheelEnum::LIGHT_COLOR> _lights;
		TimeType _theTime;
		size_t _colorN;

	public:

		Ogre::SceneNode * getNullSceneNode(void);
		Ogre::Entity * getNullEntity(void);
		Ogre::AnimationState * getNullAnimationState(void);
	};
}

#endif

