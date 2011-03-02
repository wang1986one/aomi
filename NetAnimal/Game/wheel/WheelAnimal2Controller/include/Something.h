
#ifndef __Orz_Something_h__
#define __Orz_Something_h__

#include "WheelAnimalControllerConfig.h"
#include "Animal.h"
class OSMScene;
namespace Orz
{

	class SomethingRise
	{
	public:
		SomethingRise(float high, float speed, Ogre::SceneNode * sn);
		~SomethingRise(void);
		bool update(TimeType interval);
		void clear(void);
	private:
		float _high;
		float _speed;
		Ogre::SceneNode * _sn;
		Ogre::Vector3 _from;
	};

	typedef boost::shared_ptr<SomethingRise> SomethingRisePtr;

	class SomethingReplace
	{
	public:
		SomethingReplace(TimeType interval, std::vector<AnimalPtr> & animals, std::vector<AnimalPtr>::iterator & curAnimal, Ogre::SceneNode * node);
		void update(TimeType interval);
		void stop(WheelEnum::AnimalType  type);
		~SomethingReplace(void);  
		void clear(void);
	private:
		void jump(void);
		std::vector<AnimalPtr> & _animals;
		std::vector<AnimalPtr>::iterator & _curAnimal;
		const TimeType _interval;
		TimeType _time;
		Ogre::SceneNode * _node;
		Ogre::Quaternion _dir;
	};

	typedef boost::shared_ptr<SomethingReplace> SomethingReplacePtr;
}

#endif