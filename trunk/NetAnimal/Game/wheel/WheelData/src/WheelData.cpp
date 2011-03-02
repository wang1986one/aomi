#include "WheelData.h"
#include <orz/Toolkit_Base/Exception.h>
using namespace Orz;
//WheelData::~WheelData(void)
//{
//
//}
WheelData::WheelData(void)
{
	
	using namespace WheelEnum;
	using namespace AnimalEnum;


	/*  0x00   »ÆÍÃ
	0x01   ÂÌÍÃ
	0x02   ºìÍÃ*/
	
	_wheelMap[YELLOW_RABBIT] = WheelMsg( NONE, ANIMAL_TYPE( RABBIT , PEOPLE),  Yellow); 
	_wheelMap[GREEN_RABBIT] = WheelMsg( NONE, ANIMAL_TYPE( RABBIT , PEOPLE),  Green); //0x01  ÂÌÍÃ
	_wheelMap[RED_RABBIT] = WheelMsg( NONE, ANIMAL_TYPE( RABBIT , PEOPLE),  Red);   //0x02  ºìÍÃ



	_wheelMap[YELLOW_MONKEY] = WheelMsg( NONE, ANIMAL_TYPE( MONKEY , PEOPLE),  Yellow);//»Æºï 
	_wheelMap[GREEN_MONKEY] = WheelMsg( NONE, ANIMAL_TYPE( MONKEY , PEOPLE),  Green); //ÂÌºï
	_wheelMap[RED_MONKEY] = WheelMsg( NONE, ANIMAL_TYPE( MONKEY , PEOPLE),  Red);   //ºìºï

	/*   
	0x06   »ÆÐÜÃ¨
	0x07   ÂÌÐÜÃ¨
	0x08   ºìÐÜÃ¨*/


	_wheelMap[YELLOW_PANDA] = WheelMsg( NONE, ANIMAL_TYPE( PANDA , PEOPLE),  Yellow); //»ÆÐÜÃ¨
	_wheelMap[GREEN_PANDA] = WheelMsg( NONE, ANIMAL_TYPE( PANDA , PEOPLE),  Green); //ÂÌÐÜÃ¨
	_wheelMap[RED_PANDA] = WheelMsg( NONE, ANIMAL_TYPE( PANDA , PEOPLE),  Red);  //ºìÐÜÃ¨



	/*
	0x09   »ÆÊ¨×Ó
	0x0A   ÂÌÊ¨×Ó
	0x0B   ºìÊ¨×Ó*/


	_wheelMap[YELLOW_LION] = WheelMsg( NONE, ANIMAL_TYPE( LION , PEOPLE),  Yellow); //  »ÆÊ¨×Ó
	_wheelMap[GREEN_LION] = WheelMsg( NONE, ANIMAL_TYPE( LION , PEOPLE),  Green);//ÂÌÊ¨×Ó 
	_wheelMap[RED_LION] = WheelMsg( NONE, ANIMAL_TYPE( LION , PEOPLE),  Red); //	ºìÊ¨×Ó


	
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



	_wheelMap[G_YELLOW_RABBIT] = WheelMsg( GOLD, ANIMAL_TYPE( RABBIT , KING),  Yellow); //	»Æ½ðÍÃ
	_wheelMap[G_GREEN_RABBIT] = WheelMsg( GOLD, ANIMAL_TYPE( RABBIT , KING),  Green); //ÂÌ½ðÍÃ
	_wheelMap[G_RED_RABBIT] = WheelMsg( GOLD, ANIMAL_TYPE( RABBIT , KING),  Red); // ºì½ðÍÃ

	_wheelMap[G_YELLOW_MONKEY] = WheelMsg( GOLD, ANIMAL_TYPE( MONKEY , KING),  Yellow);//»Æ½ðºï
	_wheelMap[G_GREEN_MONKEY] = WheelMsg( GOLD, ANIMAL_TYPE( MONKEY , KING),  Green); //	ÂÌ½ðºï
	_wheelMap[G_RED_MONKEY] = WheelMsg( GOLD, ANIMAL_TYPE( MONKEY , KING),  Red);   // ºì½ðºï


	_wheelMap[G_YELLOW_PANDA] = WheelMsg( GOLD, ANIMAL_TYPE( PANDA , KING),  Yellow); //»Æ½ðÐÜÃ¨
	_wheelMap[G_GREEN_PANDA] = WheelMsg( GOLD, ANIMAL_TYPE( PANDA , KING),  Green); //ÂÌ½ðÐÜÃ¨
	_wheelMap[G_RED_PANDA] = WheelMsg( GOLD, ANIMAL_TYPE( PANDA , KING),  Red);  //ºì½ðÐÜÃ¨

	_wheelMap[G_YELLOW_LION] = WheelMsg( GOLD, ANIMAL_TYPE( LION , KING),  Yellow); //  »Æ½ðÊ¨×Ó
	_wheelMap[G_GREEN_LION] = WheelMsg( GOLD, ANIMAL_TYPE( LION , KING),  Green);//ÂÌ½ðÊ¨×Ó
	_wheelMap[G_RED_LION] = WheelMsg( GOLD, ANIMAL_TYPE( LION , KING),  Red);//ºì½ðÊ¨×Ó
		

	/*    
	0x18   »ÆÉ«È«ÖÐ
	0x19   ÂÌÉ«È«ÖÐ
	0x1a   ºìÉ«È«ÖÐ*/



	_wheelMap[ALL_YELLOW] = WheelMsg( ALL_COLOR, ANIMAL_TYPE( LION , PEOPLE),  Yellow); //   »ÆÉ«È«ÖÐ
	_wheelMap[ALL_GREEN] = WheelMsg( ALL_COLOR, ANIMAL_TYPE( LION , PEOPLE),  Green); //  ÂÌÉ«È«ÖÐ
	_wheelMap[ALL_RED] = WheelMsg( ALL_COLOR, ANIMAL_TYPE( LION , PEOPLE),  Red);  // ºìÉ«È«ÖÐ
	/*   
	0x1b   ÍÃ×ÓÈ«ÖÐ
	0x1c   ºï×ÓÈ«ÖÐ
	0x1d    ÐÜÃ¨È«ÖÐ
	0x1e   Ê¨×ÓÈ«ÖÐ*/





	_wheelMap[ALL_RABBIT] = WheelMsg( ALL_ANIMAL, ANIMAL_TYPE( RABBIT , PEOPLE),  Yellow); //   ÍÃ×ÓÈ«ÖÐ
	_wheelMap[ALL_MONKEY] = WheelMsg( ALL_ANIMAL, ANIMAL_TYPE( MONKEY , PEOPLE),  Green);// ºï×ÓÈ«ÖÐ
	_wheelMap[ALL_PANDA] = WheelMsg( ALL_ANIMAL, ANIMAL_TYPE( PANDA , PEOPLE),  Red); //   ÐÜÃ¨È«ÖÐ
	_wheelMap[ALL_LION] = WheelMsg( ALL_ANIMAL, ANIMAL_TYPE( LION , PEOPLE),  Red); //     Ê¨×ÓÈ«ÖÐ                      

		

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






	_wheelMap[DOUBLE_YELLOW_RABBIT] = WheelMsg( DOUBLE, ANIMAL_TYPE( RABBIT , PEOPLE),  Yellow); //	»ÆÍÃ2±¶
	_wheelMap[DOUBLE_GREEN_RABBIT] = WheelMsg( DOUBLE, ANIMAL_TYPE( RABBIT , PEOPLE),  Green); //ÂÌÍÃ2±¶
	_wheelMap[DOUBLE_RED_RABBIT] = WheelMsg( DOUBLE, ANIMAL_TYPE( RABBIT , PEOPLE),  Red); // ºìÍÃ	2±¶

	_wheelMap[DOUBLE_YELLOW_MONKEY] = WheelMsg( DOUBLE, ANIMAL_TYPE( MONKEY , PEOPLE),  Yellow);//»Æºï 2±¶
	_wheelMap[DOUBLE_GREEN_MONKEY] = WheelMsg( DOUBLE, ANIMAL_TYPE( MONKEY , PEOPLE),  Green); //	ÂÌºï 2±¶
	_wheelMap[DOUBLE_RED_MONKEY] = WheelMsg( DOUBLE, ANIMAL_TYPE( MONKEY , PEOPLE),  Red);   // ºìºï2±¶


	_wheelMap[DOUBLE_YELLOW_PANDA] = WheelMsg( DOUBLE, ANIMAL_TYPE( PANDA , PEOPLE),  Yellow); //»ÆÐÜÃ¨	2±¶
	_wheelMap[DOUBLE_GREEN_PANDA] = WheelMsg( DOUBLE, ANIMAL_TYPE( PANDA , PEOPLE),  Green); //ÂÌÐÜÃ¨2±¶
	_wheelMap[DOUBLE_RED_PANDA] = WheelMsg( DOUBLE, ANIMAL_TYPE( PANDA , PEOPLE),  Red);  //ºìÐÜÃ¨ 2±¶

	_wheelMap[DOUBLE_YELLOW_LION] = WheelMsg( DOUBLE, ANIMAL_TYPE( LION , PEOPLE),  Yellow); //  »ÆÊ¨×Ó2±¶
	_wheelMap[DOUBLE_GREEN_LION] = WheelMsg( DOUBLE, ANIMAL_TYPE( LION , PEOPLE),  Green);//ÂÌÊ¨×Ó	 2±¶
	_wheelMap[DOUBLE_RED_LION] = WheelMsg( DOUBLE, ANIMAL_TYPE( LION , PEOPLE),  Red); //	ºìÊ¨×Ó   2±¶


		
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



	_wheelMap[TREBLE_YELLOW_RABBIT] = WheelMsg( TREBLE, ANIMAL_TYPE( RABBIT , PEOPLE),  Yellow); //	»ÆÍÃ3±¶
	_wheelMap[TREBLE_GREEN_RABBIT] = WheelMsg( TREBLE, ANIMAL_TYPE( RABBIT , PEOPLE),  Green); //ÂÌÍÃ3±¶
	_wheelMap[TREBLE_RED_RABBIT] = WheelMsg( TREBLE, ANIMAL_TYPE( RABBIT , PEOPLE),  Red); // ºìÍÃ	3±¶

	_wheelMap[TREBLE_YELLOW_MONKEY] = WheelMsg( TREBLE, ANIMAL_TYPE( MONKEY , PEOPLE),  Yellow);//»Æºï 3±¶
	_wheelMap[TREBLE_GREEN_MONKEY] = WheelMsg( TREBLE, ANIMAL_TYPE( MONKEY , PEOPLE),  Green); //	ÂÌºï 3±¶
	_wheelMap[TREBLE_RED_MONKEY] = WheelMsg( TREBLE, ANIMAL_TYPE( MONKEY , PEOPLE),  Red);   // ºìºï3±¶


	_wheelMap[TREBLE_YELLOW_PANDA] = WheelMsg( TREBLE, ANIMAL_TYPE( PANDA , PEOPLE),  Yellow); //»ÆÐÜÃ¨	3±¶
	_wheelMap[TREBLE_GREEN_PANDA] = WheelMsg( TREBLE, ANIMAL_TYPE( PANDA , PEOPLE),  Green); //ÂÌÐÜÃ¨3±¶
	_wheelMap[TREBLE_RED_PANDA] = WheelMsg( TREBLE, ANIMAL_TYPE( PANDA , PEOPLE),  Red);  //ºìÐÜÃ¨ 3±¶

	_wheelMap[TREBLE_YELLOW_LION] = WheelMsg( TREBLE, ANIMAL_TYPE( LION , PEOPLE),  Yellow); //  »ÆÊ¨×Ó3±¶
	_wheelMap[TREBLE_GREEN_LION] = WheelMsg( TREBLE, ANIMAL_TYPE( LION , PEOPLE),  Green);//ÂÌÊ¨×Ó	 3±¶
	_wheelMap[TREBLE_RED_LION] = WheelMsg( TREBLE, ANIMAL_TYPE( LION , PEOPLE),  Red);//ºìÊ¨×Ó	 3±¶


	/*   
	0x37   ºìÍÃ+»ÆÃ¨
	0x38   ÂÌÍÃ+ºìÃ¨
	0x39   »Æºï+ÂÌÊ¨
	0x3a   »ÆÍÃ+ÂÌºï
	0x3b   ºìºï+ÂÌÃ¨*/




	_wheelMap[RED_RABBIT_YELLOW_PANDA] = WheelMsg( ONE, ANIMAL_TYPE( RABBIT , PEOPLE),  Red);//ºìÍÃ+»ÆÃ¨
	_wheelMap[GREEN_RABBIT_RED_PANDA] = WheelMsg( ONE, ANIMAL_TYPE( RABBIT , PEOPLE),  Green);//ÂÌÍÃ+ºìÃ¨
	_wheelMap[YELLOW_MONKEY_GREEN_LION] = WheelMsg( ONE, ANIMAL_TYPE( MONKEY , PEOPLE),  Yellow);//»Æºï+ÂÌÊ¨
	_wheelMap[YELLOW_RABBIT_GREEN_MONKEY] = WheelMsg( ONE, ANIMAL_TYPE( RABBIT , PEOPLE),  Yellow);//»ÆÍÃ+ÂÌºï
	_wheelMap[RED_MONKEY_GREEN_PANDA] = WheelMsg( ONE, ANIMAL_TYPE( MONKEY , PEOPLE),  Red);//ºìºï+ÂÌÃ¨

	//0x3c   »ÆÍÃ+ÂÌºï+ºìÊ¨
	//0x3d   ÂÌÍÃ+ºìÍÃ+ÂÌÃ¨
	//0x3e   ºìºï+»ÆÍÃ+»ÆÃ¨

	_wheelMap[YELLOW_RABBIT_GREEN_MONKEY_RED_LION] = WheelMsg( TWO, ANIMAL_TYPE( RABBIT , PEOPLE),  Yellow);//»ÆÍÃ+ÂÌºï+ºìÊ¨
	_wheelMap[GREEN_RABBIT_RED_RABBIT_GREEN_PANDA] = WheelMsg( TWO, ANIMAL_TYPE( RABBIT , PEOPLE),  Green);//ÂÌÍÃ+ºìÍÃ+ÂÌÃ¨
	_wheelMap[RED_MONKEY_YELLOW_RABBIT_YELLOW_PANDA] = WheelMsg( TWO, ANIMAL_TYPE( MONKEY , PEOPLE),  Red);// ºìºï+»ÆÍÃ+»ÆÃ¨


	//0x3f   »ÆÍÃ+ºìÍÃ+»Æºï+ÂÌÃ¨
	//0x40   ÂÌÍÃ+ÂÌºï+»Æºï+»ÆÃ¨
	//0x41  »Æºï+»ÆÍÃ+ÂÌºï+»ÆÊ¨


	_wheelMap[YELLOW_RABBIT_RED_RABBIT_YELLOW_MANKEY_GREEN_PANDA] = WheelMsg( THREE, ANIMAL_TYPE( RABBIT , PEOPLE),  Yellow);// »ÆÍÃ+ºìÍÃ+»Æºï+ÂÌÃ¨
	_wheelMap[GREEN_RABBIT_GREEN_MONKEY_YELLOW_MONKEY_YELLOW_PANDA] = WheelMsg( THREE, ANIMAL_TYPE( RABBIT , PEOPLE),  Green);//ÂÌÍÃ+ÂÌºï+»Æºï+»ÆÃ¨
	_wheelMap[YELLOW_MONKEY_YELLOW_RABBIT_GREEN_PANDA_YELLOW_LION] = WheelMsg( THREE, ANIMAL_TYPE( MONKEY , PEOPLE),  Yellow);//»Æºï+»ÆÍÃ+ÂÌºï+»ÆÊ¨

	/*   0x42  ºìÍÃ+»Æºï+ºìºï+»ÆÃ¨+ÂÌºï
	0x43  »ÆÍÃ+ºìÍÃ+»ÆÃ¨+ÂÌÃ¨+ºìÊ¨
	0x44  ÂÌÍÃ+»Æºï+ÂÌºï+ºìºï+ÂÌÃ¨*/
	_wheelMap[RED_RABBIT_YELLOW_MONKEY_RED_MONKEY_YELLOW_PANDA_GREEN_MONKEY] = WheelMsg( FOUR, ANIMAL_TYPE( RABBIT , PEOPLE),  Red);// ºìÍÃ+»Æºï+ºìºï+»ÆÃ¨+ÂÌºï
	_wheelMap[YELLOW_RABBIT_RED_RABBIT_YELLOW_PANDA_GREEN_PANDA_RED_LION] = WheelMsg( FOUR, ANIMAL_TYPE( RABBIT , PEOPLE),  Yellow);//»ÆÍÃ+ºìÍÃ+»ÆÃ¨+ÂÌÃ¨+ºìÊ¨
	_wheelMap[GREEN_RABBIT_YELLOW_MONKEY_GREEN_MONKEY_RED_MONKEY_GREEN_PANDA] = WheelMsg( FOUR, ANIMAL_TYPE( RABBIT , PEOPLE),  Green);//ÂÌÍÃ+»Æºï+ÂÌºï+ºìºï+ÂÌÃ¨

			
	/*   
	0x45 »ÆÍÃ+ºìÍÃ+ÂÌºï+»ÆÃ¨+ÂÌÃ¨+»ÆÊ¨
	0x46 »Æºï+»ÆÍÃ+ÂÌºï+ÂÌÃ¨+»ÆÊ¨+ºìÊ¨
	0x47 ÂÌºï+ºìºï+»ÆÃ¨+ÂÌÃ¨+ºìÃ¨+ÂÌÊ¨*/
	_wheelMap[YELLOW_RUBBIT_RED_RABBIT_GREEN_MONKEY_YELLOW_PANDA_GREEN_PANDA_YELLOW_LION] = WheelMsg( FIVE, ANIMAL_TYPE( RABBIT , PEOPLE),  Yellow);// »ÆÍÃ+ºìÍÃ+ÂÌºï+»ÆÃ¨+ÂÌÃ¨+»ÆÊ¨
	_wheelMap[YELLOW_MOKEY_YELLOW_RABBIT_GREEN_MONKEY_GREEN_PANDA_YELLOW_LION_RED_LION] = WheelMsg( FIVE, ANIMAL_TYPE( MONKEY , PEOPLE),  Yellow);//»Æºï+»ÆÍÃ+ÂÌºï+ÂÌÃ¨+»ÆÊ¨+ºìÊ¨
	_wheelMap[GREEN_MONKEY_RED_MONKEY_YELLOW_PANDA_GREEN_PANDA_RED_PANDA_GREEN_LION] = WheelMsg( FIVE, ANIMAL_TYPE( MONKEY , PEOPLE),  Green);//ÂÌºï+ºìºï+»ÆÃ¨+ÂÌÃ¨+ºìÃ¨+ÂÌÊ¨









}


WheelData & WheelData::getInstance(void)
{
	return *(getInstancePtr());
}
WheelData * WheelData::getInstancePtr(void)
{
	static WheelData instance;
	return &instance;
}

const WheelData::WheelMsg & WheelData::getWheelMsg(WheelEnum::HARDWARE_WIN_MODE mode) const
{
	WheelMap::const_iterator it = _wheelMap.find(mode);
	if(it == _wheelMap.end())
	{
		throw ORZ_EXCEPTION(Exception::ERR_ITEM_NOT_FOUND)<<errno_info_text("Can't find WheelEnum::HARDWARE_WIN_MODE in the _wheelMap!");
	}
	return it->second;
}