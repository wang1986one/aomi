#include "WheelGobalStableHeaders.h"
#include "TVListMap.h"
using namespace Orz;


TVListMap::TVListMap(void)
{
	
}


void TVListMap::insert(const WheelEnum::AnimalItem & item, WheelEnum::TVListPtr list)
{
	_listMap[item] = list;
}

WheelEnum::AnimalItem TVListMap::getAnimalItem(const WheelEnum::AnimalItem & item, size_t i)
{
	WheelEnum::ListMap::iterator it = _listMap.find(item);
	if(it != _listMap.end())
	{
		if(i<(it->second)->size())
			return ((it->second)->at(i));
	}
	return WheelEnum::AnimalItem();
}


bool TVListMap::hasAnimalItem(const WheelEnum::AnimalItem & item, size_t i)
{
	WheelEnum::ListMap::iterator it = _listMap.find(item);
	if(it != _listMap.end())
	{
		if(i<(it->second)->size())
		{
			return true;
		}
		
	}
	return false;
}