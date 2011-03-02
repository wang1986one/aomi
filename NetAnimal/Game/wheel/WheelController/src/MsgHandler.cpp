#include "WheelControllerStableHeaders.h"
#include "MsgHandler.h"

using namespace Orz;

const unsigned char decodeMap[256]={ //数据解密表
	0x0b,0x00,0x06,0x09,0x03,0x05,0x0e,0x0f,0x0c,0x02,0x08,0x0a,0x04,0x07,0x01,0x0d, //0
	0x08,0x0c,0x0a,0x04,0x0e,0x07,0x05,0x0b,0x01,0x00,0x03,0x02,0x06,0x0d,0x0f,0x09,//1
	0x00,0x0e,0x01,0x04,0x07,0x03,0x02,0x0c,0x0b,0x08,0x0a,0x05,0x0f,0x06,0x0d,0x09,//2
	0x0c,0x04,0x0f,0x0a,0x07,0x00,0x0e,0x0d,0x06,0x08,0x09,0x01,0x03,0x02,0x0b,0x05,//3
	0x08,0x01,0x00,0x04,0x06,0x09,0x03,0x0e,0x02,0x0d,0x0b,0x0a,0x07,0x0f,0x05,0x0c,//4
	0x09,0x0e,0x03,0x02,0x08,0x0f,0x0c,0x0b,0x07,0x0d,0x00,0x04,0x06,0x05,0x01,0x0a,//5
	0x0b,0x0e,0x07,0x06,0x0a,0x0c,0x03,0x02,0x04,0x0f,0x05,0x01,0x09,0x08,0x00,0x0d,//6
	0x06,0x0a,0x0e,0x00,0x0c,0x0d,0x03,0x0f,0x07,0x09,0x02,0x05,0x08,0x0b,0x01,0x04,//7
	0x0f,0x09,0x0d,0x03,0x01,0x0a,0x0c,0x06,0x05,0x08,0x04,0x07,0x02,0x0b,0x00,0x0e,//8
	0x07,0x01,0x09,0x03,0x05,0x06,0x0e,0x0d,0x0b,0x0f,0x02,0x04,0x08,0x00,0x0a,0x0c,//9
	0x0c,0x0d,0x04,0x03,0x0f,0x05,0x07,0x0e,0x06,0x08,0x02,0x09,0x0a,0x0b,0x01,0x00,//10
	0x0a,0x05,0x01,0x03,0x0b,0x04,0x00,0x08,0x07,0x0f,0x0c,0x06,0x02,0x09,0x0e,0x0d,//11
	0x03,0x07,0x0d,0x00,0x02,0x04,0x0f,0x0a,0x09,0x05,0x08,0x0b,0x0e,0x01,0x0c,0x06,//12
	0x0b,0x00,0x0c,0x07,0x04,0x09,0x0d,0x0a,0x03,0x05,0x06,0x01,0x0f,0x0e,0x08,0x02,//13
	0x07,0x0f,0x09,0x02,0x04,0x05,0x0d,0x08,0x00,0x01,0x0c,0x0a,0x06,0x0b,0x03,0x0e,//14
	0x0e,0x0b,0x06,0x05,0x0d,0x0f,0x01,0x00,0x02,0x0c,0x03,0x07,0x0a,0x09,0x04,0x08//15
};



const unsigned char encodeMap[256]={//数据加密表
	0x01,0x0e,0x09,0x04,0x0c,0x05,0x02,0x0d,0x0a,0x03,0x0b,0x00,0x08,0x0f,0x06,0x07, //0
	0x09,0x08,0x0b,0x0a,0x03,0x06,0x0c,0x05,0x00,0x0f,0x02,0x07,0x01,0x0d,0x04,0x0e,//1
	0x00,0x02,0x06,0x05,0x03,0x0b,0x0d,0x04,0x09,0x0f,0x0a,0x08,0x07,0x0e,0x01,0x0c,//2
	0x05,0x0b,0x0d,0x0c,0x01,0x0f,0x08,0x04,0x09,0x0a,0x03,0x0e,0x00,0x07,0x06,0x02,//3
	0x02,0x01,0x08,0x06,0x03,0x0e,0x04,0x0c,0x00,0x05,0x0b,0x0a,0x0f,0x09,0x07,0x0d,//4
	0x0a,0x0e,0x03,0x02,0x0b,0x0d,0x0c,0x08,0x04,0x00,0x0f,0x07,0x06,0x09,0x01,0x05,//5
	0x0e,0x0b,0x07,0x06,0x08,0x0a,0x03,0x02,0x0d,0x0c,0x04,0x00,0x05,0x0f,0x01,0x09,//6
	0x03,0x0e,0x0a,0x06,0x0f,0x0b,0x00,0x08,0x0c,0x09,0x01,0x0d,0x04,0x05,0x02,0x07,//7
	0x0e,0x04,0x0c,0x03,0x0a,0x08,0x07,0x0b,0x09,0x01,0x05,0x0d,0x06,0x02,0x0f,0x00,//8
	0x0d,0x01,0x0a,0x03,0x0b,0x04,0x05,0x00,0x0c,0x02,0x0e,0x08,0x0f,0x07,0x06,0x09,//9
	0x0f,0x0e,0x0a,0x03,0x02,0x05,0x08,0x06,0x09,0x0b,0x0c,0x0d,0x00,0x01,0x07,0x04,//10
	0x06,0x02,0x0c,0x03,0x05,0x01,0x0b,0x08,0x07,0x0d,0x00,0x04,0x0a,0x0f,0x0e,0x09,//11
	0x03,0x0d,0x04,0x00,0x05,0x09,0x0f,0x01,0x0a,0x08,0x07,0x0b,0x0e,0x02,0x0c,0x06,//12
	0x01,0x0b,0x0f,0x08,0x04,0x09,0x0a,0x03,0x0e,0x05,0x07,0x00,0x02,0x06,0x0d,0x0c,//13
	0x08,0x09,0x03,0x0e,0x04,0x05,0x0c,0x00,0x07,0x02,0x0b,0x0d,0x0a,0x06,0x0f,0x01,//14
	0x07,0x06,0x08,0x0a,0x0e,0x03,0x02,0x0b,0x0f,0x0d,0x0c,0x01,0x09,0x04,0x00,0x05//15
};



MsgHandler::MsgHandler(void):_state(SLEEP)
{

}
void MsgHandler::push(unsigned char data)
{
	switch(_state)
	{
	case SLEEP:
		if(data == 0xa5)
			_state = WAIT_BEGIN;
		break;
	case WAIT_BEGIN:
		if(data == 0x5a)
			_state = READ;
		else if(data != 0xa5)
			_state = SLEEP;
		break;

	case READ:
		if(data == 0xaa)
			_state = WAIT_END;
		else
		_msg.push_back(data);
		
		break;
	case WAIT_END:
		if(data == 0x55)
		{
			_msgs.push(_msg);
			_msg.clear();
			_state = SLEEP;
		}else if(data == 0xaa)
		{
			_msg.push_back(0xaa);
		}
		else
		{
			
			_msg.push_back(0xaa);
			
			_msg.push_back(data);
			_state = READ;
		}
		break;

	}

}
bool MsgHandler::empty(void)
{
	return _msgs.empty();
}
MsgBuffer  MsgHandler::pop(void)
{

	MsgBuffer str;
	if(!empty())
	{
		decode(_msgs.front(), str);
		_msgs.pop();
	}
	return str;
}


class Encode
{
public:
	Encode(MsgBuffer & to, int suijishu):_to(to),_suijishu(suijishu){}
	Encode(const Encode & encode):_to(encode._to), _suijishu(encode._suijishu){}
	void operator() (unsigned char data)
	{

		
		_to.push_back(encode(data));  


	}

	unsigned char encode(unsigned char data)
	{
		
		unsigned char data_mima_0 = data & 0x0f;
		unsigned char data_mima_1 = data & 0xf0;
		data_mima_1 = data_mima_1>>4;
		
		return (encodeMap[data_mima_1+_suijishu]<<4)+encodeMap[data_mima_0+_suijishu];
	}
private:
	MsgBuffer  & _to;
	const int _suijishu;
};


class Decode
{
public:
	Decode(MsgBuffer  & to, int suijishu):_to(to),_suijishu(suijishu){}
	Decode(const Decode & decode):_to(decode._to), _suijishu(decode._suijishu){}
	void operator() (unsigned char data)
	{
		_to.push_back(decode(data));
	}

	unsigned char decode(unsigned char data)
	{
		unsigned char data_mima_0 = data & 0x0f;
		unsigned char data_mima_1 = data & 0xf0;
		data_mima_1 = data_mima_1>>4;
		return (decodeMap[data_mima_1+_suijishu]<<4)+decodeMap[data_mima_0+_suijishu];
		
	}
private:
	MsgBuffer  & _to;
	const int _suijishu;
};



	
bool MsgHandler::decode(const MsgBuffer  & from, MsgBuffer & to)
{

	


	unsigned int suijishu=from[3]-13;  //随机数解密
	Decode decode(to, suijishu);
	//to.push_back(suijishu);

	std::for_each(from.begin(), from.begin()+3, decode);

	//to.push_back(suijishu);

	unsigned char connect_data_long = decode.decode(from[4]); //数据长度解密; 加0x07指向校验和数据
	
	
	//to.push_back(connect_data_long);


	
	if(from.size() != connect_data_long + 6/*前面5个+校验和*/)
		return false;


	
	unsigned int connect_jiaoyan = 0;
	for(unsigned int i =0; i< from.size() -1; ++i)
	{
		connect_jiaoyan+= from.at(i);
	}

	connect_jiaoyan %= 97; //计算数组校验和;

	if(*from.rbegin()!=connect_jiaoyan)
		return false;
	



	std::for_each(from.begin()+5, from.end()-1, decode);
	

	
	return true;

}


unsigned char MsgHandler::encode(unsigned char c, int suijishu)
{
	MsgBuffer b;
	Encode e(b, suijishu);
	return e.encode(c);
}
unsigned char MsgHandler::decode(unsigned char c, int suijishu)
{

	MsgBuffer b;
	Decode d(b, suijishu);
	
	return d.decode(c);
}
MsgBuffer MsgHandler::encode(const MsgBuffer  & head, const MsgBuffer & from)
{

	assert(head.size() == 3);

	unsigned int  jiaoyanghe;
	//std::cout<<static_cast<unsigned int>(_clock.elapsed() *100.f)<<std::endl;
	srand(static_cast<unsigned int>(_clock.elapsed() *100.f));
	int suijishu = rand()%16*16;  //生成随机数
	MsgBuffer  to;
	to.push_back(0xa5);//初始前导码
	to.push_back(0x5a);

	
	Encode encode(to, suijishu);
	


	std::for_each(head.begin(), head.end() , encode);//3

	to.push_back(suijishu+13); //随机数加密4


	encode(from.size());//5

	std::for_each(from.begin(), from.end(), encode);
	

	jiaoyanghe = 0;                    //计算校验和


	for(unsigned int i=2;i<to.size();i++)              
	{
		jiaoyanghe += to.at(i);
	}


	to.push_back(jiaoyanghe%97);//校验和写入数组 6

	to.push_back(0xaa);
	to.push_back(0x55); //结束码

	return to;

}
