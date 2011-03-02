//#ifndef __Orz_GameTranslate__
//#define __Orz_GameTranslate__
//
//#include <WheelGobal/WinData.h>
//#include <WheelGobal/WheelEnum.h>
//#include "CSanSoldierInterface.h"
//#include "CNewGameSceneInterface.h"
//#include <boost/bimap.hpp>
//namespace Orz
//{
//
//	class GameTranslate
//	{
//	public:
//		GameTranslate()
//		{
//
//			for(int i =0; i<24; ++i)
//			{
//				_animal[i] =  (i %4 == 0)? AnimalEnum::TYPE0 : 
//					(
//					(i %4 == 1)?AnimalEnum::TYPE1 :
//					(	
//					(i %4 == 2)?AnimalEnum::TYPE2 :
//					AnimalEnum::TYPE3
//					)
//					);
//
//			}
//
//		}
//		void resetRate(WheelEnum::RATE rate)
//		{
//			for(int i =0; i<24; ++i)
//			{
//				if(i < 8)
//					_light[i] =  CNewGameSceneInterface::Red ;
//				else if (i <16)
//					_light[i] =  CNewGameSceneInterface::Yellow ;
//				else 
//					_light[i] =  CNewGameSceneInterface::Green ;
//
//			}
//			for(int i = 0; i<24; ++i)
//			{
//				std::swap(_light[i], _light[rand()%24]);
//			}
//
//		}
//		int getRandomColor(CNewGameSceneInterface::LIGHT_COLOR color)
//		{
//
//			return 	getItem<CNewGameSceneInterface::LIGHT_COLOR>(_light, color, rand()%3);
//		}
//
//		int getRandomType(AnimalEnum::TYPE type)
//		{
//			return 	getItem<AnimalEnum::TYPE>(_animal, type, rand()%3);
//		}
//		const boost::array<CNewGameSceneInterface::LIGHT_COLOR, 24> & getColorList(void) const
//		{
//
//			return 	_light;
//		}
//
//		const boost::array<AnimalEnum::TYPE, 24> & getAnimalList(void) const
//		{
//
//			return 	_animal;
//		}
//
//			
//			
//	
//		private:
//		template<class T>
//		int getItem(const boost::array<T, 24> &list, T what, int num)
//		{
//			int i = rand()% list.size();
//			for(;i<300; i++)
//			{
//				int n = i % list.size();
//				if(list.at(n) == what)
//				{
//					num--;
//					if(num <=0)
//						return n;
//				}
//			
//			}
//			return -1;
//		}
//
//		boost::array<CNewGameSceneInterface::LIGHT_COLOR, 24> _light;
//		boost::array<AnimalEnum::TYPE, 24> _animal;
//
//
//	};
//}
//#endif