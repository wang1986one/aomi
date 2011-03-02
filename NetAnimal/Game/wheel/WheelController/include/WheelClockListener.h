#ifndef __Orz_WheelClockListener_h__
#define __Orz_WheelClockListener_h__	


#include "WheelControllerConfig.h"
namespace Orz
{
 
class _OrzWheelControlleExport WheelClockListener
{
public:
	virtual ~WheelClockListener(void){}
	virtual void clockChanged(int second) = 0;
};

}

#endif