#ifndef __Orz_F5Table_h__
#define __Orz_F5Table_h__
#include "F5TableInterface.h"
#include "F6TableInterface.h"
#include <boost/multi_array.hpp>	
#include "CoinPool.h"
namespace Orz
{
	class F5Table
	{
	public:
		typedef F5TableInterface::ID ID;
		typedef F5TableInterface::ACCOUNTS_ITEM ACCOUNTS_ITEM;
		typedef F5TableInterface::SignalType SignalType;
	private:
	public:
		bool setDataIndex(F6TableInterface::ITEM item, int data);
		int getDataIndex(F6TableInterface::ITEM item) const;
		int getData(F6TableInterface::ITEM item) const;
		void f6Save(void);
		void f6Load(void);
	public:
		
		void setData(ID id, ACCOUNTS_ITEM item, size_t data);
		size_t getData(ID id, ACCOUNTS_ITEM item) const;
		static F5Table & getInstance(void);
		static F5Table * getInstancePtr(void);
		void pushScore(ID id, int score);
		size_t popScore(ID id, int score);
		void pushCoin(ID id, int coin);
		size_t popCoin(ID id, int coin);
		void setCoin2Score(int coin2Score);
		int getCoin2Score(void) const;
		size_t costScore(ID id, int score);
		void earnScore(ID id, int coin);
		size_t costZXHScore(ID id, int score);
		void earnZXHScore(ID id, int coin);

		
		boost::signals2::connection refreshSigConnection(const SignalType::slot_type &subscriber);
		int getBounsPool(void) const;
		int setBounsPoolOut(int out);
		int getPrizePool(void) const;
		int setPrizePoolOut(int out);
		void pushCoinPool(int total);
		
	private:
		F5Table(void);
		boost::multi_array<size_t, 2> _datas;
		int _coin2Score;
		SignalType _refresh;

		
		Temp::CoinPoolPtr _coinPool;
		Temp::CoinPoolPtr _earningsPool;
		Temp::CoinPoolPtr _rebatePool;
		Temp::CoinPoolPtr _prizePool;
		Temp::CoinPoolPtr _bounsPool;
	
		typedef std::map<F6TableInterface::ITEM, int> F6Map;
		F6Map _f6Data;
	};
}


#endif
