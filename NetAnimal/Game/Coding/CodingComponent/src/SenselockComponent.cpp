#include "CodingComponentStableHeaders.h"
#include "SenselockComponent.h"
#include "LockInterface.h"
#include "md5.h"
#include "Senselock.h"
using namespace Orz;
#define OFFSET_HALF 20
#define OFFSET 40
SenselockComponent::~SenselockComponent(void)
{

}


unsigned int  SenselockComponent::key(int seed)
{

	unsigned char test[] = {Senselock::FUN_KEY,seed, 0, 0, 0}; 
	int len = sizeof(test); 
 
	
	if(Senselock::getInstance().call_ele("Code", test, len))
	{
		
		unsigned key = 0;
		
		
		key = * (unsigned int *)(test +1);
		
		return key;
	}
	return 0;
}
bool SenselockComponent::setLockCode(const std::string & code)
{
	if(code.size() != OFFSET_HALF )
		return false;

	Senselock::MemoryType & memory = Senselock::getInstance().getMemory();
	for(int i=0; i<OFFSET_HALF; ++i)
	{
		memory.at(i) = char(code.at(i));
	}
	return true;
}
std::string SenselockComponent::getLockCode(void)
{
	
	std::string ret;
	
		
	Senselock::MemoryType & memory = Senselock::getInstance().getMemory();
	for(int i=0; i<OFFSET_HALF; ++i)
	{
		ret.push_back(char(memory.at(i)));
	}


	return ret;
}


bool SenselockComponent::setLockCode2(const std::string & code)
{
	if(code.size() != OFFSET_HALF )
		return false;
	Senselock::MemoryType & memory = Senselock::getInstance().getMemory();
	for(int i=OFFSET_HALF; i<OFFSET; ++i)
	{
		memory.at(i) = char(code.at(i - OFFSET_HALF));
	}
	
	return true;
}
std::string SenselockComponent::getLockCode2(void)
{
	
	std::string ret;
		
	Senselock::MemoryType & memory = Senselock::getInstance().getMemory();
	for(int i=OFFSET_HALF; i<OFFSET; ++i)
	{
		ret.push_back(char(memory.at(i)));
	}
	
	return ret;
}


SenselockComponent::SenselockComponent(void):_lockInterface(new LockInterface())
{
	_lockInterface->link = boost::bind(&SenselockComponent::link, this);
	_lockInterface->unlink = boost::bind(&SenselockComponent::unlink, this);
	_lockInterface->getLockCode = boost::bind(&SenselockComponent::getLockCode, this);
	_lockInterface->setLockCode = boost::bind(&SenselockComponent::setLockCode, this, _1);
	_lockInterface->getLockCode2 = boost::bind(&SenselockComponent::getLockCode2, this);
	_lockInterface->setLockCode2 = boost::bind(&SenselockComponent::setLockCode2, this, _1);
	_lockInterface->key = boost::bind(&SenselockComponent::key, this, _1);
	_lockInterface->check = boost::bind(&SenselockComponent::check, this);
	_lockInterface->update = boost::bind(&Senselock::update, Senselock::getInstancePtr());
	_lockInterface->commit = boost::bind(&Senselock::commit, Senselock::getInstancePtr());
	_lockInterface->getMemory = boost::bind(&Senselock::getMemory, Senselock::getInstancePtr());
	_lockInterface->print = boost::bind(&Senselock::print, Senselock::getInstancePtr());


	
	_lockInterface->getData8 = boost::bind(&SenselockComponent::getData8, this, _1);
	_lockInterface->getData16 = boost::bind(&SenselockComponent::getData16, this, _1);
	_lockInterface->getData32 = boost::bind(&SenselockComponent::getData32, this, _1);


	
	_lockInterface->setData8 = boost::bind(&SenselockComponent::setData8, this, _1, _2);
	_lockInterface->setData16 = boost::bind(&SenselockComponent::setData16, this, _1, _2);
	_lockInterface->setData32 = boost::bind(&SenselockComponent::setData32, this, _1, _2);


	_query.add(_lockInterface.get());

	
	


}


bool SenselockComponent::link(void)
{

	return true;
}

bool SenselockComponent::check(void)
{
	return (key(0) != 0);
}
void SenselockComponent::unlink(void)
{

}


ComponentInterface * SenselockComponent::_queryInterface(const TypeInfo & info)
{

	return _query.queryInterface(info);
}


uint8 SenselockComponent::getData8(LockInterface::Data8 index) const
{
	
	Senselock::MemoryType & memory = Senselock::getInstance().getMemory();
	return memory.at(OFFSET + index);
}
uint16 SenselockComponent::getData16(LockInterface::Data16 index) const
{
	
	uint16 data = 0;
	Senselock::MemoryType & memory = Senselock::getInstance().getMemory();
	int i =  OFFSET + LockInterface::Data8_Size + (index * 2);
	data = memory.at(i);
	data = data<<8;
	data = data|memory.at(i+1);
	return data;
}
uint32 SenselockComponent::getData32(LockInterface::Data32 index) const
{
	uint32 data = 0;
	Senselock::MemoryType & memory = Senselock::getInstance().getMemory();
	int i =  OFFSET + LockInterface::Data8_Size +(LockInterface::Data16_Size*2) + (index * 4);
	data = memory.at(i);
	data = data<<8;
	data = data|memory.at(i+1);
	data = data<<8;
	data = data|memory.at(i+2);
	data = data<<8;
	data = data|memory.at(i+3);
	return data;
}

void SenselockComponent::setData8(LockInterface::Data8 index, uint8 data)
{
	
	Senselock::MemoryType & memory = Senselock::getInstance().getMemory();
	memory.at(OFFSET + index) = data;
}
void SenselockComponent::setData16(LockInterface::Data16 index, uint16 data)
{
	Senselock::MemoryType & memory = Senselock::getInstance().getMemory();
	int i =  OFFSET + LockInterface::Data8_Size + (index * 2);
	memory.at(i) = 0xFF&(data>>8);

	memory.at(i+1) = 0xFF&(data);
}
void SenselockComponent::setData32(LockInterface::Data32 index, uint32 data)
{
	Senselock::MemoryType & memory = Senselock::getInstance().getMemory();
	int i =  OFFSET + LockInterface::Data8_Size +(LockInterface::Data16_Size*2)+ (index * 4);
	memory.at(i) = 0xFF&(data>>24);
	memory.at(i+1) = 0xFF&(data>>16);
	memory.at(i+2) = 0xFF&(data>>8);
	memory.at(i+3) = 0xFF&(data);
}