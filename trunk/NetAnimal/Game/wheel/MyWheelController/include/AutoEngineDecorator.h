#ifndef __Orz_AutoEngineDecorator_h__
#define __Orz_AutoEngineDecorator_h__	


#include "WheelControllerConfig.h"
#include "WheelEngineInterface.h"
namespace Orz
{

	class _OrzMyWheelControlleExport AutoEngineDecorator:public WheelEngineInterface, public EventHandler//,  public KeyListener 
	{
	public:
		AutoEngineDecorator(WheelEngineInterfacePtr engine);
		~AutoEngineDecorator(void);

	
	private:


		
		///重载，被用于处理消息调用
		virtual void doExecute(Event * evt);
		
		
		///重载，被用于进入消息管理调用
		virtual void doEnable(void);
		
		
		///重载，被用于离开消息管理调用
		virtual void doDisable(void);

		///重载，被用于更新调用
		virtual void doFrame(unsigned int step);

		

		WheelEngineInterfacePtr _engine;
	private:

		
		virtual void startGame(size_t time);
		//virtual void pushRate(void);
		virtual void runGame(void);
		//virtual void clickButton(int id, int button);

		virtual TimeType getTime(void) const;


		TimeType _currTime;

		void  sendMsg(const Orz::MsgBuffer & head, const Orz::MsgBuffer & msg);
	};

	
	typedef boost::shared_ptr<AutoEngineDecorator> AutoEngineDecoratorPtr;
}

#endif

