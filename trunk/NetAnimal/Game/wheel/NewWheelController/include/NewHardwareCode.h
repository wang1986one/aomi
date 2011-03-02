#ifndef __Orz_NewHardwareCode_h__
#define __Orz_NewHardwareCode_h__
#include "WheelControllerConfig.h"
#include "ThreadQueue.h"
namespace Orz
{


	namespace WheelEnum
	{

		enum HARDWARE
		{
			HW_FIND_PC = 0xa1,
			HW_TIME = 0xa2,
			HW_BOUNS = 0xa3,
			HW_WIN_NONE = 0xa4,
			HW_WIN_BOUNS = 0xa5,
			HW_WIN_ANIMAL = 0xa6,
			HW_WIN_COLOR = 0xa7,
			HW_WIN_MANY = 0xa8,
			HW_WIN_JP = 0xa9,

		};
	};
	struct HardwareMsg
	{
		WheelEnum::HARDWARE msg;
		std::vector<unsigned char> data;

	};


	class _OrzNewWheelControlleExport NewHardwareCode: public Singleton<NewHardwareCode>
	{
		typedef boost::array<unsigned char , 40> Container;
		typedef boost::array<unsigned char , 2> EncodeContainer;
		typedef boost::function<void (HardwareMsg & receive)> DealMassageCallbackFunction;
	public:
		NewHardwareCode(void);
		~NewHardwareCode(void);
		void push_decode(const Container & container);
		void setDataSize(WheelEnum::HARDWARE data, size_t size);
		void update(void);
		DealMassageCallbackFunction _callback;

		void encode(unsigned char order, unsigned char bTime, boost::array<unsigned char , 40> & container);

	private:

		void decode(const Container & container, HardwareMsg & receive);


		std::map<WheelEnum::HARDWARE, size_t> _dataSize;
		ThreadQueue<EncodeContainer> _encodeQueue;
		ThreadQueue<Container> _decodeQueue;
		ThreadQueue<HardwareMsg> _msgQueue;


		bool _isRunning;
		boost::scoped_ptr<::boost::thread> _thrd;
		void _threadRunning(void);

	};
}



#endif