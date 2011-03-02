#ifndef __Orz_UIList__
#define __Orz_UIList__

#include <WheelGobal/WinData.h>
#include <WheelGobal/WheelData.h>
#include <WheelGobal/WheelEnum.h>

namespace Orz
{
	namespace UI
	{
		class UIList
		{

		public:
			UIList(void):_multiArray(boost::extents[3][4])
			{

				_multiArray[WheelEnum::Red][AnimalEnum::TYPE0] = "set:sample image:panada_red";//ÐÜÃ¨
				_multiArray[WheelEnum::Red][AnimalEnum::TYPE1]  = "set:sample image:tiger_red";//ÀÏ»¢
				_multiArray[WheelEnum::Red][AnimalEnum::TYPE2]  = "set:sample image:elephant_red";//´óÏó
				_multiArray[WheelEnum::Red][AnimalEnum::TYPE3]  = "set:sample image:crocodile_red";//öùÓã

				_multiArray[WheelEnum::Yellow][AnimalEnum::TYPE0]  = "set:sample image:panada_yellow";
				_multiArray[WheelEnum::Yellow][AnimalEnum::TYPE1]  = "set:sample image:tiger_yellow";
				_multiArray[WheelEnum::Yellow][AnimalEnum::TYPE2]  = "set:sample image:elephant_yellow";
				_multiArray[WheelEnum::Yellow][AnimalEnum::TYPE3]  = "set:sample image:crocodile_yellow";

				_multiArray[WheelEnum::Green][AnimalEnum::TYPE0]  = "set:sample image:panada_green";
				_multiArray[WheelEnum::Green][AnimalEnum::TYPE1]  = "set:sample image:tiger_green";
				_multiArray[WheelEnum::Green][AnimalEnum::TYPE2]  = "set:sample image:elephant_green";
				_multiArray[WheelEnum::Green][AnimalEnum::TYPE3]  = "set:sample image:crocodile_green";


				_colorArray[WheelEnum::Red]  = "set:sample2 image:allred";
				_colorArray[WheelEnum::Yellow]  = "set:sample2 image:allyellow";
				_colorArray[WheelEnum::Green]  = "set:sample2 image:allgreen";
				_animalArray[AnimalEnum::TYPE0]  = "set:sample2 image:quancaiP";
				_animalArray[AnimalEnum::TYPE1]  = "set:sample2 image:quancaiT";
				_animalArray[AnimalEnum::TYPE2]  = "set:sample2 image:quancaiE";
				_animalArray[AnimalEnum::TYPE3]  = "set:sample2 image:quancaiD";


			}

			void add()
			{
				_winDataList.push_front(WinData::getInstance().getClone());
				if(_winDataList.size() > 14)
				{
					_winDataList.resize(14);
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
				for(;i < 14; ++i)
				{
					setVisible(i, false);
				}
			}
			void draw(size_t i, const WinDataClone & data)
			{


				CEGUI::WindowManager::getSingleton().getWindow("PICTURE/" + boost::lexical_cast<std::string>(i+1)+"/lightning")->setVisible(
					data.getWinMode() == Orz::WheelEnum::DOUBLE||data.getWinMode() == Orz::WheelEnum::TREBLE
					);



				CEGUI::WindowManager::getSingleton().getWindow("PICTURE/" + boost::lexical_cast<std::string>(i+1)+"king")->setVisible(data.getWinMode() == Orz::WheelEnum::GOLD);


				std::string id = boost::lexical_cast<std::string>(i+1);
				CEGUI::Window*  flhs =  CEGUI::WindowManager::getSingleton().getWindow("PICTURE/" + id); 
				flhs->hide();



				CEGUI::Window*  wsw =  CEGUI::WindowManager::getSingleton().getWindow("PICTURE/" + id+"/smalllogo"); 
				switch(data.getWinner())
				{
				case WheelEnum::Dealer:
					wsw->setProperty("Image", "set:sample2 image:logozhuang");
					break;
				case  WheelEnum::Player:
					wsw->setProperty("Image", "set:sample2 image:logoxian");
					break;
				case  WheelEnum::Draw:
					wsw->setProperty("Image", "set:sample2 image:logohe");
					break;


				}




				CEGUI::Window* what =  CEGUI::WindowManager::getSingleton().getWindow("PICTURE/" + id);


				switch(data.getWinMode())
				{
				case WheelEnum::MANY:
					std::cout<<data.size()<<"set:sample2 image:songdeng" + boost::lexical_cast<std::string>(data.size() -1)<<std::endl;
					what->setProperty("Image", "set:sample2 image:songdeng" + boost::lexical_cast<std::string>(data.size() -1));
					break;
					/*		
					break;
					case WheelEnum::TWO:
					what->setProperty("Image", "set:sample2 image:songdeng2");
					break;
					case WheelEnum::THREE:
					what->setProperty("Image", "set:sample2 image:songdeng3");
					break;
					case WheelEnum::FOUR:
					what->setProperty("Image", "set:sample2 image:songdeng4");
					break;
					case WheelEnum::FIVE:
					what->setProperty("Image", "set:sample2 image:songdeng5");
					break;*/
				case WheelEnum::ALL_ANIMAL:
					what->setProperty("Image", _animalArray[data.getType()]);
					break;
				case WheelEnum::ALL_COLOR:
					what->setProperty("Image", _colorArray[data.getLightColor()]);
					break;


				default:
					what->setProperty("Image", _multiArray[data.getLightColor()][data.getType()]);

				}
				what->show();
			}
			void setVisible(size_t i, bool isShow)
			{
				CEGUI::WindowManager::getSingleton().getWindow("PICTURE/" + boost::lexical_cast<std::string>(i+1))->setVisible(isShow);
				if(!isShow)
					CEGUI::WindowManager::getSingleton().getWindow("PICTURE/" + boost::lexical_cast<std::string>(i+1)+"king")->setVisible(false);

			}
			~UIList(void)
			{

			}

		private:
			std::deque<WinDataClone> _winDataList;
			boost::multi_array<std::string, 2> _multiArray;
			boost::array<std::string, 3> _colorArray;
			boost::array<std::string, 4> _animalArray;
		};
	}
}


#endif