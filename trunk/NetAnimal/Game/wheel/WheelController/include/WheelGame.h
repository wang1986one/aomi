#ifndef __Orz_WheelGame_h__
#define __Orz_WheelGame_h__	

#include "WheelClockListener.h"

#include "WheelControllerConfig.h"
#include "WheelEngineListener.h"
#include "WheelGameInterface.h"
#include "Hardware.h"
#include "WheelClock.h"
#include "SetupUI.h"
namespace Orz
{
	class WheelEngineInterface;

	
	
	typedef boost::shared_ptr<WheelEngineInterface> WheelEngineInterfacePtr;
	//typedef boost::shared_ptr<WheelGameInterface> WheelGameInterfacePtr;


	class _OrzWheelControlleExport WheelGame: public SetupUIListener, public WheelGameInterface, public WheelEngineListener, public WheelClockListener
	{
	public:
		virtual ~WheelGame(void);
		WheelGame(EventWorld * world, SetupUIPtr setupUI, HardwarePtr hardware, WheelEngineInterfacePtr engine, WheelClockPtr clock);
		
		/*virtual void askForData(void);*/
		virtual void updateUIData(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8);


	public:
		///通知硬件收到消息
		void received(void);
		///当游戏时钟改变之后通知
		virtual void clockChanged(int second);
		///设置是否显示数据目录
		void setMenuDataVisible(bool visible);
		///设置是否显示设置目录
		void setSetupVisible(bool visible);
		///
		void menuResult(bool result);
		///动作1
		void actionOne(void);
		///动作2
		void actionTwo(void);
		///动作3
		void actionThree(void);
		///返回状态到硬件
		void answerState(unsigned char state);
		///设置是否播放logo
		void setLogoShow(bool show);
		///设置时钟总即时时间
		void setAllSecond(int second);
		void addBottomToUI(void);

		void resetClock(void);
		void answerTime(void);
		void setStartUIVisible(bool visible);
		void setEndUIVisible(bool visible);
		void updateClock(TimeType interval);
		void update(TimeType interval);

		void runWinner(void);
		bool canAction(void);


		EventWorld * getWorld(void) const;

		
	//	ProcessPtr createProcess(Event::message_type enable,  Event::message_type disable, TimeType minTime = 0.5f, TimeType maxTime = 100.0f);
	private:
		
		virtual void push_data(int id, ACCOUNTS_ITEM item, unsigned long data);
		virtual void push_total(ACCOUNTS_ITEM item, unsigned long data );
		
		virtual void uploadPassword(int password);
	private:
		HardwarePtr _hardware;
		WheelEngineInterfacePtr _engine;
		EventWorld * _world;
		WheelClockPtr _clock;
		SetupUIPtr _setupUI;
	
	};

	
}

#endif

