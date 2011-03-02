#include "WheelGobalStableHeaders.h"
#include "WheelData.h"
#include "WinData.h"
#include "TVListMap.h"
#include <orz/Toolkit_Base/Exception.h>

using namespace Orz;
//WheelData::~WheelData(void)
//{
//
//}
WheelData_::WheelData_(void)
{
	
	using namespace WheelEnum;


	/*  0x00   »ÆÍÃ
	0x01   ÂÌÍÃ
	0x02   ºìÍÃ*/
	
	_wheelMap[YELLOW_RABBIT] = WheelMsg( NONE, AnimalType( RABBIT , PEOPLE),  Yellow); 
	_wheelMap[GREEN_RABBIT] = WheelMsg( NONE, AnimalType( RABBIT , PEOPLE),  Green); //0x01  ÂÌÍÃ
	_wheelMap[RED_RABBIT] = WheelMsg( NONE, AnimalType( RABBIT , PEOPLE),  Red);   //0x02  ºìÍÃ



	_wheelMap[YELLOW_MONKEY] = WheelMsg( NONE, AnimalType( MONKEY , PEOPLE),  Yellow);//»Æºï 
	_wheelMap[GREEN_MONKEY] = WheelMsg( NONE, AnimalType( MONKEY , PEOPLE),  Green); //ÂÌºï
	_wheelMap[RED_MONKEY] = WheelMsg( NONE, AnimalType( MONKEY , PEOPLE),  Red);   //ºìºï

	/*   
	0x06   »ÆÐÜÃ¨
	0x07   ÂÌÐÜÃ¨
	0x08   ºìÐÜÃ¨*/


	_wheelMap[YELLOW_PANDA] = WheelMsg( NONE, AnimalType( PANDA , PEOPLE),  Yellow); //»ÆÐÜÃ¨
	_wheelMap[GREEN_PANDA] = WheelMsg( NONE, AnimalType( PANDA , PEOPLE),  Green); //ÂÌÐÜÃ¨
	_wheelMap[RED_PANDA] = WheelMsg( NONE, AnimalType( PANDA , PEOPLE),  Red);  //ºìÐÜÃ¨



	/*
	0x09   »ÆÊ¨×Ó
	0x0A   ÂÌÊ¨×Ó
	0x0B   ºìÊ¨×Ó*/


	_wheelMap[YELLOW_LION] = WheelMsg( NONE, AnimalType( LION , PEOPLE),  Yellow); //  »ÆÊ¨×Ó
	_wheelMap[GREEN_LION] = WheelMsg( NONE, AnimalType( LION , PEOPLE),  Green);//ÂÌÊ¨×Ó 
	_wheelMap[RED_LION] = WheelMsg( NONE, AnimalType( LION , PEOPLE),  Red); //	ºìÊ¨×Ó


	
	/*    
	0x0c   ½ðÉ«»ÆÍÃ×Ó
	0x0d   ½ðÉ«ÂÌÍÃ×Ó
	0x0e    ½ðÉ«ºìÍÃ×Ó

	0x0f   ½ðÉ«»Æºï×Ó
	0x10   ½ðÉ«ÂÌºï×Ó
	0x11   ½ðÉ«ºìºï×Ó

	0x12  ½ðÉ«»ÆÐÜÃ¨
	0x13  ½ðÉ«ÂÌÐÜÃ¨
	0x14   ½ðÉ«ºìÐÜÃ¨

	0x15   ½ðÉ«»ÆÊ¨×Ó
	0x16   ½ðÉ«ÂÌÊ¨×Ó
	0x17   ½ðÉ«ºìÊ¨×Ó*/



	_wheelMap[G_YELLOW_RABBIT] = WheelMsg( GOLD, AnimalType( RABBIT , KING),  Yellow); //	»Æ½ðÍÃ
	_wheelMap[G_GREEN_RABBIT] = WheelMsg( GOLD, AnimalType( RABBIT , KING),  Green); //ÂÌ½ðÍÃ
	_wheelMap[G_RED_RABBIT] = WheelMsg( GOLD, AnimalType( RABBIT , KING),  Red); // ºì½ðÍÃ

	_wheelMap[G_YELLOW_MONKEY] = WheelMsg( GOLD, AnimalType( MONKEY , KING),  Yellow);//»Æ½ðºï
	_wheelMap[G_GREEN_MONKEY] = WheelMsg( GOLD, AnimalType( MONKEY , KING),  Green); //	ÂÌ½ðºï
	_wheelMap[G_RED_MONKEY] = WheelMsg( GOLD, AnimalType( MONKEY , KING),  Red);   // ºì½ðºï


	_wheelMap[G_YELLOW_PANDA] = WheelMsg( GOLD, AnimalType( PANDA , KING),  Yellow); //»Æ½ðÐÜÃ¨
	_wheelMap[G_GREEN_PANDA] = WheelMsg( GOLD, AnimalType( PANDA , KING),  Green); //ÂÌ½ðÐÜÃ¨
	_wheelMap[G_RED_PANDA] = WheelMsg( GOLD, AnimalType( PANDA , KING),  Red);  //ºì½ðÐÜÃ¨

	_wheelMap[G_YELLOW_LION] = WheelMsg( GOLD, AnimalType( LION , KING),  Yellow); //  »Æ½ðÊ¨×Ó
	_wheelMap[G_GREEN_LION] = WheelMsg( GOLD, AnimalType( LION , KING),  Green);//ÂÌ½ðÊ¨×Ó
	_wheelMap[G_RED_LION] = WheelMsg( GOLD, AnimalType( LION , KING),  Red);//ºì½ðÊ¨×Ó
		

	/*    
	0x18   »ÆÉ«È«ÖÐ
	0x19   ÂÌÉ«È«ÖÐ
	0x1a   ºìÉ«È«ÖÐ*/



	_wheelMap[ALL_YELLOW] = WheelMsg( ALL_COLOR, AnimalType( LION , PEOPLE),  Yellow); //   »ÆÉ«È«ÖÐ
	_wheelMap[ALL_GREEN] = WheelMsg( ALL_COLOR, AnimalType( LION , PEOPLE),  Green); //  ÂÌÉ«È«ÖÐ
	_wheelMap[ALL_RED] = WheelMsg( ALL_COLOR, AnimalType( LION , PEOPLE),  Red);  // ºìÉ«È«ÖÐ
	/*   
	0x1b   ÍÃ×ÓÈ«ÖÐ
	0x1c   ºï×ÓÈ«ÖÐ
	0x1d    ÐÜÃ¨È«ÖÐ
	0x1e   Ê¨×ÓÈ«ÖÐ*/





	_wheelMap[ALL_RABBIT] = WheelMsg( ALL_ANIMAL, AnimalType( RABBIT , PEOPLE),  Yellow); //   ÍÃ×ÓÈ«ÖÐ
	_wheelMap[ALL_MONKEY] = WheelMsg( ALL_ANIMAL, AnimalType( MONKEY , PEOPLE),  Green);// ºï×ÓÈ«ÖÐ
	_wheelMap[ALL_PANDA] = WheelMsg( ALL_ANIMAL, AnimalType( PANDA , PEOPLE),  Red); //   ÐÜÃ¨È«ÖÐ
	_wheelMap[ALL_LION] = WheelMsg( ALL_ANIMAL, AnimalType( LION , PEOPLE),  Red); //     Ê¨×ÓÈ«ÖÐ                      

		

	/*        
	0x1f   »ÆÍÃ2±¶
	0x20   ÂÌÍÃ2±¶
	0x21   ºìÍÃ2±¶
	0x22   »Æºï2±¶
	0x23   ÂÌºï2±¶
	0x24   ºìºï2±¶
	0x25   »ÆÃ¨2±¶
	0x26   ÂÌÃ¨2±¶
	0x27   ºìÃ¨2±¶
	0x28  »ÆÊ¨2±¶
	0x29   ÂÌÊ¨2±¶
	0x2a  ºìÊ¨2±¶*/






	_wheelMap[DOUBLE_YELLOW_RABBIT] = WheelMsg( DOUBLE, AnimalType( RABBIT , PEOPLE),  Yellow); //	»ÆÍÃ2±¶
	_wheelMap[DOUBLE_GREEN_RABBIT] = WheelMsg( DOUBLE, AnimalType( RABBIT , PEOPLE),  Green); //ÂÌÍÃ2±¶
	_wheelMap[DOUBLE_RED_RABBIT] = WheelMsg( DOUBLE, AnimalType( RABBIT , PEOPLE),  Red); // ºìÍÃ	2±¶

	_wheelMap[DOUBLE_YELLOW_MONKEY] = WheelMsg( DOUBLE, AnimalType( MONKEY , PEOPLE),  Yellow);//»Æºï 2±¶
	_wheelMap[DOUBLE_GREEN_MONKEY] = WheelMsg( DOUBLE, AnimalType( MONKEY , PEOPLE),  Green); //	ÂÌºï 2±¶
	_wheelMap[DOUBLE_RED_MONKEY] = WheelMsg( DOUBLE, AnimalType( MONKEY , PEOPLE),  Red);   // ºìºï2±¶


	_wheelMap[DOUBLE_YELLOW_PANDA] = WheelMsg( DOUBLE, AnimalType( PANDA , PEOPLE),  Yellow); //»ÆÐÜÃ¨	2±¶
	_wheelMap[DOUBLE_GREEN_PANDA] = WheelMsg( DOUBLE, AnimalType( PANDA , PEOPLE),  Green); //ÂÌÐÜÃ¨2±¶
	_wheelMap[DOUBLE_RED_PANDA] = WheelMsg( DOUBLE, AnimalType( PANDA , PEOPLE),  Red);  //ºìÐÜÃ¨ 2±¶

	_wheelMap[DOUBLE_YELLOW_LION] = WheelMsg( DOUBLE, AnimalType( LION , PEOPLE),  Yellow); //  »ÆÊ¨×Ó2±¶
	_wheelMap[DOUBLE_GREEN_LION] = WheelMsg( DOUBLE, AnimalType( LION , PEOPLE),  Green);//ÂÌÊ¨×Ó	 2±¶
	_wheelMap[DOUBLE_RED_LION] = WheelMsg( DOUBLE, AnimalType( LION , PEOPLE),  Red); //	ºìÊ¨×Ó   2±¶


		
	/*  
	0x2b   »ÆÍÃ3±¶
	0x2c   ÂÌÍÃ3±¶
	0x2d   ºìÍÃ3±¶
	0x2e   »Æºï3±¶
	0x2f   ÂÌºï3±¶
	0x30   ºìºï3±¶
	0x31   »ÆÃ¨3±¶
	0x32   ÂÌÃ¨3±¶
	0x33   ºìÃ¨3±¶
	0x34   »ÆÊ¨3±¶
	0x35   ÂÌÊ¨3±¶
	0x36   ºìÊ¨3±¶*/



	_wheelMap[TREBLE_YELLOW_RABBIT] = WheelMsg( TREBLE, AnimalType( RABBIT , PEOPLE),  Yellow); //	»ÆÍÃ3±¶
	_wheelMap[TREBLE_GREEN_RABBIT] = WheelMsg( TREBLE, AnimalType( RABBIT , PEOPLE),  Green); //ÂÌÍÃ3±¶
	_wheelMap[TREBLE_RED_RABBIT] = WheelMsg( TREBLE, AnimalType( RABBIT , PEOPLE),  Red); // ºìÍÃ	3±¶

	_wheelMap[TREBLE_YELLOW_MONKEY] = WheelMsg( TREBLE, AnimalType( MONKEY , PEOPLE),  Yellow);//»Æºï 3±¶
	_wheelMap[TREBLE_GREEN_MONKEY] = WheelMsg( TREBLE, AnimalType( MONKEY , PEOPLE),  Green); //	ÂÌºï 3±¶
	_wheelMap[TREBLE_RED_MONKEY] = WheelMsg( TREBLE, AnimalType( MONKEY , PEOPLE),  Red);   // ºìºï3±¶


	_wheelMap[TREBLE_YELLOW_PANDA] = WheelMsg( TREBLE, AnimalType( PANDA , PEOPLE),  Yellow); //»ÆÐÜÃ¨	3±¶
	_wheelMap[TREBLE_GREEN_PANDA] = WheelMsg( TREBLE, AnimalType( PANDA , PEOPLE),  Green); //ÂÌÐÜÃ¨3±¶
	_wheelMap[TREBLE_RED_PANDA] = WheelMsg( TREBLE, AnimalType( PANDA , PEOPLE),  Red);  //ºìÐÜÃ¨ 3±¶

	_wheelMap[TREBLE_YELLOW_LION] = WheelMsg( TREBLE, AnimalType( LION , PEOPLE),  Yellow); //  »ÆÊ¨×Ó3±¶
	_wheelMap[TREBLE_GREEN_LION] = WheelMsg( TREBLE, AnimalType( LION , PEOPLE),  Green);//ÂÌÊ¨×Ó	 3±¶
	_wheelMap[TREBLE_RED_LION] = WheelMsg( TREBLE, AnimalType( LION , PEOPLE),  Red);//ºìÊ¨×Ó	 3±¶


	/*   
	0x37   ºìÍÃ+»ÆÃ¨
	0x38   ÂÌÍÃ+ºìÃ¨
	0x39   »Æºï+ÂÌÊ¨
	0x3a   »ÆÍÃ+ÂÌºï
	0x3b   ºìºï+ÂÌÃ¨*/




	_wheelMap[RED_RABBIT_YELLOW_PANDA] = WheelMsg( MANY, AnimalType( RABBIT , PEOPLE),  Red);//ºìÍÃ+»ÆÃ¨
	_wheelMap[GREEN_RABBIT_RED_PANDA] = WheelMsg( MANY, AnimalType( RABBIT , PEOPLE),  Green);//ÂÌÍÃ+ºìÃ¨
	_wheelMap[YELLOW_MONKEY_GREEN_LION] = WheelMsg( MANY, AnimalType( MONKEY , PEOPLE),  Yellow);//»Æºï+ÂÌÊ¨
	_wheelMap[YELLOW_RABBIT_GREEN_MONKEY] = WheelMsg( MANY, AnimalType( RABBIT , PEOPLE),  Yellow);//»ÆÍÃ+ÂÌºï
	_wheelMap[RED_MONKEY_GREEN_PANDA] = WheelMsg( MANY, AnimalType( MONKEY , PEOPLE),  Red);//ºìºï+ÂÌÃ¨

	//0x3c   »ÆÍÃ+ÂÌºï+ºìÊ¨
	//0x3d   ÂÌÍÃ+ºìÍÃ+ÂÌÃ¨
	//0x3e   ºìºï+»ÆÍÃ+»ÆÃ¨

	_wheelMap[YELLOW_RABBIT_GREEN_MONKEY_RED_LION] = WheelMsg( MANY, AnimalType( RABBIT , PEOPLE),  Yellow);//»ÆÍÃ+ÂÌºï+ºìÊ¨
	_wheelMap[GREEN_RABBIT_RED_RABBIT_GREEN_PANDA] = WheelMsg( MANY, AnimalType( RABBIT , PEOPLE),  Green);//ÂÌÍÃ+ºìÍÃ+ÂÌÃ¨
	_wheelMap[RED_MONKEY_YELLOW_RABBIT_YELLOW_PANDA] = WheelMsg( MANY, AnimalType( MONKEY , PEOPLE),  Red);// ºìºï+»ÆÍÃ+»ÆÃ¨


	//0x3f   »ÆÍÃ+ºìÍÃ+»Æºï+ÂÌÃ¨
	//0x40   ÂÌÍÃ+ÂÌºï+»Æºï+»ÆÃ¨
	//0x41  »Æºï+»ÆÍÃ+ÂÌºï+»ÆÊ¨


	_wheelMap[YELLOW_RABBIT_RED_RABBIT_YELLOW_MANKEY_GREEN_PANDA] = WheelMsg( MANY, AnimalType( RABBIT , PEOPLE),  Yellow);// »ÆÍÃ+ºìÍÃ+»Æºï+ÂÌÃ¨
	_wheelMap[GREEN_RABBIT_GREEN_MONKEY_YELLOW_MONKEY_YELLOW_PANDA] = WheelMsg( MANY, AnimalType( RABBIT , PEOPLE),  Green);//ÂÌÍÃ+ÂÌºï+»Æºï+»ÆÃ¨
	_wheelMap[YELLOW_MONKEY_YELLOW_RABBIT_GREEN_PANDA_YELLOW_LION] = WheelMsg( MANY, AnimalType( MONKEY , PEOPLE),  Yellow);//»Æºï+»ÆÍÃ+ÂÌºï+»ÆÊ¨

	/*   0x42  ºìÍÃ+»Æºï+ºìºï+»ÆÃ¨+ÂÌºï
	0x43  »ÆÍÃ+ºìÍÃ+»ÆÃ¨+ÂÌÃ¨+ºìÊ¨
	0x44  ÂÌÍÃ+»Æºï+ÂÌºï+ºìºï+ÂÌÃ¨*/
	_wheelMap[RED_RABBIT_YELLOW_MONKEY_RED_MONKEY_YELLOW_PANDA_GREEN_MONKEY] = WheelMsg( MANY, AnimalType( RABBIT , PEOPLE),  Red);// ºìÍÃ+»Æºï+ºìºï+»ÆÃ¨+ÂÌºï
	_wheelMap[YELLOW_RABBIT_RED_RABBIT_YELLOW_PANDA_GREEN_PANDA_RED_LION] = WheelMsg( MANY, AnimalType( RABBIT , PEOPLE),  Yellow);//»ÆÍÃ+ºìÍÃ+»ÆÃ¨+ÂÌÃ¨+ºìÊ¨
	_wheelMap[GREEN_RABBIT_YELLOW_MONKEY_GREEN_MONKEY_RED_MONKEY_GREEN_PANDA] = WheelMsg( MANY, AnimalType( RABBIT , PEOPLE),  Green);//ÂÌÍÃ+»Æºï+ÂÌºï+ºìºï+ÂÌÃ¨

			
	/*   
	0x45 »ÆÍÃ+ºìÍÃ+ÂÌºï+»ÆÃ¨+ÂÌÃ¨+»ÆÊ¨
	0x46 »Æºï+»ÆÍÃ+ÂÌºï+ÂÌÃ¨+»ÆÊ¨+ºìÊ¨
	0x47 ÂÌºï+ºìºï+»ÆÃ¨+ÂÌÃ¨+ºìÃ¨+ÂÌÊ¨*/
	_wheelMap[YELLOW_RUBBIT_RED_RABBIT_GREEN_MONKEY_YELLOW_PANDA_GREEN_PANDA_YELLOW_LION] = WheelMsg( MANY, AnimalType( RABBIT , PEOPLE),  Yellow);// »ÆÍÃ+ºìÍÃ+ÂÌºï+»ÆÃ¨+ÂÌÃ¨+»ÆÊ¨
	_wheelMap[YELLOW_MOKEY_YELLOW_RABBIT_GREEN_MONKEY_GREEN_PANDA_YELLOW_LION_RED_LION] = WheelMsg( MANY, AnimalType( MONKEY , PEOPLE),  Yellow);//»Æºï+»ÆÍÃ+ÂÌºï+ÂÌÃ¨+»ÆÊ¨+ºìÊ¨
	_wheelMap[GREEN_MONKEY_RED_MONKEY_YELLOW_PANDA_GREEN_PANDA_RED_PANDA_GREEN_LION] = WheelMsg( MANY, AnimalType( MONKEY , PEOPLE),  Green);//ÂÌºï+ºìºï+»ÆÃ¨+ÂÌÃ¨+ºìÃ¨+ÂÌÊ¨



	 /*5,8,6,8,13,10,14,23,17,28,46,35,(»ÆÍÃ,ÂÌÍÃ,ºìÍÃ,»Æºï,ÂÌºï,ºìºï,»ÆÐÜ,ÂÌÐÜ,ºìÐÜ,»ÆÊ¨,ÂÌÊ¨,ºìÊ¨)
 5,6,7,8,10,11,15,17,26,31,35,40,
  7,5,6,11,8,10,20,15,17,40,31,35,
  4,7,8,7,11,13,12,20,23,25,40,46,
  7,8,4,11,13,7,20,23,12,40,46,25,
  8,4,7,13,7,11,23,12,20,46,25,40*/

	_rates[0][WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Yellow)] = 5;
	_rates[0][WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Green)] = 8;
	_rates[0][WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Red)] = 6;
	_rates[0][WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Yellow)] = 8;
	_rates[0][WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Green)] = 13;
	_rates[0][WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Red)] = 10;
	_rates[0][WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Yellow)] = 14;
	_rates[0][WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Green)] = 23;
	_rates[0][WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Red)] = 17;
	_rates[0][WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Yellow)] = 28;
	_rates[0][WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Green)] = 46;
	_rates[0][WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Red)] = 35;

////////////////////////////////////////////////////////////////////

	_rates[1][WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Yellow)] = 5;
	_rates[1][WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Green)] = 6;
	_rates[1][WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Red)] = 7;
	_rates[1][WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Yellow)] = 8;
	_rates[1][WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Green)] = 10;
	_rates[1][WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Red)] = 11;
	_rates[1][WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Yellow)] = 15;
	_rates[1][WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Green)] = 17;
	_rates[1][WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Red)] = 26;
	_rates[1][WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Yellow)] = 31;
	_rates[1][WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Green)] = 35;
	_rates[1][WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Red)] = 40;

///////////////////////////////////////////////////////////////////

	_rates[2][WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Yellow)] = 7;
	_rates[2][WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Green)] = 5;
	_rates[2][WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Red)] = 6;
	_rates[2][WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Yellow)] = 11;
	_rates[2][WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Green)] = 8;
	_rates[2][WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Red)] = 10;
	_rates[2][WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Yellow)] = 20;
	_rates[2][WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Green)] = 15;
	_rates[2][WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Red)] = 17;
	_rates[2][WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Yellow)] = 40;
	_rates[2][WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Green)] = 31;
	_rates[2][WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Red)] = 35;


	
///////////////////////////////////////////////////////////////////

	_rates[3][WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Yellow)] = 4;
	_rates[3][WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Green)] = 7;
	_rates[3][WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Red)] = 8;
	_rates[3][WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Yellow)] = 7;
	_rates[3][WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Green)] = 11;
	_rates[3][WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Red)] = 13;
	_rates[3][WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Yellow)] = 12;
	_rates[3][WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Green)] = 20;
	_rates[3][WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Red)] = 23;
	_rates[3][WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Yellow)] = 25;
	_rates[3][WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Green)] = 40;
	_rates[3][WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Red)] = 46;

///////////////////////////////////////////////////////////////////


	_rates[4][WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Yellow)] = 7;
	_rates[4][WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Green)] = 8;
	_rates[4][WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Red)] = 4;
	_rates[4][WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Yellow)] = 11;
	_rates[4][WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Green)] = 13;
	_rates[4][WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Red)] = 7;
	_rates[4][WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Yellow)] = 20;
	_rates[4][WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Green)] = 23;
	_rates[4][WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Red)] = 12;
	_rates[4][WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Yellow)] = 40;
	_rates[4][WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Green)] = 46;
	_rates[4][WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Red)] = 25;

///////////////////////////////////////////////////////////////////
 
	_rates[5][WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Yellow)] = 8;
	_rates[5][WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Green)] = 4;
	_rates[5][WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Red)] = 7;
	_rates[5][WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Yellow)] = 13;
	_rates[5][WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Green)] = 7;
	_rates[5][WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Red)] = 11;
	_rates[5][WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Yellow)] = 23;
	_rates[5][WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Green)] = 12;
	_rates[5][WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Red)] = 20;
	_rates[5][WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Yellow)] = 46;
	_rates[5][WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Green)] = 25;
	_rates[5][WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Red)] = 40;



///////////////////////////////////////////////////////////////////////

	
	TVListMapPtr listMap(new TVListMap());
	WheelEnum::TVListPtr list;


	//0x37   ºìÍÃ+»ÆÃ¨

	list.reset(new WheelEnum::TVList());
	list->push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Red));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Yellow));
	listMap->insert(*list->begin(), list);

	/*0x38   ÂÌÍÃ+ºìÃ¨*/

	
	list.reset(new WheelEnum::TVList());
	list->push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Green));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Red));
	listMap->insert(*list->begin(), list);

	/*0x39   »Æºï+ÂÌÊ¨*/

	list.reset(new WheelEnum::TVList());
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Green));
	listMap->insert(*list->begin(), list);

	//0x3a   »ÆÍÃ+ÂÌºï

	list.reset(new WheelEnum::TVList());
	list->push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Green));
	listMap->insert(*list->begin(), list);


	/*0x3b   ºìºï+ÂÌÃ¨*/
	
	list.reset(new WheelEnum::TVList());
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Red));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Green));
	listMap->insert(*list->begin(), list);

	
	_tvListMap[0] = listMap;


////////////////////////////////
	
	listMap.reset(new TVListMap());


//0x3c   »ÆÍÃ+ÂÌºï+ºìÊ¨

	list.reset(new WheelEnum::TVList());
	list->push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Green));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Red));
	listMap->insert(*list->begin(), list);

//0x3d   ÂÌÍÃ+ºìÍÃ+ÂÌÃ¨

	
	list.reset(new WheelEnum::TVList());
	list->push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Green));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Red));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Green));
	listMap->insert(*list->begin(), list);
//0x3e   ºìºï+»ÆÍÃ+»ÆÃ¨

	list.reset(new WheelEnum::TVList());
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Red));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Yellow));
	listMap->insert(*list->begin(), list);
	
	_tvListMap[1] = listMap;

////////////////////////////////
	
	listMap.reset(new TVListMap());

//0x3f   »ÆÍÃ+ºìÍÃ+»Æºï+ÂÌÃ¨


	list.reset(new WheelEnum::TVList());
	list->push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Red));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Green));
	listMap->insert(*list->begin(), list);

//0x43 ÂÌÍÃ+ÂÌºï+»Æºï+»ÆÃ¨

	
	list.reset(new WheelEnum::TVList());
	list->push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Green));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Green));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Yellow));
	listMap->insert(*list->begin(), list);

//0x44 »Æºï+»ÆÍÃ+ÂÌºï+»ÆÊ¨

	list.reset(new WheelEnum::TVList());
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Green));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Yellow));
	listMap->insert(*list->begin(), list);
	
	_tvListMap[2] = listMap;


////////////////////////////////////////
	

	listMap.reset(new TVListMap());

//0x42  ºìÍÃ+»Æºï+ºìºï+»ÆÃ¨+ÂÌºï

	list.reset(new WheelEnum::TVList());
	list->push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Red));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Red));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Green));
	listMap->insert(*list->begin(), list);

//0x43  »ÆÍÃ+ºìÍÃ+»ÆÃ¨+ÂÌÃ¨+ºìÊ¨
	
	list.reset(new WheelEnum::TVList());
	list->push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Red));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Green));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Red));
	listMap->insert(*list->begin(), list);

//0x44 ÂÌÍÃ+»Æºï+ÂÌºï+ºìºï+ÂÌÃ¨

	list.reset(new WheelEnum::TVList());
	list->push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Green));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Green));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Red));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Green));
	listMap->insert(*list->begin(), list);
	
	_tvListMap[3] = listMap;



////////////////////////////////////////
	

	listMap.reset(new TVListMap());

//0x45 »ÆÍÃ+ºìÍÃ+ÂÌºï+»ÆÃ¨+ÂÌÃ¨+»ÆÊ¨

	list.reset(new WheelEnum::TVList());
	list->push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Red));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Green));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Green));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Yellow));
	listMap->insert(*list->begin(), list);

//0x46  »Æºï+»ÆÍÃ+ÂÌºï+ÂÌÃ¨+»ÆÊ¨+ºìÊ¨
	
	list.reset(new WheelEnum::TVList());
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Green));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Green));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Red));
	listMap->insert(*list->begin(), list);

//0x47 ÂÌºï+ºìºï+»ÆÃ¨+ÂÌÃ¨+ºìÃ¨+ÂÌÊ¨

	list.reset(new WheelEnum::TVList());
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Green));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Red));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Green));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Red));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Green));
	listMap->insert(*list->begin(), list);
	
	_tvListMap[4] = listMap;

}
int getN(WheelEnum::HARDWARE_WIN_MODE mode)
{
	using namespace WheelEnum;
	switch(mode)
	{
	case RED_RABBIT_YELLOW_PANDA:
	case GREEN_RABBIT_RED_PANDA:
	case YELLOW_MONKEY_GREEN_LION:
	case YELLOW_RABBIT_GREEN_MONKEY:
	case RED_MONKEY_GREEN_PANDA:
		return 0;
	case YELLOW_RABBIT_GREEN_MONKEY_RED_LION:
	case GREEN_RABBIT_RED_RABBIT_GREEN_PANDA:
	case RED_MONKEY_YELLOW_RABBIT_YELLOW_PANDA:
		return 1;
		
	case YELLOW_RABBIT_RED_RABBIT_YELLOW_MANKEY_GREEN_PANDA:
	case GREEN_RABBIT_GREEN_MONKEY_YELLOW_MONKEY_YELLOW_PANDA:
	case YELLOW_MONKEY_YELLOW_RABBIT_GREEN_PANDA_YELLOW_LION:
		return 2;
	case RED_RABBIT_YELLOW_MONKEY_RED_MONKEY_YELLOW_PANDA_GREEN_MONKEY:
	case YELLOW_RABBIT_RED_RABBIT_YELLOW_PANDA_GREEN_PANDA_RED_LION:
	case GREEN_RABBIT_YELLOW_MONKEY_GREEN_MONKEY_RED_MONKEY_GREEN_PANDA:
		return 3;
	case YELLOW_RUBBIT_RED_RABBIT_GREEN_MONKEY_YELLOW_PANDA_GREEN_PANDA_YELLOW_LION:
	case YELLOW_MOKEY_YELLOW_RABBIT_GREEN_MONKEY_GREEN_PANDA_YELLOW_LION_RED_LION:
	case GREEN_MONKEY_RED_MONKEY_YELLOW_PANDA_GREEN_PANDA_RED_PANDA_GREEN_LION:
		return 4;
			
	}
	return 4;
}
		
bool WheelData_::hasTVNext(WheelEnum::HARDWARE_WIN_MODE mode,  WheelEnum::AnimalItem ai, size_t i)
{
	TVListMapPtr listMap = _tvListMap[getN(mode)];
	return listMap->hasAnimalItem(ai, i);
}
WheelEnum::AnimalItem WheelData_::getTVNext(WheelEnum::HARDWARE_WIN_MODE mode,  WheelEnum::AnimalItem ai, size_t i)
{
	TVListMapPtr listMap = _tvListMap[getN(mode)];
	return listMap->getAnimalItem(ai, i);
}
int WheelData_::getOverride(WheelEnum::AnimalItem ai) 
{

	return _rates[_rate][ai];
}


void WheelData_::setRate(WheelEnum::RATE rate) 
{
	_rate = rate;
}


WheelData_ & WheelData_::getInstance(void)
{
	return *(getInstancePtr());
}
WheelData_ * WheelData_::getInstancePtr(void)
{
	static WheelData_ instance;
	return &instance;
}

//WheelEnum::RATE

const WheelData_::WheelMsg & WheelData_::getWheelMsg(WheelEnum::HARDWARE_WIN_MODE mode) const
{
	WheelMap::const_iterator it = _wheelMap.find(mode);
	if(it == _wheelMap.end())
	{
		throw ORZ_EXCEPTION(Exception::ERR_ITEM_NOT_FOUND)<<errno_info_text("Can't find WheelEnum::HARDWARE_WIN_MODE in the _wheelMap!");
	}
	return it->second;
}