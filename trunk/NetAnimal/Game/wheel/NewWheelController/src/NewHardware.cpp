#include "NewWheelControllerStableHeaders.h"
#include "NewHardware.h"

#include <orz/View_SingleChip/SingleChipManager.h>
#include "NewHardwareCode.h"


using namespace Orz;


boost::array<unsigned char , 40> container;
NewHardware::NewHardware(void)
{

}

void NewHardware::link(void)
{
	unsigned char out[2] = {0xbb, 0xee};
	Orz::SingleChipManager::getSingleton().write(out , 2);
}
void NewHardware::findPC(void)
{
	std::cout<<"Find PC"<<std::endl;
	unsigned char out[2] = {0xa1,0xee};
	Orz::SingleChipManager::getSingleton().write(out , 2);
}

void NewHardware::end(void)
{
	
	NewHardwareCode::getSingleton().encode( 0xaa, 0xee, container);
	//Orz::SingleChipManager::getSingleton().write(container.begin(), 40);
}
void NewHardware::answerTime(int second)
{
	NewHardwareCode::getSingleton().encode( 0xa2, unsigned char(second), container);

	//Orz::SingleChipManager::getSingleton().write(container.begin() , 40);
}


NewHardware & NewHardware::getInstance(void)
{
	return *(getInstancePtr());
}


NewHardware * NewHardware::getInstancePtr(void)
{
	static NewHardware instance;
	return &instance;
}