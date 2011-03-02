#ifndef __Orz_Number__
#define __Orz_Number__
//#include <boost/multi_array.hpp>
//#include <iostream>
//#include <CEGUI/cegui.h>
//#include "WheelEnum.h"
//#include "UIAnimation.h"
#include <WheelGobal/WheelEnum.h>
namespace Orz
{
	class Number
	{
		
	public:
		Number(void)
		{
			
		}
		void show(int num)
		{
			std::vector<CEGUI::Window *>::iterator it;

			for(it = _windows.begin(); it != _windows.end(); ++it)
			{
				(*it)->setProperty("Image", _numbers[num%10]);
				num/=10;
			}
		}
		~Number(void)
		{

		}
		void push_back(CEGUI::Window * window)
		{
			_windows.push_back(window);
		}

		void setFigure(int i, const std::string & figure)
		{
			_numbers[i] = figure;
		}
	private:
		std::vector<CEGUI::Window *> _windows;
		boost::array<std::string, 10> _numbers;
	};
}


#endif