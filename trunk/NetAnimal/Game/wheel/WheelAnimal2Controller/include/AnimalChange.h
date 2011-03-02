											   
#ifndef __Orz_AnimalChange_h__
#define __Orz_AnimalChange_h__

#include "WheelAnimalControllerConfig.h"
#include "Animal.h"
#include "Something.h"

class OSMScene;
namespace Orz
{

typedef boost::shared_ptr<SomethingReplace> SomethingReplacePtr;
class AnimalChange
{
public:
	AnimalChange(AnimalPtr animal, Ogre::SceneNode * root);
public:

	bool update(TimeType interval);
	void stop(AnimalPtr animal);
	void reset(void);
	void clear(void);			 
	void insertAnimal(AnimalPtr animal);
	SomethingRise * getRise(float speed);
	SomethingReplace * getReplace(void);

	void setRingVisible(bool visible); 
private:
	std::vector<AnimalPtr> _animals;
	Ogre::AnimationState * _animation;
	boost::shared_ptr<OSMScene> _osm;
	Ogre::SceneNode * _sn;
	Ogre::SceneNode * _root;
	TimeType _changeTime;
	std::vector<AnimalPtr>::iterator _curAnimal;
	SomethingRisePtr _rise;
	SomethingReplacePtr _replace;
};


}

#endif