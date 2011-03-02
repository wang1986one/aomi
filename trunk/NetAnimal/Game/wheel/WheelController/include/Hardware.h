#ifndef __Orz_Hardware_h__
#define __Orz_Hardware_h__

#include "WheelControllerConfig.h"
namespace Orz
{
class _OrzWheelControlleExport Hardware
{

	
public:
	void received(bool isReceived);
	void answerTime(int second);
	void actionOne(void);
	void actionTwo(void);
	void actionThree(void);
	
	void answerState(unsigned char state);

	void setup(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8);

	void pushPassword(int password);
private:

};
typedef  boost::shared_ptr<Hardware > HardwarePtr;
}

	

#endif