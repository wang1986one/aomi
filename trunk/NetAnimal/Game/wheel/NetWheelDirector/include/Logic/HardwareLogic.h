#ifndef __Orz_HardwareLogic_h__
#define __Orz_HardwareLogic_h__	

#include "WheelLogic.h"
#include "TasksManager.h"
#include "GameLogic.h"
#include "WheelAnimalProcess.h"
namespace Orz
{

	//×°ÅÌµÄÐý×ª
	template<class Father, class Next, class Handle>
	class HardwareLogic: public FSM::LogicAdv<HardwareLogic<Father, Next, Handle>, Father>
	{
	public:

		enum NetState
		{
			Send,
			Receive,
			Over,
		};

		typedef boost::mpl::list< sc::custom_reaction< UpdateEvt > > reactions;
		HardwareLogic(my_context ctx):LogicAdv(ctx),_waitTime(0.2f),_time(0.f)
		{
			CommunicateInterface * communicate = getOwner()->getHardware()->queryInterface<CommunicateInterface>();

			_hardware = getOwner()->getHardware()->queryInterface<WMHardwareInterface>();
			_connection = communicate->receiveSubscribe(boost::bind(&HardwareLogic<Father, Next, Handle>::receive, this, _1));
			_it = _hardware->getIdSet().begin();
			if(_it != _hardware->getIdSet().end())
			{
				_state = Send;
			}else
			{
				_state = Over;
			}
			
			context<GameLogic>().stopQueryId();
			
			_handle.init(getOwner());
		}
		~HardwareLogic(void)
		{

		}
		sc::result react(const UpdateEvt & evt)
		{
			if(_state == Over)
				return transit<Next>();

			if(_state == Send)
			{

				if(_handle.send(*_it))
				{
					
					_state = Receive;
					_time = 0.f;
				}
				else
				{
					
					_it++;
					if(_it != _hardware->getIdSet().end())
					{
						_state = Send;
					}
					else
					{
						_state = Over;
					}
				}
			}else if(_state == Receive)
			{
				_time += evt.getInterval();
				if(_time >= _waitTime)
				{
					if(_it != _hardware->getIdSet().end())
					{
						_state = Send;
					}
					else
					{
						_state = Over;
					}
				}
			}

			return forward_event();
		}



		void exit(void)
		{
			_handle.exit();
			_connection.disconnect();
			context<GameLogic>().startQueryId();
		}



		void receive(CommunicateInterface::PackagePtr package)
		{
			
			if(_state == Receive && _handle.receive(package, *_it))
			{
				_it++;
				if(_it != _hardware->getIdSet().end())
				{
					_state = Send;
				}
				else
				{
					_state = Over;
				}
			}
		}
	private:
		Handle _handle;

		boost::signals2::connection _connection;
		WMHardwareInterface::IdSet::const_iterator _it;
		WMHardwareInterface * _hardware;
		NetState _state;
		const TimeType _waitTime;
		TimeType _time;

	};

	
class GameOver
{

public:	
	GameOver(void):_communicate(NULL)
	{

	}
	~GameOver(void)
	{

	}
	bool send(Orz::CommunicateInterface::PanelID id)
	{
		_communicate->over(id);
		return false;

	}
	bool receive(CommunicateInterface::PackagePtr package, Orz::CommunicateInterface::PanelID id)
	{
		return (package->getId() == id); 
	}
	void init(WheelGame * game)
	{
		assert(game);
		_communicate = game->getHardware()->queryInterface<CommunicateInterface>();
	}
	void exit(){}
private:
	CommunicateInterface * _communicate;
};

}
#endif