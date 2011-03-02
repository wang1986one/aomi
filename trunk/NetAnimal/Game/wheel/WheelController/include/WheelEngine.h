#ifndef __Orz_WheelEngine_h__
#define __Orz_WheelEngine_h__	


#include "WheelControllerConfig.h"
#include "WheelEngineInterface.h"
#include "Accounts.h"
namespace Orz
{
	class _OrzWheelControlleExport WheelEngine:public WheelEngineInterface, public WheelEngineListener
	{
	public:
		WheelEngine(Orz::EventWorld * world);
		virtual ~WheelEngine(void);
	private:
		virtual void pushMessage(MsgBuffer & buffer);
		void toEvent(MsgBuffer & buffer);
		
		void addListener(WheelEngineListener * listener);
		void removeListener(WheelEngineListener * listener);
		virtual void refreshMenuData(void);
		/*
		virtual void push_data(int id, ACCOUNTS_ITEM item, unsigned long data);
		virtual void push_total(ACCOUNTS_ITEM item, unsigned long data );*/
	//	void toWinner(const MsgBuffer & buffer);
	//	void selectMode(const MsgBuffer & buffer);
	//	void toSetup(const MsgBuffer & buffer);
	//	void toSetup(const MsgBuffer & buffer);

	//	case COME_IN_SETUP:
	//	{
	//		evt = WheelEvents::createEvent(WheelEvents::COME_IN_SETUP);
	//		for(int i = 0; i<9; ++i)
	//		{
	//		//	_setups[i] = buffer.at(3+i);
	//		}
	//	}
	//case REPORT:



		Orz::EventWorld * _world;
	
		WheelEngineListener * _listener;
		Accounts _acc;
	};
}

#endif

