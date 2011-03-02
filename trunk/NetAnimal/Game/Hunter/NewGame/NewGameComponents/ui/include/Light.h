#ifndef __Orz_Light__
#define __Orz_Light__
#include "UIAnimation2.h"
namespace Orz
{

	namespace UI
	{
	class Light
	{
	public:
		Light(void):_play(NULL)
		{
		
			_win= CEGUI::WindowManager::getSingleton().loadWindowLayout("Light.layout");
			_win->setAlwaysOnTop(true);
			_win->hide();
			CEGUI::Window * f = CEGUI::WindowManager::getSingleton().getWindow("Root");
			f->addChildWindow(_win);

			_x2.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Fire1"), 0.1f);
			_x2.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Fire2"), 0.1f);
			_x2.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Fire2"), 0.1f);
			_x2.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Fire1"), 0.1f);
			_x2.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Fire2"), 0.1f);
			_x2.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Fire1"), 0.1f);
			_x2.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Fire2"), 0.1f);
			_x2.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Double0"), 0.1f);
			_x2.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Double1"), 0.1f);
			_x2.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Double2"), 0.1f);
			_x2.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Double3"), 0.1f);
			_x2.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Double2"), 0.1f);
			_x2.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Double1"), 0.1f);
			_x2.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Double0"), 0.1f);
			_x2.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Double1"), 0.1f);
			_x2.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Double2"), 0.1f);
			_x2.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Double3"), 0.1f);
			_x2.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Double2"), 0.1f);
			_x2.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Double1"), 0.1f);
			_x2.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Double0"), 0.1f);

			
			_x3.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Fire1"), 0.1f);
			_x3.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Fire2"), 0.1f);
			_x3.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Fire2"), 0.1f);
			_x3.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Fire1"), 0.1f);
			_x3.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Fire2"), 0.1f);
			_x3.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Fire1"), 0.1f);
			_x3.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Fire2"), 0.1f);
			_x3.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Treble0"), 0.1f);
			_x3.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Treble1"), 0.1f);
			_x3.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Treble2"), 0.1f);
			_x3.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Treble3"), 0.1f);
			_x3.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Treble2"), 0.1f);
			_x3.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Treble1"), 0.1f);
			_x3.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Treble0"), 0.1f);
			_x3.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Treble1"), 0.1f);
			_x3.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Treble2"), 0.1f);
			_x3.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Treble3"), 0.1f);
			_x3.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Treble2"), 0.1f);
			_x3.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Treble1"), 0.1f);
			_x3.push_back(CEGUI::WindowManager::getSingleton().getWindow("Light/Treble0"), 0.1f);
			clear();
		}
		~Light(void)
		{
			
		}

		bool update(TimeType i)
		{
			
			if(_play)
			{
				bool ret = _play->update(i);
				if(!ret)
				{
					
					if(_play == &_x3)
					{
						
						CEGUI::WindowManager::getSingleton().getWindow("Light/x3")->show();
					}else 
					if(_play == &_x2)
					{
						
						CEGUI::WindowManager::getSingleton().getWindow("Light/x2")->show();
					}
					_play = NULL;
					return false;
				}
				return true;
			}

			return false;
		}

		void clear(void)
		{
			
			_win->hide();
			
			CEGUI::WindowManager::getSingleton().getWindow("Light/x2")->hide();
			CEGUI::WindowManager::getSingleton().getWindow("Light/x3")->hide();
		}
		void x3(void)
		{
			_play = &_x3;
			_play->reset();
			_win->show();
		}


		void x2(void)
		{
			_play = &_x2;
			_play->reset();
			_win->show();
		}
	private:
		CEGUI::Window * _win;
		UIAnimation2 _x2;
		UIAnimation2 _x3;
		UIAnimation2 * _play;

	};
	}
}


#endif