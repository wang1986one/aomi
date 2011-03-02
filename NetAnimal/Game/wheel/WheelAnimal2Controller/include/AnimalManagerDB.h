#ifndef __Orz_AnimalManagerDB_h__
#define __Orz_AnimalManagerDB_h__	


#include "WheelAnimalControllerConfig.h"
#include "Animal.h"
namespace Orz
{
	class AnimalManagerDB
	{
	public:
		/*bool load(const std::string & name);
		virtual ~WheelDB(void);*/

		AnimalPtr createAnimal(WheelEnum::AnimalType type, Ogre::SceneNode * sn);


	private:

		std::string getMeshName(WheelEnum::AnimalType type);

		void insertAnimationLion(AnimalPtr ani);
		void insertAnimationRabbit(AnimalPtr ani);
		void insertAnimationMonkey(AnimalPtr ani);
		void insertAnimationPanda(AnimalPtr ani);

		void insertAnimationLionBoss(AnimalPtr ani);
		void insertAnimationRabbitBoss(AnimalPtr ani);
		void insertAnimationMonkeyBoss(AnimalPtr ani);
		void insertAnimationPandaBoss(AnimalPtr ani);

	};
}

#endif

