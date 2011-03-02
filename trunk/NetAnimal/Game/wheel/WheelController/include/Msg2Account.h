
#ifndef __Orz_Msg2Account_h__
#define __Orz_Msg2Account_h__
#include "Accounts.h"
#include "MsgHandler.h"
namespace Orz
{
	class Msg2Account
	{
	public:
		Msg2Account(Accounts * acc):_acc(acc)
		{
			
		}
		bool push_msg(MsgBuffer & buffer)
		{
			assert(buffer.size()== 39);
			int id = int(buffer[1]) - 1;
			int i=2;
			unsigned long  tms/*台面数*/ = uchar2ulong(buffer[3], buffer[4], buffer[5], buffer[6]);
			unsigned long  zzf/*总中分*/ = uchar2ulong(buffer[7], buffer[8], buffer[9], buffer[10]);
			unsigned long  zyf/*总压分*/ = uchar2ulong(buffer[11], buffer[12], buffer[13], buffer[14]); 
			unsigned long  zkf/*总开分*/ = uchar2ulong(buffer[15], buffer[16], buffer[17], buffer[18]);
			unsigned long  zxf/*总消分*/ = uchar2ulong(buffer[19], buffer[20], buffer[21], buffer[22]);
			unsigned long  ztob/*总投币*/ = uchar2ulong(buffer[23], buffer[24], buffer[25], buffer[26]);
			unsigned long  ztub/*总退币*/ = uchar2ulong(buffer[27], buffer[28], buffer[29], buffer[30]);
			unsigned long  zxhzyf/*总退币*/ = uchar2ulong(buffer[31], buffer[32], buffer[33], buffer[34]);
			unsigned long  zxhzzf/*总退币*/ = uchar2ulong(buffer[35], buffer[36], buffer[37], buffer[38]);
			
			std::cout<<"id="<<id<<";tms="<<tms<<";zzf="<<zzf<<";zyf="<<zyf<<";zkf="<<zkf<<";ztob="<<ztob<<std::endl;
			return _acc->push(id, tms, zzf, zyf, zkf, zxf, ztob, ztub, zxhzyf, zxhzzf);
			//std::cout<<int(buffer[1]);
		
		}
	private:
		Accounts * _acc;
		
	};
}

#endif