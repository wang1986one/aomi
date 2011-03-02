#ifndef __Orz_WheelEnum_h__
#define __Orz_WheelEnum_h__	


#include "WheelGobalConfig.h"
#include <orz/Toolkit_Base/Variant.h>
namespace Orz
{

	namespace WheelEnum
	{
		enum WINNER
		{
			Dealer = 0,//×°
			Player = 1,//ÏÐ
			Draw = 2//ºÍ
		};

		typedef WINNER Winner;
		enum LIGHT_COLOR
		{
			Red = 0,
			Yellow = 1,
			Green  =2,
			Blue =3,
			DeepBlue = 4
		};
		
		typedef LIGHT_COLOR LightColor;
		enum WIN_MODE
		{
			NONE,
			ALL_ANIMAL,
			ALL_COLOR,
			DOUBLE,
			TREBLE,
			GOLD,
			MANY,
			/*ONE = MANY,
			TWO,
			THREE,
			FOUR,
			FIVE*/
		};

		typedef WIN_MODE WinMode;
		enum RATE
		{
			MODE0 = 0,
			MODE1 = 1,
			MODE2 = 2,
			MODE3 = 3,
			MODE4 = 4,
			MODE5 = 5
		};

		typedef RATE Rate;
		enum HARDWARE_WIN_MODE
		{
			YELLOW_RABBIT = 0,
			GREEN_RABBIT,
			RED_RABBIT,
			YELLOW_MONKEY = 3,
			GREEN_MONKEY,
			RED_MONKEY,
			YELLOW_PANDA = 0x6,
			GREEN_PANDA,
			RED_PANDA,
			YELLOW_LION,
			GREEN_LION,
			RED_LION,
			G_YELLOW_RABBIT,
			G_GREEN_RABBIT,
			G_RED_RABBIT,
			G_YELLOW_MONKEY,
			G_GREEN_MONKEY,
			G_RED_MONKEY,
			G_YELLOW_PANDA,
			G_GREEN_PANDA,
			G_RED_PANDA,
			G_YELLOW_LION,
			G_GREEN_LION,
			G_RED_LION,
			ALL_YELLOW,
			ALL_GREEN,
			ALL_RED,
			ALL_RABBIT,
			ALL_MONKEY,
			ALL_PANDA,
			ALL_LION,
			DOUBLE_YELLOW_RABBIT,
			DOUBLE_GREEN_RABBIT,
			DOUBLE_RED_RABBIT,
			DOUBLE_YELLOW_MONKEY,
			DOUBLE_GREEN_MONKEY,
			DOUBLE_RED_MONKEY,
			DOUBLE_YELLOW_PANDA,
			DOUBLE_GREEN_PANDA,
			DOUBLE_RED_PANDA,
			DOUBLE_YELLOW_LION,
			DOUBLE_GREEN_LION,
			DOUBLE_RED_LION,
			TREBLE_YELLOW_RABBIT,
			TREBLE_GREEN_RABBIT,
			TREBLE_RED_RABBIT,
			TREBLE_YELLOW_MONKEY,
			TREBLE_GREEN_MONKEY,
			TREBLE_RED_MONKEY,
			TREBLE_YELLOW_PANDA, 
			TREBLE_GREEN_PANDA,
			TREBLE_RED_PANDA,
			TREBLE_YELLOW_LION,
			TREBLE_GREEN_LION,
			TREBLE_RED_LION,
			RED_RABBIT_YELLOW_PANDA,
			GREEN_RABBIT_RED_PANDA,
			YELLOW_MONKEY_GREEN_LION,
			YELLOW_RABBIT_GREEN_MONKEY,
			RED_MONKEY_GREEN_PANDA,
			YELLOW_RABBIT_GREEN_MONKEY_RED_LION,
			GREEN_RABBIT_RED_RABBIT_GREEN_PANDA,
			RED_MONKEY_YELLOW_RABBIT_YELLOW_PANDA,
			YELLOW_RABBIT_RED_RABBIT_YELLOW_MANKEY_GREEN_PANDA,
			GREEN_RABBIT_GREEN_MONKEY_YELLOW_MONKEY_YELLOW_PANDA,
			YELLOW_MONKEY_YELLOW_RABBIT_GREEN_PANDA_YELLOW_LION,
			RED_RABBIT_YELLOW_MONKEY_RED_MONKEY_YELLOW_PANDA_GREEN_MONKEY,
			YELLOW_RABBIT_RED_RABBIT_YELLOW_PANDA_GREEN_PANDA_RED_LION,
			GREEN_RABBIT_YELLOW_MONKEY_GREEN_MONKEY_RED_MONKEY_GREEN_PANDA,
			YELLOW_RUBBIT_RED_RABBIT_GREEN_MONKEY_YELLOW_PANDA_GREEN_PANDA_YELLOW_LION,
			YELLOW_MOKEY_YELLOW_RABBIT_GREEN_MONKEY_GREEN_PANDA_YELLOW_LION_RED_LION,
			GREEN_MONKEY_RED_MONKEY_YELLOW_PANDA_GREEN_PANDA_RED_PANDA_GREEN_LION
		};
		const std::string WINNER_STR("Wheel:Winner");
		const std::string BONUS_STR("Wheel:Bonus");
		const std::string WHEELMSG_STR("Wheel:WheelMsg");
		const std::string SETTIME_STR("Wheel:SetTime");
		const std::string RATE_STR("Wheel:RATE");
		const std::string REPORT_STR("Wheel:Report");
		const std::string SETUP_STR("Wheel:Setup");


		
		enum ACTION_TYPE
		{
			ACTION1,  
			ACTION2,
			ACTION3,
			ACTION4
		};

		enum STATUS
		{
			KING,
			PEOPLE 
		};
		enum TYPE
		{
			TYPE0 =0,		//RABBIT
			TYPE1 =1,		//MONKEY
			TYPE2 =2,		//PANDA
			TYPE3 =3,		//LION
			RABBIT = TYPE0,
			MONKEY = TYPE1,
			PANDA = TYPE2,
			LION = TYPE3,
			NO_TYPE
		};
		
		typedef std::pair<TYPE, STATUS> ANIMAL_TYPE;
		typedef ANIMAL_TYPE AnimalType;
		typedef std::pair<TYPE, WheelEnum::LIGHT_COLOR> ANIMAL_ITEM;
		typedef ANIMAL_ITEM AnimalItem;
	

	
	
		typedef std::vector<AnimalItem > TVList;
		typedef boost::shared_ptr<TVList> TVListPtr;
		typedef std::map<AnimalItem , TVListPtr> ListMap;
		typedef std::pair<RATE, AnimalItem > RateKey;
		typedef std::map<AnimalItem , int> ModeMap;
		
	}

	namespace AnimalEnum = WheelEnum;
}

#endif



