#ifndef __Orz_HardwareEngineDecorator_h__
#define __Orz_HardwareEngineDecorator_h__	


#include "WheelControllerConfig.h"
#include "WheelEngineInterface.h"
#include "MsgHandler.h"
namespace Orz
{
	class _OrzWheelControlleExport HardwareEngineDecorator:public WheelEngineInterface,  public KeyListener , public SingleChipListener
	{
	public:
		HardwareEngineDecorator(WheelEngineInterfacePtr engine);
		virtual ~HardwareEngineDecorator(void);
	private:
		virtual void pushMessage(MsgBuffer & buffer);
		void toEvent(MsgBuffer & buffer);
		
		void addListener(WheelEngineListener * listener);
		void removeListener(WheelEngineListener * listener);
		virtual void refreshMenuData(void);
	private:
		
		virtual void read(boost::circular_buffer<unsigned char> & data);
		///通知键盘按下事件
		virtual bool onKeyPressed(const KeyEvent & evt);
		///通知键盘释放事件
		virtual bool onKeyReleased(const KeyEvent & evt);

		MsgHandler _handler;
		WheelEngineInterfacePtr _engine;
	};
}

#endif

