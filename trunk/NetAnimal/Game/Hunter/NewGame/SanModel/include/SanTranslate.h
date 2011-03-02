#ifndef __Orz_SanTranslate__
#define __Orz_SanTranslate__

#include <WheelGobal/WheelUIInterface.h>
#include <WheelGobal/WinData.h>
#include "CSanSoldierInterface.h"
#include <boost/bimap.hpp>
namespace Orz
{

	class SanTranslate
	{
	public:
		SanTranslate()
		{


		}

		void getSoldierList(void)
		{
			boost::array<int, 21> temp;
			for(int i = 0; i<21; ++i)
			{
				temp[i] = i;
			}

			for(int i = 0; i<21; ++i)
			{
				std::swap(temp[i], temp[rand()%21]);
			}
			for(int i = 0; i<21; ++i)
			{

				_bimap.insert( boost::bimap<int, int>::value_type(i, temp[i]) );
			}
			std::cout<<std::endl;
		}
		CSanSoldierInterface::Soldier getSoldier(int i)
		{
			return _getSoldier(_bimap.left.at(i));;
		}
		int getRandomSoldierLocation(CSanSoldierInterface::Soldier type)
		{
			return _bimap.right.at(type * 7 +rand()%7);
		}
	private:

		CSanSoldierInterface::Soldier  _getSoldier(int i)
		{
			if(i <7)
				return CSanSoldierInterface::Archer;
			if(i <14)
				return CSanSoldierInterface::Cavalry;
			return CSanSoldierInterface::Foot;
		}



		boost::bimap<int, int> _bimap;

	};
}
#endif