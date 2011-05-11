
#include "MyWheelDirectorStableHeaders.h"

#include "logic/AllLogic.h"


#include "logic/LogoLogic.h"
#include "F5TableInterface.h"
using namespace Orz;

void GameLogic::receive(CommunicateInterface::PackagePtr package)
{
	if(package->getFunction() == CommunicateInterface::QueryData)
	{



		F5TableInterface * table = _table->queryInterface<F5TableInterface>();
		if(package->hasLongData(8))
			table->setData(F5TableInterface::ID(package->getId()), F5TableInterface::TMS, package->getLongData(8));

		if(package->hasLongData (2))
			table->setData(F5TableInterface::ID(package->getId()), F5TableInterface::ZKF, package->getLongData(1));

		if(package->hasLongData(3))
			table->setData(F5TableInterface::ID(package->getId()), F5TableInterface::ZXF, package->getLongData(2));

		if(package->hasLongData(4))
			table->setData(F5TableInterface::ID(package->getId()), F5TableInterface::ZTOB, package->getLongData(3));

		if(package->hasLongData(5))
			table->setData(F5TableInterface::ID(package->getId()), F5TableInterface::ZTUB, package->getLongData(4));

		if(package->hasLongData(6))
			table->setData(F5TableInterface::ID(package->getId()), F5TableInterface::ZYF, package->getLongData(5));

		if(package->hasLongData(7))
			table->setData(F5TableInterface::ID(package->getId()), F5TableInterface::ZZF, package->getLongData(6));

		table->save();
	}
	

}

GameLogic::GameLogic(my_context ctx):LogicAdv(ctx),_isQueryId(false),_id(CommunicateInterface::Panel1), _distance(1.0f)
{

	_commuicate = getOwner()->getHardware()->queryInterface<CommunicateInterface>();
	_connection = _commuicate->receiveSubscribe(boost::bind(&GameLogic::receive, this, _1));
	_table = Orz::ComponentFactories::getInstance().create("Table");
	startQueryId();
}
GameLogic::~GameLogic(void)
{

}


void GameLogic::startQueryId(void)
{
	_commuicate->notifyState(CommunicateInterface::State1);
	_isQueryId = true;
	_id = CommunicateInterface::Panel1;
	_time = 0.f;
}
void GameLogic::stopQueryId(void)
{
	_isQueryId = false;
}


sc::result GameLogic::react(const UpdateEvt & evt)
{

	
	if(_isQueryId)
	{
		_time += evt.getInterval();
		if(_time > _distance)
		{
			_time = 0.f;
			_commuicate->queryId(static_cast<CommunicateInterface::PanelID>(_id));
			_id++;
			if(_id == CommunicateInterface::PanelEnd)
				_id = CommunicateInterface::Panel1;
		}
	}
	return forward_event();
}

void GameLogic::exit(void)
{
	stopQueryId();
	_connection.disconnect();
}