#include "WheelAnimalControllerStableHeaders.h"
#include "AnimalManager.h"
#include "AnimalManagerImpl.h"
#include "Animal_AnimalManagerImpl.h"
//#include "WheelDB.h"
#include "AnimalManagerDB.h"
using namespace Orz;


AnimalManager::AnimalManager(void)
{


}

AnimalManager::~AnimalManager(void)
{


}

AnimalManagerPtr AnimalManager::create(const std::string name)
{
	if(name == "animal.osm")
		return AnimalManagerPtr(new AnimalManagerImpl<AnimalManagerDB>());
	return AnimalManagerPtr();
}

