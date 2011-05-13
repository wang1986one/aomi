#include "NetWheelDirectorStableHeaders.h"
#include "F5Table.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/json_parser.hpp>

#include <boost/iostreams/device/file.hpp>
#include <boost/iostreams/device/file_descriptor.hpp>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/filter/zlib.hpp>
#include <boost/iostreams/stream.hpp>
using namespace Orz;



void F5Table::load(void)
{
	std::string filename("F5Table.dll");

	// Create an empty property tree object
	using namespace std;
	using boost::property_tree::ptree;
	using namespace boost::iostreams::zlib;
	using namespace boost::iostreams;


	
	ifstream file(filename.c_str(), ios_base::in| ios_base::binary);
	ptree pt;


	filtering_istream in;
	in.push(zlib_decompressor());
	in.push(file);
		


	// Load the XML file into the property tree. If reading fails
	// (cannot open file, parse error), an exception is thrown.
	try
	{
		read_json(in, pt);
		for(int i = 0; i<F5TableInterface::_end; i++ )
		{
			for(int j = 0; j<F5TableInterface::END; j++ )
			{
				_datas[i][j] =  pt.get<int>(boost::lexical_cast<std::string>(i) + "_" + boost::lexical_cast<std::string>(j), 0);

			}
		}
		
		_clear = pt.get("clear" , false);


	}
	catch(...)
	{
		save();
	}
}

void F5Table::save(void)
{
	// Create an empty property tree object
	using boost::property_tree::ptree;
	using namespace boost::iostreams::zlib;
	using namespace boost::iostreams;
	using namespace std;


	ptree pt;


	for(int i = 0; i<F5TableInterface::_end; i++ )
	{
		for(int j = 0; j<F5TableInterface::END; j++ )
		{
			pt.put(boost::lexical_cast<std::string>(i) + "_" + boost::lexical_cast<std::string>(j) , _datas[i][j]);
		}
	}

	pt.put("clear" , bool(_clear));

	std::string filename("F5Table.dll");



	ofstream file(filename.c_str(), ios_base::out| ios_base::binary);
	using boost::property_tree::ptree;
	using namespace boost::iostreams::zlib;
	using namespace boost::iostreams;


	filtering_ostream out;
	out.push(zlib_compressor());
	out.push(file);


	write_json(out, pt);
}

void F5Table::clear(void)
{
	
	_clear = true;
	save();
}

bool F5Table::isClear(void) const
{
	return _clear;
}
void F5Table::updateClear(void)
{
	if(_clear)
	{
		for(int i = 0; i<F5TableInterface::_end; i++ )
		{
			for(int j = 0; j<F5TableInterface::END; j++ )
			{
				if(j != F5TableInterface::TMS)
					_datas[i][j] =  0;

			}
		}
		_clear = false;
		save();
	}
}
F5Table & F5Table::getInstance(void)
{
	return *(getInstancePtr());
}

size_t F5Table::getData(ID id, ACCOUNTS_ITEM item) const
{
	return _datas[id][item];
}


F5Table::F5Table(void):_datas(boost::extents[F5TableInterface::_end][F5TableInterface::END]), _clear(false)
{
	load();
	updateClear();

}
void F5Table::setData(ID id, ACCOUNTS_ITEM item, size_t data)
{
	_datas[id][item] = data;
	
	int all = 0;
	for(int i = 0; i< F5TableInterface::_all; ++i)
	{
		all += _datas[i][item];
	}
	
	_datas[F5TableInterface::_all][item] = all;
	_refresh();
	//_refresh(id, item);
}
F5Table * F5Table::getInstancePtr(void)
{
	static F5Table instance;
	return &instance;
}

boost::signals2::connection  F5Table::refreshSigConnection(const SignalType::slot_type &subscriber)
{
	return _refresh.connect(subscriber);
}