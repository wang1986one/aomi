							  
#ifndef __Orz_AnimalManagerImpl_h__
#define __Orz_AnimalManagerImpl_h__

 
#include "WheelAnimalControllerConfig.h"
#include "./AnimalManager.h"
namespace Orz
{

template<class AM>
class AnimalManagerImpl:public AnimalManager
{
public:
	AnimalManagerImpl(void){}
	~AnimalManagerImpl(void){}
	AnimalPtr createAnimal(WheelEnum::AnimalType type, Ogre::SceneNode * sn)
	{
		return 	_am.createAnimal(type, sn);;
	}
public:
	AM _am;
};

}

#endif