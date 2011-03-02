#ifndef __Orz_UIAnimation2__
#define __Orz_UIAnimation2__

namespace Orz
{
	namespace UI
	{
		class UIAnimation2
		{
		public:
			UIAnimation2(void):_window(NULL),_time(0.f)
			{
				_curWindow = _windows.begin();
			}
			~UIAnimation2(void)
			{

			}
			void push_back(CEGUI::Window * window, TimeType i)
			{
				window->hide();
				_windows.push_back(std::make_pair(window,i));
				_curWindow = _windows.begin();
			}
			bool update(TimeType i)
			{
				_time += i;
				if(_time >= _curWindow->second)
				{	

					_time -= _curWindow->second;

					_curWindow->first->hide();

					++_curWindow;

					if(_curWindow == _windows.end())
					{
						return false;
					}
					else
						_curWindow->first->show();
				}
				return true;
			}
			void reset(void)
			{
				_curWindow = _windows.begin();
				_curWindow->first->show();
			}
		private:
			CEGUI::Window * _window;
			typedef std::vector<std::pair<CEGUI::Window * , TimeType > > WindowListType;
			WindowListType _windows;
			WindowListType::iterator _curWindow;
			TimeType _time;
		};
	}
}

#endif