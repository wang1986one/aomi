#ifndef __Orz_Accounts__
#define __Orz_Accounts__
#include "WheelEngineListener.h"
namespace Orz
{


class Accounts
{
public:


public:
	void clear(void);
	bool push(int id, unsigned long  tms/*台面数*/, unsigned long  zzf/*总中分*/, unsigned long  zyf/*总压分*/, unsigned long  zkf/*总开分*/, unsigned long  zxf/*总消分*/, unsigned long  ztob/*总投币*/, unsigned long  ztub/*总退币*/, unsigned zxhzyf/*装先河宗亚芬*/, unsigned zxhzzf/*装先河宗中芬*/);
	bool isComplete(void);
	Accounts(void);
	int get(int i, ACCOUNTS_ITEM item);
	int getTotal(ACCOUNTS_ITEM item);
	void setCallback(WheelEngineListener * callback)
	{
		_callback = callback;
	}

	void upload(void)
	{
		if(_callback)
		for(int i=0; i<9; ++i)
		{
			for(int j=TMS; j<END; j++)
			{

				_callback->push_data(i, ACCOUNTS_ITEM(j), _info[i][j]);
			}
		}

		for(int j=TMS; j<END; j++)
		{
			_callback->push_total(ACCOUNTS_ITEM(j), getTotal(ACCOUNTS_ITEM(j)));
		}
		
	}
	bool check(void)
	{
		if(!isComplete())
			return false;
		for(int i = TMS; i<END; ++i)
		{
			if(getTotal(ACCOUNTS_ITEM(i)) != _info[8][i])
			{
				return false;
			}
		}
		return true;
	}
private:
	boost::multi_array<unsigned long, 2> _info;
	boost::array<unsigned long, END> _total;
	WheelEngineListener * _callback;
};
}


#endif