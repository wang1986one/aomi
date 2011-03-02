#ifndef __Orz_Logo__
#define __Orz_Logo__

#include <CEGUI/cegui.h>
#include "WheelAnimalControllerConfig.h"
//#include "..\..\WheelObject\include\WheelAnimalSceneObj.h"
namespace Orz
{
	class Logo
	{
	public:
		Logo(void):_alphaUp(1)
		{
			_win= CEGUI::WindowManager::getSingleton().loadWindowLayout("abc.layout");
			_win->setAlwaysOnTop(true);
			_win->hide();
			CEGUI::Window * f = CEGUI::WindowManager::getSingleton().getWindow("AnimalUI");
			f->addChildWindow(_win);

			_sun = CEGUI::WindowManager::getSingleton().getWindow("Anim/Bg/Sun");

		}
		void show(void)
		{
			_win->show();
		}
		void hide(void)
		{
			_win->hide();
    	}
		~Logo(void)
		{

		}

		void update(TimeType i)
		{
			if(_win->isVisible())
			{
				float alpha = _sun->getAlpha();
				if(alpha >= 1.0f)
				{
					_alphaUp  = -2;
				}
				else if(alpha<=0.0f)
				{
					_alphaUp  = 2;
				}
				alpha += i*_alphaUp;
				_sun->setAlpha(alpha);
			}

		}
	private:
		CEGUI::Window * _win; 
		CEGUI::Window * _sun;
		int _alphaUp;


	};
}


#endif