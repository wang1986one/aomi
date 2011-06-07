
#include "WheelGobalStableHeaders.h"

#include "WheelGameUIRegister.h"
#include "WheelUIInterface.h"
using namespace Orz;
template<> WheelGameUIRegister* Singleton<WheelGameUIRegister>::_singleton = NULL;
WheelGameUIRegister::~WheelGameUIRegister(void)
{

}


		
WheelGameUIRegister::WheelGameUIRegister(void):_ui(new WheelNullUI())
{
}


void WheelGameUIRegister::active(WheelUIInterfacePtr ui)
{

	deactive(_ui);
	if(!ui)
	{
		ui.reset(new WheelNullUI());
	}
	_ui = ui;
	
}
void WheelGameUIRegister::deactive(WheelUIInterfacePtr ui)
{

	if(_ui == ui)
	{
		_ui.reset();
	}
}


void WheelGameUIRegister::setTheTime(int second)
{
	_ui->setTheTime(second);
}
void WheelGameUIRegister::setStartVisible(bool visible)
{
	_ui->setStartVisible(visible);
}
void WheelGameUIRegister::setEndVisible(bool visible)
{
	_ui->setEndUIVisible(visible);
}
void WheelGameUIRegister::setLogoShow(bool visible)
{
	_ui->setLogoShow(visible);
}
void WheelGameUIRegister::addBottom(void)
{
	_ui->addBottom();
}
void WheelGameUIRegister::runWinner(void)
{
	_ui->runWinner();
}


void WheelGameUIRegister::update(TimeType i)
{
	_ui->update(i);
}