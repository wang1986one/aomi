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
		

		///֪ͨ���̰����¼�
		bool onKeyPressed(const KeyEvent & evt);
		///֪ͨ�����ͷ��¼�
		bool onKeyReleased(const KeyEvent & evt);
	private:


	


	};
}


#endif
