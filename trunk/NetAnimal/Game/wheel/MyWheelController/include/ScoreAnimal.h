#ifndef __Orz_ScoreAnimal_h__
#define __Orz_ScoreAnimal_h__	


#include "WheelControllerConfig.h"
#include "WheelEngineInterface.h"
#include "WheelEnum.h"
#include "WinDataPrototype.h"
#include <boost/random.hpp>
#include <boost/multi_array.hpp>
namespace Orz
{

	//class ScoreAnimal;
	//typedef boost::shared_ptr<ScoreAnimal> ScoreAnimalPtr;
	//class _OrzMyWheelControlleExport ScoreAnimal
	//{
	//public:
	//	class Animal
	//	{
	//		friend class ScoreAnimal;
	//	public:
	//		inline Animal(void):_set(boost::extents[4][3])
	//		{
	//			reset();
	//		}
	//		inline void set(const WheelEnum::AnimalItem & animal, int i)
	//		{
	//			_set[animal.first][animal.second] = i;
	//		}
	//		inline void reset(void)//清零
	//		{
	//			for(int i=0; i<4; ++i)
	//			{
	//				for(int j=0; j<3; ++j)
	//				{
	//					_set[i][j] = 0 ;
	//				}

	//			}
	//		}

	//		inline void push(const WheelEnum::AnimalItem & animal)
	//		{
	//			_set[animal.first][animal.second] = _set[animal.first][animal.second] + 1;
	//		}
	//		inline int get(const WheelEnum::AnimalItem & animal) const 
	//		{
	//			return _set[animal.first][animal.second];
	//		}
	//		inline void sum(const ScoreAnimal::Animal & animal)
	//		{
	//			for(int i=0; i<4; ++i)
	//			{
	//				for(int j=0; j<3; ++j)
	//				{
	//					_set[i][j] += animal._set[i][j] ;
	//				}

	//			}
	//		}


	//		int getTotal(void) const
	//		{
	//			int all = 0;

	//			for(int i=0; i<4; ++i)
	//			{
	//				for(int j=0; j<3; ++j)
	//				{
	//					all += _set[i][j];
	//				}

	//			}
	//			return all;
	//		}
	//		boost::multi_array<int, 2> _set;
	//	};
	//public:


	//	//计算所有动物的反奖
	//	int calculate(const ScoreAnimal::Animal & animal, WinDataPrototype * winData, const WheelEnum::RATE mode) const
	//	{
	//		int all = 0;

	//		for(int i=0; i<4; ++i)
	//		{
	//			for(int j=0; j<3; ++j)
	//			{
	//				WheelEnum::AnimalItem ai = std::make_pair(WheelEnum::TYPE(i),WheelEnum::LIGHT_COLOR(j));
	//				int n = winData->calculate(ai, mode);
	//				all += n * animal.get(ai);
	//			}

	//		}


	//	/*	for(size_t i=0; i<  12; ++i )
	//		{

	//			WheelEnum::AnimalItem ai = Animal::getAnimal(i);
	//			int n = winData->calculate(ai, mode);
	//			all += n * animal.get(ai);

	//		}*/
	//		return all;


	//	}


	//	//	_winner = scoreAnimal->getWinner(scm ,_prizePool.get(), _winDatas, _bigWinDatas);
	//	std::pair<int, WinDataPrototypePtr> getWinner(
	//		const Animal & animal, 
	//		const std::vector<WinDataPrototypePtr> & nomal, 
	//		const std::vector<WinDataPrototypePtr> & big, int prize, bool mustNomal) 
	//	{


	//		BOOST_FOREACH(WinDataPrototypePtr data, nomal)
	//		{



	//			int get = calculate(animal, data.get(), Orz::WinData::getInstance().getRate());//->calculate();
	//			if(get > animal.getTotal())
	//			{
	//				if(get <= prize)
	//					_win.push_back(std::make_pair(get, data));
	//			}else
	//			{
	//				_lost.push_back(std::make_pair(get, data));
	//			}
	//		}

	//		if(!mustNomal)
	//		{
	//			BOOST_FOREACH(WinDataPrototypePtr data, big)
	//			{
	//				int get = calculate(animal, data.get(), Orz::WinData::getInstance().getRate());//->calculate();
	//				if(get > animal.getTotal())
	//				{
	//					if(get <= prize)
	//						_bigWin.push_back(std::make_pair(get, data));
	//				}else
	//				{
	//					_bigLost.push_back(std::make_pair(get, data));
	//				}
	//			}
	//		}

	//		//std::pair<int, WinDataPrototypePtr>  winner = getWin();
	//		return getWin(probability(prize));
	//		/*_winner = winner.second;
	//		_winner->submit( Orz::WinData::getInstance().getRate());
	//		_prizePool->out(winner.first);*/

	//	}

	//	float probability(int i)
	//	{
	//		float n = 0;
	//		if(i > 500)
	//			n = 1.f;
	//		else 
	//			n = i/500.f;

	//		return 1.f - (1.f-n)*(1.f-n);

	//	}


	//
	//	bool isWin(float rate)//是否是赢钱（几率）
	//	{
	//		boost::mt19937 engine(time(NULL));
	//		using namespace boost;
	//		boost::uniform_real<> distribution(0,1);
	//		variate_generator<mt19937, uniform_real<> > myrandom (engine, distribution);
	//		return myrandom() <rate;
	//	}

	//	bool isBig()//是否是大奖
	//	{

	//		boost::mt19937 engine(time(NULL));
	//		using namespace boost;
	//		float n = 0.1f;
	//		boost::uniform_real<> distribution(0,1);
	//		//boost::mt19937 engine(time(NULL));
	//		variate_generator<mt19937, uniform_real<> > myrandom (engine, distribution);
	//		return myrandom() <n;
	//	}


	//	std::pair<int, WinDataPrototypePtr> getWin(float rate)
	//	{

	//		boost::mt19937 engine(time(NULL));

	//		using namespace boost;

	//		bool big = isBig();
	//		bool win = isWin(rate);
	//		if(win)
	//		{
	//			if(big && !_bigWin.empty())
	//			{
	//				boost::uniform_int<> distribution(0, _bigWin.size() -1);
	//				variate_generator<mt19937, uniform_int<> > myrandom (engine, distribution);
	//				return _bigWin.at(myrandom());
	//			}else if(!_win.empty())
	//			{
	//				boost::uniform_int<> distribution(0, _win.size() -1);
	//				variate_generator<mt19937, uniform_int<> > myrandom (engine, distribution);
	//				return _win.at(myrandom());
	//			}
	//		}else 
	//		{

	//			if(big && !_bigLost.empty())
	//			{
	//				boost::uniform_int<> distribution(0, _bigLost.size() -1);
	//				variate_generator<mt19937, uniform_int<> > myrandom (engine, distribution);
	//				return _bigLost.at(myrandom());
	//			}else if(!_lost.empty())
	//			{
	//				boost::uniform_int<> distribution(0, _lost.size() -1);
	//				variate_generator<mt19937, uniform_int<> > myrandom (engine, distribution);
	//				return _lost.at(myrandom());
	//			}
	//		}


	//		boost::uniform_int<> distribution(0, _lost.size() -1);
	//		variate_generator<mt19937, uniform_int<> > myrandom (engine, distribution);
	//		int r = myrandom();

	//		return _lost.at(r);


	//		//NULL;
	//	}

	//	void reset(void)
	//	{
	//		_win.clear();
	//		_lost.clear();
	//		_bigWin.clear();
	//		_bigLost.clear();
	//	}
	//private:

	//	std::vector<std::pair<int, WinDataPrototypePtr> > _win;
	//	std::vector<std::pair<int, WinDataPrototypePtr> > _lost;
	//	std::vector<std::pair<int, WinDataPrototypePtr> > _bigWin;
	//	std::vector<std::pair<int, WinDataPrototypePtr> > _bigLost;
	//	//	ScoreWinner(void);
	//	//	~ScoreWinner(void);
	//	//	WheelEnum::WINNER getWinner(const Winner & w, int prize, boost::mt19937 & engine) const;
	//	////	int calculate(WheelEnum::WINNER winner, int n = 1) const;
	//	//	int getOverride(WheelEnum::WINNER winner) const;
	//	//	int getOdds(WheelEnum::WINNER winner) const;
	//	//	WheelEnum::WINNER  getOddsWinner(boost::mt19937 & engine) const;
	//	//private:

	//};


}

#endif

