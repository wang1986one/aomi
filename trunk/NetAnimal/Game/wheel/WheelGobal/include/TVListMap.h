#ifndef __Orz_TVListMap_h__
#define __Orz_TVListMap_h__
#include "WheelGobalConfig.h"
#include "WheelEnum.h"
namespace Orz
{

	
	class TVListMap
	{
	public:

	public:
		TVListMap(void);
		WheelEnum::AnimalItem getAnimalItem(const WheelEnum::AnimalItem & item, size_t i);
		
		bool hasAnimalItem(const WheelEnum::AnimalItem & item, size_t i);
		void insert(const WheelEnum::AnimalItem & item, WheelEnum::TVListPtr list);
	private:

		WheelEnum::ListMap _listMap;
	};
}

#endif