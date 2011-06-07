#ifndef __Orz_NetGameComponent__
#define __Orz_NetGameComponent__
#include "JsInterface.h"
#include "GameInterface.h"
#include "RouletteGameInterfaces.h"
#include <WheelGobal/WheelGameUIRegister.h>

namespace Orz
{
	class  NetClock
	{
	public:
		NetClock(void);
		~NetClock(void);

		//获取剩余时间
		int getLastSecond(void) const;

		//获取当前时间
		int getSecond(void) const;

		//获取总时间
		int getAllSecond(void) const;

		//设置当前时间
		void setSecond(int second);

		//设置总时间
		void setAllSecond(int allSecond);

		//void setListener(NetClockListener * listener);

		void setTime(int time);
		void update(TimeType interval);
		void reset(void);
	private:
		int _second;
		int _allSecond;
		TimeType _pass;
	};


	//void NetClock::changeClock(void)
	//{
	//	if(_callback)
	//		_callback->clockChanged(_allSecond- _second);
	//}
	class  NetGameComponent: public Component
	{

	public :
		NetGameComponent(void);
		virtual ~NetGameComponent(void);
	private:            
		void setTime(int time);
		void enableState(Event::message_type evt, RouletteGameInterfaces::Referenced referenced);
		void disableState(Event::message_type evt);
		bool update(TimeType i);
		void startGame(void);

		boost::scoped_ptr<RouletteGameInterfaces> _gameInterface;
		boost::scoped_ptr<RouletteClockInterface> _clockInterface;
		boost::scoped_ptr<RouletteUIInterface> _uiInterface;

		NetClock _clock;
		WheelGameUIRegister _uiRegister;
		RouletteGameInterfaces::Referenced  _holdLogo;

	};



}
#endif