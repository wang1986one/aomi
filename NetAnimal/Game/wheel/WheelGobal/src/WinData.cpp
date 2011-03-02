#include "WheelGobalStableHeaders.h"
	


#include "WinData.h"
#include "WheelData.h"
#include "BlackBoardSystem.h"
#include <orz/Toolkit_Base/LogSystem.h>
using namespace Orz;


WinDataClone &  WinDataClone::operator =(const WinDataClone & wdc)
{
	_winner = wdc._winner;
	_lightColor = wdc._lightColor;
	_winMode = wdc._winMode;
	_animalType = wdc._animalType;
	_size = wdc._size;
	_table = wdc._table;
	return *this;
}

WinDataClone::WinDataClone(const WinDataClone & wdc)
{
	_winner = wdc._winner;
	_lightColor = wdc._lightColor;
	_winMode = wdc._winMode;
	_animalType = wdc._animalType;
	_size = wdc._size;
	_table = wdc._table;
}
WheelEnum::WINNER WinDataClone::getWinner(void) const
{
	return _winner;
}
WheelEnum::LIGHT_COLOR WinDataClone::getLightColor(void) const
{
	return _lightColor;
}

int WinDataClone::getTable(void) const
{
	return _table;
}
WheelEnum::WIN_MODE WinDataClone::getWinMode(void) const
{
	return _winMode;
}
WheelEnum::TYPE WinDataClone::getType(void) const
{
	
	
	return _animalType;
}


WinDataClone::WinDataClone(void)
{
	
}
size_t WinDataClone::size(void) const
{
	//if(_winMode == WheelEnum::GOLD)
		 
		return _size;
}
		

WheelEnum::AnimalItem WinDataClone::getAnimalItem(void) const
{
	//if(_winMode == WheelEnum::GOLD)
		 
		return WheelEnum::AnimalItem(getType(), getLightColor());
}


void WinDataClone::init(WheelEnum::WINNER winner, WheelEnum::LIGHT_COLOR lightColor, WheelEnum::WIN_MODE winMode, WheelEnum::TYPE animalType, size_t size, int table)
{
	
	_table = table;
	_winner = winner;
	_lightColor = lightColor;
	_winMode = winMode;
	_animalType = animalType;
	_size = size;


}


template<> WinData* Singleton<WinData>::_singleton = NULL;

WheelEnum::STATUS WinData::getAnimalStatus(void) const
{
	if(this->_winMode == WheelEnum::GOLD)
		return  WheelEnum::KING;

	return  WheelEnum::PEOPLE;
}


WinData::WinData(void):
_winner(WheelEnum::Dealer),
_bonus(0),
_rate(WheelEnum::MODE0),
_winMode(WheelEnum::NONE),
_secondWinner(false)
{
	
}

void WinData::setSecondWinnerId(int Id)
{
	_secondWinnerId = Id;
}
int WinData::getSecondWinnerId(void) const
{
	return _secondWinnerId;
}
bool WinData::getSecondWinner(void) const
{
	return _secondWinner;
}

void WinData::setSecondWinner(bool secondWinner)
{
	_secondWinner = secondWinner;
}

WheelEnum::TYPE WinData::getType(int i) const
{
	if(size_t(i) >= _items.size())
		return WheelEnum::TYPE0;
	return _items.at(i).type;
}

WinData & WinData::getInstance(void)
{
	return *(getInstancePtr());
}

WinDataClone & WinData::getClone(void)
{
	_clone.init(_winner, getLightColor(0), _winMode, getType(0), size(), _secondWinnerId);
	return _clone;
}

WinData * WinData::getInstancePtr(void)
{
	static WinData instance;
	return &instance;
}
WheelEnum::AnimalItem WinData::getAnimalItem(int i) const
{
	return WheelEnum::AnimalItem(getType(i), getLightColor(i));
	//return WheelEnum::AnimalItem(_animalType, _lightColor);
}

size_t WinData::size(void) const
{
	return _items.size();
}


void WinData::setRate(WheelEnum::RATE rate)
{
	_rate =  rate;//static_cast<WheelEnum::RATE>(BlackBoardSystem::getInstance().read<int>(WheelEnum::RATE_STR));
}
WheelEnum::RATE WinData::getRate(void) const
{
	return _rate;
}
WheelEnum::WINNER WinData::getWinner(void) const
{
	return _winner;
}
WheelEnum::LIGHT_COLOR WinData::getLightColor(int i) const
{
	if(size_t(i) >= _items.size())
		return WheelEnum::Red;
	return _items.at(i).color;
	//return _lightColor;
}

int WinData::getRate(const WheelEnum::AnimalItem & animal) const
{
	std::vector<WinItem>::const_iterator it;
	for(it = _items.begin(); 
		it != _items.end(); 
		++it)
	{
		if(it->type == animal.first && it->color == animal.second)
		{
			return it->rate;
		}
	}
	return 0;
}
int WinData::getRate(int i) const
{
	if(size_t(i) >= _items.size())
		return 0;
	return _items.at(i).rate;
}
WheelEnum::WIN_MODE WinData::getWinMode(void) const
{
	return _winMode;
}
WheelEnum::AnimalType WinData::getAnimalType(int i) const
{
	return WheelEnum::AnimalType(getType(i), getAnimalStatus());

}
int WinData::getBonus(void) const
{
	return _bonus;
}




void WinData::clear(void)
{
	_secondWinnerId = -1;
	_items.clear();
}
void WinData::push_back(const WheelEnum::AnimalItem & animal, int rate)
{
	_items.push_back(WinItem(animal.second, animal.first, rate));
	
}




		
void WinData::setWinMode(WheelEnum::WIN_MODE winMode)
{
	_winMode = winMode;
}
void WinData::setBonus(int bonus)
{
	_bonus = bonus;
}
void WinData::setWinner(WheelEnum::WINNER winner)
{
	_winner = winner;
}
