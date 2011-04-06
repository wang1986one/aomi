#include "JsComponentStableHeaders.h"
#include "JsComponent.h"
#include "Js.h"

using namespace Orz;

JsComponent::JsComponent(void):_jsInterface(new JsInterface()), _gameInterface(new GameInterface<0>())
{
	_query.add(_jsInterface.get());
	_query.add(_gameInterface.get());

	_jsInterface->subscribeEnableButton = boost::bind(&Js::subscribeEnableButton, Js::getInstancePtr(), _1);
	_gameInterface->setButtonEnable = boost::bind(&Js::setButtonEnable, Js::getInstancePtr(), _1);


	

	_jsInterface->subscribeSetTime = boost::bind(&Js::subscribeSetTime, Js::getInstancePtr(), _1);
	_gameInterface->setTime = boost::bind(&Js::setTime, Js::getInstancePtr(), _1);

	

	_jsInterface->subscribeAskPanelData = boost::bind(&Js::subscribeAskPanelData, Js::getInstancePtr(), _1);
	_gameInterface->askPanelData = boost::bind(&Js::askPanelData, Js::getInstancePtr());


	
	_gameInterface->subscribePostPanelData = boost::bind(&Js::subscribePostPanelData, Js::getInstancePtr(), _1);
	_jsInterface->postPanelData = boost::bind(&Js::postPanelData, Js::getInstancePtr(), _1, _2);

	
	_jsInterface->subscribeAddProfit = boost::bind(&Js::subscribeAddProfit, Js::getInstancePtr(), _1);
	_gameInterface->addProfit = boost::bind(&Js::addProfit, Js::getInstancePtr(), _1);

	
	_jsInterface->subscribeSetProfit = boost::bind(&Js::subscribeSetProfit, Js::getInstancePtr(), _1);
	_gameInterface->setProfit = boost::bind(&Js::setProfit, Js::getInstancePtr(), _1);

	
	_jsInterface->subscribeRollProfit = boost::bind(&Js::subscribeRollProfit, Js::getInstancePtr(), _1);
	_gameInterface->rollProfit = boost::bind(&Js::rollProfit, Js::getInstancePtr());


	_jsInterface->subscribeSetWinner = boost::bind(&Js::subscribeSetWinner, Js::getInstancePtr(), _1);
	_gameInterface->setWinner = boost::bind(&Js::setWinner, Js::getInstancePtr(), _1, _2);


	





}
JsComponent::~JsComponent(void)
{
	
}
ComponentInterface * JsComponent::_queryInterface(const TypeInfo & info)
{
	return _query.queryInterface(info);
}