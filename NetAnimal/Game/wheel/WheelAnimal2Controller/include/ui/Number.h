#ifndef __Orz_Number__
#define __Orz_Number__
#include <CEGUI/cegui.h>

namespace Orz
{
	class Number
	{
	public:
		Number()
		{

		}
		~Number(void)
		{

		}
		void push_back(CEGUI::Window * win)
		{
			_windows.push_back(win);
		}
		void setNumber(int i, const std::string & image)
		{
			_numbers[i] = image;
		}
		void show(int i)
		{

			WindowsType::iterator it;

			for(it = _windows.begin(); it != _windows.end(); ++it)
			{

				(*it)->setProperty("Image", _numbers[i%10]);

				//if(WinData::getInstance().getWinMode() == WheelEnum::ONE||
				//	WinData::getInstance().getWinMode() == WheelEnum::TWO||
				//	WinData::getInstance().getWinMode() == WheelEnum::THREE||
				//	WinData::getInstance().getWinMode() == WheelEnum::FOUR||
				//	WinData::getInstance().getWinMode() == WheelEnum::FIVE)
				//{
				//	if(i<100 && it == _windows.begin()+(_windows.size()-1))
				//	{

				//		(*it)->setProperty("Image","set:AnimalUIEX image:BeishunumX");
				//	}
				//}
				i/=10;
			}

		}

		void showWinnerNum(int i)
		{

			WindowsType::iterator it;

			bool num = false;
			if(i<100)
				num = true;
			for(it = _windows.begin(); it != _windows.end(); ++it)
			{

				(*it)->setProperty("Image", _numbers[i%10]);
				
				if(num == true && it == _windows.begin()+(_windows.size()-1))
				{
					CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/X")->hide();
					CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/X1")->hide();
					CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/X2")->hide();
					CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/X3")->hide();
					CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/X4")->hide();
					CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/X5")->hide();
					(*it)->setProperty("Image","set:AnimalUIEX image:BeishunumX");
				}

				i/=10;
			}

		}

	private:
		typedef  std::vector<CEGUI::Window * > WindowsType;
		WindowsType _windows;
		boost::array<std::string,10> _numbers;
	};
}


#endif