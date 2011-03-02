#ifndef __Orz_UnitTest_CRCUT__
#define __Orz_UnitTest_CRCUT__
#include "UnitTestConfig.h"
#include "CRC16ZmodemInterface.h"

/* A name record consists of the given name (e.g. "Charlie")
* and the family name (e.g. "Brown"). The full name, calculated
* by name_record::name() is laid out in the "phonebook order"
* family name + given_name.
*/


BOOST_AUTO_TEST_CASE(CRCUT)
{
	Orz::ComponentPtr comp = Orz::ComponentFactories::getInstance().create("CRC16");
	CRC16ZmodemInterface * crc16 = comp->queryInterface<CRC16ZmodemInterface>();

	for(int  i =0; i<256; i++)
	{

		for(int  j =0; j<256; j++)
		{
			for(int  k =0; k<256; k++)
			{
				crc16->push_back(i);

				crc16->push_back(j);
				crc16->push_back(k);

				crc16->getResult();
				if(crc16->rel[0] == 0x37 && crc16->rel[1] == 0x24)
					std::cout<<std::hex<<i<<j<<k<<"!"<<int(crc16->rel[1])<<","<<int(crc16->rel[0])<<std::endl;
			}
		}
	}

}

#endif