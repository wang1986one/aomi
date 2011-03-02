#ifndef __Orz_UIList__
#define __Orz_UIList__
//#include <boost/multi_array.hpp>
//#include <iostream>
//#include <CEGUI/cegui.h>
//#include "WheelEnum.h"
//#include "UIAnimation.h"
#include <WheelGobal/WheelEnum.h>
#include "ui/Number.h"
#include <boost/multi_array.hpp>
namespace Orz
{

	class UIList
	{

	public:
		UIList(void):_multiArray(boost::extents[3][4])
		{
			_multiArray[WheelEnum::Red][AnimalEnum::TYPE0] = "set:sanall image:feng_gong";
			_multiArray[WheelEnum::Red][AnimalEnum::TYPE1]  = "set:sanall image:lin_gong";
			_multiArray[WheelEnum::Red][AnimalEnum::TYPE2]  = "set:sanall image:huo_gong";
			_multiArray[WheelEnum::Red][AnimalEnum::TYPE3]  = "set:sanall image:shan_gong";

			_multiArray[WheelEnum::Yellow][AnimalEnum::TYPE0]  = "set:sanall image:feng_ma";
			_multiArray[WheelEnum::Yellow][AnimalEnum::TYPE1]  = "set:sanall image:lin_ma";
			_multiArray[WheelEnum::Yellow][AnimalEnum::TYPE2]  = "set:sanall image:huo_ma";
			_multiArray[WheelEnum::Yellow][AnimalEnum::TYPE3]  = "set:sanall image:shan_ma";

			_multiArray[WheelEnum::Green][AnimalEnum::TYPE0]  = "set:sanall image:feng_bu";
			_multiArray[WheelEnum::Green][AnimalEnum::TYPE1]  = "set:sanall image:lin_bu";
			_multiArray[WheelEnum::Green][AnimalEnum::TYPE2]  = "set:sanall image:huo_bu";
			_multiArray[WheelEnum::Green][AnimalEnum::TYPE3]  = "set:sanall image:shan_bu";



		}

		void add(/*const WinData & WinData::getInstance()*/)
		{
			_winDataList.push_front(WinData::getInstance().getClone());
			if(_winDataList.size() > 10)
			{
				_winDataList.resize(10);
			}
			draw();
		}
		void draw(void)
		{
			size_t i =0;
			for(; i<_winDataList.size(); i++)
			{
				setVisible(i, true);
				draw(i, _winDataList.at(i));
			}
			for(;i < 10; ++i)
			{
				setVisible(i, false);
			}
		}
		void draw(size_t i, const WinDataClone & data)
		{


			/*namespace WheelEnum
			{*/
			//enum WINNER
			//{
			//	Dealer,//×°
			//	Player,//ÏÐ
			//	Draw//ºÍ
			//};
			//enum LIGHT_COLOR
			//{
			//	Red = 0,
			//	Yellow = 1,
			//	Green  =2,
			//	Blue =3,
			//	DeepBlue = 4
			//};
			//enum WIN_MODE
			//{
			//	NONE,
			//	ALL_ANIMAL,
			//	ALL_COLOR,
			//	DOUBLE,
			//	TREBLE,
			//	GOLD,
			//	ONE,
			//	TWO,
			//	THREE,
			//	FOUR,
			//	FIVE
			//};

			//	
			//	

			std::string id = boost::lexical_cast<std::string>(i);
			CEGUI::Window*  flhs =  CEGUI::WindowManager::getSingleton().getWindow("main/list/win/what/flhs" + id); 
			flhs->hide();



			CEGUI::Window*  wsw =  CEGUI::WindowManager::getSingleton().getWindow("main/list/win/3guo" + id); 

			switch(data.getWinner())
			{
			case WheelEnum::Dealer:
				wsw->setProperty("Image", "set:sanall image:wei");
				break;
			case  WheelEnum::Player:
				wsw->setProperty("Image", "set:sanall image:shu");
				break;
			case  WheelEnum::Draw:
				wsw->setProperty("Image", "set:sanall image:wu");
				break;

			}


			CEGUI::Window* doubleWindow = CEGUI::WindowManager::getSingleton().getWindow("main/list/win/double" + id);
			if(data.getWinMode() == WheelEnum::DOUBLE)
			{

				doubleWindow->setVisible(true);
				doubleWindow->setProperty("Image", "set:sanall image:double");
			}
			else if(data.getWinMode() == WheelEnum::TREBLE)
			{

				doubleWindow->setVisible(true);
				doubleWindow->setProperty("Image", "set:sanall image:treble");
			}else 
				doubleWindow->setVisible(false);

			CEGUI::Window* what =  CEGUI::WindowManager::getSingleton().getWindow("main/list/win/what" + id);

			switch(data.getWinMode())
			{
		/*	case WheelEnum::ONE:
				what->setProperty("Image", "set:sanall image:yi");
				break;
			case WheelEnum::TWO:
				what->setProperty("Image", "set:sanall image:er");
				break;
			case WheelEnum::THREE:
				what->setProperty("Image", "set:sanall image:san");
				break;
			case WheelEnum::FOUR:
				what->setProperty("Image", "set:sanall image:si");
				break;
			case WheelEnum::FIVE:
				what->setProperty("Image", "set:sanall image:wu5");
				break;*/
			case WheelEnum::GOLD:
				{
					switch(data.getLightColor())
					{
					case WheelEnum::Red:
						what->setProperty("Image", "set:sanall image:huangyueying");
						break;

					case WheelEnum::Yellow:
						what->setProperty("Image", "set:sanall image:zhaoyun");
						break;

					case WheelEnum::Green:
						what->setProperty("Image", "set:sanall image:zhangfei");
						break;


					}


					switch(data.getType())
					{
					case AnimalEnum::TYPE0:
						flhs->setProperty("Image", "set:sanall image:feng");
						break;

					case AnimalEnum::TYPE1:
						flhs->setProperty("Image", "set:sanall image:lin");
						break;

					case AnimalEnum::TYPE2:
						flhs->setProperty("Image", "set:sanall image:huo");
						break;
					case AnimalEnum::TYPE3:
						flhs->setProperty("Image", "set:sanall image:shan");
						break;
					}
					flhs->show();
				}
				break;

				//	,
				//	ALL_COLOR,
			case WheelEnum::ALL_ANIMAL:
				switch(data.getLightColor())
				{
				case WheelEnum::Red:
					what->setProperty("Image", "set:sanall image:gong_quan");
					break;

				case WheelEnum::Yellow:
					what->setProperty("Image", "set:sanall image:ma_quan");
					break;

				case WheelEnum::Green:
					what->setProperty("Image", "set:sanall image:bu_quan");
					break;


				}
				break;


			case WheelEnum::ALL_COLOR:

				switch(data.getType())
				{
				case AnimalEnum::TYPE0:
					what->setProperty("Image", "set:sanall image:feng_quan");
					break;

				case AnimalEnum::TYPE1:
					what->setProperty("Image", "set:sanall image:lin_quan");
					break;

				case AnimalEnum::TYPE2:
					what->setProperty("Image", "set:sanall image:huo_quan");
					break;
				case AnimalEnum::TYPE3:
					what->setProperty("Image", "set:sanall image:shan_quan");
					break;
				}


				break;
			default:
				what->setProperty("Image", _multiArray[data.getLightColor()][data.getType()]);
			}


		}
		void setVisible(size_t i, bool isShow)
		{
			CEGUI::WindowManager::getSingleton().getWindow("main/list/win" + boost::lexical_cast<std::string>(i))->setVisible(isShow);
		}
		~UIList(void)
		{

		}

	private:
		std::deque<WinDataClone> _winDataList;
		boost::multi_array<std::string, 2> _multiArray;
	};
}


#endif