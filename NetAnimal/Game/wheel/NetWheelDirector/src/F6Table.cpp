#include "NetWheelDirectorStableHeaders.h"
#include "F6Table.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/json_parser.hpp>

#include <boost/iostreams/device/file.hpp>
#include <boost/iostreams/device/file_descriptor.hpp>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/filter/zlib.hpp>
#include <boost/iostreams/stream.hpp>
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




void F6Table::save(void)
{
	// Create an empty property tree object
	using boost::property_tree::ptree;
	ptree pt;

	BOOST_FOREACH(F6Map::value_type it, _f6Data)
	{
		pt.put( Item2String(it.first), it.second);
	}


	std::string filename("F6Table.dll");

	using boost::property_tree::ptree;
	using namespace boost::iostreams::zlib;
	using namespace boost::iostreams;

	using namespace std;


	ofstream file(filename.c_str(), ios_base::out| ios_base::binary);

	filtering_ostream out;
	out.push(zlib_compressor());
	out.push(file);


	write_json(out, pt);
}



void F6Table::load(void)
{


	std::string filename("F6Table.dll");

	// Create an empty property tree object
	using namespace std;
	using boost::property_tree::ptree;
	using namespace boost::iostreams::zlib;
	using namespace boost::iostreams;


			
	ifstream file(filename.c_str(), ios_base::in| ios_base::binary);


	filtering_istream in;
	in.push(zlib_decompressor());
	in.push(file);
		




	ptree pt;

	// Load the XML file into the property tree. If reading fails
	// (cannot open file, parse error), an exception is thrown.
	try
	{
		read_json(in, pt);
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
		save();
	}


}
int F6Table::getData(F6TableInterface::ITEM item) const
{
	return GetData(item, getDataIndex(item));
}
bool F6Table::setDataIndex(F6TableInterface::ITEM item, int data)
{
	if(GetData(item, data) == -1)
		return false;
	_f6Data[item] = data;
	return true;
}
int F6Table::getDataIndex(F6TableInterface::ITEM item) const
{
	F6Map::const_iterator it = _f6Data.find(item);
	if(it == _f6Data.end())
		return -1;

	return it->second;
}

F6Table & F6Table::getInstance(void)
{
	return *(getInstancePtr());
}


F6Table::F6Table(void)
{

	
	load();

}

F6Table * F6Table::getInstancePtr(void)
{
	static F6Table instance;
	return &instance;
}
