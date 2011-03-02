#include "MyWheelDirectorStableHeaders.h"
#include "F5Table.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

using namespace Orz;

std::string Item2String(F6TableInterface::ITEM item)
{
	switch(item)
	{
	case F6TableInterface::PoTaiFenShu:
		return "Data.PoTaiFenShu";
		////////////////////////
	case F6TableInterface::DongWuZuiDaYaZhu:
		return "Data.DongWuZuiDaYaZhu";
	
		//////////////////
	case F6TableInterface::DongWuZuiXiaoYaZhu:
		return "Data.DongWuZuiXiaoYaZhu";
	
		/////////
	case F6TableInterface::DaoShuShiJian:
		return "Data.DaoShuShiJian";
/////////

	case F6TableInterface::TuiBiGongNeng:
		return "Data.TuiBiGongNeng";

		
/////////

	case F6TableInterface::KaiFenDanWei:
		return "Data.KaiFenDanWei";
		/////////

	case F6TableInterface::KaiFenShangXian:
		return "Data.KaiFenShangXian";
		/////////

	case F6TableInterface::ZhuangXianZuiDaYaZhu:
		return "Data.ZhuangXianZuiDaYaZhu";
	case F6TableInterface::HeZuiDaYaZhu:
		return "Data.HeZuiDaYaZhu";

	}
	return "";
}


int GetData(F6TableInterface::ITEM item, int index)
{
	switch(item)
	{
	case F6TableInterface::PoTaiFenShu:
		switch(index)
		{
		case 1:
			return 10000;
		case 2:
			return 20000;
		case 3:
			return 30000;
		case 4:
			return 50000;
		case 5:
			return 100000;
		case 6:
			return 200000;
		case 7:
			return 500000;
		}
		break;
		////////////////////////
	case F6TableInterface::DongWuZuiDaYaZhu:
		switch(index)
		{
		case 1:
			return 50;
		case 2:
			return 99;
		case 3:
			return 250;
		case 4:
			return 999;
		}
		break;
		//////////////////
	case F6TableInterface::DongWuZuiXiaoYaZhu:
		switch(index)
		{
		case 1:
			return 1;
		case 2:
			return 5;
		case 3:
			return 10;
		case 4:
			return 20;
		}
		break;

		/////////
	case F6TableInterface::DaoShuShiJian:
		switch(index)
		{
		case 1:
			return 10;
		case 2:
			return 15;
		case 3:
			return 20;
		case 4:
			return 25;
		case 5:
			return 30;
		case 6:
			return 35;
		}
		break;
/////////

	case F6TableInterface::TuiBiGongNeng:
		switch(index)
		{
		case 0:
			return F6TableInterface::BackNone;
		case 1:
			return F6TableInterface::BackAll;
		case 2:
			return F6TableInterface::Back5;
		case 3:
			return F6TableInterface::BackPush;
		}
		break;

		
/////////

	case F6TableInterface::KaiFenDanWei:
		switch(index)
		{
		case 0:
			return 0;
		case 1:
			return 100;
		case 2:
			return 200;
		case 3:
			return 400;
		case 4:
			return 500;
		case 5:
			return 1000;
		case 6:
			return 2000;
		case 7:
			return 4000;
		case 8:
			return 5000;
		case 9:
			return 10000;
		}
		break;
		
		/////////

	case F6TableInterface::KaiFenShangXian:
		switch(index)
		{
		case 1:
			return 5000;
		case 2:
			return 10000;
		case 3:
			return 20000;
		case 4:
			return 50000;
		case 5:
			return 100000;
		}
		break;	
		
		/////////

	case F6TableInterface::ZhuangXianZuiDaYaZhu:
		switch(index)
		{
		case 1:
			return 100;
		case 2:
			return 500;
		case 3:
			return 1000;
		case 4:
			return 2000;
		case 5:
			return 3000;
		case 6:
			return 5000;
		case 7:
			return 6000;
		case 8:
			return 8000;
		case 9:
			return 9999;
		}
		break;

	case F6TableInterface::HeZuiDaYaZhu:
		switch(index)
		{
		case 1:
			return 10;
		case 2:
			return 50;
		case 3:
			return 100;
		case 4:
			return 300;
		case 5:
			return 500;
		case 6:
			return 1000;
		case 7:
			return 2000;
		}
		break;
		

	}
	return -1;
}


void F5Table::f6Save(void)
{
	 // Create an empty property tree object
   using boost::property_tree::ptree;
   ptree pt;

   BOOST_FOREACH(F6Map::value_type it, _f6Data)
   {
	   pt.put( Item2String(it.first), it.second);
   }
 
   write_xml("f6table.xml", pt);

}
void F5Table::f6Load(void)
{
	
    using boost::property_tree::ptree;
    ptree pt;

    // Load the XML file into the property tree. If reading fails
    // (cannot open file, parse error), an exception is thrown.
	try
	{
		read_xml("f6table.xml", pt);
		_f6Data[F6TableInterface::PoTaiFenShu] = pt.get<int>(Item2String(F6TableInterface::PoTaiFenShu), 1);
		_f6Data[F6TableInterface::DongWuZuiDaYaZhu] = pt.get<int>(Item2String(F6TableInterface::DongWuZuiDaYaZhu), 1);
		_f6Data[F6TableInterface::DongWuZuiXiaoYaZhu] = pt.get<int>(Item2String(F6TableInterface::DongWuZuiXiaoYaZhu), 1);
		_f6Data[F6TableInterface::DaoShuShiJian] = pt.get<int>(Item2String(F6TableInterface::DaoShuShiJian), 1);
		_f6Data[F6TableInterface::TuiBiGongNeng] = pt.get<int>(Item2String(F6TableInterface::TuiBiGongNeng), 1);
		_f6Data[F6TableInterface::KaiFenDanWei] = pt.get<int>(Item2String(F6TableInterface::KaiFenDanWei), 1);
		_f6Data[F6TableInterface::KaiFenShangXian] = pt.get<int>(Item2String(F6TableInterface::KaiFenShangXian), 1);
		_f6Data[F6TableInterface::ZhuangXianZuiDaYaZhu] = pt.get<int>(Item2String(F6TableInterface::ZhuangXianZuiDaYaZhu), 1);
		_f6Data[F6TableInterface::HeZuiDaYaZhu] = pt.get<int>(Item2String(F6TableInterface::HeZuiDaYaZhu), 1);

		

	}
	catch(...)
	{
		
		_f6Data[F6TableInterface::PoTaiFenShu] = 1;
		_f6Data[F6TableInterface::DongWuZuiDaYaZhu] = 1;
		_f6Data[F6TableInterface::DongWuZuiXiaoYaZhu] = 1;
		_f6Data[F6TableInterface::DaoShuShiJian] = 1;
		_f6Data[F6TableInterface::TuiBiGongNeng] = 1;
		_f6Data[F6TableInterface::KaiFenDanWei] = 1;
		_f6Data[F6TableInterface::KaiFenShangXian] = 1;
		_f6Data[F6TableInterface::ZhuangXianZuiDaYaZhu] = 1;
		_f6Data[F6TableInterface::HeZuiDaYaZhu] = 1;
		f6Save();
	}
	//pt
    // Get the filename and store it in the m_file variable.
    // Note that we construct the path to the value by separating
    // the individual keys with dots. If dots appear in the keys,
    // a path type with a different separator can be used.
    // If the debug.filename key is not found, an exception is thrown.
   

}
int F5Table::getData(F6TableInterface::ITEM item) const
{
	return GetData(item, getDataIndex(item));
}
bool F5Table::setDataIndex(F6TableInterface::ITEM item, int data)
{
	if(GetData(item, data) == -1)
		return false;
	_f6Data[item] = data;
	return true;
}
int F5Table::getDataIndex(F6TableInterface::ITEM item) const
{
	F6Map::const_iterator it = _f6Data.find(item);
	if(it == _f6Data.end())
		return -1;

	return it->second;
}

F5Table & F5Table::getInstance(void)
{
	return *(getInstancePtr());
}

void F5Table::pushScore(ID id, int score)
{

	size_t tmScore = getData(id, F5TableInterface::TMS);
	setData(id, F5TableInterface::TMS, score + tmScore);


	size_t oldScore = getData(id, F5TableInterface::ZYF);
	setData(id, F5TableInterface::ZYF, score + oldScore);
}
size_t F5Table::popScore(ID id, int score)
{

	size_t tmScore = getData(id, F5TableInterface::TMS);
	int popScore = 0;
	if(tmScore >= score)
	{
		setData(id, F5TableInterface::TMS, tmScore - score);
		popScore = score;

	}
	else
	{
		setData(id, F5TableInterface::TMS, 0);
		popScore = tmScore;
	}


	size_t oldScore = getData(id, F5TableInterface::ZXF);
	setData(id, F5TableInterface::ZXF, oldScore + popScore);
	return popScore;

}




size_t F5Table::costScore(ID id, int score)
{	
	size_t tmScore = getData(id, F5TableInterface::TMS);
	size_t theScore = 0;
	if(score <= tmScore)
	{
		theScore = score;
	}else
	{
		theScore = tmScore;
	}
	setData(id, F5TableInterface::TMS, tmScore - theScore);

	size_t oldScore = getData(id, F5TableInterface::ZYF);
	setData(id, F5TableInterface::ZYF, oldScore + theScore);
	return theScore;

}
void F5Table::earnScore(ID id, int score)
{	
	size_t tmScore = getData(id, F5TableInterface::TMS);
	setData(id, F5TableInterface::TMS, tmScore + score);

	size_t zzScore = getData(id, F5TableInterface::ZZF);
	setData(id, F5TableInterface::ZZF, zzScore + score);
}



size_t F5Table::costZXHScore(ID id, int score)
{	

	size_t tmScore = getData(id, F5TableInterface::TMS);
	size_t theScore = 0;
	if(score <= tmScore)
	{
		theScore = score;
	}else
	{
		theScore = tmScore;
	}
	setData(id, F5TableInterface::TMS, tmScore - theScore);
	size_t oldScore = getData(id, F5TableInterface::ZXHZYF);
	setData(id, F5TableInterface::ZXHZYF, oldScore + theScore);
	return theScore;

}




boost::signals2::connection  F5Table::refreshSigConnection(const SignalType::slot_type &subscriber)
{
	return _refresh.connect(subscriber);
}


void F5Table::earnZXHScore(ID id, int score)
{	
	size_t tmScore = getData(id, F5TableInterface::TMS);
	setData(id, F5TableInterface::TMS, tmScore + score);

	size_t zzScore = getData(id, F5TableInterface::ZXHZZF);
	setData(id, F5TableInterface::ZXHZZF, zzScore + score);
}





void F5Table::pushCoin(ID id, int coin)
{	

	size_t score = coin * _coin2Score;
	size_t tmScore = getData(id, F5TableInterface::TMS);
	setData(id, F5TableInterface::TMS, score + tmScore);


	size_t oldCoin = getData(id, F5TableInterface::ZTOB);
	setData(id, F5TableInterface::ZTOB, oldCoin + coin);

}

size_t F5Table::popCoin(ID id, int coin)
{
	do
	{
		size_t tmScore = getData(id, F5TableInterface::TMS);
		size_t score = coin * _coin2Score;
		if(score <= tmScore)
		{
			size_t oldCoin = getData(id, F5TableInterface::ZTUB);
			setData(id, F5TableInterface::ZTUB, oldCoin + coin);


			setData(id, F5TableInterface::TMS, tmScore - score);
			break;
		}


	}
	while(coin--);
	return coin;
}

size_t F5Table::getData(ID id, ACCOUNTS_ITEM item) const
{
	return _datas[id][item];
}


F5Table::F5Table(void):_datas(boost::extents[F5TableInterface::_ALL][F5TableInterface::END]),_coin2Score(1)
{

	using namespace Temp;
	_coinPool.reset(new CoinPool(100));
	_earningsPool.reset(new CoinPool(2));
	_rebatePool.reset(new CoinPool(98));
	_prizePool.reset(new CoinPool(49));
	_bounsPool.reset(new CoinPool(49));

	_coinPool->link(_earningsPool, 2);
	_coinPool->link(_rebatePool, CoinPool::AllOther);

	_rebatePool->link(_prizePool, 49);
	_rebatePool->link(_bounsPool, CoinPool::AllOther);
	f6Load();

}
void F5Table::setData(ID id, ACCOUNTS_ITEM item, size_t data)
{
	_datas[id][item] = data;
	_refresh(id, item);
}
F5Table * F5Table::getInstancePtr(void)
{
	static F5Table instance;
	return &instance;
}
void F5Table::setCoin2Score(int coin2Score)
{
	_coin2Score = coin2Score;
}
int F5Table::getCoin2Score(void) const
{
	return _coin2Score;
}


int F5Table::getBounsPool(void) const
{
	return _bounsPool->total();
}

int F5Table::setBounsPoolOut(int out)
{
	int total = _bounsPool->total();
	if(out > total)
	{
		out = total;
	}
	_bounsPool->out(out);
	return out;

}



int F5Table::getPrizePool(void) const
{
	return _prizePool->total();
}

int F5Table::setPrizePoolOut(int out)
{
	int total = _prizePool->total();
	if(out > total)
	{
		out = total;
	}
	_prizePool->out(out);
	return out;

}


void F5Table::pushCoinPool(int total)
{
	for(int i=0; i<total; ++i)
	{
		_coinPool->push();
	}
}

