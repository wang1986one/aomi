#ifndef __Orz_WinData_h__
#define __Orz_WinData_h__	


#include "WheelGobalConfig.h"
#include "WheelEnum.h"
namespace Orz
{



	class _OrzWheelGobalExport WinDataClone
	{
	public:
		friend class WinData;
		WinDataClone(const WinDataClone & wdc);
		WinDataClone & operator = (const WinDataClone & rhs);
		WheelEnum::WINNER getWinner(void) const;
		WheelEnum::LIGHT_COLOR getLightColor(void) const;
		WheelEnum::WIN_MODE getWinMode(void) const;
		WheelEnum::AnimalType getAnimalType(void) const;
		WheelEnum::TYPE getType(void) const;
		int getTable(void) const;
		WheelEnum::STATUS getAnimalStatus(void) const;
		WheelEnum::AnimalItem getAnimalItem(void) const;
		size_t size(void) const;
		WinDataClone(void);
	private:
		
		void init(WheelEnum::WINNER winner, WheelEnum::LIGHT_COLOR lightColor, WheelEnum::WIN_MODE winMode, WheelEnum::TYPE animalType, size_t size, int table);
		WheelEnum::WINNER _winner;//要
		WheelEnum::LIGHT_COLOR _lightColor;//要
		WheelEnum::WIN_MODE _winMode;//要
		WheelEnum::TYPE _animalType;//要
		size_t _size;
		int _table;
	};
	//class _OrzWheelGobalExport WinDataPrototype
	//{
	//public:

	//}


	class _OrzWheelGobalExport WinData//  : public Singleton<WinData>
	{
		struct WinItem
		{
			WinItem(WheelEnum::LIGHT_COLOR color_, WheelEnum::TYPE type_, int rate_):
			color(color_),
			type(type_),
			rate(rate_){}
			WheelEnum::LIGHT_COLOR color;
			WheelEnum::TYPE type;
			int rate;
		};
	public:
		typedef std::pair<int, WheelEnum::LIGHT_COLOR> SecondWinner;
		typedef std::vector<SecondWinner>  SecondWinnerList;

		void setRate(WheelEnum::RATE rate);
		WheelEnum::RATE getRate(void) const;
		WheelEnum::WINNER getWinner(void) const;
		WheelEnum::LIGHT_COLOR getLightColor(int i = 0) const;
		int getRate(int i) const;
		int getRate(const WheelEnum::AnimalItem & animal) const;
		WheelEnum::WIN_MODE getWinMode(void) const;
		WheelEnum::AnimalType getAnimalType(int i = 0) const;
		SecondWinnerList * getSecondWinnerList(void)
		{
			if(getSecondWinner())
			{
				return &_secondWinnerList;
			}
			return NULL;
		}
		
		bool getSecondWinner(void) const;
		void setSecondWinnerId(int Id);
		int getSecondWinnerId(void) const;
		void setSecondWinner(bool secondWinner);
		WheelEnum::TYPE getType(int i = 0) const;
		WheelEnum::STATUS getAnimalStatus(void) const;
		int getBonus(void) const;
		WheelEnum::AnimalItem getAnimalItem(int i = 0) const;
		size_t size(void) const;
		static WinData & getInstance(void);
		static WinData * getInstancePtr(void);

		WinDataClone & getClone(void);

	public:
		void clear(void);
		void push_back(const WheelEnum::AnimalItem & animal, int rate);
		void setWinMode(WheelEnum::WIN_MODE winMode);
		void setBonus(int bonus);
		void setWinner(WheelEnum::WINNER winner);
		
	private:
		
		WinData(void);

		WheelEnum::WINNER _winner;//要
		//WheelEnum::LIGHT_COLOR _lightColor;//要
		WheelEnum::RATE _rate;//不要
		WheelEnum::WIN_MODE _winMode;//要
		//WheelEnum::TYPE _animalType;//要
		int _bonus;//不要
		
		//WheelEnum::STATUS _status;

		WinDataClone _clone;
	
		std::vector<WinItem> _items;

		
		
		SecondWinnerList _secondWinnerList;
		bool _secondWinner;
		int _secondWinnerId;
	//	void init(const WinData & WinData::getSingleton());
	};
	typedef boost::shared_ptr<WinData> WinDataPtr;
}

#endif



