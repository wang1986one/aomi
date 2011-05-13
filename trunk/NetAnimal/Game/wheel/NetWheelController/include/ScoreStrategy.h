#ifndef __Orz_ScoreStrategy_h__
#define __Orz_ScoreStrategy_h__
#include "WheelControllerConfig.h"
#include "WheelEnum.h"
#include "WinData.h"
#include "CoinPool.h"
#include "ScoreData.h"
#include "SCMData.h"
#include "WinDataPrototype.h"
#include "ScoreSecondWinner.h"
#include <boost/random.hpp>
namespace Orz
{
	//class ScoreStrategy
	//{
	//public:
	//	
	//	virtual int rebate(const SCMData & scm) = 0;
	//	virtual ~ScoreStrategy(void){}
	//	virtual void ready(ScoreData & data) = 0;
	//	virtual void go( const ScoreData & data,  SCMDataList & scms) = 0;
	//private:
	//};
	//typedef boost::shared_ptr<ScoreStrategy> ScoreStrategyPtr;

	//class ScoreStrategyNomal:public ScoreStrategy
	//{

	//public:
	//	typedef std::vector<WinDataPrototypePtr> WinList;
	//	ScoreStrategyNomal(void);
	//	virtual void ready(ScoreData & data);
	//	virtual void go( const ScoreData & data,  SCMDataList & scms);
	//	virtual int rebate(const SCMData & scm);
	//private:
	//	WinList _winDatas;
	//	WinList _bigWinDatas;
	//	ScoreAnimalPtr _scoreAnimal;
	//	ScoreWinnerPtr _scoreWinner;
	//	ScoreBonusPtr _scoreBonus;
	//	WinDataPrototypePtr _winner;
	////	CoinPoolPtr _coinPool;
	//	//CoinPoolPtr _earningsPool;
	////	CoinPoolPtr _rebatePool;
	//	//CoinPoolPtr _prizePool;
	////	CoinPoolPtr _bonusPool;
	//	WinDataPrototypePtr _mustWinData;
	//	
	//	Orz::ComponentPtr _table;

	//};

}



#endif