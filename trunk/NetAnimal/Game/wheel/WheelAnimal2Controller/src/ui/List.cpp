#include "WheelAnimalControllerStableHeaders.h"
#include "List.h"
#include "WheelEnum.h"
using namespace Orz;



ListItem::ListItem(CEGUI::Window * all, 
				   CEGUI::Window * main, 
				   CEGUI::Window * banker, 
				   CEGUI::Window * king,
				   CEGUI::Window * theDouble,
				   CEGUI::Window * table
				   ):
_all(all),
_main(main),
_banker(banker),
_king(king),
_double(theDouble),
_table(table)
{
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


}
void ListItem::hide(void)
{
	_all->hide();
}


const WinDataClone & ListItem::getData(void) const
{
	return _winData;
}
void ListItem::show(const WinDataClone & data)
{
	_winData = data;


	switch(_winData.getWinner())
	{
	case WheelEnum::Dealer:
		_banker->setProperty("Image", "set:AnimalUI image:Zhuang");
		break;
	case WheelEnum::Player:
		_banker->setProperty("Image", "set:AnimalUI image:Xian");
		break;
	case WheelEnum::Draw:
		_banker->setProperty("Image", "set:AnimalUI image:He");
		break;
	}

	_table->hide();
	if(_winData.getWinMode() == WheelEnum::ALL_ANIMAL)
	{
		switch(_winData.getType())
		{
		case WheelEnum::LION:
			_main->setProperty("Image","set:AnimalUI image:Threecolorlion");
			break;
		case WheelEnum::MONKEY:
			_main->setProperty("Image","set:AnimalUI image:Threecolormonkey");
			break;
		case WheelEnum::RABBIT:
			_main->setProperty("Image","set:AnimalUI image:Threecolorrabblt");
			break;
		case WheelEnum::PANDA:
			_main->setProperty("Image","set:AnimalUI image:Threecolorpanda");
			break;
		}
	}else if(_winData.getWinMode() == WheelEnum::ALL_COLOR)
	{
		switch(_winData.getLightColor())
		{
		case WheelEnum::Red:
			_main->setProperty("Image","set:AnimalUIEX image:AllRed");
			break;
		case WheelEnum::Green:
			_main->setProperty("Image","set:AnimalUIEX image:AllGreen");
			break;
		case WheelEnum::Yellow:
			_main->setProperty("Image","set:AnimalUIEX image:AllYellow");
			break;
		}
	}else
	{


		switch(_winData.getWinMode())
		{
		case WheelEnum::MANY:
			switch(_winData.size())
			{
			case 2:
				_main->setProperty("Image","set:AnimalUI image:Songdengone");
				break;
			case 3:
				_main->setProperty("Image","set:AnimalUI image:Songdengtwo");
				break;
			case 4:
				_main->setProperty("Image","set:AnimalUI image:Songdengthree");
				break;
			case 5:
				_main->setProperty("Image","set:AnimalUI image:Songdengfour");
				break;
			case 6:
				_main->setProperty("Image","set:AnimalUI image:Songdengfive");
				break;

			}
			break;

		default:
			{
				if(_winData.getWinMode() == WheelEnum::NONE)
				{
					int table = _winData.getTable() +1;
					if(table >=0 &&  table <=8)
						_table->setProperty("Image","set:AnimalUIEX image:Table"+boost::lexical_cast<std::string>(table));
					_table->show();
				}
				_main->setProperty("Image",_picture[_winData.getAnimalItem()]);
			}
		}


	}


	if(_winData.getWinMode() == WheelEnum::TREBLE || _winData.getWinMode() == WheelEnum::DOUBLE)
		_double->show();
	else
		_double->hide();


	if(_winData.getWinMode() == WheelEnum::GOLD )
		_king->show();
	else
		_king->hide();

	_all->show();
}

ListItem::~ListItem(void)
{

}
bool ListItem::isVisible(void) const
{
	return _all->isVisible();
}
//
//const WinData & ListItem::getWinData(void) 
//{
//	return WinData::getSingleton();
//}
List::List(void)
{
	for(int i =0; i<17; ++i)
	{

		std::string n = boost::lexical_cast<std::string>(i);
		_list.push_back(
			ListItem
			(
			CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Bottom/"+n),
			CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Bottom/"+n+"/main"),
			CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Bottom/"+n+"/banker"),
			CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Bottom/"+n+"/king"),
			CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Bottom/"+n+"/double"),
			CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Bottom/"+n+"/table")
			)
			);
	}	


	ListType::iterator it;
	for(it = _list.begin(); it!=_list.end(); ++it)
	{
		it->hide();
	}
	hide();

}
List::~List(void)
{
	CEGUI::System::getSingleton().getRenderer()->createTexture();
}

void List::show(void)
{
	CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Bottom")->show();
}
void List::hide(void)
{
	CEGUI::WindowManager::getSingleton().getWindow("AnimalUI/Bottom")->hide();
}
