#ifndef __Orz_Dan__
#define __Orz_Dan__

#include "WheelGobalConfig.h"
#include <CEGUI/cegui.h>
#include "DanListener.h"
#include <Ogre/Ogre.h>

#include "F5TableInterface.h"
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


	class Dan : public KeyListener
	{
	public:
		bool textAccepted(const CEGUI::EventArgs&) ;

		Dan(DanListener * listener, ComponentPtr dataServer);
		void write(int i, int j, const std::string & text);
		void show(void);
		void hide(void);
		~Dan(void);
		void update(TimeType time);
		void result(bool ret);
		
	private:
		bool check(void);
		void warning(const std::wstring & text, TimeType time = 1.0f);
		bool onKeyPressed(const KeyEvent & evt);
		bool onKeyReleased(const KeyEvent & evt);
		void refresh(F5TableInterface::ID id, F5TableInterface::ACCOUNTS_ITEM item);
		void refresh(void);
		void setText(const std::string & window, const std::wstring & str);
		void setText(const std::string & window, const std::string & str);
		CEGUI::Window * _win; 
		DanListener * _callback;
		TimeType _time;
		std::vector<LinePtr > _lines;
		Orz::ComponentPtr _table;
		Orz::ComponentPtr _coding;
	/*	Orz::ComponentPtr _lockCoding;
		Orz::ComponentPtr _lock;*/
		
		ComponentPtr _dataServer;
		boost::signals2::connection _connection;
		//ComponentPtr _dataServer;
	};
}


#endif