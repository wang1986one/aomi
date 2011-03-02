#ifndef __Orz_DanListener_h__
#define __Orz_DanListener_h__
#include "WheelAnimalControllerConfig.h"
namespace Orz
{
	


	
	
	class _OrzWheelAnimal2ControllerExport  DanListener
	{
	public:
		virtual void updateUIData(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8) = 0;
		virtual void uploadPassword(int password) = 0;
		virtual ~DanListener(void){}
	};
	

	

}

#endif 