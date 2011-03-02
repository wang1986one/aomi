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
	bool push(int id, unsigned long  tms/*̨����*/, unsigned long  zzf/*���з�*/, unsigned long  zyf/*��ѹ��*/, unsigned long  zkf/*�ܿ���*/, unsigned long  zxf/*������*/, unsigned long  ztob/*��Ͷ��*/, unsigned long  ztub/*���˱�*/, unsigned zxhzyf/*װ�Ⱥ����Ƿ�*/, unsigned zxhzzf/*װ�Ⱥ����з�*/);
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