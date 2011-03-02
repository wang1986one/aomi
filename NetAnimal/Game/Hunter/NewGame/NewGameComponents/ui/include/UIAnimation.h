
#ifndef __Orz_UIAnimation__
#define __Orz_UIAnimation__
#include "Number.h"
namespace Orz
{
	class UIAnimation
	{
	public:
		

		UIAnimation(void):_window(NULL),_time(0.0f)
		{
			_curImage = _images.begin();
		}      

		~UIAnimation(void)
		{
			
		}

		void setWindow(CEGUI::Window * window)
		{
			_window = window;
		}

		void push_back(const std::string & image, TimeType i)
		{
			_images.push_back(std::make_pair(image,i));
			_curImage = _images.begin();
		}

		void update(TimeType i, bool isOK)
		{
			_time += i;
			
			if(_time >= _curImage->second && isOK == false)
			{	
				_time -= _curImage->second;
				if(_window)
				{
					_window->setProperty("Image",_curImage->first);
				}	
				++_curImage;
			}

			if(_curImage == _images.end())
				_curImage = _images.begin();

		}


		bool update(TimeType i)
		{
			_time += i;
			if(_time >= _curImage->second)
			{	

				_time -= _curImage->second;

				++_curImage;

				if(_curImage == _images.end())
				{
					return false;
				}
				else
					if(_window)
						_window->setProperty("Image",_curImage->first);
			}
			return true;
		}

		void reset()
		{
			_curImage = _images.begin();
			_time = 0.0f;
		}

		void setPic(const std::string & pic)
		{
			_window->setProperty("Image", pic);
		}

	private:
		CEGUI::Window * _window;	
		typedef std::vector<std::pair<std::string, TimeType > > ImageListType;
		ImageListType _images;
		ImageListType::iterator _curImage;
		TimeType _time;
	};
}


#endif