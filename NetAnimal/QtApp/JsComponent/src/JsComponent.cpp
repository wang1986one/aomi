#include "JsComponentStableHeaders.h"
#include "JsComponent.h"

using namespace Orz;

JsComponent::JsComponent(void):_jsInterface(new JsInterface())
{
	_query.add(_jsInterface.get());
}
JsComponent::~JsComponent(void)
{
	
}
ComponentInterface * JsComponent::_queryInterface(const TypeInfo & info)
{
	return _query.queryInterface(info);
}