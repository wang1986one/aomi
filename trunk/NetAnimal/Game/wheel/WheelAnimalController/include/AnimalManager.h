						  
#ifndef __Orz_AnimalManager_h__
#define __Orz_AnimalManager_h__

 
#include "WheelAnimalControllerConfig.h"
#include "./Animal.h"
namespace Orz
{
class AnimalManager;
typedef boost::shared_ptr<AnimalManager> AnimalManagerPtr;
class AnimalManager
{

public:
	~AnimalManager(void);
	static AnimalManagerPtr create(const std::string name);
	virtual AnimalPtr createAnimal(WheelEnum::ANIMAL_TYPE type, Ogre::SceneNode * sn) = 0;
protected:
	AnimalManager(void);
private:
};
}

#endif