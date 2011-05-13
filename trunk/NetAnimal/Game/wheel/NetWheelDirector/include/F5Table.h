#ifndef __Orz_F5Table_h__
#define __Orz_F5Table_h__
#include "F5TableInterface.h"
//#include "F6TableInterface.h"
#include <boost/multi_array.hpp>	
//#include "CoinPool.h"
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
		
		void clear(void);
		bool isClear(void) const;
		void updateClear(void);
		void save(void);
		void load(void);
	public:
		
		void setData(ID id, ACCOUNTS_ITEM item, size_t data);
		size_t getData(ID id, ACCOUNTS_ITEM item) const;
		static F5Table & getInstance(void);
		static F5Table * getInstancePtr(void);
		
		
		boost::signals2::connection refreshSigConnection(const SignalType::slot_type &subscriber);
		
	private:
		F5Table(void);
		boost::multi_array<size_t, 2> _datas;
		bool _clear;
		SignalType _refresh;
	};
}


#endif
