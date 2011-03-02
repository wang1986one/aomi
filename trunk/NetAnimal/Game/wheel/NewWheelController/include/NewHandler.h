#ifndef __Orz_NewHandler_h__
#define __Orz_NewHandler_h__

#include "WheelControllerConfig.h"
#include "NewHardwareCode.h"
namespace Orz
{
class _OrzNewWheelControlleExport NewHandler
{

	enum State
	{
		SLEEP,
		READ
	};
public:
	NewHandler(void);
	~NewHandler(void);
	void push(unsigned char data);
	/*bool empty(void);
	HardwareMsg pop(void);*/
private:
	boost::array<unsigned char, 40> _msgs;
	State _state;
	HardwareMsg _msg;
	bool _isEasy;
	//bool _isEmpty;
	int _num;
};



}

	

#endif