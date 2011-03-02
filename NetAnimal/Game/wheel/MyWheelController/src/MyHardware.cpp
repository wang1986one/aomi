#include "MyWheelControllerStableHeaders.h"
#include "MyHardware.h"

#include <orz/View_SingleChip/SingleChipManager.h>
#include "MyHardwareCode.h"


using namespace Orz;


boost::array<unsigned char , 40> container;
MyHardware::MyHardware(void)
{

}

void MyHardware::link(void)
{
	unsigned char out[2] = {0xbb, 0xee};
	//Orz::SingleChipManager::getSingleton().write(out , 2);
}
void MyHardware::findPC(void)
{
	std::cout<<"Find PC"<<std::endl;
	unsigned char out[2] = {0xa1,0xee};
	//Orz::SingleChipManager::getSingleton().write(out , 2);
}

void MyHardware::end(void)
{
	
	//MyHardwareCode::getSingleton().encode( 0xaa, 0xee, container);
	//Orz::SingleChipManager::getSingleton().write(container.begin(), 40);
}
void MyHardware::answerTime(int second)
{
	//MyHardwareCode::getSingleton().encode( 0xa2, unsigned char(second), container);

	//Orz::SingleChipManager::getSingleton().write(container.begin() , 40);
}


MyHardware & MyHardware::getInstance(void)
{
	return *(getInstancePtr());
}


MyHardware * MyHardware::getInstancePtr(void)
{
	static MyHardware instance;
	return &instance;
}