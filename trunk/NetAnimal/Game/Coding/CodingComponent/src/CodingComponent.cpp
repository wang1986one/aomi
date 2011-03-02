#include "CodingComponentStableHeaders.h"
#include "CodingComponent.h"
#include "CodingInterface.h"
#include "md5.h"
using namespace Orz;



CodingComponent::~CodingComponent(void)
{

}


void CodingComponent::clear(void)
{
	_set.clear();
}

const CodingComponent::CodingSet & CodingComponent::push(unsigned int begin, unsigned int end, unsigned long num)
{

	if(_set.size()< end)
	{
		_set.resize(end);
	}

	for(int i = begin; i< end; i++)
	{
		_set[i] = num&0x1;
		num >>= 1;
	}
	return _set;
}
unsigned long CodingComponent::pop(unsigned int begin, unsigned int end)
{

	if(_set.size()< end)
	{
		_set.resize(end);
	}


	unsigned long num = 0;

	for(int i = begin; i< end; i++)
	{

		num |= _set[i]<<(i-begin);
	}
	return num;
}
CodingComponent::CodingComponent(void):_codingInterface(new CodingInterface())
{
	_codingInterface->push = boost::bind(&CodingComponent::push, this, _1, _2, _3);
	_codingInterface->pop = boost::bind(&CodingComponent::pop, this, _1, _2);
	_codingInterface->clear = boost::bind(&CodingComponent::clear, this);
	_codingInterface->print = boost::bind(&CodingComponent::print, this);

	_codingInterface->write = boost::bind(&CodingComponent::write, this, _1);
	_codingInterface->write10 = boost::bind(&CodingComponent::write10, this, _1);
	_codingInterface->read10 = boost::bind(&CodingComponent::read10, this, _1);
	_codingInterface->read = boost::bind(&CodingComponent::read, this, _1);
	_codingInterface->getCheck16 = boost::bind(&CodingComponent::getCheck16, this, _1);
	_codingInterface->getCheck8 = boost::bind(&CodingComponent::getCheck8, this, _1);
	_codingInterface->encode = boost::bind(&CodingComponent::encode, this, _1, _2);
	_codingInterface->decode = boost::bind(&CodingComponent::decode, this, _1, _2);
	_query.add(_codingInterface.get());
}


unsigned short CodingComponent::getCheck16(unsigned int n)
{
	float step = float(n)/ 16.f;
	unsigned short check = 0;
	float lenght  = 0;
	int i = 0;
	for(i = 0,lenght = 0; lenght < 16; lenght+= step, ++i)
	{

		int f = int(lenght);
		int bit = 0;
		if(n<_set.size())
		{
			bit = _set[f];
		}
		check |= (bit)<<i;
	}
	return check;

}



unsigned char CodingComponent::getCheck8(unsigned int n)
{

	unsigned char check = 0;
	//for(int i = 0; i< n && i<_set.size();  ++i)
	//{
	//	check+= _set[i];
	//}
	md5_state_t hash_state;


    md5_init(&hash_state);                     // prepare for a new hash    
	unsigned char hash[16];

	if(_set.size() < n)
		_set.resize(n);
	for(int i = 0; i< n ;  ++i)
	{
		const char string_a[] = "a";
		const char string_b[] = "b";
		if(_set[i])
		{
			md5_append(&hash_state, (const unsigned char *)string_a, 1);    
		}else
		{
			md5_append(&hash_state, (const unsigned char *)string_b, 1);
		}
	}


	md5_finish(&hash_state, hash);             // calculate hash value

	for(int i = 0; i<16; i++)
	{
		check += hash[i];
		//std::cout<<int(hash[i])<<std::endl;

	}

	//for(int i = 0; i< n && i<_set.size();  ++i)
	//{
	//	check+= _set[i];
	//}
	return check;

}



void CodingComponent::encode(unsigned int key, size_t size)
{
	if(key == 0)
	{
		srand(time(NULL));
		key = rand();
	}
	using namespace std;
	
	if(_set.size()< size)
	{
		_set.resize(size);
	}
	size_t halfSize = size/2;

	for(int i = 0; i< halfSize; ++i)
	{
		if((key>>i)&0x1)
		{

			int bit  = _set[i];
			_set[i]= _set[size-i-1];
			_set[size-i-1] = bit;
		}
	}
}


void CodingComponent::decode(unsigned int key, size_t size)
{
	if(key == 0)
	{
		srand(time(NULL));
		key = rand();
	}
	using namespace std;
	size_t halfSize = size/2;

	if(_set.size()< size)
	{
		_set.resize(size);
	}
	for(int i = 0; i< halfSize; ++i)
	{
		if((key>>i)&0x1)
		{

			int bit  = _set[i];
			_set[i]= _set[size-i-1];
			_set[size-i-1] = bit;
		}
	}
}


void CodingComponent::write(std::ostream & os)
{
	typedef std::vector<CodingSet::block_type> List;
	typedef List::iterator Iterator;
	List out;
	boost::to_block_range(_set, std::back_inserter(out));
	//std::cout<<sizeof(CodingSet::block_type)<<"%"<<int(_set.size())<<"!!@!@"<<std::endl;
	//int(_set.size())/(sizeof(CodingSet::block_type) * 8)
	
	int all = int(_set.size())/4;
	if(_set.size()%4)
	{
		all+=1;
	}
	for(size_t i = 0; i<out.size(); ++i)
	{
		if(i == out.size()-1)
		{
			if((all - (i+1)*2) == 0)
				os<<std::setfill('0')<<std::setw(2)<<std::hex<<int(out.at(i));
			else
				os<<int(out.at(i));
		}
		else
		{
			os<<std::setfill('0')<<std::setw(2)<<std::hex<<int(out.at(i));
		}
	}

}


void CodingComponent::write10(std::ostream & os)
{
	uint64 num = 0;
	size_t size = 0;
	if(_set.size() > 64)
		size = 64;
	else
		size = _set.size();
	//print();
	for(int i = size-1; i >= 0; --i )
	{
		
		if(_set[i])
			num = (num<<1) | 0x1;
		else
			num = (num<<1);
	}
	
	while(num!=0)
	{
		
		os<<int(num%10);
		num/=10;
	}
//
}



void CodingComponent::read10(std::istream & is)
{
	_set.clear();
	CodingSet::block_type block = 0;
	char chr = 0;

	uint64 n = 0;
	uint64 num = 0;
	uint64 i = 1;
	while(is.read(&chr, 1))
	{
		if(chr>='0' && chr<='9')
		{
			n = chr - '0';
			num += n * i;
			i = i * 10;
		}
	}
	
	while(num !=0)
	{
		_set.push_back(num & 0x1);
		num= num>>1;
	}


}
void CodingComponent::read(std::istream & is)
{

	
	_set.clear();
	CodingSet::block_type block = 0;
	char chr = 0;

	int o = 0;
	unsigned char c = 0;
	unsigned char n = 0;
	while(is.read(&chr, 1))
	{
		if(chr >= 'A' && chr <= 'Z')
		{
			n = chr - 'A' + 10;
		}else if(chr >= 'a' && chr <= 'z')
		{
			n = chr - 'a' + 10;
		}else  if(chr >= '0' && chr <= '9')
		{
			n = chr - '0';
		}
		//std::cout<<chr<<":"<<int(n)<<std::endl;

		o++;
		if(o%2==1)
		{
			c |= 0xF0 & (n<<4);
		
		}else
		{
			c |= 0x0F & n;
			_set.append(c);
			c = 0;
		}
	}
	if(o%2==1)
	{
		for(int i = 0; i< 4; ++i)
		{
			_set.push_back((n>>i) & 0x1);
		}
	}
}

ComponentInterface * CodingComponent::_queryInterface(const TypeInfo & info)
{

	return _query.queryInterface(info);
}
void CodingComponent::print(void)
{
	std::cout<<_set<<std::endl;
}