#ifndef __Orz_UnitTest_CoinPoolUT__
#define __Orz_UnitTest_CoinPoolUT__
#include "UnitTestConfig.h"
#include "CodingInterface.h"
#include "CodingFormatInterface.h"
#include "LockInterface.h"

/* A name record consists of the given name (e.g. "Charlie")
* and the family name (e.g. "Brown"). The full name, calculated
* by name_record::name() is laid out in the "phonebook order"
* family name + given_name.
*/

unsigned int test(int i)
{
	std::cout<<"!!"<<i<<std::endl;
	return i * 13641689489;
	
}

BOOST_AUTO_TEST_CASE(MultiIndexUT)
{

	Orz::ComponentPtr lockComp = Orz::ComponentFactories::getInstance().create("Senselock");
	
	LockInterface * lock = lockComp->queryInterface<LockInterface>();
	
	Orz::ComponentPtr comp = Orz::ComponentFactories::getInstance().create("Format");
	CodingInterface * coding = comp->queryInterface<CodingInterface>();

	CodingFormatInterface * format = comp->queryInterface<CodingFormatInterface>();
	format->_key = lock->key;

	BOOST_CHECK(coding!= NULL);
	BOOST_CHECK(format!= NULL);

	coding->push(0, 25, 0);
	coding->clear();
	coding->push(0, 24, 0);
	coding->clear();
	coding->push(0, 60, 0);
	coding->clear();
	coding->push(0, 61, 0);
	coding->clear();
	//lock->print();

	std::string lockCode = lock->getLockCode();
	//
	if(!format->decode10(lockCode, 60))
	{
		srand(time(NULL));
		format->clear();
		format->setLockTimes(0);
		format->setLockID(rand()%256);
		format->setLockLeavings(0);
		format->setLockPass(0);
		lockCode = format->encode10(60, 20);
		lock->setLockCode(lockCode);
		////////format->setLockCode
	}else
	{
		std::cout<<format->getLockID()<<"!@!@$"<<std::endl;
	}

		std::cout<<format->getLockLeavings()<<"!@!@$"<<std::endl;
	//SetFunction setTimes;
	//SetFunction setNumber;
	//SetFunction setCost ;
	//SetFunction setEarn;
	//SetFunction setPass;
	//format->setTimes(i);

	//
	//for(int i=0; i<3000; i++)
	//{
	//	format->setNumber(i);
	//	std::string code = format->encode10(1364189489, 60);
	//	format->decode10(code,1364189489, 60);
	//	BOOST_CHECK(format->getNumber() == i%256);

	//}


	//
	//for(int i=0; i<3000; i++)
	//{
	//	format->setTimes(i);
	//	std::string code = format->encode10(1364189489, 60);
	//	format->decode10(code,1364189489, 60);
	//	BOOST_CHECK(format->getTimes() == i%256);

	//}
	//	
	//
	//for(int i=0; i<50000; i++)
	//{
	//	format->setCost(i);
	//	std::string code = format->encode10(1364189489, 60);
	//	format->decode10(code,1364189489, 60);
	//	
	//	int n = i;
	//	while(n>=40960)
	//	{
	//		n -= 40960;
	//	}

	//	if(n>=4096)
	//	{
	//		n = n - n%10;
	//	}else
	//		n = n;
	//	BOOST_CHECK_EQUAL(format->getCost(), n);

	//}


	
	//format->setCost(i);

	format->clear();
	format->setTimes(100);
	format->setCost(123);;
	format->setEarn(2123);
	format->setPass(100);
	std::string code = format->encode10(60, 20);
	std::cout<<code<<std::endl;
	format->decode10(code,60);

	BOOST_CHECK_EQUAL(format->getCost(), 123);
	BOOST_CHECK_EQUAL(format->getTimes(), 100);
	BOOST_CHECK_EQUAL(format->getPass(), 100);
	BOOST_CHECK_EQUAL(format->getEarn(), 2123);

	coding->clear();





	/*std::string code = format->encodeDecimal();*/
	


}

#endif