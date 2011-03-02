#include "CodingComponentStableHeaders.h"

#include "CodingFormatComponent.h"
#include "CodingFormatInterface.h"
#include "CodingInterface.h"
using namespace Orz;



CodingFormatComponent::~CodingFormatComponent(void)
{

}

ComponentInterface * CodingFormatComponent::_queryInterface(const TypeInfo & info)
{
	return _query.queryInterface(info);
}


bool  CodingFormatComponent::set(int begin, int end, unsigned int data, int scale)
{
	CodingInterface * coding =_codingComp->queryInterface<CodingInterface>();
	//int ten = 0;

	//if(scale<2)
	//	scale = 2;

	if(scale > 1)
	{
		end--;
		int bits= end - begin;//就范围
		assert(bits>0);//范围一定大于零
		unsigned int  range = 1<<bits;
		assert(range>0);
		bool ret = true;

		while(data > range * scale)
		{
			data -= range * scale;
			ret = false;
		}
		if(data >= range)
		{
			unsigned int multiple = data/scale;
			coding->push(begin, end, multiple);
			coding->push(end, end +1 , 1);
		}else
		{
			coding->push(begin, end, data);
			coding->push(end, end +1 , 0);
		}

		return ret;

	}
	else
	{

		int bits= end - begin;
		assert(bits>0);
		int range = 1<<bits;
		assert(range>0);
		
		bool ret = true;
		while(data>range)
		{
			data -= range;
			ret = false;
		}

		coding->push(begin, end, data);
		

		return ret;
	}
	//if(data> 4095)
	//{
	//	data /= 10;
	//	ten = 1;
	//	if(data >4095)
	//		return false;
	//}
	//int offset = id * 13;
	//coding->push(offset, offset+12, data);
	//coding->push(offset+12, offset+13, ten);
	//return true;
}

unsigned int CodingFormatComponent::get(int begin, int end, int scale)
{

	CodingInterface * coding =_codingComp->queryInterface<CodingInterface>();
	//int ten = 0;


	if(scale > 1)
	{

		end--;

		int bits= end - begin;//就范围
		assert(bits>0);//范围一定大于零
		unsigned int  range = 1<<bits;
		unsigned int data = coding->pop(begin, end);
		int ten = coding->pop(end, end +1);
		if(ten == 1)
			data = data * scale ;
		return data;

	}
	else
	{
		unsigned int data = coding->pop(begin, end);

		return data;
	}



}/*

bool CodingFormatComponent::set10(unsigned int data)
{
	CodingInterface * coding =_codingComp->queryInterface<CodingInterface>();

	coding->push(8, 52, data);

	return true;
}
bool CodingFormatComponent::set1check8(unsigned int data)
{

	CodingInterface * coding =_codingComp->queryInterface<CodingInterface>();
	coding->push(0, 8, data);
	return true;
}
unsigned int CodingFormatComponent::get10(void)
{
	CodingInterface * coding = _codingComp->queryInterface<CodingInterface>();
	unsigned int data = coding->pop(8, 52);
	return data;
}
unsigned int CodingFormatComponent::get1check8(void)
{

	CodingInterface * coding = _codingComp->queryInterface<CodingInterface>();
	unsigned int data = coding->pop(0, 8);
	return data;
}*/

unsigned int CodingFormatComponent::getCheck8(size_t size)
{

	CodingInterface * coding = _codingComp->queryInterface<CodingInterface>();
	unsigned int data = coding->pop(size-8, size);
	return data;
}



bool CodingFormatComponent::decode(const std::string & code, size_t size)
{


	CodingInterface * coding =_codingComp->queryInterface<CodingInterface>();
	std::string str;
	int i = code.at(0) - '0';
	for(int i = 1; i<code.size(); ++i)
	{	
		str.push_back(code.at(i));
	}
	
	std::stringstream ss(str);
	coding->read10(ss);
	
	//coding->print();
	if(_formatInterface->_key)
		coding->decode(_formatInterface->_key(i), size);
	else
		coding->decode(15000159790, size);

	unsigned char check = coding->getCheck8(size - 8);

	//coding->write(std::cout);
	unsigned char check2 = coding->pop(size -8, size);
	if(unsigned int(check) ==unsigned int(unsigned char(check2)))
	{
		return true;
	}

	coding->clear();
	return false;
}

std::string CodingFormatComponent::encode(size_t size, size_t length)
{

	CodingInterface * coding =_codingComp->queryInterface<CodingInterface>();
	unsigned char check = coding->getCheck8(size - 8);
	srand(time(NULL));
	int i = rand()%10;
	coding->push(size - 8, size, unsigned char(check));

	
	if(_formatInterface->_key)
		coding->encode(_formatInterface->_key(i), size);//coding->decode(, size);
	else
		coding->encode(15000159790, size);//coding->decode(, size);
	
	std::stringstream ss;
	
	coding->write10(ss);
	std::string ret;
	ret.push_back(i + '0');
	ret += ss.str();
	while(ret.size()<length)
		ret.push_back('X');
	return ret;
}
CodingFormatComponent::CodingFormatComponent(void):_formatInterface(new CodingFormatInterface())
{

	
	_codingComp =  Orz::ComponentFactories::getInstance().create("Coding");



	_formatInterface->setPass = boost::bind(&CodingFormatComponent::set, this, 0, 10, _1, 24);
	_formatInterface->getPass = boost::bind(&CodingFormatComponent::get, this, 0, 10, 24);

	_formatInterface->setID = boost::bind(&CodingFormatComponent::set, this, 10, 18, _1, 1);
	_formatInterface->getID = boost::bind(&CodingFormatComponent::get, this, 10, 18, 1);

	
	_formatInterface->setTimes = boost::bind(&CodingFormatComponent::set, this, 18, 26, _1, 1);
	_formatInterface->getTimes = boost::bind(&CodingFormatComponent::get, this, 18, 26, 1);

	_formatInterface->setEarn = boost::bind(&CodingFormatComponent::set, this, 26, 39, _1, 10);
	_formatInterface->getEarn = boost::bind(&CodingFormatComponent::get, this, 26, 39, 10);

	_formatInterface->setCost = boost::bind(&CodingFormatComponent::set, this, 39, 52, _1, 1000);
	_formatInterface->getCost = boost::bind(&CodingFormatComponent::get, this, 39, 52,  1000);



	
	_formatInterface->setLockPass = boost::bind(&CodingFormatComponent::set, this, 0, 10, _1, 24);
	_formatInterface->getLockPass = boost::bind(&CodingFormatComponent::get, this, 0, 10, 24);

	_formatInterface->setLockID = boost::bind(&CodingFormatComponent::set, this, 10, 18, _1, 1);
	_formatInterface->getLockID = boost::bind(&CodingFormatComponent::get, this, 10, 18, 1);

	
	_formatInterface->setLockTimes = boost::bind(&CodingFormatComponent::set, this, 18, 26, _1, 1);
	_formatInterface->getLockTimes = boost::bind(&CodingFormatComponent::get, this, 18, 26, 1);


	_formatInterface->setLockLeavings = boost::bind(&CodingFormatComponent::set, this, 26, 52, _1, 1);
	_formatInterface->getLockLeavings = boost::bind(&CodingFormatComponent::get, this, 26, 52, 1);

	

	
	
	_formatInterface->setBackLeavingsIndex = boost::bind(&CodingFormatComponent::set, this, 0, 4, _1, 1);
	_formatInterface->getBackLeavingsIndex = boost::bind(&CodingFormatComponent::get, this, 0, 4, 1);

	_formatInterface->setBackID = boost::bind(&CodingFormatComponent::set, this, 5, 12, _1, 1);
	_formatInterface->getBackID = boost::bind(&CodingFormatComponent::get, this, 5, 12, 1);

	
	_formatInterface->setBackCheck = boost::bind(&CodingFormatComponent::set, this, 12, 20, _1, 1);
	_formatInterface->getBackCheck = boost::bind(&CodingFormatComponent::get, this, 12, 20, 1);






	_formatInterface->getCheck8 = boost::bind(&CodingFormatComponent::getCheck8, this, _1);


	//_formatInterface->encode = boost::bind(&CodingFormatComponent::encode, this,_1, _2,false);
	//_formatInterface->decode = boost::bind(&CodingFormatComponent::decode, this, _1,_2, _3,false);

	_formatInterface->encode10 = boost::bind(&CodingFormatComponent::encode, this,_1, _2);
	_formatInterface->decode10 = boost::bind(&CodingFormatComponent::decode, this, _1,_2);




	//_formatInterface->get10 = boost::bind(&CodingFormatComponent::get10, this);
	//_formatInterface->get1check8 = boost::bind(&CodingFormatComponent::get1check8, this);

	//_formatInterface->set10 = boost::bind(&CodingFormatComponent::set10, this, _1);
	//_formatInterface->set1check8 = boost::bind(&CodingFormatComponent::set1check8, this, _1);


	CodingInterface * coding =_codingComp->queryInterface<CodingInterface>();
	_formatInterface->clear = coding->clear;

	_query.add(_formatInterface.get());
	_query.add(_codingComp.get());
}

