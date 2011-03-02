#include "WheelAnimalControllerStableHeaders.h"
#include "LightRunning.h"

#include <orz/Toolkit_Base/Clock.h>
#include "WinData.h"
using namespace Orz;
Clock<TimeType> ck;




LightRunning::LightRunning(boost::shared_ptr<ObjectLights> lights):_lights(lights),_tick(-1)
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
	if(_allTime >= 106.f )
	{
		_running = false;
		return false;
	}
	if(_tick != int(_allTime))
	{
		_tick = int(_allTime);
		if(_tick < 48)
		{
			if(_tick %2 == 0)
			{
				
				_lights->setLightLiang(_tick/2);
					
			}else
			{
				
				_lights->setLight(_tick/2);
			}
		}
		else if(_tick < 96)
		{
			
			_lights->setTable((_tick/2)-24);
		}
	}

	/*if(_tick2 != int(_allTime - 0.5))
	{
		_tick2 = int(_allTime + 0.5);
		if(_tick2 < 24)
			_lights->setLightLiang(_tick2);
		
	}*/
	
	_allTime+=interval * 16;		  
	return true;

}

void LightRunning::init(void)
{
	_allTime = 0.f;
	_tick = 0;
	_running =false;

	for(int i =0; i<24; ++i)
	{
		
		_lights->setTableAn(i);
	}
	for(int i =0; i<24; ++i)
	{
		
		_lights->setLightAn(i);
	}
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

	srand(ck.elapsed() *100.f);

	WinData::SecondWinnerList * list =  Orz::WinData::getInstance().getSecondWinnerList();
	if(list)
	{
		BOOST_FOREACH(WinData::SecondWinner sw, *list)
		{
			_lights->push(sw.second, sw.first);
			switch(sw.second)
			{
			case WheelEnum::Green:
				--green;
				break;
			case WheelEnum::Yellow:
				--yellow;
				break;
			case WheelEnum::Red:
				--red;
				break;
			}
		}
		//list->
	}
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