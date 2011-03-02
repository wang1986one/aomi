#include "MyWheelControllerStableHeaders.h"
//#include "MyHardwareCode.h"
//
//#include "elitee.h"
//
//using namespace Orz;
//
//template<> MyHardwareCode* Singleton<MyHardwareCode>::_singleton = NULL;
////static unsigned char seed[] = {
////	0xdd, 0xdc, 0xdb, 0xda, 0xd9, 0xd8
////};//加密算法起始指令
//void call_count(const unsigned char *in, unsigned char * b)
//{
//	unsigned char max =  in[0] - 0xd5;
//	unsigned char i;
//	b[0] = in[1];
//	for(i = 2; i < max ; ++i)
//	{
//		b[0]^= in[i];
//	}
//
//	b[1] = in[8];
//	for(i = 7; i >= max ; --i)
//	{
//		b[1]^= in[i];
//	}
//}
//
////void call_count(const unsigned char * in, unsigned char * b) 
////{ 
////	ELE_DEVICE_CONTEXT ctx = {0};
////	unsigned long size = 0;
////	unsigned long error= 0;
////	BOOL ret = FALSE; 
////	ctx.ulSize = sizeof(ELE_DEVICE_CONTEXT);
////	if (!EleOpenFirstDevice(NULL,NULL,NULL,ELE_EXCLUSIVE_MODE,&ctx)) 
////	{ 
////		printf("Elitee not found!\n"); return;
////	}
////
////	if (!EleExecute(&ctx, "encode", const_cast<unsigned char *>(in), 40, b, 2, &size)) 
////	{
////		printf("Execute Elitee module failed!\n");
////		EleClose(&ctx); return; 
////	}
////	EleClose(&ctx); 
////	return;
////}
//
//void _decode(const unsigned char * code,unsigned char * text)
//{
//
//	unsigned char  b[2];
//	short index;
//	int i;
//
//
//	if(code[0] == 0xa1)
//	{
//		text[0] = code[0];
//		text[1] = code[1];
//		return;
//	}
//
//
//	call_count(code, b);
//	index = 9 + b[0]%7;
//	text[0] = (code[index]^b[0]);
//
//
//	for (i = 1 + index; i < 40; i++)
//	{
//		text[i - index] = code[i]^b[1];
//	}
//
//
//}
//
//void MyHardwareCode::update(void)
//{
//	HardwareMsg msg;
//	if(_callback && _msgQueue.dequeue(msg))
//	{
//		_callback(msg);
//	}
//}
//void MyHardwareCode::decode(const boost::array<unsigned char , 40> & container, HardwareMsg & receive)
//{
//	boost::array<unsigned char , 40> out;
//	receive.data.clear();
//	_decode(container.begin(), out.begin());
//	receive.msg = WheelEnum::HARDWARE(out.at(0));
//
//
//
//	size_t size = _dataSize[receive.msg];
//
//	for (size_t i = 1; i < size; i++)
//	{
//		unsigned char data = out.at(i);
//		receive.data.push_back(data);
//	}
//
//}
//
//
//void _encode(unsigned char *text , unsigned char * code)
//{
//
//
//
//	unsigned char b[2] , i;
//	short index;
//	srand((unsigned)time(NULL));
//
//	code[0] = 0xd8 + rand()%6;
//	code[39] = 0xee;
//
//	for(i = 1; i < 39; i++)
//	{
//		code[i] = rand()%256;
//	}
//	call_count(code, b);
//
//	index = 9 + b[0]%7;
//	code[index] = text[0]^b[0];
//	code[index+1] = text[1]^b[1];
//
//
//}
//
//
//void MyHardwareCode::_threadRunning(void)
//{
//	EncodeContainer in;
//	Container code;
//	HardwareMsg receive;
//	while(_isRunning)
//	{
//		::Sleep(7);
//		while(_encodeQueue.dequeue(in))
//		{
//			_encode(in.begin(), code.begin());
//			//	Orz::SingleChipManager::getSingleton().write(code.begin() , 40);
//		}
//		::Sleep(7);
//		while(_decodeQueue.dequeue(code))
//		{
//			decode(code, receive);
//			_msgQueue.enqueue(receive);
//		}
//	}
//}
//
//
//void MyHardwareCode::push_decode(const Container & container)
//{
//	_decodeQueue.enqueue(container);
//}
//MyHardwareCode::~MyHardwareCode(void)
//{
//
//	_isRunning = false;
//	_thrd->join();
//}
//MyHardwareCode::MyHardwareCode(void)
//{
//
//
//	_isRunning = true;
//	_thrd.reset(new ::boost::thread(boost::bind(&MyHardwareCode::_threadRunning, this)));
//	/*setDataSize(WheelEnum::HW_FIND_PC, 2);
//	setDataSize(WheelEnum::HW_TIME, 2);
//	setDataSize(WheelEnum::HW_BOUNS, 3);
//	setDataSize(WheelEnum::HW_WIN_NONE, 4);
//	setDataSize(WheelEnum::HW_WIN_BOUNS, 4);
//	setDataSize(WheelEnum::HW_WIN_ANIMAL, 8);
//	setDataSize(WheelEnum::HW_WIN_COLOR, 10);
//	setDataSize(WheelEnum::HW_WIN_MANY, 24);
//	setDataSize(WheelEnum::HW_WIN_JP, 5);*/
//
//}
//
//void MyHardwareCode::encode(unsigned char order, unsigned char bTime, boost::array<unsigned char , 40> & container)
//{
//	EncodeContainer in;
//	in[0] = order;
//	in[1] = bTime;
//	//unsigned char in[2] = {order, bTime};
//	//_encode(in, container.begin());
//	_encodeQueue.enqueue(in);
//	//	m_pSerial->SendData(data, 40);
//}
//
//
//void MyHardwareCode::setDataSize(WheelEnum::HARDWARE data, size_t size)
//{
//	_dataSize[data] = size;
//}
