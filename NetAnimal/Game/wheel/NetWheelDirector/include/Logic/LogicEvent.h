#ifndef __Orz_LogicEvent_h__
#define __Orz_LogicEvent_h__	


#include "NetWheelDirectorStableHeaders.h"
#include "RouletteGameInterfaces.h"
#include "WheelClock.h"
namespace Orz
{
	namespace LogicEvent
	{

		//开始旋转
		class WheelStart: public boost::statechart::event<WheelStart>
		{
		public:

			//void execute(WheelGame * game) const
			//{
			////	game->received();
			//}

		};


		class SetTime: public boost::statechart::event<SetTime>
		{
		public:
			SetTime(int time):  _time(time)
			{

				if(_time>40)
					_time = 40;
			}
			void execute(RouletteClockInterface * clock) const
			{
			//	game->setAllSecond(_time);
			}
		private:
			int _time;
		};



		//硬件询问时间	  
		class AskTime: public boost::statechart::event<AskTime>
		{
		public:
			void resetClock(RouletteClockInterface * clock) const
			{
				//clock->resetClock();
			}
			//void answerTime(WheelGame * game) const
			//{
			////	game->answerTime();
			//}

		};
		//class HowWin: public boost::statechart::event<HowWin>
		//{
		//
		//};
		class Dan1: public boost::statechart::event<Dan1>
		{
		
		};
		class Dan2: public boost::statechart::event<Dan2>
		{
		
		};
		class ResetGame: public boost::statechart::event<ResetGame>
		{
		
		};


		class F1: public boost::statechart::event<F1>
		{
		
		};

		class F2: public boost::statechart::event<F2>
		{
		
		};

		
		class F3: public boost::statechart::event<F3>
		{
		
		};

	/*	class ClickButton: public boost::statechart::event<ClickButton>
		{
		public:
			ClickButton(int id, int button):_id(id),  _button(button)
			{

			}
			int getButton(void) const
			{
				return _button;
			}
			int getID(void) const
			{
				return _id;
			}
		private:
			int _button;
			int _id;
		};*/

		
		//class FindSC: public boost::statechart::event<FindSC>
		//{
		//
		//};
	
		

	}
}

#endif