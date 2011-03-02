
#include "WheelControllerConfig.h"
#ifndef __Orz_MsgHandler_h__
#define __Orz_MsgHandler_h__

namespace Orz
{
	typedef std::vector<unsigned char>  MsgBuffer;
	
	class _OrzWheelControllePrivate MsgHandler
	{
		enum State
		{
			SLEEP,
			WAIT_BEGIN,
			READ,
			WAIT_END

		};
	public:
		MsgHandler(void);
		void push(unsigned char data);
		bool empty(void);
		MsgBuffer pop(void);
		bool decode(const MsgBuffer & from, MsgBuffer & to);
		MsgBuffer encode(const MsgBuffer & head, const MsgBuffer & from);
		
		unsigned char encode(unsigned char c, int suijishu);
		unsigned char decode(unsigned char c, int suijishu);
	private:
		std::queue<MsgBuffer> _msgs;
		State _state;
		MsgBuffer  _msg;
		//static const char decodeMap[256];
		//static const char _encodeMap[256];
		
		Clock<TimeType> _clock;
	};
	inline unsigned long uchar2ulong(unsigned char c1, unsigned char c2, unsigned char c3, unsigned char c4)
	{
		unsigned long ret = 0;
		unsigned char * t = static_cast<unsigned char*>(static_cast<void *>(&ret));
		t[0]=c1;
		t[1]=c2;
		t[2]=c3;
		t[3]=c4;
		return ret;
	}

}
namespace Orz
{
	inline static MsgBuffer & operator ,( MsgBuffer & buffer, unsigned char data)
	{
		buffer.push_back(data);
		return buffer;
	}

}
#endif