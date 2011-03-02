#include "WheelAnimalControllerStableHeaders.h"
#include "LightRunning.h"

#include <orz/Toolkit_Base/Clock.h>
using namespace Orz;
Clock<TimeType> ck;




LightRunning::LightRunning(boost::shared_ptr<ObjectLights> lights):_lights(lights)
{
	init();
}
ObjectLights * LightRunning::getLights(void)
{
	return _lights.get();
}

bool LightRunning::update(TimeType interval/*, WheelAnimalSceneObj * scene*/)
{
	if(!_running)
		return false;
	if(_allTime >= 30.f )
	{
		_running= false;
		return false;
	}
	if(int(_allTime) <= 23)
		_lights->setLight(int(_allTime));

	_allTime+=interval * 8;		  
	return true;

}

void LightRunning::init(void)
{
	_allTime = 0.f;

	_running =false;
	_lights->_init();
}


void LightRunning::setMode(WheelEnum::RATE mode)
{
	init();
	std::pair<int, int> green_blue = getYellowGreen(mode);
	const int green = green_blue.first;
	const int blue = green_blue.second;
	assert(green + blue <= 24);
	
	srand(ck.elapsed() *100.f);
	for(int g = green; g>0; --g)
	{
		_lights->push_random(WheelEnum::Yellow, WheelEnum::Red);
	}


	for(int b = blue; b>0; --b)
	{
		_lights->push_random(WheelEnum::Green, WheelEnum::Red);
	}

	_running = true;
}
std::pair<int, int> LightRunning::getYellowGreen(WheelEnum::RATE mode)
{
	switch(mode)
	{
	case WheelEnum::MODE0:
		return	std::make_pair(6,8);
	case WheelEnum::MODE1:
		return	std::make_pair(7,7);
	case WheelEnum::MODE2:
		return	std::make_pair(8,6);
	case WheelEnum::MODE3:
		return	std::make_pair(7,8);
	case WheelEnum::MODE4:
		return	std::make_pair(8,7);
	case WheelEnum::MODE5:
		return	std::make_pair(7,7);
	}
	return	std::make_pair(7,7);
}