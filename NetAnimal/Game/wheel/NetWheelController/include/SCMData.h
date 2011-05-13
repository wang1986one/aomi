#ifndef __Orz_SCMData_h__
#define __Orz_SCMData_h__	


#include "WheelControllerConfig.h"
#include "WheelEnum.h"
#include "WinData.h"
#include "ScoreData.h"
#include "WinDataPrototype.h"
#include "CoinPool.h"
#include "ScoreWinner.h"
#include "ScoreAnimal.h"
namespace Orz
{


	//class _OrzNetWheelControlleExport SCMData
	//{
	//public:
	//	SCMData()
	//	{


	//	}
	//	void clickButton(int button)
	//	{


	//		switch(ScoreData::innuendo(button))
	//		{
	//		case 0:
	//			_winner.push(Orz::WheelEnum::Dealer);
	//			break;
	//		case 1:
	//			_winner.push(Orz::WheelEnum::Player);
	//			break;
	//		case 2:
	//			_winner.push(Orz::WheelEnum::Draw);
	//			break;

	//		case 3:
	//			_animal.push(Orz::WheelEnum::AnimalItem(WheelEnum::TYPE0, WheelEnum::Red));
	//			break;
	//		case 4:
	//			_animal.push(Orz::WheelEnum::AnimalItem(WheelEnum::TYPE0, WheelEnum::Yellow));
	//			break;
	//		case 5:
	//			_animal.push(Orz::WheelEnum::AnimalItem(WheelEnum::TYPE0, WheelEnum::Green));
	//			break;


	//			
	//		case 6:
	//			_animal.push(Orz::WheelEnum::AnimalItem(WheelEnum::TYPE1, WheelEnum::Red));
	//			break;
	//		case 7:
	//			_animal.push(Orz::WheelEnum::AnimalItem(WheelEnum::TYPE1, WheelEnum::Yellow));
	//			break;
	//		case 8:
	//			_animal.push(Orz::WheelEnum::AnimalItem(WheelEnum::TYPE1, WheelEnum::Green));
	//			break;


	//			
	//		case 9:
	//			_animal.push(Orz::WheelEnum::AnimalItem(WheelEnum::TYPE2, WheelEnum::Red));
	//			break;
	//		case 10:
	//			_animal.push(Orz::WheelEnum::AnimalItem(WheelEnum::TYPE2, WheelEnum::Yellow));
	//			break;
	//		case 11:
	//			_animal.push(Orz::WheelEnum::AnimalItem(WheelEnum::TYPE2, WheelEnum::Green));
	//			break;


	//			
	//		case 12:
	//			_animal.push(Orz::WheelEnum::AnimalItem(WheelEnum::TYPE3, WheelEnum::Red));
	//			break;
	//		case 13:
	//			_animal.push(Orz::WheelEnum::AnimalItem(WheelEnum::TYPE3, WheelEnum::Yellow));
	//			break;
	//		case 14:
	//			_animal.push(Orz::WheelEnum::AnimalItem(WheelEnum::TYPE3, WheelEnum::Green));
	//			break;



	//		}

	//	}
	//	void clear(void)
	//	{
	//		_animal.reset();
	//		_winner.reset();
	//	}
	//	void sum(const SCMData & data)
	//	{
	//		_animal.sum(data._animal);
	//		_winner.sum(data._winner);
	//	}
	//	int getTotal(void) const
	//	{
	//		int winner = _winner.getTotal();
	//		int animal = _animal.getTotal();
	//		return winner + animal;
	//	}


	//	const ScoreWinner::Winner & getWinner(void) const
	//	{
	//		return _winner;
	//	}

	//	const ScoreAnimal::Animal & getAnimal(void) const
	//	{
	//		return _animal;
	//	}
	//private: 
	//	ScoreWinner::Winner _winner;
	//	ScoreAnimal::Animal _animal;

	//};



	//typedef std::vector<SCMData> SCMDataList;


}

#endif

