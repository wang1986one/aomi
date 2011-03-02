#ifndef __Orz_UnitTest_BackUT__
#define __Orz_UnitTest_BackUT__
#include "UnitTestConfig.h"
#include "CodingInterface.h"
#include "CodingFormatInterface.h"
#include "LockInterface.h"

/* A name record consists of the given name (e.g. "Charlie")
* and the family name (e.g. "Brown"). The full name, calculated
* by name_record::name() is laid out in the "phonebook order"
* family name + given_name.
*/


BOOST_AUTO_TEST_CASE(BackUT)
{
	
	Orz::ComponentPtr comp = Orz::ComponentFactories::getInstance().create("Format");
	CodingInterface * coding = comp->queryInterface<CodingInterface>();

	CodingFormatInterface * format = comp->queryInterface<CodingFormatInterface>();
	
	format->clear();
	format->setBackID(123);
	format->setBackCheck(21);
	format->setBackLeavingsIndex(15);
	std::string code = format->encode10(28, 10);
	std::cout<<code<<std::endl;
	format->decode10(code,28);

	BOOST_CHECK_EQUAL(format->getBackID(), 123);
	BOOST_CHECK_EQUAL(format->getBackCheck(), 21);
	BOOST_CHECK_EQUAL(format->getBackLeavingsIndex(), 15);

	coding->clear();


}

#endif