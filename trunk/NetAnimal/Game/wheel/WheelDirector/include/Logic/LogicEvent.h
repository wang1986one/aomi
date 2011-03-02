#ifndef __Orz_LogicEvent_h__
#define __Orz_LogicEvent_h__	


#include "WheelDirectorStableHeaders.h"
#include "WheelMediator.h"
#include "WheelClock.h"
namespace Orz
{
	namespace LogicEvent
	{

		//开始旋转
		class WheelStart: public boost::statechart::event<WheelStart>
		{
		public:

			void execute(WheelGame * game) const
			{
				game->received();
			}

		};


		class SetTime: public boost::statechart::event<SetTime>
		{
		public:
			SetTime(/*WheelClock & clock, */int time): /*_clock(clock),*/ _time(time)
			{}
			void execute(WheelGame * game) const
			{
				game->setAllSecond(_time);
			}
		private:
	/*		WheelClock & _clock;*/
			int _time;
		};



		//重新启动游戏
		class ResetGame: public boost::statechart::event<ResetGame>{};


		//进入目录
		class ComeInMenu: public boost::statechart::event<ComeInMenu>{};

		//进入设置
		class ComeInSetup: public boost::statechart::event<ComeInSetup>{};


		//退出目录
		class GoOutMenu: public boost::statechart::event<GoOutMenu>{};


		//传目录数据
		class DataMenu: public boost::statechart::event<DataMenu>
		{
		public:
			void execute(WheelGame * game) const
			{
				game->setMenuDataVisible(true);
			}
		};

		class HardwareReturn: public boost::statechart::event<HardwareReturn>
		{
		public:
			HardwareReturn(bool ret):_return(ret)
			{}
			void execute(WheelGame * game) const
			{
				game->menuResult(_return);
			}
		private:
			bool _return;

		};


		class ActionOne: public boost::statechart::event<ActionOne>
		{
		public:
			void execute(WheelGame * game) const
			{
				game->actionOne();
			}
		};
	

		class ActionTwo: public boost::statechart::event<ActionTwo>
		{
		
		};
	

		class ActionThree: public boost::statechart::event<ActionThree>
		{
		
		};
	



		//硬件询问状态
		class AskState: public boost::statechart::event<AskState>
		{
		public:
			void execute(WheelGame * game, int state) const
			{
				game->answerState(state);
			}
		};


		//硬件询问时间	  
		class AskTime: public boost::statechart::event<AskTime>
		{
		public:
			void resetClock(WheelGame * game) const
			{
				game->resetClock();
			}
			void answerTime(WheelGame * game) const
			{
				game->answerTime();
			}

			void actionTwo(WheelGame * game) const
			{	
				game->actionTwo();
			}
			void actionThree(WheelGame * game) const
			{		
				game->actionThree();
			}

			bool canAction(WheelGame * game) const
			{
				return game->canAction();
			}
		};
		class HowWin: public boost::statechart::event<HowWin>
		{
		
		};
	
		

	}
}

#endif