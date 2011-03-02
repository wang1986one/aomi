#ifndef __Orz_WheelEngineInterface_h__
#define __Orz_WheelEngineInterface_h__	


#include "WheelControllerConfig.h"
namespace Orz
{

	class WheelEngineListener;
	
	class _OrzNewWheelControlleExport WheelEngineInterface
	{
	public:
		
	public:
		//virtual void addListener(WheelEngineListener * listener) = 0;
		//virtual void removeListener(WheelEngineListener * listener) = 0;
		WheelEngineInterface(void);
		virtual ~WheelEngineInterface(void);

		virtual void startGame(size_t time) = 0;
		virtual void pushRate(void) = 0;
		virtual void runGame(void) = 0;
		
		virtual void findSC(void) = 0;

		
		
	};


	typedef boost::shared_ptr<WheelEngineInterface> WheelEngineInterfacePtr;
}

#endif



