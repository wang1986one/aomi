#ifndef __Orz_SetWinMsgA_h__
#define __Orz_SetWinMsgA_h__	

#include "WheelLogic.h"
#include "StartLogic.h"
#include "WMHardwareInterface.h"
#include "WinData.h"
#include "LockInterface.h"
#include "DataServerInterface.h"
namespace Orz
{


	
		


	////ÉèÖÃÓ²¼þÊôÐÔ
	//class SetWinMsg
	//{

	//public:	
	///*	TimeType getWaitTime(void) const
	//	{
	//		return 0.0f;
	//	}*/
	//	SetWinMsg(void):/*_allScore(0),*/_communicate(NULL)/*,_lock(NULL),_dataServer(NULL)*/
	//	{

	//		Orz::ComponentPtr scoreComp = Orz::ComponentFactories::getInstance().create("Score");
	//		ScoreInterface  * score = scoreComp->queryInterface<ScoreInterface>();
	//		score->calculator();
	//		const ScoreInterface::ScoreResult & result = score->getResult();
	//		_prototype = result.prototype;
	//		WinData::getInstance().clear();

	//		WinData::getInstance().setTable(result.table);
	//		WinData::getInstance().setWinner(result.winner);
	//	
	//		if(result.bonus.has && _prototype->winMode == WheelEnum::NONE)
	//		{
	//			WinData::getInstance().setWinMode(WheelEnum::GOLD);

	//		}else
	//		{
	//			WinData::getInstance().setWinMode(_prototype->winMode);
	//		}
	//			
	//		WinData::getInstance().setBonus(result.bonus.has, result.bonus.bonus, result.bonus.invest, result.bonus.profitForPerInvest);

	//		Orz::ComponentPtr dataComp = Orz::ComponentFactories::getInstance().create("DataCentre");
	//		Orz::DataCentreInterface * data = dataComp->queryInterface<DataCentreInterface>();



	//		BOOST_FOREACH(WheelEnum::AnimalItem item , _prototype->animalItems)
	//		{
	//			int id  = data->item2Id(item);
	//			WinData::getInstance().push_back(item, data->getRate(id, WinData::getInstance().getRate()));
	//		}
	//	//	//_opComp = Orz::ComponentFactories::getInstance().create("OperatingPanel");

	//	}
	//	~SetWinMsg(void)
	//	{

	//	}

	//	void init(WheelGame * game)
	//	{	
	//		assert(game);
	//		//_communicate = game->getHardware()->queryInterface<CommunicateInterface>();
	//	}
	//	void exit(void)
	//	{
	//		
	//	
	//	}
	//	bool send(Orz::CommunicateInterface::PanelID id)
	//	{


	//		const WinData::Bonus & bonus = WinData::getInstance().getBonus();
	//		WheelEnum::Winner winner = WinData::getInstance().getWinner();
	//		OperatingPanelInterface * operation = //_opComp->queryInterface<OperatingPanelInterface>();
	//		size_t score = operation->testAnimal2Player(CommunicateInterface::PanelID(id), _prototype);

	//		int table = Orz::WinData::getInstance().getTable();
	//	
	//		
	//		score += operation->testWinner2Player(id, winner);

	//
	//		if(bonus.has)
	//		{
	//			score += operation->getAnimalCoins(id) * bonus.profitForPerInvest;
	//			_communicate->setScore(id, ScoreInterface::WinPrototypePtr(), score);
	//		}else
	//		{
	//			
	//			if(_prototype->winMode == WheelEnum::NONE && table == id)
	//			{
	//				score *=2;
	//			}
	//			_communicate->setScore(id, _prototype, score);
	//		}
	//		//_allScore += score;
	//		return false;

	//	}
	//	bool receive(CommunicateInterface::PackagePtr package, Orz::CommunicateInterface::PanelID id)
	//	{

	//		return (package->getId() == id); 
	//	}
	//private:
	//	Orz::ComponentPtr //_opComp;
	//	//ScoreInterface::WinPrototypePtr _prototype;
	//	//int _allScore;
	//	//CommunicateInterface * _communicate;
	//	//LockInterface * _lock;// = _dataServer->queryInterface<LockInterface>();
	//	//DataServerInterface * _dataServer;
	//};
}
#endif