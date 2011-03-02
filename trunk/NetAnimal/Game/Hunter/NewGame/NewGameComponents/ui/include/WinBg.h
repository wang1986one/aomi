
#ifndef __Orz_WinBg__
#define __Orz_WinBg__

#include <WheelGobal/WinData.h>
#include <WheelGobal/WheelData.h>
#include <WheelGobal/WheelEnum.h>
#include "Number.h"
namespace Orz
{
	//namespace MY
	//{
	//	class Number
	//	{
	//	public:
	//		Number()
	//		{
	//			_number.setNumber(0, "set:AnimalUIEX image:Beishunum0");
	//			_number.setNumber(1, "set:AnimalUIEX image:Beishunum1");
	//			_number.setNumber(2, "set:AnimalUIEX image:Beishunum2");
	//			_number.setNumber(3, "set:AnimalUIEX image:Beishunum3");
	//			_number.setNumber(4, "set:AnimalUIEX image:Beishunum4");
	//			_number.setNumber(5, "set:AnimalUIEX image:Beishunum5");
	//			_number.setNumber(6, "set:AnimalUIEX image:Beishunum6");
	//			_number.setNumber(7, "set:AnimalUIEX image:Beishunum7");
	//			_number.setNumber(8, "set:AnimalUIEX image:Beishunum8");
	//			_number.setNumber(9, "set:AnimalUIEX image:Beishunum9");
	//		}
	//		~Number(void)
	//		{

	//		}
	//		void push_back(CEGUI::Window * win)
	//		{
	//			_windows.push_back(win);
	//		}
	//		void setNumber(int i, const std::string & image)
	//		{
	//			_numbers[i] = image;
	//		}
	//		void show(int i)
	//		{

	//			WindowsType::iterator it;

	//			for(it = _windows.begin(); it != _windows.end(); ++it)
	//			{

	//				(*it)->setProperty("Image", _numbers[i%10]);

	//				i/=10;
	//			}

	//		}

	//		void showWinnerNum(int i, CEGUI::W)
	//		{

	//			WindowsType::iterator it;

	//			bool num = false;
	//			if(i<100)
	//				num = true;
	//			for(it = _windows.begin(); it != _windows.end(); ++it)
	//			{

	//				(*it)->setProperty("Image", _numbers[i%10]);

	//				/*if(num == true && it == _windows.begin()+(_windows.size()-1))
	//				{
	//					CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/X")->hide();
	//					CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/X1")->hide();
	//					CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/X2")->hide();
	//					CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/X3")->hide();
	//					CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/X4")->hide();
	//					CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/X5")->hide();
	//					(*it)->setProperty("Image","set:AnimalUIEX image:BeishunumX");
	//				}*/

	//				i/=10;
	//			}

	//		}

	//	private:
	//		typedef  std::vector<CEGUI::Window * > WindowsType;
	//		WindowsType _windows;
	//		boost::array<std::string,10> _numbers;
	//	};

	//}
	namespace UI
	{
		class WinPic
		{
		public:
			/*WinPic):
			_all(all),_main(main), _left(left), _middle(middle), _right(right)
			{





			}*/
			static void show(CEGUI::Window * main)
			{

			}

			/*void hide(void)
			{
			_all->hide();
			}*/
		private:



			//CEGUI::Window * _all;
			//CEGUI::Window * _main;
			//CEGUI::Window * _left;
			//CEGUI::Window * _middle;
			//CEGUI::Window * _right;
			//CEGUI::Window * _x;
			//MY::Number _number;
		};






		class WinBg
		{
		public:
			WinBg(void):_sonWin(NULL)
			{

				_number.setFigure(0, "set:AnimalUIEX image:Beishunum0");
				_number.setFigure(1, "set:AnimalUIEX image:Beishunum1");
				_number.setFigure(2, "set:AnimalUIEX image:Beishunum2");
				_number.setFigure(3, "set:AnimalUIEX image:Beishunum3");
				_number.setFigure(4, "set:AnimalUIEX image:Beishunum4");
				_number.setFigure(5, "set:AnimalUIEX image:Beishunum5");
				_number.setFigure(6, "set:AnimalUIEX image:Beishunum6");
				_number.setFigure(7, "set:AnimalUIEX image:Beishunum7");
				_number.setFigure(8, "set:AnimalUIEX image:Beishunum8");
				_number.setFigure(9, "set:AnimalUIEX image:Beishunum9");

				_picture.insert(std::make_pair(
					std::make_pair(AnimalEnum::TYPE0, WheelEnum::Green),
					"set:sample image:panada_green"
					));

				_picture.insert(std::make_pair(
					std::make_pair(AnimalEnum::TYPE1, WheelEnum::Green),
					"set:sample image:tiger_green"
					));

				_picture.insert(std::make_pair(
					std::make_pair(AnimalEnum::TYPE2, WheelEnum::Green),
					"set:sample image:elephant_green"
					));

				_picture.insert(std::make_pair(
					std::make_pair(AnimalEnum::TYPE3, WheelEnum::Green),
					"set:sample image:crocodile_green"
					));



				_picture.insert(std::make_pair(
					std::make_pair(AnimalEnum::TYPE0, WheelEnum::Red),
					"set:sample image:panada_red"
					));

				_picture.insert(std::make_pair(
					std::make_pair(AnimalEnum::TYPE1, WheelEnum::Red),
					"set:sample image:tiger_red"
					));

				_picture.insert(std::make_pair(
					std::make_pair(AnimalEnum::TYPE2, WheelEnum::Red),
					"set:sample image:elephant_red"
					));

				_picture.insert(std::make_pair(
					std::make_pair(AnimalEnum::TYPE3, WheelEnum::Red),
					"set:sample image:crocodile_red"
					));



				_picture.insert(std::make_pair(
					std::make_pair(AnimalEnum::TYPE0, WheelEnum::Yellow),
					"set:sample image:panada_yellow"
					));

				_picture.insert(std::make_pair(
					std::make_pair(AnimalEnum::TYPE1, WheelEnum::Yellow),
					"set:sample image:tiger_yellow"
					));

				_picture.insert(std::make_pair(
					std::make_pair(AnimalEnum::TYPE2, WheelEnum::Yellow),
					"set:sample image:elephant_yellow"
					));

				_picture.insert(std::make_pair(
					std::make_pair(AnimalEnum::TYPE3, WheelEnum::Yellow),
					"set:sample image:crocodile_yellow"
					));



				_win= CEGUI::WindowManager::getSingleton().loadWindowLayout("NewMenu.layout");
				//_win->setAlwaysOnTop(true);
				_win->hide();
				CEGUI::Window * f = CEGUI::WindowManager::getSingleton().getWindow("Root");
				f->addChildWindow(_win);

				//显示默认的UI的排列方式
				/*	_wins.push_back(WinPic(
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right")
				));

				_wins.push_back(WinPic(
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner1"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim1"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left1"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle1"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right1")
				));

				_wins.push_back(WinPic(
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner2"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim2"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left2"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle2"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right2")
				));

				_wins.push_back(WinPic(
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner3"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim3"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left3"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle3"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right3")
				));

				_wins.push_back(WinPic(
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner4"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim4"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left4"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle4"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right4")
				));

				_wins.push_back(WinPic(
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner5"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim5"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left5"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle5"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right5")
				));*/


				//显示1个胜利UI的排列方式
				/*	_wins1.push_back(WinPic(
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right")
				));*/

				////显示2个胜利UI的排列方式
				//_wins2.push_back(WinPic(
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner1"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim1"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left1"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle1"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right1")
				//	));

				//_wins2.push_back(WinPic(
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner2"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim2"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left2"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle2"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right2")
				//	));


				////显示3个胜利UI的排列方式
				//_wins3.push_back(WinPic(
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right")
				//	));

				//_wins3.push_back(WinPic(
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner1"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim1"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left1"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle1"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right1")
				//	));

				//_wins3.push_back(WinPic(
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner2"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim2"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left2"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle2"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right2")
				//	));

				////显示4个胜利UI的排列方式
				//_wins4.push_back(WinPic(
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner1"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim1"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left1"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle1"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right1")
				//	));

				//_wins4.push_back(WinPic(
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner2"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim2"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left2"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle2"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right2")
				//	));

				//_wins4.push_back(WinPic(
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner3"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim3"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left3"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle3"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right3")
				//	));

				//_wins4.push_back(WinPic(
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner4"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim4"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left4"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle4"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right4")
				//	));


				////显示5个胜利UI的排列方式
				//_wins5.push_back(WinPic(
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right")
				//	));

				//_wins5.push_back(WinPic(
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner1"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim1"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left1"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle1"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right1")
				//	));

				//_wins5.push_back(WinPic(
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner2"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim2"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left2"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle2"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right2")
				//	));

				//_wins5.push_back(WinPic(
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner3"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim3"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left3"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle3"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right3")
				//	));

				//_wins5.push_back(WinPic(
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner4"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim4"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left4"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle4"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right4")
				//	));

				////显示6个胜利UI的排列方式
				//_wins6.push_back(WinPic(
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right")
				//	));

				//_wins6.push_back(WinPic(
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner1"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim1"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left1"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle1"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right1")
				//	));

				//_wins6.push_back(WinPic(
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner2"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim2"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left2"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle2"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right2")
				//	));

				//_wins6.push_back(WinPic(
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner3"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim3"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left3"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle3"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right3")
				//	));

				//_wins6.push_back(WinPic(
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner4"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim4"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left4"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle4"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right4")
				//	));

				//_wins6.push_back(WinPic(
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner5"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim5"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left5"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle5"),
				//	CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right5")
				//	));


				//显示数字
				/**/

				//_number.push_back(CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Bonus/Number/5"));
				//				_number.push_back(CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Bonus/Number/4"));
				//				_number.push_back(CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Bonus/Number/3"));
				//				_number.push_back(CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Bonus/Number/2"));
				//				_number.push_back(CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Bonus/Number/1"));
				//
				//				_number.setNumber(0, "set:AnimalUIEX image:Beishunum0");
				//				_number.setNumber(1, "set:AnimalUIEX image:Beishunum1");
				//				_number.setNumber(2, "set:AnimalUIEX image:Beishunum2");
				//				_number.setNumber(3, "set:AnimalUIEX image:Beishunum3");
				//				_number.setNumber(4, "set:AnimalUIEX image:Beishunum4");
				//				_number.setNumber(5, "set:AnimalUIEX image:Beishunum5");
				//				_number.setNumber(6, "set:AnimalUIEX image:Beishunum6");
				//				_number.setNumber(7, "set:AnimalUIEX image:Beishunum7");
				//				_number.setNumber(8, "set:AnimalUIEX image:Beishunum8");
				//				_number.setNumber(9, "set:AnimalUIEX image:Beishunum9");

			}

			//显示哪一个窗口
			int showWitchWindows()
			{

				/*int i = 0;
				if(WinData::getInstance().getWinMode() == WheelEnum::NONE ||
					WinData::getInstance().getWinMode()  == WheelEnum::DOUBLE ||
					WinData::getInstance().getWinMode()== WheelEnum::TREBLE ||
					WinData::getInstance().getWinMode() == WheelEnum::GOLD 
					)
				{

					i = 1;

				}
				else if(WinData::getInstance().getWinMode() == WheelEnum::ONE)
				{

					i = 2;
				}
				else if(WinData::getInstance().getWinMode() == WheelEnum::ALL_ANIMAL || WinData::getInstance().getWinMode()  == WheelEnum::TWO)
				{

					i = 3;
				}
				else if(WinData::getInstance().getWinMode()  == WheelEnum::ALL_COLOR || WinData::getInstance().getWinMode()   == WheelEnum::THREE)
				{

					i = 4;
				}
				else if(WinData::getInstance().getWinMode() == WheelEnum::FOUR)
				{


					i = 5;
				}
				else if(WinData::getInstance().getWinMode() == WheelEnum::FIVE)
				{

					i = 6;

				}*/
				int i =WinData::getInstance().size();
				if(i==0)
					i = 1;
				_sonWin = CEGUI::WindowManager::getSingleton().getWindow("Win/Bg"+ boost::lexical_cast<std::string>(i-1));
				return i;
			}

			void show()
			{
				if(WinData::getInstance().getWinMode() == WheelEnum::GOLD)
				{

					CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Bonus")->show();
					_number.clear();
					_number.push_back(CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Bonus/Number/5"));
					_number.push_back(CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Bonus/Number/4"));
					_number.push_back(CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Bonus/Number/3"));
					_number.push_back(CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Bonus/Number/2"));
					_number.push_back(CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Bonus/Number/1"));
					_number.show(WinData::getInstance().getBonus());
				}else
				{
					CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Bonus")->hide();
				}
				int n = showWitchWindows();

				_sonWin->show();
				for(int i = 0 ; i<n; ++i)
				{
					show_win(i, _sonWin->getName().c_str());
				}
				_win->setAlpha(0.f);

				if(WinData::getInstance().getWinMode() == WheelEnum::GOLD)
				{
					CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Bonus")->show();
					CEGUI::WindowManager::getSingleton().getWindow("Win/Bg0/king/0")->show();
				}
				else
				{
					CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Bonus")->hide();
					CEGUI::WindowManager::getSingleton().getWindow("Win/Bg0/king/0")->hide();
				}

				_win->show();
			}


			void show_win(int i, const std::string & name)
			{
				std::string id = boost::lexical_cast<std::string>(i);
				CEGUI::Window * main = CEGUI::WindowManager::getSingleton().getWindow( name+"/Anim/"+id);
				Orz::AnimalEnum::ANIMAL_ITEM ai;
				ai = WinData::getInstance().getAnimalItem(i);
				/*switch(WinData::getInstance().getWinMode())
				{

	
				case WheelEnum::ONE:
				case WheelEnum::TWO:
				case WheelEnum::THREE:
				case WheelEnum::FOUR:
				case WheelEnum::FIVE:
					ai = WinData::getInstance().getAnimalItem(i);
					break;
				case WheelEnum::ALL_ANIMAL:
					ai = WinData::getInstance().getAnimalItem(i);
					break;
				case WheelEnum::ALL_COLOR:
					ai = WinData::getInstance().getAnimalItem(i);
					break;
				default:
					ai = WinData::getInstance().getAnimalItem();
				}*/
				
				main->setProperty("Image", _picture[ai]);
				_number.clear();
				_number.push_back(CEGUI::WindowManager::getSingleton().getWindow( name+ "/Score/Right/"+ id));
				_number.push_back(CEGUI::WindowManager::getSingleton().getWindow( name+ "/Score/Middle/"+ id));
				_number.push_back(CEGUI::WindowManager::getSingleton().getWindow( name+ "/Score/Left/"+ id));
				int o = WinData::getInstance().getRate(ai);//,ai);


				if(WinData::getInstance().getWinMode()== WheelEnum::DOUBLE)
					o*=2;
				if(WinData::getInstance().getWinMode()== WheelEnum::TREBLE)
					o*=3;

				_number.show(o);


				if(o >= 100)
				{
					CEGUI::WindowManager::getSingleton().getWindow( name+ "/Score/X/"+ id)->setProperty("Image", "set:AnimalUIEX image:BeishunumX");
					CEGUI::WindowManager::getSingleton().getWindow( name+ "/Score/X/"+ id)->show();

				}
				else if(o >=10)
				{
					CEGUI::WindowManager::getSingleton().getWindow( name+ "/Score/X/"+ id)->hide();
					CEGUI::WindowManager::getSingleton().getWindow( name+ "/Score/Left/"+ id)->setProperty("Image", "set:AnimalUIEX image:BeishunumX");
					CEGUI::WindowManager::getSingleton().getWindow( name+ "/Score/Left/"+ id)->show();
				}
				else
				{
					CEGUI::WindowManager::getSingleton().getWindow( name+ "/Score/X/"+ id)->hide();
					CEGUI::WindowManager::getSingleton().getWindow( name+ "/Score/Left/"+ id)->hide();
					CEGUI::WindowManager::getSingleton().getWindow( name+ "/Score/Middle/"+ id)->setProperty("Image", "set:AnimalUIEX image:BeishunumX");
					CEGUI::WindowManager::getSingleton().getWindow( name+ "/Score/Middle/"+ id)->show();
				}
				//* to do
			}
			void hide(void)
			{	
				/*	WinPicType::iterator it;
				for(it = _wins.begin(); it!=_wins.end(); ++it)
				{
				it->hide();
				}
				*/
				if(_sonWin)
					_sonWin->hide();
				_win->hide();
			}
			void update(TimeType i)
			{
				if(_win->isVisible())
				{
					float alpha = _win->getAlpha();
					if(alpha < 1.0f)
					{
						alpha+= i*2;
						_win->setAlpha(alpha);
					}
				}
			}
			~WinBg(void)
			{

			}
		private:
			CEGUI::Window * _win;
			CEGUI::Window * _sonWin;
			Number _number;
			typedef std::vector<WinPic> WinPicType;
			/*	WinPicType _wins;
			WinPicType _wins1;
			WinPicType _wins2;
			WinPicType _wins3;
			WinPicType _wins4;
			WinPicType _wins5;
			WinPicType _wins6;*/
			/*MY::Number _number;*/
			std::map<std::pair<AnimalEnum::TYPE, WheelEnum::LIGHT_COLOR>, std::string> _picture;



		};
	}
}


#endif