#ifndef __Orz_SetupDataLogic_h__
#define __Orz_SetupDataLogic_h__	

#include "WheelLogic.h"
#include "TasksManager.h"
#include "GameLogic.h"
#include "WheelAnimalProcess.h"
#include "F5TableInterface.h"
namespace Orz
{

		
	class SetupData
	{

	public:	
		SetupData():_f5table(NULL), _communicate(NULL)
		{

			_tableComp = Orz::ComponentFactories::getInstance().create("Table");
		}
		~SetupData(void)
		{

		}

		void init(WheelGame * game)
		{
			assert(game);
			_communicate = game->getHardware()->queryInterface<CommunicateInterface>();
			_f5table = _tableComp->queryInterface<F5TableInterface>();
			_f5table->load();
		}
		void exit(void)
		{
			_f5table->save();
		}
		bool send(Orz::CommunicateInterface::PanelID id)
		{
			
			


			CommunicateInterface::Data data;

			data.setData(CommunicateInterface::SETUP_TMS, _f5table->getData(Orz::F5TableInterface::ID(id), F5TableInterface::TMS));
			data.setData(CommunicateInterface::SETUP_ZZF, _f5table->getData(Orz::F5TableInterface::ID(id), F5TableInterface::ZZF));
			data.setData(CommunicateInterface::SETUP_ZYF, _f5table->getData(Orz::F5TableInterface::ID(id), F5TableInterface::ZYF));
			data.setData(CommunicateInterface::SETUP_ZKF, _f5table->getData(Orz::F5TableInterface::ID(id), F5TableInterface::ZKF));
			data.setData(CommunicateInterface::SETUP_ZXF, _f5table->getData(Orz::F5TableInterface::ID(id), F5TableInterface::ZXF));
			data.setData(CommunicateInterface::SETUP_ZTOB, _f5table->getData(Orz::F5TableInterface::ID(id), F5TableInterface::ZTOB));
			data.setData(CommunicateInterface::SETUP_ZTUB, _f5table->getData(Orz::F5TableInterface::ID(id), F5TableInterface::ZTUB));
			data.setData(CommunicateInterface::SETUP_WHAT, 0);

			_communicate->setupData(id, data);


			return false;

		}
		bool receive(CommunicateInterface::PackagePtr package, Orz::CommunicateInterface::PanelID id)
		{

			return (package->getId() == id); 
		}
	private:
		Orz::ComponentPtr _tableComp;
		F5TableInterface * _f5table;// = _f6table->queryInterface<F6TableInterface>();
		CommunicateInterface * _communicate;
	};
	class GameLogic;

	//×°ÅÌµÄÐý×ª
	//template<class Father, class Next, class Handle>
	class SetupDataLogic : public FSM::LogicAdv<SetupDataLogic, WheelLogic>  //public FSM::LogicAdv<SetupDataLogic, Father>
	{
	public:

		enum MyState
		{
			Send,
			Receive,
			Over,
		};

		typedef boost::mpl::list< sc::custom_reaction< UpdateEvt > > reactions;
		SetupDataLogic(my_context ctx):LogicAdv(ctx),_waitTime(0.2f),_time(0.f)
		{
			CommunicateInterface * communicate = getOwner()->getHardware()->queryInterface<CommunicateInterface>();

			_hardware = getOwner()->getHardware()->queryInterface<WMHardwareInterface>();
			_connection = communicate->receiveSubscribe(boost::bind(&SetupDataLogic::receive, this, _1));
			_it = _hardware->getIdSet().begin();
			if(_it != _hardware->getIdSet().end())
			{
				_state = Send;
			}else
			{
				_state = Over;
			}
			
			
			_handle.init(getOwner());
		}
		~SetupDataLogic(void)
		{

		}
		sc::result react(const UpdateEvt & evt)
		{
			if(_state == Over)
				return transit<GameLogic>();

			if(_state == Send)
			{

			//	CommunicateInterface * communicate = getOwner()->getHardware()->queryInterface<CommunicateInterface>();
				if(_handle.send(/*communicate,*/ *_it))
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
			//CommunicateInterface * communicate = getOwner()->getHardware()->queryInterface<CommunicateInterface>();
			_handle.exit(/*communicate*/);
			_connection.disconnect();

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
		SetupData _handle;

		boost::signals2::connection _connection;
		WMHardwareInterface::IdSet::const_iterator _it;
		WMHardwareInterface * _hardware;
		MyState _state;
		const TimeType _waitTime;
		TimeType _time;

	};

	

}
#endif