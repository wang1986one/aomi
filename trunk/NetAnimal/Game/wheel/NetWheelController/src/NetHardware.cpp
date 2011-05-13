#include "NetWheelControllerStableHeaders.h"
#include "NetHardware.h"

#include <orz/View_SingleChip/SingleChipManager.h>
#include "NetHardwareCode.h"


using namespace Orz;
//
//
//boost::array<unsigned char , 40> container;
//NetHardware::NetHardware(void)
//{
//
//}
//
//void NetHardware::link(void)
//{
//	unsigned char out[2] = {0xbb, 0xee};
//	//Orz::SingleChipManager::getSingleton().write(out , 2);
//}
//void NetHardware::findPC(void)
//{
//	std::cout<<"Find PC"<<std::endl;
//	unsigned char out[2] = {0xa1,0xee};
//	//Orz::SingleChipManager::getSingleton().write(out , 2);
//}
//
//void NetHardware::end(void)
//{
//	
//	//NetHardwareCode::getSingleton().encode( 0xaa, 0xee, container);
//	//Orz::SingleChipManager::getSingleton().write(container.begin(), 40);
//}
//void NetHardware::answerTime(int second)
//{
//	//NetHardwareCode::getSingleton().encode( 0xa2, unsigned char(second), container);
//
//	//Orz::SingleChipManager::getSingleton().write(container.begin() , 40);
//}
//
//
//NetHardware & NetHardware::getInstance(void)
//{
//	return *(getInstancePtr());
//}
//
//
//NetHardware * NetHardware::getInstancePtr(void)
//{
//	static NetHardware instance;
//	return &instance;
//}