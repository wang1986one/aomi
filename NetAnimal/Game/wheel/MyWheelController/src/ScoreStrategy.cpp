#include "MyWheelControllerStableHeaders.h"
#include "ScoreStrategy.h"
#include "F5TableInterface.h"
using namespace Orz;
//void ScoreStrategyNomal::ready(ScoreData & data)
//{
//	_scoreAnimal->reset();
//	_scoreWinner->reset();
//
//
//
//	Orz::WinData::getInstance().setSecondWinnerId(-1);
//	WinData::SecondWinnerList * list =  Orz::WinData::getInstance().getSecondWinnerList();
//	if(list)
//	{
//
//		list->clear();
//		int secondWinNumber = rand() %7 +2;
//		for(int i =0 ; i< secondWinNumber; ++i)
//		{
//			list->push_back(
//				WinData::SecondWinner(
//				rand() %8, 
//				WheelEnum::LIGHT_COLOR( i%3))
//				);
//		}
//		//	Orz::WinData::getInstance().addSecondWinner(_secondWinnerList);
//	}
//
//	Orz::WinData::getInstance().setRate(WheelEnum::RATE(rand() %6));
//
//}
//void ScoreStrategyNomal::go( const ScoreData & data,  SCMDataList & scms)
//{ 
//
//	F5TableInterface * table = _table->queryInterface<F5TableInterface>();
//	SCMData scm;
//	scm.clear();
//	for(size_t i=0; i< scms.size(); ++i)
//	{
//		scm.sum(scms.at(i));
//	}
//
//
//	int total = scm.getTotal();
//
//	
//	table->pushCoinPool(total);
//	/*for(int i = 0 ; i < total; ++i)
//	{
//		_coinPool->push();
//	}*/
//
//
//
//	////设置装先河
//	{
//		std::pair<int , WheelEnum::WINNER> ret= _scoreWinner->getWinner(scm.getWinner(),table->getPrizePool()/*_Pool->total()*/);
//		table->setPrizePoolOut(ret.first);
//		//_prizePool->out();
//		WinData::getInstance().setWinner(ret.second);
//	}
//
//
//	if(_mustWinData)
//	{
//		_winner = _mustWinData;
//		_winner->submit( Orz::WinData::getInstance().getRate());
//		return;
//	}
//	//是否得到金奖
//	int bouns = _scoreBouns->getBounsAmount(table->getBounsPool(), scm.getAnimal().getTotal(), 0.01f);
//	bool isBouns = _scoreBouns->isBounsAmount(bouns);
//	//isBouns = true;
//	{
//		///计算得哪个奖
//		std::pair<int , WinDataPrototypePtr> ret = _scoreAnimal->getWinner(scm.getAnimal() , _winDatas, _bigWinDatas, table->getPrizePool(), isBouns);
//		table->setPrizePoolOut(ret.first);
//		//_prizePool->out();
//		_winner = ret.second;
//
//		if(isBouns)
//		{
//			_winner= _winner->gatBounsData();
//			_winner->setBouns(bouns);
//			table->setBounsPoolOut(bouns);//_bounsPool->out(bouns);
//		}
//		else
//		{
//			_winner->setBouns(-1);
//		}
//
//
//
//		_winner->submit( Orz::WinData::getInstance().getRate());
//
//
//		WinData::SecondWinnerList * list =  Orz::WinData::getInstance().getSecondWinnerList();
//		if(list && list->size() && _winner->getWinMode() == WheelEnum::NONE)
//		{
//			using namespace boost;
//			boost::mt19937 engine(time(NULL));
//			boost::uniform_real<> distribution(0,1);
//
//			variate_generator<mt19937, uniform_real<> > myrandom (engine, distribution);
//			float r =  myrandom();
//			if(r <0.3f)
//			{
//				//int i = rand() % list->size();
//				//	WinData::SecondWinner secondWinner = list->at(i);
//				BOOST_FOREACH(WinData::SecondWinner sw ,*list)
//				{
//					if(sw.second == Orz::WinData::getInstance().getLightColor(0))
//					{
//						if(sw.first < scms.size())
//						{
//							int back = _scoreAnimal->calculate(scms.at(sw.first).getAnimal(), _winner.get(), Orz::WinData::getInstance().getRate());
//							if(table->getPrizePool() >= back)
//							{
//								table->setPrizePoolOut(back);
//								Orz::WinData::getInstance().setSecondWinnerId(sw.first);
//								break;
//							}
//						}
//
//					}
//				}
//
//
//			}
//
//			ScoreSecondWinner::getSecondWinner(table->getPrizePool(), scms);
//
//		}
//
//
//
//	}
//
//
//
//
//}
//
//int ScoreStrategyNomal::rebate(const SCMData & scm)
//{
//
//	return  _scoreAnimal->calculate(scm.getAnimal(), _winner.get(), Orz::WinData::getInstance().getRate());//->calculate();
//	//scm.calculate(_winner.get(), Orz::WinData::getInstance().getRate());//
//
//}
//ScoreStrategyNomal::ScoreStrategyNomal(void)
//{
//
//	
//	_table = Orz::ComponentFactories::getInstance().create("F5Table");
//	//_coinPool.reset(new CoinPool(100));
//	//_earningsPool.reset(new CoinPool(4));
//	//_rebatePool.reset(new CoinPool(96));
//	////_prizePool.reset(new CoinPool(48));
//	////_bounsPool.reset(new CoinPool(48));
//
//	//_coinPool->link(_earningsPool, 4);
//	//_coinPool->link(_rebatePool, CoinPool::AllOther);
//
////	_rebatePool->link(_prizePool, 48);
//	//_rebatePool->link(_bounsPool, CoinPool::AllOther);
//
//
//	WinDataPrototypePtr data;
//	data.reset(new WinDataPrototype(WheelEnum::NONE));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE0, WheelEnum::Red));
//	_winDatas.push_back(data);
//
//
//	data.reset(new WinDataPrototype(WheelEnum::NONE));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE0, WheelEnum::Yellow));
//	_winDatas.push_back(data);
//
//
//
//	data.reset(new WinDataPrototype(WheelEnum::NONE));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE0, WheelEnum::Green));
//	_winDatas.push_back(data);
//
//
//
//
//	data.reset(new WinDataPrototype(WheelEnum::NONE));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE1, WheelEnum::Red));
//	_winDatas.push_back(data);
//
//
//	data.reset(new WinDataPrototype(WheelEnum::NONE));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE1, WheelEnum::Yellow));
//	_winDatas.push_back(data);
//
//
//
//	data.reset(new WinDataPrototype(WheelEnum::NONE));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE1, WheelEnum::Green));
//	_winDatas.push_back(data);
//
//
//
//
//
//
//	data.reset(new WinDataPrototype(WheelEnum::NONE));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE2, WheelEnum::Red));
//	_winDatas.push_back(data);
//
//
//	data.reset(new WinDataPrototype(WheelEnum::NONE));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE2, WheelEnum::Yellow));
//	_winDatas.push_back(data);
//
//
//
//	data.reset(new WinDataPrototype(WheelEnum::NONE));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE2, WheelEnum::Green));
//	_winDatas.push_back(data);
//
//
//
//
//
//
//	data.reset(new WinDataPrototype(WheelEnum::NONE));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE3, WheelEnum::Red));
//	_winDatas.push_back(data);
//
//
//	data.reset(new WinDataPrototype(WheelEnum::NONE));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE3, WheelEnum::Yellow));
//	_winDatas.push_back(data);
//
//
//
//	data.reset(new WinDataPrototype(WheelEnum::NONE));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE3, WheelEnum::Green));
//	_winDatas.push_back(data);
//
//
//
//
//	data.reset(new WinDataPrototype(WheelEnum::ALL_ANIMAL));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE0, WheelEnum::Red));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE0, WheelEnum::Yellow));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE0, WheelEnum::Green));
//	_bigWinDatas.push_back(data);
//
//
//
//	data.reset(new WinDataPrototype(WheelEnum::ALL_ANIMAL));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE1, WheelEnum::Red));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE1, WheelEnum::Yellow));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE1, WheelEnum::Green));
//	_bigWinDatas.push_back(data);
//
//
//
//
//	data.reset(new WinDataPrototype(WheelEnum::ALL_ANIMAL));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE2, WheelEnum::Red));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE2, WheelEnum::Yellow));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE2, WheelEnum::Green));
//	_bigWinDatas.push_back(data);
//
//
//
//
//	data.reset(new WinDataPrototype(WheelEnum::ALL_ANIMAL));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE3, WheelEnum::Red));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE3, WheelEnum::Yellow));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE3, WheelEnum::Green));
//	_bigWinDatas.push_back(data);
//
//
//
//
//	data.reset(new WinDataPrototype(WheelEnum::ALL_COLOR));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE0, WheelEnum::Red));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE1, WheelEnum::Red));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE2, WheelEnum::Red));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE3, WheelEnum::Red));
//	_bigWinDatas.push_back(data);
//	
//
//	data.reset(new WinDataPrototype(WheelEnum::ALL_COLOR));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE0, WheelEnum::Yellow));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE1, WheelEnum::Yellow));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE2, WheelEnum::Yellow));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE3, WheelEnum::Yellow));
//	_bigWinDatas.push_back(data);
//
//
//
//
//	data.reset(new WinDataPrototype(WheelEnum::ALL_COLOR));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE0, WheelEnum::Green));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE1, WheelEnum::Green));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE2, WheelEnum::Green));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE3, WheelEnum::Green));
//	_bigWinDatas.push_back(data);
//
//	///////////////////////////////////////////////////////////
//
//
//	data.reset(new WinDataPrototype(WheelEnum::DOUBLE));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE0, WheelEnum::Red));
//	_bigWinDatas.push_back(data);
//
//
//	data.reset(new WinDataPrototype(WheelEnum::DOUBLE));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE0, WheelEnum::Yellow));
//	_bigWinDatas.push_back(data);
//
//	data.reset(new WinDataPrototype(WheelEnum::DOUBLE));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE0, WheelEnum::Green));
//	_bigWinDatas.push_back(data);
//
//
//
//	data.reset(new WinDataPrototype(WheelEnum::DOUBLE));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE1, WheelEnum::Red));
//	_bigWinDatas.push_back(data);
//
//
//	data.reset(new WinDataPrototype(WheelEnum::DOUBLE));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE1, WheelEnum::Yellow));
//	_bigWinDatas.push_back(data);
//
//	data.reset(new WinDataPrototype(WheelEnum::DOUBLE));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE1, WheelEnum::Green));
//	_bigWinDatas.push_back(data);
//
//
//
//
//	data.reset(new WinDataPrototype(WheelEnum::DOUBLE));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE2, WheelEnum::Red));
//	_bigWinDatas.push_back(data);
//
//
//	data.reset(new WinDataPrototype(WheelEnum::DOUBLE));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE2, WheelEnum::Yellow));
//	_bigWinDatas.push_back(data);
//
//	//_mustWinData = data;
//	data.reset(new WinDataPrototype(WheelEnum::DOUBLE));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE2, WheelEnum::Green));
//	_bigWinDatas.push_back(data);
//
//
//
//
//	data.reset(new WinDataPrototype(WheelEnum::DOUBLE));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE3, WheelEnum::Red));
//	_bigWinDatas.push_back(data);
//
//
//	data.reset(new WinDataPrototype(WheelEnum::DOUBLE));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE3, WheelEnum::Yellow));
//	_bigWinDatas.push_back(data);
//
//	data.reset(new WinDataPrototype(WheelEnum::DOUBLE));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE3, WheelEnum::Green));
//	_bigWinDatas.push_back(data);
//	///////////////////////////////////////////////////////////
//
//
//	data.reset(new WinDataPrototype(WheelEnum::TREBLE));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE0, WheelEnum::Red));
//	_bigWinDatas.push_back(data);
//
//
//	data.reset(new WinDataPrototype(WheelEnum::TREBLE));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE0, WheelEnum::Yellow));
//	_bigWinDatas.push_back(data);
//
//	data.reset(new WinDataPrototype(WheelEnum::TREBLE));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE0, WheelEnum::Green));
//	_bigWinDatas.push_back(data);
//
//
//
//	data.reset(new WinDataPrototype(WheelEnum::TREBLE));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE1, WheelEnum::Red));
//	_bigWinDatas.push_back(data);
//
//
//	data.reset(new WinDataPrototype(WheelEnum::TREBLE));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE1, WheelEnum::Yellow));
//	_bigWinDatas.push_back(data);
//
//	data.reset(new WinDataPrototype(WheelEnum::TREBLE));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE1, WheelEnum::Green));
//	_bigWinDatas.push_back(data);
//
//
//
//
//	data.reset(new WinDataPrototype(WheelEnum::TREBLE));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE2, WheelEnum::Red));
//	_bigWinDatas.push_back(data);
//
//
//	data.reset(new WinDataPrototype(WheelEnum::TREBLE));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE2, WheelEnum::Yellow));
//	_bigWinDatas.push_back(data);
//
//	data.reset(new WinDataPrototype(WheelEnum::TREBLE));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE2, WheelEnum::Green));
//	_bigWinDatas.push_back(data);
//
//
//
//
//	data.reset(new WinDataPrototype(WheelEnum::TREBLE));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE3, WheelEnum::Red));
//	_bigWinDatas.push_back(data);
//
//
//	data.reset(new WinDataPrototype(WheelEnum::TREBLE));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE3, WheelEnum::Yellow));
//	_bigWinDatas.push_back(data);
//
//	data.reset(new WinDataPrototype(WheelEnum::TREBLE));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::TYPE3, WheelEnum::Green));
//	_bigWinDatas.push_back(data);
//
//	////////////////////////////////
//
//
//	//RED_RABBIT_YELLOW_PANDA,
//	data.reset(new WinDataPrototype(WheelEnum::MANY));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::PANDA, WheelEnum::Red));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::PANDA, WheelEnum::Yellow));
//	_bigWinDatas.push_back(data);
//
//
//	//GREEN_RABBIT_RED_PANDA,
//	data.reset(new WinDataPrototype(WheelEnum::MANY));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::RABBIT, WheelEnum::Green));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::PANDA, WheelEnum::Red));
//	_bigWinDatas.push_back(data);
//
//
//	//YELLOW_MONKEY_GREEN_LION
//	data.reset(new WinDataPrototype(WheelEnum::MANY));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::MONKEY, WheelEnum::Yellow));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::LION, WheelEnum::Green));
//	_bigWinDatas.push_back(data);
//
//
//
//	//YELLOW_RABBIT_GREEN_MONKEY
//	data.reset(new WinDataPrototype(WheelEnum::MANY));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::RABBIT, WheelEnum::Yellow));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::MONKEY, WheelEnum::Green));
//	_bigWinDatas.push_back(data);
//
//
//	//RED_MONKEY_GREEN_PANDA
//	data.reset(new WinDataPrototype(WheelEnum::MANY));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::MONKEY, WheelEnum::Red));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::PANDA, WheelEnum::Green));
//	_bigWinDatas.push_back(data);
//
//
//
//
//	//YELLOW_RABBIT_GREEN_MONKEY_RED_LION
//	data.reset(new WinDataPrototype(WheelEnum::MANY));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::RABBIT, WheelEnum::Yellow));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::MONKEY, WheelEnum::Green));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::LION, WheelEnum::Red));
//	_bigWinDatas.push_back(data);
//
//	//GREEN_RABBIT_RED_RABBIT_GREEN_PANDA
//	data.reset(new WinDataPrototype(WheelEnum::MANY));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::RABBIT, WheelEnum::Green));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::RABBIT, WheelEnum::Red));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::PANDA, WheelEnum::Green));
//	_bigWinDatas.push_back(data);
//
//
//	/////sqwsqwdhjqdkqwdjh
//	//GREEN_RABBIT_RED_RABBIT_GREEN_PANDA
//	data.reset(new WinDataPrototype(WheelEnum::MANY));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::RABBIT, WheelEnum::Green));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::RABBIT, WheelEnum::Red));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::PANDA, WheelEnum::Green));
//	_bigWinDatas.push_back(data);
//
//
//	//RED_MONKEY_YELLOW_RABBIT_YELLOW_PANDA
//	data.reset(new WinDataPrototype(WheelEnum::MANY));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::MONKEY, WheelEnum::Red));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::RABBIT, WheelEnum::Yellow));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::PANDA, WheelEnum::Yellow));
//	_bigWinDatas.push_back(data);
//
//
//	//YELLOW_RABBIT_RED_RABBIT_YELLOW_MANKEY_GREEN_PANDA
//	data.reset(new WinDataPrototype(WheelEnum::MANY));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::RABBIT, WheelEnum::Yellow));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::RABBIT, WheelEnum::Red));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::MONKEY, WheelEnum::Yellow));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::PANDA, WheelEnum::Green));
//	_bigWinDatas.push_back(data);
//
//
//	//GREEN_RABBIT_GREEN_MONKEY_YELLOW_MONKEY_YELLOW_PANDA
//	data.reset(new WinDataPrototype(WheelEnum::MANY));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::RABBIT, WheelEnum::Green));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::MONKEY, WheelEnum::Green));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::MONKEY, WheelEnum::Yellow));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::PANDA, WheelEnum::Yellow));
//	_bigWinDatas.push_back(data);
//
//	////////////////////////
//
//	//YELLOW_MONKEY_YELLOW_RABBIT_GREEN_PANDA_YELLOW_LION
//	data.reset(new WinDataPrototype(WheelEnum::MANY));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::MONKEY, WheelEnum::Yellow));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::RABBIT, WheelEnum::Yellow));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::PANDA, WheelEnum::Green));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::LION, WheelEnum::Yellow));
//	_bigWinDatas.push_back(data);
//
//
//	//RED_RABBIT_YELLOW_MONKEY_RED_MONKEY_YELLOW_PANDA_GREEN_MONKEY
//	data.reset(new WinDataPrototype(WheelEnum::MANY));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::RABBIT, WheelEnum::Red));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::MONKEY, WheelEnum::Yellow));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::MONKEY, WheelEnum::Red));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::PANDA, WheelEnum::Yellow));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::MONKEY, WheelEnum::Green));
//	_bigWinDatas.push_back(data);
//
//
//	//YELLOW_RABBIT_RED_RABBIT_YELLOW_PANDA_GREEN_PANDA_RED_LION
//	data.reset(new WinDataPrototype(WheelEnum::MANY));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::RABBIT, WheelEnum::Yellow));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::RABBIT, WheelEnum::Red));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::PANDA, WheelEnum::Yellow));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::PANDA, WheelEnum::Green));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::LION, WheelEnum::Red));
//	_bigWinDatas.push_back(data);
//
//
//	//GREEN_RABBIT_YELLOW_MONKEY_GREEN_MONKEY_RED_MONKEY_GREEN_PANDA
//	data.reset(new WinDataPrototype(WheelEnum::MANY));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::RABBIT, WheelEnum::Green));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::MONKEY, WheelEnum::Yellow));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::MONKEY, WheelEnum::Green));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::MONKEY, WheelEnum::Red));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::PANDA, WheelEnum::Green));
//	_bigWinDatas.push_back(data);
//
//
//	//YELLOW_RUBBIT_RED_RABBIT_GREEN_MONKEY_YELLOW_PANDA_GREEN_PANDA_YELLOW_LION
//	data.reset(new WinDataPrototype(WheelEnum::MANY));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::RABBIT, WheelEnum::Yellow));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::RABBIT, WheelEnum::Red));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::MONKEY, WheelEnum::Green));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::PANDA, WheelEnum::Yellow));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::PANDA, WheelEnum::Green));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::LION, WheelEnum::Yellow));
//	_bigWinDatas.push_back(data);
//
//
//	//YELLOW_MOKEY_YELLOW_RABBIT_GREEN_MONKEY_GREEN_PANDA_YELLOW_LION_RED_LION
//	data.reset(new WinDataPrototype(WheelEnum::MANY));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::MONKEY, WheelEnum::Yellow));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::RABBIT, WheelEnum::Yellow));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::MONKEY, WheelEnum::Green));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::PANDA, WheelEnum::Green));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::LION, WheelEnum::Yellow));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::LION, WheelEnum::Red));
//	_bigWinDatas.push_back(data);
//
//
//	//GREEN_MONKEY_RED_MONKEY_YELLOW_PANDA_GREEN_PANDA_RED_PANDA_GREEN_LION
//	data.reset(new WinDataPrototype(WheelEnum::MANY));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::MONKEY, WheelEnum::Green));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::MONKEY, WheelEnum::Red));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::PANDA, WheelEnum::Yellow));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::PANDA, WheelEnum::Green));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::PANDA, WheelEnum::Red));
//	data->push_back( WheelEnum::AnimalItem( WheelEnum::LION, WheelEnum::Green));
//	_bigWinDatas.push_back(data);
//
//
//	//data->setWinMode(WheelEnum::NONE);
//	//data->push_back()
//
//	_scoreAnimal.reset(new ScoreAnimal());
//	_scoreWinner.reset(new ScoreWinner());
//	_scoreBouns.reset(new ScoreBouns());
//
//
//
//
//	//	ScoreAnimalPtr _scoreAnimal;
//
//}
