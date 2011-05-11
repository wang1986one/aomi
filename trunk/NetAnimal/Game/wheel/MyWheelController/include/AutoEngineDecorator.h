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


		
		///���أ������ڴ�����Ϣ����
		virtual void doExecute(Event * evt);
		
		
		///���أ������ڽ�����Ϣ�������
		virtual void doEnable(void);
		
		
		///���أ��������뿪��Ϣ�������
		virtual void doDisable(void);

		///���أ������ڸ��µ���
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

