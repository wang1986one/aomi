#include "NetWheelDirectorStableHeaders.h"

#include "CoinPool.h"
using namespace Orz;
using namespace Temp;

const int Temp::CoinPool::AllOther = -1;

CoinPool::CoinPool(int quantitative):_quantitative(quantitative),_allOther(quantitative),_remaining(quantitative),_total(0)
{
	
}
bool CoinPool::link(CoinPoolPtr pool,const int & part)
{

	if(&part == &AllOther)
	{
		if(_allOther == 0)
			return false;
		_list.push_back(boost::tuple<CoinPoolPtr, int, int>(pool, _allOther, _allOther));
		_allOther = 0;
		return true;
	}else
	{
		if(part > _allOther)
			return false;
		_list.push_back(boost::tuple<CoinPoolPtr, int, int>(pool, part, part));
		_allOther -= part;
		return true;
	}
}


void CoinPool::push(void)
{


	_total++;

	int witch = rand()%_remaining;
	witch ++;
	for(size_t i = 0 ; i<_list.size() ; i ++)
	{
		if(witch > _list.at(i).get<2>())
		{
			witch -=  _list.at(i).get<2>();
		}
		else
		{
			_list.at(i).get<0>()->push();
			--_list.at(i).get<2>();
			_total--;
			break;
		}
	}

	_remaining--;
	if(_remaining == 0)
	{
		reset();
	}
}
size_t CoinPool::total(void)
{
	return _total;
}
bool CoinPool::out(size_t n)
{
	if(n<= _total)
	{
		_total -= n;
		return true;
	}
	return false;
}
void CoinPool::reset(void)
{
	for(size_t i = 0 ; i<_list.size() ; i ++)
	{
		_list.at(i).get<2>() = _list.at(i).get<1>(); 
	}
	_remaining = _quantitative;
}