#ifndef __Orz_MyHandler_h__
#define __Orz_MyHandler_h__

#include "WheelControllerConfig.h"
#include "MyHardwareCode.h"
namespace Orz
{
class _OrzMyWheelControlleExport MyHandler
{

	enum State
	{
		READ,
		FILL
	};
public:
	MyHandler(void);
	~MyHandler(void);
	void push(unsigned char data);
	bool empty(void);
	HardwareMsg pop(void);
private:
	unsigned short _buttonState;
	unsigned short _oldButtonState;

	HardwareMsg _msg;
	State _state;
	bool _isEmpty;

};



}

	

#endif