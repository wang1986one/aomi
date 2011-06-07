#ifndef __Orz_TableComponentKey_h__
#define __Orz_TableComponentKey_h__
//#include "CodingInterface.h"
namespace Orz
{
	class F5TableInterface;
	class TableComponentKey: public Component, public KeyListener
	{
	private:
	public:
		virtual ~TableComponentKey(void);
		TableComponentKey(void);
		

		///通知键盘按下事件
		bool onKeyPressed(const KeyEvent & evt);
		///通知键盘释放事件
		bool onKeyReleased(const KeyEvent & evt);
	private:


	

	};
}


#endif
