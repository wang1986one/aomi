#ifndef __Orz_NetHandler_h__
#define __Orz_NetHandler_h__

#include "WheelControllerConfig.h"
#include "NetHardwareCode.h"
namespace Orz
{
class _OrzNetWheelControlleExport NetHandler
{

	enum State
	{
		READ,
		FILL
	};
public:
	NetHandler(void);
	~NetHandler(void);
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