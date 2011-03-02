#include "NewWheelControllerStableHeaders.h"
#include "NewHardwareEngineDecorator.h"
#include "NewHardwareCode.h"
#include <orz/View_SingleChip/SingleChipManager.h>
#include "WinData.h"
#include "NewHardware.h"
using namespace Orz;



NewHardwareEngineDecorator::NewHardwareEngineDecorator(WheelEngineInterfacePtr engine):_engine(engine)
{
	Orz::SingleChipManager::getSingleton().addListener(this);
	NewHardwareCode::getSingleton()._callback = boost::bind(&NewHardwareEngineDecorator::dealMassage,this,_1); 
}



NewHardwareEngineDecorator::~NewHardwareEngineDecorator(void)
{

	Orz::SingleChipManager::getSingleton().removeListener(this);
	//NewHardwareCode::getSingleton()._callback.reset();
}


void NewHardwareEngineDecorator::startGame(size_t time)
{
	if(_engine)
		_engine->startGame(time);
}
void NewHardwareEngineDecorator::pushRate(void)
{
	if(_engine)
		_engine->pushRate();

}
void NewHardwareEngineDecorator::runGame(void)
{
	if(_engine)
		_engine->runGame();

}

void NewHardwareEngineDecorator::findSC(void)
{
	if(_engine)
		_engine->findSC();

}

static void SetWinDataWinner(unsigned char w)
{
	switch(w)
	{
	case 1:
		WinData::getInstance().setWinner(Orz::WheelEnum::Dealer);
		break;
	case 2:
		WinData::getInstance().setWinner(Orz::WheelEnum::Player);
		break;
	case 3:
		WinData::getInstance().setWinner(Orz::WheelEnum::Draw);
		break;
	}
}
static void SetWinData(unsigned char a, unsigned char r)
{
	WheelEnum::ANIMAL_ITEM animal;
	switch(a)
	{
	case 1:
		animal = WheelEnum::ANIMAL_ITEM(WheelEnum::TYPE3 , WheelEnum::Red);
		break;
	case 2:
		animal = WheelEnum::ANIMAL_ITEM(WheelEnum::TYPE2 , WheelEnum::Red);
		break;
	case 3:
		animal = WheelEnum::ANIMAL_ITEM(WheelEnum::TYPE1 , WheelEnum::Red);
		break;
	case 4:
		animal = WheelEnum::ANIMAL_ITEM(WheelEnum::TYPE0 , WheelEnum::Red);
		break;
	case 5:
		animal = WheelEnum::ANIMAL_ITEM(WheelEnum::TYPE3 , WheelEnum::Green);
		break;
	case 6:
		animal = WheelEnum::ANIMAL_ITEM(WheelEnum::TYPE2 , WheelEnum::Green);
		break;
	case 7:
		animal = WheelEnum::ANIMAL_ITEM(WheelEnum::TYPE1 , WheelEnum::Green);
		break;
	case 8:
		animal = WheelEnum::ANIMAL_ITEM(WheelEnum::TYPE0 , WheelEnum::Green);
		break;
	case 9:
		animal = WheelEnum::ANIMAL_ITEM(WheelEnum::TYPE3 , WheelEnum::Yellow);
		break;
	case 10:
		animal = WheelEnum::ANIMAL_ITEM(WheelEnum::TYPE2 , WheelEnum::Yellow);
		break;
	case 11:
		animal = WheelEnum::ANIMAL_ITEM(WheelEnum::TYPE1 , WheelEnum::Yellow);
		break;
	case 12:
		animal = WheelEnum::ANIMAL_ITEM(WheelEnum::TYPE0 , WheelEnum::Yellow);
		break;
	}
	WinData::getInstance().push_back(animal, int(r));

}

void NewHardwareEngineDecorator::dealMassage(HardwareMsg & msg)
{
	switch(msg.msg)
	{
	case WheelEnum::HW_FIND_PC:
		{
			this->findSC();
		}
		break;
	case WheelEnum::HW_TIME:
		{
			this->startGame(int(msg.data.at(0)));
		}

		break;
	case WheelEnum::HW_BOUNS:
		{
			int b0 = static_cast<int>(msg.data.at(0));
			int b1 = static_cast<int>(msg.data.at(1));
			int b = (b0<<8)|(b1);
			Orz::WinData::getInstance().setBonus(b);
		}
		break;
	case WheelEnum::HW_WIN_NONE:
		{

			WinData::getInstance().setWinMode(WheelEnum::NONE);
			WinData::getInstance().clear();
			SetWinData(msg.data.at(0), msg.data.at(1));
			SetWinDataWinner(msg.data.at(2));
			runGame();
		}
		break;
	case WheelEnum::HW_WIN_BOUNS:
		{

			
			WinData::getInstance().setWinMode(WheelEnum::NONE);
			//WinData::getInstance().setWinMode(WheelEnum::GOLD);
			WinData::getInstance().clear();
			SetWinData(msg.data.at(0), msg.data.at(1));
			SetWinDataWinner(msg.data.at(2));
			runGame();
		}
		break;
	case WheelEnum::HW_WIN_ANIMAL:
		{
			
			WinData::getInstance().setWinMode(WheelEnum::ALL_ANIMAL);
			WinData::getInstance().clear();
		
			for( int i = 0; i< 3; i++ )
			{
				SetWinData(msg.data.at(i * 2), msg.data.at(i*2 +1));
			}
		
			SetWinDataWinner(msg.data.at(6));
			runGame();
		}
		break;
	case WheelEnum::HW_WIN_COLOR:
		{

			WinData::getInstance().setWinMode(WheelEnum::ALL_COLOR);
			WinData::getInstance().clear();
			
			for(int i = 0; i< 4; i++ )
			{
				SetWinData(msg.data.at(i * 2), msg.data.at(i*2 +1));
			}
		
			SetWinDataWinner(msg.data.at(8));
			runGame();
		}
		break;
	case WheelEnum::HW_WIN_MANY:
		{
			WinData::getInstance().setWinMode(WheelEnum::MANY);
			WinData::getInstance().clear();
			
			for(int i = 0; i< 11; i++ )
			{
				if(msg.data.at(i * 2) != 0)
					SetWinData(msg.data.at(i * 2), msg.data.at(i*2 +1));
			}
		
			SetWinDataWinner(msg.data.at(22));
			runGame();
		}
		break;
	case WheelEnum::HW_WIN_JP:
		{
			if(msg.data.at(2) == 2)
				WinData::getInstance().setWinMode(WheelEnum::DOUBLE);
			else 
				WinData::getInstance().setWinMode(WheelEnum::TREBLE);

				WinData::getInstance().clear();
				SetWinData(msg.data.at(0), msg.data.at(1)/2);
			
				SetWinDataWinner(msg.data.at(3));
				runGame();
			}
			break;
		}

	}
	void NewHardwareEngineDecorator::read(boost::circular_buffer<unsigned char> & data)
{
	boost::circular_buffer<unsigned char>::iterator it;
	for(it = data.begin(); it != data.end(); ++ it)
	{
		//std::cout<<static_cast<int>(*it)<<std::endl;
		_handler.push(static_cast<unsigned char>(*it));
		/*while(!_handler.empty())
		{
			HardwareMsg msg = _handler.pop();
			dealMassage(msg);

		}*/
	}
}