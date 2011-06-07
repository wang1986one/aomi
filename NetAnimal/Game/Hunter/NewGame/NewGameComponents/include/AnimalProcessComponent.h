#ifndef __Orz_AnimalProcessComponent__
#define __Orz_AnimalProcessComponent__

#include "CSanProcessInterface.h"
namespace Ogre
{
	class SceneNode;
}

namespace Orz
{
	class CGameActionInterface;
	class CAnimalProcessInterface;
	class  AnimalProcessComponent: public Component
	{

	public :
		AnimalProcessComponent(void);
		virtual ~AnimalProcessComponent(void);
	private:

		ComponentInterface * _queryInterface(const TypeInfo & info) const;

		bool activate(SanProcess process);
		boost::scoped_ptr<CGameActionInterface> _actionInterface;
		boost::scoped_ptr<CAnimalProcessInterface> _animalInterface;

		AnimalEnum::ANIMAL_TYPE getType(void) const;
		bool init(AnimalEnum::ANIMAL_TYPE type, Ogre::SceneNode * node);
		void setWinner(bool isWinner);
		bool _isWinner;
		
		ComponentPtr _entityComp;
		void callback(int times);
		AnimalEnum::ANIMAL_TYPE _type;
	};



}
#endif