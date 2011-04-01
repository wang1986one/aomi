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
	_enableButton(enable);
}

boost::signals2::connection Js::subscribeEnableButton(const JsInterface::EnableButtonSignalType::slot_type &subscriber)
{
	return _enableButton.connect(subscriber);
}






void Js::setTime(int time)
{
	std::cout<<"??"<<time<<std::endl;
	_setTime(time);
}

boost::signals2::connection Js::subscribeSetTime(const JsInterface::SetTimeSignalType::slot_type &subscriber)
{
	return _setTime.connect(subscriber);
}




void Js::askPanelData(void)
{
	_askPanelData();
}

boost::signals2::connection Js::subscribeAskPanelData(const JsInterface::AskPanelDataSignalType::slot_type &subscriber)
{
	return _askPanelData.connect(subscriber);
}

void Js::postPanelData(JsInterface::ButtonId id, size_t num)
{
	_postPanelDataSignal(id, num);
}
boost::signals2::connection Js::subscribePostPanelData(const GameInterface<0>::PostPanelDataSignalType::slot_type &subscriber)
{
	return _postPanelDataSignal.connect(subscriber);
}





void Js::addProfit(int profit)
{
	_addProfit(profit);
}
boost::signals2::connection Js::subscribeAddProfit(const JsInterface::AddProfitSignalType::slot_type &subscriber)
{
	return _addProfit.connect(subscriber);
}

void Js::setProfit(int profit)
{
	_setProfit(profit);
}
boost::signals2::connection Js::subscribeSetProfit(const JsInterface::SetProfitSignalType::slot_type &subscriber)
{
	return _addProfit.connect(subscriber);
}

void Js::rollProfit(void)
{
	_rollProfit();
}
boost::signals2::connection Js::subscribeRollProfit(const JsInterface::RollProfitSignalType::slot_type &subscriber)
{
	return _rollProfit.connect(subscriber);
}



void Js::setWinner(JsInterface::ButtonId id, int profit)
{
	_setWinner(id, profit);
}
boost::signals2::connection Js::subscribeSetWinner(const JsInterface::SetWinnerSignalType::slot_type &subscriber)
{
	return _setWinner.connect(subscriber);
}