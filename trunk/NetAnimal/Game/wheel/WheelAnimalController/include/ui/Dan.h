#ifndef __Orz_Dan__
#define __Orz_Dan__

#include "WheelGobalConfig.h"
#include <CEGUI/cegui.h>
#include "DanListener.h"
#include <Ogre/Ogre.h>

namespace Orz
{	
	class DanLine
	{
	public:
		DanLine(void);
		~DanLine(void);
		void push_back(CEGUI::Window * win);
		void write(int i, const std::string & text);
	private:
		std::vector<CEGUI::Window * > _windows;
	};
	typedef boost::shared_ptr<DanLine> LinePtr;


	class Dan
	{
	public:
		bool textAccepted(const CEGUI::EventArgs&) ;

		Dan(DanListener * listener);
		void write(int i, int j, const std::string & text);
		void show(void);
		void hide(void);
		~Dan(void);
		void update(TimeType time);
		void result(bool ret);
	private:
		CEGUI::Window * _win; 
		DanListener * _callback;
		TimeType _time;
		
		std::vector<LinePtr > _lines;
	};
}


#endif