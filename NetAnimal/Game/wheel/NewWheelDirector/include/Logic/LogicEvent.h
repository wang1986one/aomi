#ifndef __Orz_LogicEvent_h__
#define __Orz_LogicEvent_h__	


#include "NewWheelDirectorStableHeaders.h"
//#include "WheelMediator.h"
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
			//	game->received();
			}

		};


		class SetTime: public boost::statechart::event<SetTime>
		{
		public:
			SetTime(int time):  _time(time)
			{

				if(_time>40)
					_time = 40;
			}
			void execute(WheelGame * game) const
			{
				game->setAllSecond(_time);
			}
		private:
			int _time;
		};



		//硬件询问时间	  
		class AskTime: public boost::statechart::event<AskTime>
		{
		public:
			void resetClock(WheelGame * game) const
			{
				game->resetClock();
			}
			//void answerTime(WheelGame * game) const
			//{
			////	game->answerTime();
			//}

		};
		class HowWin: public boost::statechart::event<HowWin>
		{
		
		};
		class ResetGame: public boost::statechart::event<ResetGame>
		{
		
		};
		class FindSC: public boost::statechart::event<FindSC>
		{
		
		};
	
		

	}
}

#endif