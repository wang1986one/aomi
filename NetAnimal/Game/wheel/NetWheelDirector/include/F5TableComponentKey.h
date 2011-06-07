#ifndef __Orz_F5TableComponentKey_h__
#define __Orz_F5TableComponentKey_h__
//#include "CodingInterface.h"
namespace Orz
{
	class F5TableInterface;
	class F5TableComponentKey: public Component, public KeyListener
	{
	private:
	public:
		virtual ~F5TableComponentKey(void);
		F5TableComponentKey(void);
		

		///通知键盘按下事件
		bool onKeyPressed(const KeyEvent & evt);
		///通知键盘释放事件
		bool onKeyReleased(const KeyEvent & evt);
	private:


	


	};
}


#endif
