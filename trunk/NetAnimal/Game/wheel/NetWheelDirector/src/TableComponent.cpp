#include "NetWheelDirectorStableHeaders.h"

#include "TableComponent.h"
#include "F5TableInterface.h"
#include "F6TableInterface.h"

#include "F5Table.h"
#include "F6Table.h"
using namespace Orz;

TableComponent::~TableComponent(void)
{

}
TableComponent::TableComponent(void):_f5TableInterface(new F5TableInterface()),_f6TableInterface(new F6TableInterface())
{
	
	_f5TableInterface->getData = boost::bind(&F5Table::getData, F5Table::getInstancePtr(), _1, _2);
	
	_f5TableInterface->setData= boost::bind(&F5Table::setData, F5Table::getInstancePtr(), _1, _2, _3);
	
	_f5TableInterface->save =  boost::bind(&F5Table::save, F5Table::getInstancePtr());
	_f5TableInterface->load =  boost::bind(&F5Table::load, F5Table::getInstancePtr());
	_f5TableInterface->clear =  boost::bind(&F5Table::clear, F5Table::getInstancePtr());


	_f5TableInterface->isClear =  boost::bind(&F5Table::isClear, F5Table::getInstancePtr());
	_f5TableInterface->updateClear =  boost::bind(&F5Table::updateClear, F5Table::getInstancePtr());



	
	//
	//_f5TableInterface->costZXHScore = boost::bind(&Table::costZXHScore, Table::getInstancePtr(), _1, _2);
	//_f5TableInterface->earnZXHScore = boost::bind(&Table::earnZXHScore, Table::getInstancePtr(), _1, _2);

	_f5TableInterface->refreshSigConnection = boost::bind(&F5Table::refreshSigConnection, F5Table::getInstancePtr(), _1);
	

	_f6TableInterface->setDataIndex =  boost::bind(&F6Table::setDataIndex, F6Table::getInstancePtr(), _1, _2);
	_f6TableInterface->getDataIndex =  boost::bind(&F6Table::getDataIndex, F6Table::getInstancePtr(), _1);
	_f6TableInterface->getData =  boost::bind(&F6Table::getData, F6Table::getInstancePtr(), _1);

	
	_f6TableInterface->save =  boost::bind(&F6Table::save, F6Table::getInstancePtr());
	_f6TableInterface->load =  boost::bind(&F6Table::load, F6Table::getInstancePtr());

	_query.add(_f5TableInterface.get());
	_query.add(_f6TableInterface.get());
}

