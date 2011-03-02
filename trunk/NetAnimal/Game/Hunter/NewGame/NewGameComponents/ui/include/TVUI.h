#ifndef __Orz_TVUI__
#define __Orz_TVUI__


#include <WheelGobal/WheelEnum.h>
namespace Orz
{	
namespace UI
{
	class TVUI: public Singleton<TVUI>
	{
	public:
		TVUI(void):_n(0),_multiArray(boost::extents[3][4])
		{
			_win= CEGUI::WindowManager::getSingleton().getWindow("CONTIN");


		
			_windows.push_back(CEGUI::WindowManager::getSingleton().getWindow("CONTIN/0"));
			_windows.push_back(CEGUI::WindowManager::getSingleton().getWindow("CONTIN/1"));
			_windows.push_back(CEGUI::WindowManager::getSingleton().getWindow("CONTIN/2"));
			_windows.push_back(CEGUI::WindowManager::getSingleton().getWindow("CONTIN/3"));
			_windows.push_back(CEGUI::WindowManager::getSingleton().getWindow("CONTIN/4"));
			_windows.push_back(CEGUI::WindowManager::getSingleton().getWindow("CONTIN/5"));
			_windows.push_back(CEGUI::WindowManager::getSingleton().getWindow("CONTIN/6"));
			_windows.push_back(CEGUI::WindowManager::getSingleton().getWindow("CONTIN/7"));
			_windows.push_back(CEGUI::WindowManager::getSingleton().getWindow("CONTIN/8"));
			_windows.push_back(CEGUI::WindowManager::getSingleton().getWindow("CONTIN/9"));
			_windows.push_back(CEGUI::WindowManager::getSingleton().getWindow("CONTIN/10"));
			hide();



			_multiArray[WheelEnum::Red][AnimalEnum::TYPE0]  = "set:sample image:panada_red";//ÐÜÃ¨
			_multiArray[WheelEnum::Red][AnimalEnum::TYPE1]  = "set:sample image:tiger_red";//ÀÏ»¢
			_multiArray[WheelEnum::Red][AnimalEnum::TYPE2]  = "set:sample image:elephant_red";//´óÏó
			_multiArray[WheelEnum::Red][AnimalEnum::TYPE3]  = "set:sample image:crocodile_red";//öùÓã

			_multiArray[WheelEnum::Yellow][AnimalEnum::TYPE0]  = "set:sample image:panada_yellow";
			_multiArray[WheelEnum::Yellow][AnimalEnum::TYPE1]  = "set:sample image:tiger_yellow";
			_multiArray[WheelEnum::Yellow][AnimalEnum::TYPE2]  = "set:sample image:elephant_yellow";
			_multiArray[WheelEnum::Yellow][AnimalEnum::TYPE3]  = "set:sample image:crocodile_yellow";

			_multiArray[WheelEnum::Green][AnimalEnum::TYPE0]  = "set:sample image:panada_green";
			_multiArray[WheelEnum::Green][AnimalEnum::TYPE1]  = "set:sample image:tiger_green";
			_multiArray[WheelEnum::Green][AnimalEnum::TYPE2]  = "set:sample image:elephant_green";
			_multiArray[WheelEnum::Green][AnimalEnum::TYPE3]  = "set:sample image:crocodile_green";

		}

		void show(void)
		{
			_win->show();
		}
		void hide(void)
		{
			clear();
			_win->hide();
		}
		void add(Orz::AnimalEnum::ANIMAL_ITEM ai)
		{
			if(_n>= _windows.size())
				return;
			_windows.at(_n)->setProperty("Image", _multiArray[ai.second][ai.first]);
			_windows.at(_n)->show();
			_n++;
		}
		void clear()
		{
			std::vector<CEGUI::Window *> ::iterator it;
			for(it = _windows.begin(); it != _windows.end(); ++it)
			{
				(*it)->hide();
			}
			_n = 0;
		}
		~TVUI(void)
		{

		}

	private:
		std::vector<CEGUI::Window *> _windows;
		CEGUI::Window * _win;
		size_t _n;

		
		boost::multi_array<std::string, 2> _multiArray;
	};
}
}


#endif