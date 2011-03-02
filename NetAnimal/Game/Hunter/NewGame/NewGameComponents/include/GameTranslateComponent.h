#ifndef __Orz_GameTranslateComponent_
#define __Orz_GameTranslateComponent__

#include "CSanProcessInterface.h"
#include "CGameTranslateInterface.h"
namespace Ogre
{
	class SceneNode;
}

namespace Orz
{
	class CGameActionInterface;
	class  GameTranslateComponent: public Component
	{

	public :
		GameTranslateComponent(void);
		virtual ~GameTranslateComponent(void);
	private:

		boost::scoped_ptr<CGameTranslateInterface> _translateInterface;
		ComponentInterface * _queryInterface(const TypeInfo & info);

		void resetRate(WheelEnum::RATE rate);
		int getColor();

		int getType();
		const boost::array<CNewGameSceneInterface::LIGHT_COLOR, 24> & getColorList(void) const;

		const boost::array<AnimalEnum::ANIMAL_TYPE, 24> & getAnimalList(void) const;


	private:
		template<class T>
		int getItem(const boost::array<T, 24> &list, T what, int num)
		{
			int i = rand()% list.size();
			for(;i<300; i++)
			{
				int n = i % list.size();
				if(list.at(n) == what)
				{
					num--;
					if(num <=0)
						return n;
				}

			}
			return -1;
		}

		boost::array<CNewGameSceneInterface::LIGHT_COLOR, 24> _light;
		boost::array<AnimalEnum::ANIMAL_TYPE, 24> _animal;
	

		void random(CNewGameSceneInterface::LIGHT_COLOR color, AnimalEnum::ANIMAL_TYPE type);
		int _randColor;
		int _randType;

	};



}
#endif