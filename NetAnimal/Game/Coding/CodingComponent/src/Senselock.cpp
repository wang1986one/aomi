#include "CodingComponentStableHeaders.h"
#include "Senselock.h"
#include <elitee.h>
#include "common.h"
using namespace Orz;

Senselock::~Senselock(void)
{

}
Senselock::Senselock(void):_dirty(true)
{

}
Senselock & Senselock::getInstance(void)
{
	return *(getInstancePtr());
}

Senselock * Senselock::getInstancePtr(void)
{
	static Senselock instance;
	return &instance;
}


void Senselock::print(void)
{


	for(int i=0; i< _memory.size(); ++i)
	{
		if(i %8 == 0)
			std::cout<<std::endl;
		std::cout<<std::hex<<int(_memory.at(i))<<",";
	}
	std::cout<<std::endl;
}


Senselock::MemoryType & Senselock::getMemory(void)
{
	return _memory;
}
bool Senselock::update(void)
{
	_dirty = false;
	unsigned char buff[] = { FUN_READ,
		128, 0, 0, 0, 0, 0, 0, 0,//0
		0, 0, 0, 0, 0, 0, 0, 0,//1
		0, 0, 0, 0, 0, 0, 0, 0,//2
		0, 0, 0, 0, 0, 0, 0, 0,//3
		0, 0, 0, 0, 0, 0, 0, 0,//4
		0, 0, 0, 0, 0, 0, 0, 0,//5
		0, 0, 0, 0, 0, 0, 0, 0,//6
		0, 0, 0, 0, 0, 0, 0, 0,//7
		0, 0, 0, 0, 0, 0, 0, 0,//8
		0, 0, 0, 0, 0, 0, 0, 0,//9
		0, 0, 0, 0, 0, 0, 0, 0,//10
		0, 0, 0, 0, 0, 0, 0, 0,//11
		0, 0, 0, 0, 0, 0, 0, 0,//12
		0, 0, 0, 0, 0, 0, 0, 0,//13
		0, 0, 0, 0, 0, 0, 0, 0,//14
		0, 0, 0, 0, 0, 0, 0, 0//15
	};
	
	int len = sizeof(buff); 
	if(call_ele("Code", buff, len))
	{
		for(int i=0; i<128; i++)
		{
			_memory.at(i) = buff[i+1];
			_memoryBack.at(i) = buff[i+1];
		}
		return true;
	}
	return false;
}
bool Senselock::commit(void)
{
	unsigned char buff[] = { FUN_WRITE,
		0, 0, 0, 0, 0, 0, 0, 0,//0
		0, 0, 0, 0, 0, 0, 0, 0,//1
		0, 0, 0, 0, 0, 0, 0, 0,//2
		0, 0, 0, 0, 0, 0, 0, 0,//3
		0, 0, 0, 0, 0, 0, 0, 0,//4
		0, 0, 0, 0, 0, 0, 0, 0,//5
		0, 0, 0, 0, 0, 0, 0, 0,//6
		0, 0, 0, 0, 0, 0, 0, 0,//7
		0, 0, 0, 0, 0, 0, 0, 0,//8
		0, 0, 0, 0, 0, 0, 0, 0,//9
		0, 0, 0, 0, 0, 0, 0, 0,//10
		0, 0, 0, 0, 0, 0, 0, 0,//11
		0, 0, 0, 0, 0, 0, 0, 0,//12
		0, 0, 0, 0, 0, 0, 0, 0,//13
		0, 0, 0, 0, 0, 0, 0, 0,//14
		0, 0, 0, 0, 0, 0, 0, 0//15
	};
	bool dirty = false;
	for(int i=0; i<128; i++)
	{
		buff[i+1] = _memory.at(i);
		if(_memoryBack.at(i) != _memory.at(i))
		{
			dirty = true;
			_memoryBack.at(i) = _memory.at(i);
		}
	}
	if(dirty)
	{
		int len = sizeof(buff); 
		if(call_ele("Code", buff, len))
		{
			return true;
		}
		return false;
	}
	return true;

}

bool Senselock::call_ele(char *modulename, unsigned char *buff, int len) 
{ 
	ELE_DEVICE_CONTEXT ctx = {0};   
	unsigned long size = 0; 
	unsigned long error= 0; 
	BOOL ret = FALSE; 
	BOOL bRet = FALSE;
	DWORD dwRet = 0;
	ELE_DEVICE_CONTEXT EleCtx = {0}, EleTempCtx = {0};
	unsigned long ulTempIndex = 0;
	
	
	//open first device
	EleCtx.ulSize = sizeof(ELE_DEVICE_CONTEXT);
	bRet = EleOpenFirstDevice(NULL, NULL, NULL, ELE_SHARE_MODE, &EleCtx);
	if (!bRet)
	{		
		dwRet = EleGetLastError();
		if (dwRet == ELE_NO_MORE_DEVICE)
		{
			printf("No Elite-E device present!\n");
			
			return false;
		}
		else
		{
			printf("Open Elite-E device failed! <error code: 0x%08x>\n", dwRet);
			
			return false;
		//	getch();
		}
	}

	//if (!EleOpenFirstDevice(NULL,NULL,NULL,ELE_EXCLUSIVE_MODE,&ctx)) 
	//{ 
	//	printf("Elitee not found!\n"); 
	//	return; 
	//} 


	if (!EleExecute(&EleCtx, modulename, buff, len, buff, len, &size))  
	{ 
		printf("Execute Elitee module failed!\n"); 
		
		EleClose(&ctx); 
		
		return false;
	} 

	EleClose(&EleCtx); 

	if(buff[0] == 0x55)
		return true; 
	return false;
} 