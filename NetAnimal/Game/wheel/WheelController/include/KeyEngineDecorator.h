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

		///֪ͨ���̰����¼�
		virtual bool onKeyPressed(const KeyEvent & evt);
		///֪ͨ�����ͷ��¼�
		virtual bool onKeyReleased(const KeyEvent & evt);

		WheelEngineInterfacePtr _engine;
	};
}

#endif

