#ifndef __Orz_TVUI__
#define __Orz_TVUI__


#include "WheelAnimalControllerConfig.h"

#include "WheelEnum.h"
#include <CEGUI/cegui.h>
namespace Orz
{	
	class TVUIItem
	{
	public:

	private:

	};
	class TVUI
	{
	public:
		TVUI(void):_n(0)
		{
			_win= CEGUI::WindowManager::getSingleton().loadWindowLayout("FlankUI.layout");


			CEGUI::Window * f = CEGUI::WindowManager::getSingleton().getWindow("AnimalUI");
			f->addChildWindow(_win);
			_windows.push_back(CEGUI::WindowManager::getSingleton().getWindow("FlankUI/Side1"));
			_windows.push_back(CEGUI::WindowManager::getSingleton().getWindow("FlankUI/Side2"));
			_windows.push_back(CEGUI::WindowManager::getSingleton().getWindow("FlankUI/Side3"));
			_windows.push_back(CEGUI::WindowManager::getSingleton().getWindow("FlankUI/Side4"));
			_windows.push_back(CEGUI::WindowManager::getSingleton().getWindow("FlankUI/Side5"));
			_windows.push_back(CEGUI::WindowManager::getSingleton().getWindow("FlankUI/Side6"));
			hide();



			_picture.insert(std::make_pair(
				std::make_pair(WheelEnum::LION, WheelEnum::Green),
				"set:AnimalUI image:Greenlion"
				));

			_picture.insert(std::make_pair(
				std::make_pair(WheelEnum::RABBIT, WheelEnum::Green),
				"set:AnimalUI image:Greenrabblt"
				));

			_picture.insert(std::make_pair(
				std::make_pair(WheelEnum::MONKEY, WheelEnum::Green),
				"set:AnimalUI image:Greenmonkey"
				));

			_picture.insert(std::make_pair(
				std::make_pair(WheelEnum::PANDA, WheelEnum::Green),
				"set:AnimalUI image:Greenpanda"
				));



			_picture.insert(std::make_pair(
				std::make_pair(WheelEnum::LION, WheelEnum::Red),
				"set:AnimalUI image:Redlion"
				));

			_picture.insert(std::make_pair(
				std::make_pair(WheelEnum::RABBIT, WheelEnum::Red),
				"set:AnimalUI image:Redrabblt"
				));

			_picture.insert(std::make_pair(
				std::make_pair(WheelEnum::MONKEY, WheelEnum::Red),
				"set:AnimalUI image:Redmonkey"
				));

			_picture.insert(std::make_pair(
				std::make_pair(WheelEnum::PANDA, WheelEnum::Red),
				"set:AnimalUI image:Redpanda"
				));



			_picture.insert(std::make_pair(
				std::make_pair(WheelEnum::LION, WheelEnum::Yellow),
				"set:AnimalUI image:Yellowlion"
				));

			_picture.insert(std::make_pair(
				std::make_pair(WheelEnum::RABBIT, WheelEnum::Yellow),
				"set:AnimalUI image:Yellowrabblt"
				));

			_picture.insert(std::make_pair(
				std::make_pair(WheelEnum::MONKEY, WheelEnum::Yellow),
				"set:AnimalUI image:Yellowmonkey"
				));

			_picture.insert(std::make_pair(
				std::make_pair(WheelEnum::PANDA, WheelEnum::Yellow),
				"set:AnimalUI image:Yellowpanda"
				));

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
		void add(Orz::WheelEnum::ANIMAL_ITEM ai)
		{
			if(_n>= _windows.size())
				return;
			_windows.at(_n)->setProperty("Image", _picture[ai]);
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

		std::map<Orz::WheelEnum::ANIMAL_ITEM , std::string> _picture;
	};

}


#endif