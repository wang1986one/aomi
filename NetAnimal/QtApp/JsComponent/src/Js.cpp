#include "JsComponentStableHeaders.h"
#include "Js.h"

using namespace Orz;


Js::Js(void)
{

}
Js::~Js(void)
{

}

Js & Js::getInstance(void)
{
	return *(getInstancePtr());
}
Js * Js::getInstancePtr(void)
{
	static Js instance;
	return &instance;
}



void Js::setButtonEnable(bool enable)
{
	_enableButtonSignal(enable);
}

boost::signals2::connection Js::subscribeEnableButton(const JsInterface::EnableButtonSignalType::slot_type &subscriber)
{
	return _enableButtonSignal.connect(subscriber);
}






void Js::setTime(int time)
{
	_setTimeSignal(time);
}

boost::signals2::connection Js::subscribeSetTime(const JsInterface::SetTimeSignalType::slot_type &subscriber)
{
	return _setTimeSignal.connect(subscriber);
}


