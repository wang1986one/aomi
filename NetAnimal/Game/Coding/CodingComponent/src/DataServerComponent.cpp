#include "CodingComponentStableHeaders.h"
#include "DataServerComponent.h"
#include "DataServerInterface.h"
#include "LockInterface.h"
#include "CodingFormatInterface.h"
using namespace Orz;




DataServerComponent::DataServerComponent(void):_dataInterface(new DataServerInterface()),_seconds(0)
{

	_dataInterface->loadCodingData = boost::bind(&DataServerComponent::loadCodingData, this);
	_dataInterface->saveCodingData = boost::bind(&DataServerComponent::saveCodingData, this);


	_dataInterface->load = boost::bind(&DataServerComponent::load, this);
	_dataInterface->save = boost::bind(&DataServerComponent::save, this);
	_dataInterface->getSeconds = boost::bind(&DataServerComponent::getSeconds, this);
	
//	_dataInterface->getLevingsProfits = boost::bind(&DataServerComponent::getLevingsProfits, this);

	
		//GetLevingsProfitsFunction getLevingsProfits;
		//SetLevingsProfitsFunction setLevingsProfits;

	_dataInterface->getEarn = boost::bind(&DataServerComponent::getEarn, this);
	_dataInterface->cleanCostBackTimeCode2 = boost::bind(&DataServerComponent::cleanCostBackTimeCode2, this);
	_dataInterface->getBack = boost::bind(&DataServerComponent::getBack, this);
	_dataInterface->setBack = boost::bind(&DataServerComponent::setBack, this, _1);
	_dataInterface->getCost = boost::bind(&DataServerComponent::getCost, this);
	_dataInterface->setCost = boost::bind(&DataServerComponent::setCost, this, _1);
	_dataInterface->getLevingsProfits = boost::bind(&DataServerComponent::getLevingsProfits, this);
	_dataInterface->setLevingsProfits = boost::bind(&DataServerComponent::setLevingsProfits, this, _1);
	_dataInterface->hasLevings =  boost::bind(&DataServerComponent::hasLevings, this);
	_dataInterface->reset =  boost::bind(&DataServerComponent::reset, this);
	_format = Orz::ComponentFactories::getInstance().create("Format");
	_lock = Orz::ComponentFactories::getInstance().create("Senselock");
	

	_lockInterface = _lock->queryInterface<LockInterface>();
	
	CodingFormatInterface * format = _format->queryInterface<CodingFormatInterface>();
	format->_key = _lockInterface->key; 
	_query.add(_lock.get());
	_query.add(_format.get());
	_query.add(_dataInterface.get());

}


DataServerComponent::~DataServerComponent(void)
{
	
}



ComponentInterface * DataServerComponent::_queryInterface(const TypeInfo & info)
{

	return _query.queryInterface(info);
}


//int DataServerComponent::getLevingsProfits(void)
//{
//	
//	CodingFormatInterface * format = _format->queryInterface<CodingFormatInterface>();
//	//unsigned int index = format->getLockLeavings();
//	//unsigned int levings = index2Profits(index);
//	unsigned int profits = getProfits();
//	return profits - levings;
//}

bool DataServerComponent::hasLevings(void)
{
	/*
	CodingFormatInterface * format = _format->queryInterface<CodingFormatInterface>();
	unsigned int index = format->getLockLeavings();
	unsigned int levings = index2Profits(index);
	unsigned int profits = getProfits();*/
	return getLevingsProfits() > 0;
}
unsigned int DataServerComponent::getLevingsProfits(void) const
{
	return _lockInterface->getData32(LockInterface::Data32_1);
}
void DataServerComponent::setLevingsProfits(unsigned int prifits)
{
	_lockInterface->setData32(LockInterface::Data32_1, prifits);
}


unsigned int DataServerComponent::getCost(void) const
{
	return _lockInterface->getData32(LockInterface::Data32_2);
}
void DataServerComponent::setCost(unsigned int cost)
{
	_lockInterface->setData32(LockInterface::Data32_2, cost);
}



unsigned int DataServerComponent::getBack(void) const
{
	return _lockInterface->getData32(LockInterface::Data32_3);
}
void DataServerComponent::setBack(unsigned int back)
{
	_lockInterface->setData32(LockInterface::Data32_3, back);
}

bool DataServerComponent::setCostAndBack(unsigned int cost, unsigned int back)
{
	unsigned int oCost = getCost();
	unsigned int oBack = getBack();
	unsigned int oLevings = getLevingsProfits();
	oCost += cost;
	oBack += back;
	int earn = (cost - back);
	if(oLevings > earn)
	{
		oLevings -= earn;
	}else
	{
		oLevings = 0;
	}
	setCost(oCost);
	setBack(oBack);
	setLevingsProfits(oLevings);
	return hasLevings();
}


bool DataServerComponent::loadCodingData(void)
{
	CodingFormatInterface * format = _format->queryInterface<CodingFormatInterface>();
	std::string code = 	_lockInterface->getLockCode();
	return format->decode10(code, 60);
	
}

void DataServerComponent::saveCodingData(void)
{
	CodingFormatInterface * format = _format->queryInterface<CodingFormatInterface>();
	//std::string code = 	_lockInterface->getLockCode();
	std::string code = format->encode10(60 ,20);
	_lockInterface->setLockCode(code);
	
}
void DataServerComponent::reset(void)
{
	CodingFormatInterface * format = _format->queryInterface<CodingFormatInterface>();
	srand(time(NULL));
	format->clear();
	format->setLockTimes(0);
	format->setLockID(rand()%256);
	format->setLockLeavings(0);
	format->setLockPass(0);
	std::string lockCode = format->encode10(60, 20);
	_lockInterface->setLockCode(lockCode);

	for(int i=0; i<LockInterface::Data8_Size; ++i)
	{
		_lockInterface->setData8(LockInterface::Data8(i), uint8(0));
	}
	for(int i=0; i<LockInterface::Data16_Size; ++i)
	{
		_lockInterface->setData16(LockInterface::Data16(i), uint16(0));
	}

	for(int i=0; i<LockInterface::Data32_Size; ++i)
	{
		_lockInterface->setData32(LockInterface::Data32(i), uint32(0));
	}

}
bool DataServerComponent::load(void)
{
	CodingFormatInterface * format = _format->queryInterface<CodingFormatInterface>();
	
	_lockInterface->update(); 
	
	std::string lockCode = _lockInterface->getLockCode();
	//
	if(!format->decode10(lockCode, 60))
	{
		reset();
		////////format->setLockCode
	}


	_seconds = _lockInterface->getData32(LockInterface::Data32_0);
	_startTime = boost::posix_time::second_clock::local_time();
	return true;
}
bool DataServerComponent::save(void)
{
	_seconds = getSeconds();
	_startTime = boost::posix_time::second_clock::local_time();
	_lockInterface->setData32(LockInterface::Data32_0, _seconds);
	_lockInterface->commit();
	return true;
}
int DataServerComponent::getEarn(void) const
{
	return int(getCost() - getBack());
}

void DataServerComponent::cleanCostBackTimeCode2(void)
{
	std::string code2;
	code2.resize(20);
	
	std::fill(code2.begin(), code2.end(), 0);
	_lockInterface->setLockCode2(code2);
	_lockInterface->setData32(LockInterface::Data32_0, 0);
	setCost(0);
	setBack(0);
}
unsigned int DataServerComponent::getSeconds(void)
{
		
	boost::posix_time::time_duration duraton = boost::posix_time::second_clock::local_time() -_startTime;
	unsigned int passTime = duraton.ticks()/duraton.ticks_per_second();
	return passTime + _seconds;
}