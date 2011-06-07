#ifndef __Orz_WheelGameComponente_h__
#define __Orz_WheelGameComponent_h__
#include "RouletteGameInterfaces.h"
#include "WheelClock.h"
#include "WheelGameUIRegister.h"


namespace Orz
{
//class WheelUIInterface: public ComponentInterface
//{	
//private:
//	typedef boost::function<void (bool visible)> SetVisibleFunction;
//	typedef boost::function<void (void)> VoidFunction;
//public:
//	SetVisibleFunction setStartVisible;
//	SetVisibleFunction setEndVisible;
//	VoidFunction runWinner;
//	SetVisibleFunction setLogoShow;
//
//	VoidFunction addBottom;
//};
//
//
//class WheelClockInterface: public ComponentInterface
//{
	class WheelGameComponent: public Component
	{
	public:
		WheelGameComponent(void);
		virtual ~WheelGameComponent(void);
		void enableState(Event::message_type evt, RouletteGameInterfaces::Referenced referenced);
		void disableState(Event::message_type evt);
	private:
		bool update(TimeType i);
		boost::scoped_ptr<RouletteGameInterfaces> _gameInterface;
		boost::scoped_ptr<RouletteClockInterface> _clockInterface;
		boost::scoped_ptr<RouletteUIInterface> _uiInterface;
	
		WheelClock _clock;
		WheelGameUIRegister _uiRegister;
	//	boost::scoped_ptr<WheelGame> _game;
	};
}


#endif
