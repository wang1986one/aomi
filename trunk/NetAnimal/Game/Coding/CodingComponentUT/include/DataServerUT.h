#ifndef __Orz_DataServerUT__
#define __Orz_DataServerUT__
#include "UnitTestConfig.h"
#include "DataServerInterface.h"
#include "LockInterface.h"
#include "CodingFormatInterface.h"

/* A name record consists of the given name (e.g. "Charlie")
* and the family name (e.g. "Brown"). The full name, calculated
* by name_record::name() is laid out in the "phonebook order"
* family name + given_name.
*/

BOOST_AUTO_TEST_CASE(DataServerUT)
{

	Orz::ComponentPtr dataComp = Orz::ComponentFactories::getInstance().create("DataServer");
	DataServerInterface * data = dataComp->queryInterface<DataServerInterface>();
	CodingFormatInterface * format = dataComp->queryInterface<CodingFormatInterface>();
	format->clear();
	format->setCost(100);
	format->setEarn(133);
	format->setTimes(123);
	format->setPass(213);
	//data->getEarn
	std::string str = format->encode10(60, 20);
	std::cout<<str;

	//BOOST_CHECK(data!= NULL);
	//BOOST_CHECK(lock!= NULL);
	//if(data->load())
	//{
	//	
	//	std::cout<<data->getSeconds()<<std::endl;
	//	Sleep(1000);
	//	std::cout<<data->getSeconds()<<std::endl;
	//	data->save();
	//}
	//std::cout<<data->hasLevings()<<std::endl;
	//std::cout<<data->getEarn()<<std::endl;
	//
	//lock->update();
	//lock->print();
	/*for(int i=0; i<LockInterface::Data8_Size; ++i)
	{
		lock->setData8(LockInterface::Data8(i), uint8(i));
	}*/



	
	
	/*for(int i=0; i<LockInterface::Data16_Size; ++i)
	{
		lock->setData16(LockInterface::Data16(i), uint16(i));
	}


	for(int i=0; i<LockInterface::Data32_Size; ++i)
	{
		lock->setData32(LockInterface::Data32(i), uint32(i));
	}


	for(int i=0; i<LockInterface::Data8_Size; ++i)
	{
		BOOST_CHECK_EQUAL(uint8(i), lock->getData8(LockInterface::Data8(i)));
	}

	

	for(int i=0; i<LockInterface::Data16_Size; ++i)
	{
		BOOST_CHECK_EQUAL(uint16(i), lock->getData16(LockInterface::Data16(i)));
	}


	for(int i=0; i<LockInterface::Data32_Size; ++i)
	{
		BOOST_CHECK_EQUAL(uint32(i), lock->getData32(LockInterface::Data32(i)));
	}*/
	/*lock->print();
	lock->commit();*/

}

#endif