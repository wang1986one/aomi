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


}
JsComponent::~JsComponent(void)
{
	
}
ComponentInterface * JsComponent::_queryInterface(const TypeInfo & info)
{
	return _query.queryInterface(info);
}