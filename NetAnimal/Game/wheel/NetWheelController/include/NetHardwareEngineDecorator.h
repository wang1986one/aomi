#ifndef __Orz_NetHardwareEngineDecorator_h__
#define __Orz_NetHardwareEngineDecorator_h__

#include "WheelControllerConfig.h"
#include "NetHandler.h"
#include "WheelEngineInterface.h"
namespace Orz
{
class _OrzNetWheelControlleExport NetHardwareEngineDecorator: /*public SingleChipListener, */public WheelEngineInterface, public EventHandler
{
public:
	NetHardwareEngineDecorator(WheelEngineInterfacePtr engine);
	~NetHardwareEngineDecorator(void);
	
	//void dealMassage(HardwareMsg & msg);
	//void readFromSCM(unsigned int id, unsigned char c);
	
//	virtual void read(boost::circular_buffer<unsigned char> & data){}
	void startGame(size_t time);
	//void pushRate(void);
	void runGame(void);
	
	virtual TimeType getTime(void) const;

	
//void clickButton(int id, int button);

		
	///重载，被用于处理消息调用
	virtual void doExecute(Event * evt);
	
	
	///重载，被用于进入消息管理调用
	virtual void doEnable(void);
	
	
	///重载，被用于离开消息管理调用
	virtual void doDisable(void);

	///重载，被用于更新调用
	virtual void doFrame(unsigned int step);

private:
	//NetHandler _handler;
	WheelEngineInterfacePtr _engine;
	TimeType _currTime;
	ComponentPtr _f6table;

};
//typedef  boost::shared_ptr<NetHardwareEngineDecorator> HardwarePtr;


}

	

#endif