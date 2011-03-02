#ifndef __Orz_UnitTest_NewHardwareUT__
#define __Orz_UnitTest_NewHardwareUT__
#include "UnitTestConfig.h"
/*

#include "Engine.h"
#include "KeyToMessage.h"
#include "SingleChipToMessage.h"*/
#include "NewHardwareCode.h"

#include "NewHardwareEngineDecorator.h"
BOOST_AUTO_TEST_CASE(NewHardwareUT)
{
	using namespace Orz;
	/*NewHardwareCode code;
	boost::array<unsigned char, 40> a;
	code.encode(1,2, a);

	BOOST_FOREACH(unsigned char c, a)
	{
		std::cout<<std::hex<<unsigned int(c)<<std::endl;
	}

	boost::array<unsigned char, 40> a2 = {
		0xD8,
		0xF1,
		0xD9,
		0x2A,
		0x82,
		0xC8,
		0xD8,
		0xFE,
		0x43,
		0x4D,
		0x98,
		0x55,
		0x8C,
		0xE2,
		0x8A,
		0x11,
		0x17,
		0x11,
		0x98,
		0x54,
		0x2F,
		0x11,
		0x2D,
		0x05,
		0x58,
		0xF5,
		0x6B,
		0xD6,
		0x88,
		0x07,
		0x99,
		0x92,
		0x48,
		0x33,
		0x62,
		0x41,
		0xF3,
		0x0D,
		0x23,
		0xEE};

		HardwareMsg hardware;
		code.decode(a2, hardware);
		std::cout<<unsigned int(hardware.msg)<<std::endl;

		
		BOOST_FOREACH(unsigned char c, hardware.data)
		{
			
			std::cout<<std::hex<<unsigned int(c)<<std::endl;
		}*/
	
	Orz::WheelEngineInterfacePtr a;
	NewHardwareEngineDecorator hardware(a);

	
	while(1)
	{

	
		UnitTestEnvironmen::system->run();
	}


}

#endif