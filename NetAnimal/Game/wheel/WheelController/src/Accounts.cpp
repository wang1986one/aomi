#include "WheelControllerStableHeaders.h"
#include "Accounts.h"
#include <iostream>

using namespace Orz;

void Accounts::clear(void)
{
	//std::cout<<_info[3][3]<<std::endl;
	std::fill(_total.begin(), _total.end(), -1);
	std::fill(_info[0].begin(), _info[0].end(), 0);
	std::fill(_info[1].begin(), _info[1].end(), 0);
	std::fill(_info[2].begin(), _info[2].end(), 0);
	std::fill(_info[3].begin(), _info[3].end(), 0);
	std::fill(_info[4].begin(), _info[4].end(), 0);
	std::fill(_info[5].begin(), _info[5].end(), 0);
	std::fill(_info[6].begin(), _info[6].end(), 0);
	std::fill(_info[7].begin(), _info[7].end(), 0);
	std::fill(_info[8].begin(), _info[8].end(), 0);
	
}

bool Accounts::push(int id, unsigned long tms/*台面数*/, unsigned long zzf/*总中分*/, unsigned long zyf/*总压分*/, unsigned long zkf/*总开分*/, unsigned long zxf/*总消分*/, unsigned long ztob/*总投币*/, unsigned long ztub/*总退币*/, unsigned zxhzyf/*装先河宗亚芬*/, unsigned zxhzzf/*装先河宗中芬*/)
{
	if(_info[id][FIT] == 1)
		return false;
	
	_info[id][FIT] = 1;
	_info[id][TMS] = tms;
	_info[id][ZZF] = zzf;
	_info[id][ZYF] = zyf;
	_info[id][ZKF] = zkf;
	_info[id][ZXF] = zxf;
	_info[id][ZTOB] = ztob;
	_info[id][ZTUB] = ztub;
	_info[id][ZXHZYF] = zxhzyf;
	_info[id][ZXHZZF] = zxhzzf;	
	return true;
}
bool Accounts::isComplete(void)
{
	for(int i =0; i< 9; ++i)
	{
		if(_info[i][FIT] == 0)
			return false;
	}
	return true;
}
Accounts::Accounts(void):_info(boost::extents[9][END]),_callback(NULL)
{
	clear();
}


int Accounts::get(int i, ACCOUNTS_ITEM item)
{
	return _info[i][item];
}
int Accounts::getTotal(ACCOUNTS_ITEM item)
{
	if(_total[item] == -1)
	{
		_total[item] = 0;
		for(int i =0; i< 8; ++i)
		{
			_total[item]+=_info[i][item];
		}
	}
	return _total[item];
}