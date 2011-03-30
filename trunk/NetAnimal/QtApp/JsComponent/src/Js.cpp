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
	std::cout<<"??"<<time<<std::endl;
	_setTimeSignal(time);
}

boost::signals2::connection Js::subscribeSetTime(const JsInterface::SetTimeSignalType::slot_type &subscriber)
{
	return _setTimeSignal.connect(subscriber);
}




void Js::askPanelData(void)
{
	_askPanelDataSignal();
}

boost::signals2::connection Js::subscribeAskPanelData(const JsInterface::AskPanelDataSignalType::slot_type &subscriber)
{
	return _askPanelDataSignal.connect(subscriber);
}

void Js::postPanelData(JsInterface::ButtonId id, size_t num)
{
	_postPanelDataSignal(id, num);
}
boost::signals2::connection Js::subscribePostPanelData(const GameInterface<0>::PostPanelDataSignalType::slot_type &subscriber)
{
	return _postPanelDataSignal.connect(subscriber);
}

//AskPanelDataSignalType
//typedef boost::function<boost::signals2::connection  (const EnableButtonSignalType::slot_type &subscriber)> SubscribeAskPanelData;