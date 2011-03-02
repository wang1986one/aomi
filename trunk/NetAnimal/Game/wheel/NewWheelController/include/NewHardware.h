#ifndef __Orz_NewHardware_h__
#define __Orz_NewHardware_h__

#include "WheelControllerConfig.h"
namespace Orz
{
class _OrzNewWheelControlleExport NewHardware
{

	
public:
	void answerTime(int second);
	
	void findPC(void);
	void link(void);
	void end(void);
	static NewHardware & getInstance(void);
	static NewHardware * getInstancePtr(void);
	
private:
	NewHardware(void);

};
}

	

#endif