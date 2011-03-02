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


		
		///���أ������ڴ�����Ϣ����
		virtual void doExecute(Event * evt);
		
		
		///���أ������ڽ�����Ϣ�������
		virtual void doEnable(void);
		
		
		///���أ��������뿪��Ϣ�������
		virtual void doDisable(void);

		///���أ������ڸ��µ���
		virtual void doFrame(unsigned int step);


		/////֪ͨ���̰����¼�
		//virtual bool onKeyPressed(const KeyEvent & evt);
		/////֪ͨ�����ͷ��¼�
		//virtual bool onKeyReleased(const KeyEvent & evt);

		WheelEngineInterfacePtr _engine;
	private:
		TimeType _currTime;

		void  sendMsg(const Orz::MsgBuffer & head, const Orz::MsgBuffer & msg);
	};

	
	typedef boost::shared_ptr<AutoEngineDecorator> AutoEngineDecoratorPtr;
}

#endif

