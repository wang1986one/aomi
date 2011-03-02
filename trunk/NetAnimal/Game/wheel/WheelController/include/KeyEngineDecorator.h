#ifndef __Orz_KeyEngineDecorator_h__
#define __Orz_KeyEngineDecorator_h__	


#include "WheelControllerConfig.h"
#include "WheelEngineInterface.h"
namespace Orz
{
	class _OrzWheelControlleExport KeyEngineDecorator:public WheelEngineInterface,  public KeyListener 
	{
	public:
		KeyEngineDecorator(WheelEngineInterfacePtr engine);
		~KeyEngineDecorator(void);

	
	private:
		
		virtual void addListener(WheelEngineListener * listener);
		virtual void removeListener(WheelEngineListener * listener);
		
		virtual void refreshMenuData(void);
		virtual void pushMessage(MsgBuffer & buffer);

		///通知键盘按下事件
		virtual bool onKeyPressed(const KeyEvent & evt);
		///通知键盘释放事件
		virtual bool onKeyReleased(const KeyEvent & evt);

		WheelEngineInterfacePtr _engine;
	};
}

#endif

