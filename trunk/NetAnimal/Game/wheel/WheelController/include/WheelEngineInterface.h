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
			ASK_TIME = 0x1,//硬件询问时间
			HOW_WINNER = 0x02,//硬件传来胜利模式
			ASK_STATE = 0x3,//硬件询问状态
			COME_IN_MENU = 0x4,//打开目录
			DATA_MENU = 0x5,//传递目录数据
			GO_OUT_MENU = 0x6,//关闭目录
			SET_MODE = 0x7,//设置胜利模式
			HARDWARE_RETURN1 = 0x8,//
			HARDWARE_RETURN2 = 0x0b,
			COME_IN_SETUP = 0xa,//进入设置
			REPORT = 0x09,//赢家发送报告
			RESET_GAME = 0xc,//重新启动游戏
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



