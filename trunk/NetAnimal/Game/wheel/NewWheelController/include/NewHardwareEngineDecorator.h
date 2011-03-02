#ifndef __Orz_NewHardwareEngineDecorator_h__
#define __Orz_NewHardwareEngineDecorator_h__

#include "WheelControllerConfig.h"
#include "NewHandler.h"
#include "WheelEngineInterface.h"
namespace Orz
{
class _OrzNewWheelControlleExport NewHardwareEngineDecorator: public SingleChipListener, public WheelEngineInterface
{
public:
	NewHardwareEngineDecorator(WheelEngineInterfacePtr engine);
	~NewHardwareEngineDecorator(void);
	
	void dealMassage(HardwareMsg & msg);
	void read(boost::circular_buffer<unsigned char> & data);
	
	void startGame(size_t time);
	void pushRate(void);
	void runGame(void);
	
	virtual void findSC(void);


private:
	NewHandler _handler;
	WheelEngineInterfacePtr _engine;


};
//typedef  boost::shared_ptr<NewHardwareEngineDecorator> HardwarePtr;


}

	

#endif