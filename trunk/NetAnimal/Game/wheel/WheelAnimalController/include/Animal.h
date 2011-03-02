
#ifndef __Orz_Animal_h__
#define __Orz_Animal_h__


#include "WheelAnimalControllerConfig.h"
#include "WheelEnum.h"
#include <Ogre/Ogre.h>
class OSMScene;
namespace Orz
{
	class TheAnimation
	{
	public:
		TheAnimation(Ogre::AnimationState* anim):_anim(anim)
		{
			_anim->setEnabled(true);
			_anim->setTimePosition(0.f);
		}

		bool update(TimeType interval/*********/)
		{
			_anim->addTime(interval);
			return _anim->hasEnded();
		}
		~TheAnimation(void)
		{
			_anim->setEnabled(false);
		}
	private:
		Ogre::AnimationState * _anim;
	};

}
namespace Orz
{

class TheAnimation;

class _OrzWheelAnimalControllerExport Animal
{
public:
	Animal(WheelEnum::ANIMAL_TYPE type, Ogre::SceneNode * sn, Ogre::Entity * entity);
public:

	
	bool update(TimeType interval);
	void play(WheelEnum::ACTION_TYPE action);
	WheelEnum::ANIMAL_TYPE getType(void);
	void stop(void);
	void insertAnimation(WheelEnum::ACTION_TYPE action, Ogre::AnimationState* anim);
	Ogre::Entity * getEntity(void) const;
	Ogre::SceneNode * getSceneNode(void) const;
private:
	typedef std::map<WheelEnum::ACTION_TYPE, Ogre::AnimationState *> AnimationMap;
	
	Ogre::Entity * _ent;
	Ogre::SceneNode * _sn; 
   
	boost::scoped_ptr<TheAnimation> _curAnim;

	AnimationMap _actions;
	WheelEnum::ANIMAL_TYPE _type;
};

typedef boost::shared_ptr<Animal> AnimalPtr;



}

#endif