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
		

		///֪ͨ���̰����¼�
		bool onKeyPressed(const KeyEvent & evt);
		///֪ͨ�����ͷ��¼�
		bool onKeyReleased(const KeyEvent & evt);
	private:


	

	};
}


#endif
