#ifndef __Orz_Dan2__
#define __Orz_Dan2__

#include "WheelGobalConfig.h"
#include "DanListener.h"
#include <CEGUI/cegui.h>
#include <Ogre/ogre.h>
#include <orz/Framework_Base/System/IInputManager.h>
namespace Orz
{
	class Dan2: public KeyListener
	{
	public:
		Dan2(DanListener * listener);

		bool textAccepted(const CEGUI::EventArgs&) ;
		
		bool onKeyPressed(const KeyEvent & evt);
		virtual bool onKeyReleased(const KeyEvent & evt);

		
		void result(bool ret);
		void show(void);

		void redo(int old, int now);
		//void getData(void);

		void setDan2Data(int i, int data);
		void hide(void);
		void setup(void);
		void update(TimeType time);
		~Dan2(void);
		void bao_zhang_ma(const std::string & n);
	private:
		CEGUI::Window * _win;
		boost::array<CEGUI::Editbox*, 9> _editboxs;
		int _n;
		TimeType _time;
		DanListener * _callback;
		ComponentPtr _f6table;
	};
}


#endif