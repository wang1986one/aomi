#include "WheelControllerStableHeaders.h"
#include "Hardware.h"
#include "MsgHandler.h"
using namespace Orz;


#include <orz/View_SingleChip/SingleChipManager.h>


MsgHandler handler;
void Hardware::received(bool isReceived)
{
	

	ORZ_LOG_TRACE_MESSAGE("call Hardware::received(bool isReceived)");
	Orz::MsgBuffer head;
	head.push_back(0);
	head.push_back(0);
	head.push_back(0x12);

	Orz::MsgBuffer msg;
	if(isReceived)
		msg.push_back(0x01);
	else 
		msg.push_back(0x00);

	Orz::MsgBuffer out = handler.encode(head, msg);
	//Orz::SingleChipManager::getSingleton().write(out);
}


void Hardware::answerTime(int second)
{

	ORZ_LOG_TRACE_MESSAGE("call Hardware::answerTime(int second)");
	Orz::MsgBuffer head;
	head.push_back(0);
	head.push_back(0);
	head.push_back(0x11);

	Orz::MsgBuffer msg;
	msg.push_back(static_cast<unsigned char>(second));
	Orz::MsgBuffer out = handler.encode(head, msg);
//	Orz::SingleChipManager::getSingleton().write(out);
}


void Hardware::actionTwo(void)
{
	
	Orz::MsgBuffer head;
	head.push_back(0);
	head.push_back(0);
	head.push_back(0x18);

	Orz::MsgBuffer msg;
	Orz::MsgBuffer out = handler.encode(head, msg);
	//Orz::SingleChipManager::getSingleton().write(out);
	std::cout<<"F5"<<std::endl;
}
void Hardware::actionThree(void)
{
	
	Orz::MsgBuffer head;
	head.push_back(0);
	head.push_back(0);
	head.push_back(0x14);

	Orz::MsgBuffer msg;
	Orz::MsgBuffer out = handler.encode(head, msg);
//	Orz::SingleChipManager::getSingleton().write(out);
	std::cout<<"F6"<<std::endl;
}
void Hardware::actionOne(void)
{
	
	Orz::MsgBuffer head;
	head.push_back(0);
	head.push_back(0);
	head.push_back(0x18);

	Orz::MsgBuffer msg;
	Orz::MsgBuffer out = handler.encode(head, msg);
//	Orz::SingleChipManager::getSingleton().write(out);
	std::cout<<"F4"<<std::endl;
}


void Hardware::answerState(unsigned char state)
{
	
	Orz::MsgBuffer head;
	head.push_back(0);
	head.push_back(0);
	head.push_back(0x13);

	Orz::MsgBuffer msg;
	msg.push_back(state);
	Orz::MsgBuffer out = handler.encode(head, msg);
//	Orz::SingleChipManager::getSingleton().write(out);
}

void Hardware::setup(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8)
{
	ORZ_LOG_NORMAL_MESSAGE(boost::format("Hardware::setup(%1%,%2%,%3%,%4%,%5%,%6%,%7%,%8%,%9%)")
		%p0 
		%p1
		%p2
		%p3
		%p4
		%p5
		%p6
		%p7
		%p8);
	Orz::MsgBuffer head;
	head.push_back(0);
	head.push_back(0);
	head.push_back(0x18);

	Orz::MsgBuffer msg;
	Orz::MsgBuffer out = handler.encode(head, msg);
	out.push_back(p0);
	out.push_back(p1);
	out.push_back(p2);
	out.push_back(p3);
	out.push_back(p4);
	out.push_back(p5);
	out.push_back(p6);
	out.push_back(p7);
	out.push_back(p8);
//	Orz::SingleChipManager::getSingleton().write(out);
}

void Hardware::pushPassword(int password)
{
	Orz::MsgBuffer head;
	head.push_back(0);
	head.push_back(0);
	head.push_back(0x15);

	Orz::MsgBuffer msg;
	for(int i =0; i<9; ++i)
	{
		int n = password%10;
		password /=10;
		msg.push_back(n);
	}
	Orz::MsgBuffer out = handler.encode(head, msg);
//	Orz::SingleChipManager::getSingleton().write(out);
}

