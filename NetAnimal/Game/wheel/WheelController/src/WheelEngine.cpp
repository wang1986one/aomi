#include "WheelControllerStableHeaders.h"
#include "WheelEngine.h"
#include "WheelEvents.h"
#include "Msg2Account.h"
#include "BlackBoardSystem.h"
#include "WinData.h"
#include "WheelData.h"
#include "WheelEnum.h"
#include <orz/Toolkit_Base/Exception.h>
using namespace Orz;

inline static std::string toString(const MsgBuffer buffer)
{
	std::stringstream ss;
	for(MsgBuffer::const_iterator it = buffer.begin(); it != buffer.end(); ++it)
	{
		ss<<int(*it)<<",";
	}
	return ss.str();
}
//
//void WheelEngine::push_data(int id, ACCOUNTS_ITEM item, unsigned long data)
//{
//
//}
//void WheelEngine::push_total(ACCOUNTS_ITEM item, unsigned long data )
//{
//
//}
WheelEngine::WheelEngine(Orz::EventWorld * world):_world(world),_listener(NULL)
{

}



void  WheelEngine::addListener(WheelEngineListener * listener)
{
	_listener = listener;
}
void  WheelEngine::removeListener(WheelEngineListener * listener)
{
	_listener = NULL;
}
void WheelEngine::refreshMenuData(void)
{
	if(_listener)
	{
		_acc.setCallback(_listener);
		if(_acc.isComplete())
			_acc.upload();
	}
}
WheelEngine::~WheelEngine(void)
{

}
void WheelEngine::pushMessage(MsgBuffer & buffer)
{
	try
	{
		toEvent(buffer);
	}
	catch(...)
	{
		ORZ_LOG_CRITICAL_MESSAGE("wrong massage!");
		throw ORZ_EXCEPTION(Exception::ERR_INVALID_PARAMS)<<errno_info_text("wrong massage!");
	}

}


static void toWinner(const MsgBuffer & buffer)
{

	WheelEnum::WINNER winner;
	switch(buffer.at(3))
	{
	case 0x00:
		winner = WheelEnum::Dealer;
		break;
	case 0x01:	
		winner = WheelEnum::Player;
		break;
	case 0x02:	
		winner = WheelEnum::Draw;
		break;
	}
	WinData::getInstance().setWinner(winner);
	//BlackBoardSystem::getInstance().write(WheelEnum::WINNER_STR,static_cast<int>(winner));


	unsigned char mode = buffer.at(4);

	int bonus = (buffer.at(5) * 100) + (rand() %100);


	WinData::getInstance().setBonus(bonus);
	//::getInstance().write(WheelEnum::BONUS_STR,static_cast<int>(bonus));



	//WheelData::WheelMsg msg = WheelData::getInstance().getWheelMsg(WheelEnum::HARDWARE_WIN_MODE(mode));


	//BlackBoardSystem::getInstance().write(WheelEnum::WheelMsg,msg);


	const WheelData_::WheelMsg & msg = WheelData_::getInstance().getWheelMsg(WheelEnum::HARDWARE_WIN_MODE(mode));
	//_winMode =
	//;
	//_status =  msg.get<1>().second;
	//

	WinData::getInstance().setWinMode(msg.get<0>());
	WinData::getInstance().clear();

	WheelEnum::ANIMAL_ITEM animal(msg.get<1>().first, msg.get<2>());
	switch(msg.get<0>())
	{
	case WheelEnum::ALL_COLOR:
		{
			animal.first = WheelEnum::TYPE0;
			WinData::getInstance().push_back(animal,
				WheelData_::getInstance().getOverride(animal)
				);
			
			animal.first = WheelEnum::TYPE1;
			WinData::getInstance().push_back(animal,
				WheelData_::getInstance().getOverride(animal)
				);

			animal.first = WheelEnum::TYPE2;
			WinData::getInstance().push_back(animal,
				WheelData_::getInstance().getOverride(animal)
				);
			
			animal.first = WheelEnum::TYPE3;
			WinData::getInstance().push_back(animal,
				WheelData_::getInstance().getOverride(animal)
				);
		}
		break;
	case WheelEnum::ALL_ANIMAL:
		{

			animal.second = WheelEnum::Red;
			WinData::getInstance().push_back(animal,
				WheelData_::getInstance().getOverride(animal)
				);
			
			animal.second = WheelEnum::Green;
			WinData::getInstance().push_back(animal,
				WheelData_::getInstance().getOverride(animal)
				);

			animal.second = WheelEnum::Yellow;
			WinData::getInstance().push_back(animal,
				WheelData_::getInstance().getOverride(animal)
				);
			
		}
		break;
	case WheelEnum::MANY:
		
		for(int i =0;; i++)
		{
			if(!WheelData_::getInstance().hasTVNext(WheelEnum::HARDWARE_WIN_MODE(mode), animal, i))
				break;


			WheelEnum::ANIMAL_ITEM ai = WheelData_::getInstance().getTVNext(WheelEnum::HARDWARE_WIN_MODE(mode), animal, i);

			WinData::getInstance().push_back(ai,
				WheelData_::getInstance().getOverride(ai)
				);
		}
		break;
	default:
		WinData::getInstance().push_back(animal,  WheelData_::getInstance().getOverride(animal));
	}


	//BlackBoardSystem::getInstance().write(WheelEnum::WHEELMSG_STR,static_cast<int>(mode));

	int second = buffer.at(6) ;
	BlackBoardSystem::getInstance().write(WheelEnum::SETTIME_STR, static_cast<int>(second));

}
static void  toRate(const MsgBuffer & buffer)
{
	WheelData_::getInstance().setRate(Orz::WheelEnum::RATE(buffer.at(3)));
	//	BlackBoardSystem::getInstance().write(WheelEnum::RATE_STR,static_cast<int>(buffer.at(3)) );
}


static void  toSetup(const MsgBuffer & buffer)
{

	SetupInfoPtr setup;
	if(BlackBoardSystem::getInstance().has(WheelEnum::SETUP_STR))
	{
		setup = BlackBoardSystem::getInstance().read<SetupInfoPtr>(WheelEnum::SETUP_STR);
	}
	else
	{
		setup.reset(new SetupInfo());
		BlackBoardSystem::getInstance().write(WheelEnum::SETUP_STR, setup);
	}

	for(int i = 0; i<9; ++i)
	{
		(*setup)[i] = buffer.at(3+i);
	}

}

static void  toReport(const MsgBuffer & buffer)
{

	std::string report;
	for(size_t i = 3; i<buffer.size(); ++i)
	{
		report.push_back('0'+ buffer.at(i));
		if( (i-2)%8 == 0 )
			report.push_back(',');
	}

	BlackBoardSystem::getInstance().write<std::string>(WheelEnum::REPORT_STR, report);

}
void WheelEngine::toEvent(MsgBuffer & buffer)
{
	//ORZ_LOG_NOTIFICATION<<'['<<toString(buffer)<<']';

	EventChannel channel = EventChannel::create().addUserChannel<CHANNEL_INTERNAL>();

	Event * evt = NULL;
	switch(buffer.at(2))
	{
	case ASK_TIME:
		{
			evt = WheelEvents::createEvent(WheelEvents::ASK_TIME);
			break;
		}
	case HOW_WINNER:
		{
			toWinner(buffer);
			evt = WheelEvents::createEvent(WheelEvents::HOW_WINNER);
			channel.addUserChannel<CHANNEL_PROCESS>();
			break;


		}
	case ASK_STATE:
		{
			evt = WheelEvents::createEvent(WheelEvents::ASK_STATE);
			break;
		}
	case COME_IN_MENU:
		{
			_acc.clear();
			evt = WheelEvents::createEvent(WheelEvents::COME_IN_MENU);
			break;
		}
	case DATA_MENU:
		{
			Msg2Account m2a(&_acc);
			if(m2a.push_msg(buffer) && _acc.isComplete())
			{
				evt = WheelEvents::createEvent(WheelEvents::DATA_MENU);
			}
			break;
		}
	case GO_OUT_MENU:
		{
			evt = WheelEvents::createEvent(WheelEvents::GO_OUT_MENU);
			break;
		}
	case SET_MODE:
		{
			toRate(buffer);
			evt = WheelEvents::createEvent(WheelEvents::SET_MODE);
			channel.addUserChannel<CHANNEL_PROCESS>();
			break;
		}
	case HARDWARE_RETURN1:
	case HARDWARE_RETURN2:
		{
			evt = WheelEvents::createEvent(WheelEvents::HARDWARE_RETURN);
			if(buffer.at(3) == 0)
			{
				evt->setData<bool>(false);
			}
			else
			{
				evt->setData<bool>(true);
			}
			break;
		}	

	case COME_IN_SETUP:
		{
			toSetup(buffer);
			evt = WheelEvents::createEvent(WheelEvents::COME_IN_SETUP);
			break;

		}
	case REPORT:
		{
			toReport(buffer);
			evt = WheelEvents::createEvent(WheelEvents::TO_SETUP);
			channel.addUserChannel<CHANNEL_PROCESS>();
			break;
			///!!!

			//Orz::WheelUI::getSingleton().bao_zhang_ma(n);
			//return true;
		}
	case RESET_GAME:
		{
			evt = WheelEvents::createEvent(WheelEvents::RESET_GAME);
			break;
		}

	case KEY_F4:
		{
			evt = WheelEvents::createEvent(WheelEvents::KEY_F4);
			break;
		}
	case KEY_F5:
		{
			evt = WheelEvents::createEvent(WheelEvents::KEY_F4);
			break;
		}
	case KEY_F6:
		{
			evt = WheelEvents::createEvent(WheelEvents::KEY_F4);
			break;
		}
	}
	if(evt)
	{

		evt->setChannel(channel);
		_world->broadcasting(evt);
	}
}
