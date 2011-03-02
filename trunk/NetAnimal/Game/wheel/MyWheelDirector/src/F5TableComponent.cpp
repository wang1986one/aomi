#include "MyWheelDirectorStableHeaders.h"

#include "F5TableComponent.h"
#include "F5TableInterface.h"
#include "F6TableInterface.h"
#include "F5Table.h"
using namespace Orz;

F5TableComponent::~F5TableComponent(void)
{

}
F5TableComponent::F5TableComponent(void):_f5TableInterface(new F5TableInterface()),_f6TableInterface(new F6TableInterface())
{
	
	_f5TableInterface->getData = boost::bind(&F5Table::getData, F5Table::getInstancePtr(), _1, _2);
	
	_f5TableInterface->setData= boost::bind(&F5Table::setData, F5Table::getInstancePtr(), _1, _2, _3);

	_f5TableInterface->pushCoin = boost::bind(&F5Table::pushCoin, F5Table::getInstancePtr(), _1, _2);
	_f5TableInterface->popCoin = boost::bind(&F5Table::popCoin, F5Table::getInstancePtr(), _1, _2);
	_f5TableInterface->pushScore = boost::bind(&F5Table::pushScore, F5Table::getInstancePtr(), _1, _2);
	_f5TableInterface->popScore = boost::bind(&F5Table::popScore, F5Table::getInstancePtr(), _1, _2);
	_f5TableInterface->setCoin2Score = boost::bind(&F5Table::setCoin2Score, F5Table::getInstancePtr(), _1);
	_f5TableInterface->getCoin2Score = boost::bind(&F5Table::getCoin2Score, F5Table::getInstancePtr());
	_f5TableInterface->costScore = boost::bind(&F5Table::costScore, F5Table::getInstancePtr(), _1, _2);
	_f5TableInterface->earnScore = boost::bind(&F5Table::earnScore, F5Table::getInstancePtr(), _1, _2);

	
	_f5TableInterface->costZXHScore = boost::bind(&F5Table::costZXHScore, F5Table::getInstancePtr(), _1, _2);
	_f5TableInterface->earnZXHScore = boost::bind(&F5Table::earnZXHScore, F5Table::getInstancePtr(), _1, _2);

	_f5TableInterface->refreshSigConnection = boost::bind(&F5Table::refreshSigConnection, F5Table::getInstancePtr(), _1);
	_f5TableInterface->getBounsPool =  boost::bind(&F5Table::getBounsPool, F5Table::getInstancePtr());
	_f5TableInterface->setBounsPoolOut =  boost::bind(&F5Table::setBounsPoolOut, F5Table::getInstancePtr(), _1);




	_f5TableInterface->getPrizePool =  boost::bind(&F5Table::getPrizePool, F5Table::getInstancePtr());
	_f5TableInterface->setPrizePoolOut =  boost::bind(&F5Table::setPrizePoolOut, F5Table::getInstancePtr(), _1);
	_f5TableInterface->pushCoinPool =  boost::bind(&F5Table::pushCoinPool, F5Table::getInstancePtr(), _1);

	_f6TableInterface->setDataIndex =  boost::bind(&F5Table::setDataIndex, F5Table::getInstancePtr(), _1, _2);
	_f6TableInterface->getDataIndex =  boost::bind(&F5Table::getDataIndex, F5Table::getInstancePtr(), _1);
	_f6TableInterface->getData =  boost::bind(&F5Table::getData, F5Table::getInstancePtr(), _1);

	
	_f6TableInterface->save =  boost::bind(&F5Table::f6Save, F5Table::getInstancePtr());
	_f6TableInterface->load =  boost::bind(&F5Table::f6Load, F5Table::getInstancePtr());

	_query.add(_f5TableInterface.get());
	_query.add(_f6TableInterface.get());
}

ComponentInterface * F5TableComponent::_queryInterface(const TypeInfo & info)
{
	return _query.queryInterface(info);
}

