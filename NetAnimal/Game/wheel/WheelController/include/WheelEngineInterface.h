#ifndef __Orz_WheelEngineInterface_h__
#define __Orz_WheelEngineInterface_h__	


#include "WheelControllerConfig.h"
namespace Orz
{

	class WheelEngineListener;
	
	typedef std::vector<unsigned char>  MsgBuffer;
	class _OrzWheelControlleExport WheelEngineInterface
	{
	public:
		enum WHEEL_MSG
		{
			ASK_TIME = 0x1,//Ӳ��ѯ��ʱ��
			HOW_WINNER = 0x02,//Ӳ������ʤ��ģʽ
			ASK_STATE = 0x3,//Ӳ��ѯ��״̬
			COME_IN_MENU = 0x4,//��Ŀ¼
			DATA_MENU = 0x5,//����Ŀ¼����
			GO_OUT_MENU = 0x6,//�ر�Ŀ¼
			SET_MODE = 0x7,//����ʤ��ģʽ
			HARDWARE_RETURN1 = 0x8,//
			HARDWARE_RETURN2 = 0x0b,
			COME_IN_SETUP = 0xa,//��������
			REPORT = 0x09,//Ӯ�ҷ��ͱ���
			RESET_GAME = 0xc,//����������Ϸ
			KEY_F4 = 0x21,//f4
			KEY_F5 = 0x22,//f5
			KEY_F6 = 0x23//f6
		};
	public:
		virtual void addListener(WheelEngineListener * listener) = 0;
		virtual void removeListener(WheelEngineListener * listener) = 0;
		WheelEngineInterface(void);
		virtual ~WheelEngineInterface(void);
		virtual void pushMessage(MsgBuffer & buffer) = 0;
		virtual void refreshMenuData(void) = 0;
		
	};


	typedef boost::shared_ptr<WheelEngineInterface> WheelEngineInterfacePtr;
}

#endif



