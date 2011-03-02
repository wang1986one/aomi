#ifndef __Orz_WinBg__
#define __Orz_WinBg__

#include "WheelAnimalControllerConfig.h"
#include <CEGUI/cegui.h>
#include "WheelEnum.h"
#include "WheelData.h"
namespace Orz
{
	class WinPic
	{
	public:
		WinPic(CEGUI::Window * all, CEGUI::Window * main, CEGUI::Window * left, CEGUI::Window * middle, CEGUI::Window * right):
		  _all(all),_main(main), _left(left), _middle(middle), _right(right)
		  {
			  _all->hide();

			  _picture.insert(std::make_pair(
				  std::make_pair(WheelEnum::LION, WheelEnum::Green),
				  "set:AnimalUI image:Greenlion"
				  ));

			  _picture.insert(std::make_pair(
				  std::make_pair(WheelEnum::RABBIT, WheelEnum::Green),
				  "set:AnimalUI image:Greenrabblt"
				  ));

			  _picture.insert(std::make_pair(
				  std::make_pair(WheelEnum::MONKEY, WheelEnum::Green),
				  "set:AnimalUI image:Greenmonkey"
				  ));

			  _picture.insert(std::make_pair(
				  std::make_pair(WheelEnum::PANDA, WheelEnum::Green),
				  "set:AnimalUI image:Greenpanda"
				  ));



			  _picture.insert(std::make_pair(
				  std::make_pair(WheelEnum::LION, WheelEnum::Red),
				  "set:AnimalUI image:Redlion"
				  ));

			  _picture.insert(std::make_pair(
				  std::make_pair(WheelEnum::RABBIT, WheelEnum::Red),
				  "set:AnimalUI image:Redrabblt"
				  ));

			  _picture.insert(std::make_pair(
				  std::make_pair(WheelEnum::MONKEY, WheelEnum::Red),
				  "set:AnimalUI image:Redmonkey"
				  ));

			  _picture.insert(std::make_pair(
				  std::make_pair(WheelEnum::PANDA, WheelEnum::Red),
				  "set:AnimalUI image:Redpanda"
				  ));



			  _picture.insert(std::make_pair(
				  std::make_pair(WheelEnum::LION, WheelEnum::Yellow),
				  "set:AnimalUI image:Yellowlion"
				  ));

			  _picture.insert(std::make_pair(
				  std::make_pair(WheelEnum::RABBIT, WheelEnum::Yellow),
				  "set:AnimalUI image:Yellowrabblt"
				  ));

			  _picture.insert(std::make_pair(
				  std::make_pair(WheelEnum::MONKEY, WheelEnum::Yellow),
				  "set:AnimalUI image:Yellowmonkey"
				  ));

			  _picture.insert(std::make_pair(
				  std::make_pair(WheelEnum::PANDA, WheelEnum::Yellow),
				  "set:AnimalUI image:Yellowpanda"
				  ));


			  _number.push_back(_right);
			  _number.push_back(_middle);
			  _number.push_back(_left);
			  _number.setNumber(0, "set:AnimalUIEX image:Beishunum0");
			  _number.setNumber(1, "set:AnimalUIEX image:Beishunum1");
			  _number.setNumber(2, "set:AnimalUIEX image:Beishunum2");
			  _number.setNumber(3, "set:AnimalUIEX image:Beishunum3");
			  _number.setNumber(4, "set:AnimalUIEX image:Beishunum4");
			  _number.setNumber(5, "set:AnimalUIEX image:Beishunum5");
			  _number.setNumber(6, "set:AnimalUIEX image:Beishunum6");
			  _number.setNumber(7, "set:AnimalUIEX image:Beishunum7");
			  _number.setNumber(8, "set:AnimalUIEX image:Beishunum8");
			  _number.setNumber(9, "set:AnimalUIEX image:Beishunum9");
		  }
		  void show(int i)
		  {
			  if(WinData::getInstance().getWinMode() == WheelEnum::NONE||
				  WinData::getInstance().getWinMode() == WheelEnum::DOUBLE||
				  WinData::getInstance().getWinMode() == WheelEnum::TREBLE||
				  WinData::getInstance().getWinMode() == WheelEnum::GOLD
				  )
			  {
				  if(i == 0)
				  {

					  WheelEnum::ANIMAL_ITEM  ai = WinData::getInstance().getAnimalItem();
					  _main->setProperty("Image", _picture[ai]);
					  int n = WinData::getInstance().getRate(0);
					  if( WinData::getInstance().getWinMode() == WheelEnum::DOUBLE)
					  {
						  n *= 2;
						  _number.showWinnerNum(n);
						  _all->show();
					  }
					  else if( WinData::getInstance().getWinMode() == WheelEnum::TREBLE)
					  {
						  n *= 3;
						  if(n >= 100)
						  {
							  CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/X")->show();
						  }
						  _number.showWinnerNum(n);
						  _all->show();
					  }
					  else
					  {
						  _number.showWinnerNum(n);
						  _all->show();
					  }

				  }
			  }
			  else if(WinData::getInstance().getWinMode() == WheelEnum::ALL_ANIMAL)
			  {
				  if( i == 0)
				  {
					 WheelEnum::ANIMAL_ITEM ai = std::make_pair(WinData::getInstance().getAnimalItem().first,WheelEnum::Red);
					  _main->setProperty("Image", _picture[ai]);
					  int n = WinData::getInstance().getRate(ai);
					  _number.showWinnerNum(n);
					  _all->show();
				  }else if( i == 1)
				  {
					  WheelEnum::ANIMAL_ITEM ai = std::make_pair(WinData::getInstance().getAnimalItem().first,WheelEnum::Yellow);
					  _main->setProperty("Image", _picture[ai]);
					   int n = WinData::getInstance().getRate(ai);
					  _number.showWinnerNum(n);
					  _all->show();
				  }else if(i == 2)
				  {
					  WheelEnum::ANIMAL_ITEM ai = std::make_pair(WinData::getInstance().getAnimalItem().first,WheelEnum::Green);
					  _main->setProperty("Image", _picture[ai]);
					   int n = WinData::getInstance().getRate(ai);
					  _number.showWinnerNum(n);
					  _all->show();
				  }

			  } 
			  else if(WinData::getInstance().getWinMode() == WheelEnum::ALL_COLOR)
			  {
				  if( i == 0)
				  {
					  WheelEnum::ANIMAL_ITEM ai = std::make_pair(WheelEnum::RABBIT,WinData::getInstance().getLightColor());
					  _main->setProperty("Image", _picture[ai]);
					   int n = WinData::getInstance().getRate(ai);
					  _number.showWinnerNum(n);
					  _all->show();
				  }else if( i == 1)
				  {
					  WheelEnum::ANIMAL_ITEM ai = std::make_pair(WheelEnum::MONKEY,WinData::getInstance().getLightColor());
					  _main->setProperty("Image", _picture[ai]);
					    int n = WinData::getInstance().getRate(ai);
					  _number.showWinnerNum(n);
					  _all->show();

				  }else if(i == 2)
				  {

					  WheelEnum::ANIMAL_ITEM ai = std::make_pair(WheelEnum::PANDA,WinData::getInstance().getLightColor());
					  _main->setProperty("Image", _picture[ai]);
					  int n = WinData::getInstance().getRate(ai);
					  _number.showWinnerNum(n);
					  _all->show();


				  }else if(i == 3)
				  {
					  WheelEnum::ANIMAL_ITEM ai = std::make_pair(WheelEnum::LION,WinData::getInstance().getLightColor());
					  _main->setProperty("Image", _picture[ai]);
					   int n = WinData::getInstance().getRate(ai);
					  _number.showWinnerNum(n);
					  _all->show();
				  }

			  }else if(WinData::getInstance().getWinMode() == WheelEnum::MANY)
			  {
				  if(size_t(i) < WinData::getInstance().size()/*WheelData::getInstance().hasTVNext(WinData::getInstance().getWinMode(), WinData::getInstance().getAnimalItem(), i)*/)
				  {

					  WheelEnum::ANIMAL_ITEM ai = WinData::getInstance().getAnimalItem(i);
					  _main->setProperty("Image", _picture[ai]);
					  int n = WinData::getInstance().getRate(ai);
					  _number.showWinnerNum(n);
					  _all->show();

				  }

			  }
		  }

		  void hide(void)
		  {
			  _all->hide();
		  }
	private:



		std::map<std::pair<WheelEnum::TYPE, WheelEnum::LIGHT_COLOR>, std::string> _picture;
		CEGUI::Window * _all;
		CEGUI::Window * _main;
		CEGUI::Window * _left;
		CEGUI::Window * _middle;
		CEGUI::Window * _right;
		Number _number;
	};
	class WinBg
	{
	public:
		WinBg(void)
		{
			_win= CEGUI::WindowManager::getSingleton().loadWindowLayout("Winmenu.layout");
			_win->setAlwaysOnTop(true);
			_win->hide();
			CEGUI::Window * f = CEGUI::WindowManager::getSingleton().getWindow("AnimalUI");
			f->addChildWindow(_win);

			//显示默认的UI的排列方式
			_wins.push_back(WinPic(
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
				));


			//显示1个胜利UI的排列方式
			_wins1.push_back(WinPic(
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right")
				));

			//显示2个胜利UI的排列方式
			_wins2.push_back(WinPic(
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner1"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim1"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left1"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle1"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right1")
				));

			_wins2.push_back(WinPic(
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner2"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim2"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left2"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle2"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right2")
				));


			//显示3个胜利UI的排列方式
			_wins3.push_back(WinPic(
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right")
				));

			_wins3.push_back(WinPic(
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner1"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim1"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left1"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle1"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right1")
				));

			_wins3.push_back(WinPic(
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner2"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim2"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left2"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle2"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right2")
				));

			//显示4个胜利UI的排列方式
			_wins4.push_back(WinPic(
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner1"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim1"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left1"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle1"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right1")
				));

			_wins4.push_back(WinPic(
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner2"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim2"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left2"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle2"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right2")
				));

			_wins4.push_back(WinPic(
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner3"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim3"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left3"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle3"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right3")
				));

			_wins4.push_back(WinPic(
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner4"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim4"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left4"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle4"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right4")
				));


			//显示5个胜利UI的排列方式
			_wins5.push_back(WinPic(
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right")
				));

			_wins5.push_back(WinPic(
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner1"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim1"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left1"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle1"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right1")
				));

			_wins5.push_back(WinPic(
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner2"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim2"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left2"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle2"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right2")
				));

			_wins5.push_back(WinPic(
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner3"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim3"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left3"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle3"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right3")
				));

			_wins5.push_back(WinPic(
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner4"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim4"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left4"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle4"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right4")
				));

			//显示6个胜利UI的排列方式
			_wins6.push_back(WinPic(
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right")
				));

			_wins6.push_back(WinPic(
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner1"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim1"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left1"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle1"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right1")
				));

			_wins6.push_back(WinPic(
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner2"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim2"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left2"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle2"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right2")
				));

			_wins6.push_back(WinPic(
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner3"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim3"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left3"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle3"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right3")
				));

			_wins6.push_back(WinPic(
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner4"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim4"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left4"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle4"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right4")
				));

			_wins6.push_back(WinPic(
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner5"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim5"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Left5"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Middle5"),
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Score/Right5")
				));


			//显示数字
			_number.push_back(CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Bonus/Number/5"));
			_number.push_back(CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Bonus/Number/4"));
			_number.push_back(CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Bonus/Number/3"));
			_number.push_back(CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Bonus/Number/2"));
			_number.push_back(CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Bonus/Number/1"));

			_number.setNumber(0, "set:AnimalUIEX image:Beishunum0");
			_number.setNumber(1, "set:AnimalUIEX image:Beishunum1");
			_number.setNumber(2, "set:AnimalUIEX image:Beishunum2");
			_number.setNumber(3, "set:AnimalUIEX image:Beishunum3");
			_number.setNumber(4, "set:AnimalUIEX image:Beishunum4");
			_number.setNumber(5, "set:AnimalUIEX image:Beishunum5");
			_number.setNumber(6, "set:AnimalUIEX image:Beishunum6");
			_number.setNumber(7, "set:AnimalUIEX image:Beishunum7");
			_number.setNumber(8, "set:AnimalUIEX image:Beishunum8");
			_number.setNumber(9, "set:AnimalUIEX image:Beishunum9");

		}
		
		//显示哪一个窗口
		void showWitchWindows()
		{
			if(WinData::getInstance().size() == 1
				)
			{
				_wins = _wins1;
			}
			else if(WinData::getInstance().size() == 2)
			{
				_wins = _wins2;
			}
			else if(WinData::getInstance().size() == 3)
			{
				_wins = _wins3;
			}
			else if(WinData::getInstance().size() == 4)
			{
				_wins = _wins4;
			}
			else if(WinData::getInstance().size() == 5)
			{
				_wins = _wins5;
			}
			else if(WinData::getInstance().size() == 6)
			{
				_wins = _wins6;
			}

		}

		void show()
		{
			showWitchWindows();

			WinPicType::iterator it;
			for(size_t i = 0 ; i< _wins.size(); ++i)
			{
				_wins.at(i).show(i);
			}
			_win->setAlpha(0.f);

			if(WinData::getInstance().getWinMode() == WheelEnum::GOLD)
			{
				_number.show(WinData::getInstance().getBonus());
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Bonus")->show();
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim/King")->show();
			}
			else
			{
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Bonus")->hide();
				CEGUI::WindowManager::getSingleton().getWindow("Win/Bg/Winner/Anim/King")->hide();
			}

			_win->show();
		}
		void hide(void)
		{	
			WinPicType::iterator it;
			for(it = _wins.begin(); it!=_wins.end(); ++it)
			{
				it->hide();
			}
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

		typedef std::vector<WinPic> WinPicType;
		WinPicType _wins;
		WinPicType _wins1;
		WinPicType _wins2;
	    WinPicType _wins3;
	    WinPicType _wins4;
		WinPicType _wins5;
		WinPicType _wins6;
		Number _number;


	};
}


#endif