#ifndef __Orz_AutoEngineDecorator_h__
#define __Orz_AutoEngineDecorator_h__	


#include "WheelControllerConfig.h"
#include "WheelEngineInterface.h"
namespace Orz
{

	class _OrzWheelControlleExport AutoEngineDecorator:public WheelEngineInterface, public EventHandler//,  public KeyListener 
	{
	public:
		AutoEngineDecorator(WheelEngineInterfacePtr engine);
		~AutoEngineDecorator(void);

	
	private:
		
		virtual void addListener(WheelEngineListener * listener);
		virtual void removeListener(WheelEngineListener * listener);
		
		virtual void refreshMenuData(void);
		virtual void pushMessage(MsgBuffer & buffer);


		
		///重载，被用于处理消息调用
		virtual void doExecute(Event * evt);
		
		
		///重载，被用于进入消息管理调用
		virtual void doEnable(void);
		
		
		///重载，被用于离开消息管理调用
		virtual void doDisable(void);

		///重载，被用于更新调用
		virtual void doFrame(unsigned int step);


		/////通知键盘按下事件
		//virtual bool onKeyPressed(const KeyEvent & evt);
		/////通知键盘释放事件
		//virtual bool onKeyReleased(const KeyEvent & evt);

		WheelEngineInterfacePtr _engine;
	private:
		TimeType _currTime;

		void  sendMsg(const Orz::MsgBuffer & head, const Orz::MsgBuffer & msg);
	};

	
	typedef boost::shared_ptr<AutoEngineDecorator> AutoEngineDecoratorPtr;
}

#endif

