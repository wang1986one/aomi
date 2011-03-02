#ifndef __Orz_Senselock_h__
#define __Orz_Senselock_h__
#include "LockInterface.h"
namespace Orz
{
	class Senselock
	{
	public:
		typedef  LockInterface::MemoryType MemoryType;
	public:
		enum FUN
		{
			FUN_KEY  = 0 ,
			FUN_READ  = 1, 
			FUN_WRITE  = 2 
		};
	public:
		~Senselock(void);
		Senselock(void);
		
		bool call_ele(char *modulename, unsigned char *buff, int len);
		static Senselock & getInstance(void);
		static Senselock * getInstancePtr(void);
		bool update(void);
		bool commit(void);
		MemoryType & getMemory(void);
		void print(void);
	private:
		MemoryType _memory;
		MemoryType _memoryBack;
		bool _dirty;
	};

	
}


#endif
