#include "WheelAnimalControllerStableHeaders.h"
#include "LightRunning.h"

#include <orz/Toolkit_Base/Clock.h>
#include "WinData.h"
using namespace Orz;




LightRunning::LightRunning(boost::shared_ptr<ObjectLights> lights):_lights(lights),_tick(-1)
{
	init();
	for(int i = 0; i<24; i++)
	{
		_actionList.push_back(std::make_pair(0.1f *i,boost::bind(&ObjectLights::setLightLiang, _lights.get(), i)));
		_actionList.push_back(std::make_pair(((0.1f *i) + 0.1f),boost::bind(&ObjectLights::setLight, _lights.get(), i)));
	}
}
ObjectLights * LightRunning::getLights(void)
{
	return _lights.get();
}

bool LightRunning::update(TimeType interval/*, WheelAnimalSceneObj * scene*/)
{
	if( _it == _actionList.end())
		return false;

	_allTime+=interval;
	while(_it->first <=_allTime)
	{
		_it->second();
		++_it;
		if( _it == _actionList.end())
			return false;
	}
		  
	return true;

}

void LightRunning::init(void)
{
	_allTime = 0.f;
	_tick = 0;
	_running =false;


	_it = _actionList.begin();

	/*for(int i =0; i<24; ++i)
	{*/

	_lights->closeTable();
	//}
	//for(int i =0; i<24; ++i)
	//{

	_lights->closeLight();
	//}
	_lights->clear();
}


void LightRunning::setMode(WheelEnum::RATE mode)
{
	init();
	std::pair<int, int> green_blue = getYellowGreen(mode);
	int yellow = green_blue.first;
	int green = green_blue.second;
	int red = 24 - (green+yellow);
	assert(green + yellow <= 24);

	//srand(ck.elapsed() *100.f);

	for(int y = yellow; y>0; --y)
	{
		_lights->push(WheelEnum::Yellow);
	}


	for(int g = green; g>0; --g)
	{
		_lights->push(WheelEnum::Green);
	}


	
	for(int r = red; r>0; --r)
	{
		_lights->push(WheelEnum::Red);
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