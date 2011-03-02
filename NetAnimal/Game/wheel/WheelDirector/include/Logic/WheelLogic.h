#ifndef __Orz_WheelLogic_h__
#define __Orz_WheelLogic_h__
//#include "Engine.h"
//#include "WheelUI.h"
//#include "LogiEvent.h"
#include "WheelDirectorStableHeaders.h"
#include "WheelGame.h"
#include "logic/LogicEvent.h"
namespace Orz
{



	class WheelGame;
	class GameLogic;
	class LogoLogic;
	class MenuLogic;
	class SetupLogic;
	//class LogiGame;
	//class LogiInfo;	

	//class LogiMenu;
	//class LogiStart;//����ʱ
	//class LogiPreRun;//zxhװ�Ⱥ�
	//class LogiRun;//ת��
	//
	//class LogiWin;// ���� 
	//class LogiPlay;//����һ��
	//class LogiEnd;//���
	//class LogiLogo;//���

	//
	//class LogiReady;//���


	class WheelLogic: public FSM::MainLogic<WheelLogic, WheelGame, GameLogic/**/>//, public MyClockListener
	{
	public:
		typedef boost::mpl::list< sc::custom_reaction< LogicEvent::WheelStart >, sc::custom_reaction< LogicEvent::SetTime >, sc::custom_reaction< LogicEvent::ResetGame > /*, sc::custom_reaction< LogicEvent::SetTime >,sc::custom_reaction<LogicEvent::4rResetGame>*/ > reactions;

		sc::result react(const LogicEvent::WheelStart & evt);
		sc::result react(const LogicEvent::SetTime & evt);
		sc::result react(const LogicEvent::ResetGame & evt);	/**/
	//	TutoriaLogic();
	//	void clockChanged(const MyClock & clock);
	//	/*	void setSec(int sec);
	//	int getSec(void) const;*/
	//	MyClock & getClock(void);
	//private:
	//	boost::scoped_ptr<MyClock> _clock;
	};






	


	


	



 


	//	class 
	//	class OTDFighterTouch;





	



	



 


	//	class 
	//	class OTDFighterTouch;
}

//#include "logic/AllLogic.h"
#endif