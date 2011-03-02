#include "WheelAnimalControllerStableHeaders.h"
#include "Bonus.h"

using namespace Orz;

Bonus::Bonus(void):_time(0.f),_bonus(0)
{
	_number.push_back(CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Caijinoutlineborder/num/0"));
	_number.push_back(CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Caijinoutlineborder/num/1"));
	_number.push_back(CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Caijinoutlineborder/num/2"));
	_number.push_back(CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Caijinoutlineborder/num/3"));
	_number.push_back(CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Caijinoutlineborder/num/4"));
	_number.setNumber(0,"set:AnimalUIEX image:Topcaijinnum0");
	_number.setNumber(1,"set:AnimalUIEX image:Topcaijinnum1");
	_number.setNumber(2,"set:AnimalUIEX image:Topcaijinnum2");
	_number.setNumber(3,"set:AnimalUIEX image:Topcaijinnum3");
	_number.setNumber(4,"set:AnimalUIEX image:Topcaijinnum4");
	_number.setNumber(5,"set:AnimalUIEX image:Topcaijinnum5");
	_number.setNumber(6,"set:AnimalUIEX image:Topcaijinnum6");
	_number.setNumber(7,"set:AnimalUIEX image:Topcaijinnum7");
	_number.setNumber(8,"set:AnimalUIEX image:Topcaijinnum8");
	_number.setNumber(9,"set:AnimalUIEX image:Topcaijinnum9");
}
Bonus::~Bonus(void)
{

}

void Bonus::update(TimeType i)
{
	_time+=i;
	while(_time > 0.2f)
	{
		_time-=0.2f;
		if(_bonus == 0)
			_number.show(rand()%18000 + 2000);
		else
			_number.show(_bonus);
	}
}
void Bonus::setBonus(int bonus)
{
	_bonus = bonus;
}
void Bonus::clear(void)
{
	_bonus = 0;
}
