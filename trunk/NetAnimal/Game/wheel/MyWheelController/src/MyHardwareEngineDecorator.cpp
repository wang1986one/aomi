#include "MyWheelControllerStableHeaders.h"
#include "MyHardwareEngineDecorator.h"
#include <orz/View_SingleChip/SingleChipManager.h>
#include "WinData.h"
#include "MyHardware.h"
#include "WheelEvents.h"
#include "F6TableInterface.h"
using namespace Orz;



MyHardwareEngineDecorator::MyHardwareEngineDecorator(WheelEngineInterfacePtr engine):_engine(engine),_currTime(0.f)
{
	Orz::SingleChipManager::getSingleton().addListener(this);
	//MyHardwareCode::getSingleton()._callback = boost::bind(&MyHardwareEngineDecorator::dealMassage,this,_1); 
	_f6table = Orz::ComponentFactories::getInstance().create("F5Table");
}



MyHardwareEngineDecorator::~MyHardwareEngineDecorator(void)
{

	Orz::SingleChipManager::getSingleton().removeListener(this);
	//MyHardwareCode::getSingleton()._callback.reset();
}


void MyHardwareEngineDecorator::startGame(size_t time)
{
	if(_engine)
		_engine->startGame(time);
}



void MyHardwareEngineDecorator::clickButton(int id, int button)
{
	if(_engine)
		_engine->clickButton(id, button);

}
void MyHardwareEngineDecorator::runGame(void)
{
	if(_engine)
		_engine->runGame();

}

TimeType MyHardwareEngineDecorator::getTime(void) const
{
	if(_engine)
		return _engine->getTime();
	return 30.f;

}
//
//static void SetWinDataWinner(unsigned char w)
//{
//	switch(w)
//	{
//	case 1:
//		WinData::getInstance().setWinner(Orz::WheelEnum::Dealer);
//		break;
//	case 2:
//		WinData::getInstance().setWinner(Orz::WheelEnum::Player);
//		break;
//	case 3:
//		WinData::getInstance().setWinner(Orz::WheelEnum::Draw);
//		break;
//	}
//}
//static void SetWinData(unsigned char a, unsigned char r)
//{
//	WheelEnum::AnimalItem animal;
//	switch(a)
//	{
//	case 1:
//		animal = WheelEnum::AnimalItem(WheelEnum::TYPE3 , WheelEnum::Red);
//		break;
//	case 2:
//		animal = WheelEnum::AnimalItem(WheelEnum::TYPE2 , WheelEnum::Red);
//		break;
//	case 3:
//		animal = WheelEnum::AnimalItem(WheelEnum::TYPE1 , WheelEnum::Red);
//		break;
//	case 4:
//		animal = WheelEnum::AnimalItem(WheelEnum::TYPE0 , WheelEnum::Red);
//		break;
//	case 5:
//		animal = WheelEnum::AnimalItem(WheelEnum::TYPE3 , WheelEnum::Green);
//		break;
//	case 6:
//		animal = WheelEnum::AnimalItem(WheelEnum::TYPE2 , WheelEnum::Green);
//		break;
//	case 7:
//		animal = WheelEnum::AnimalItem(WheelEnum::TYPE1 , WheelEnum::Green);
//		break;
//	case 8:
//		animal = WheelEnum::AnimalItem(WheelEnum::TYPE0 , WheelEnum::Green);
//		break;
//	case 9:
//		animal = WheelEnum::AnimalItem(WheelEnum::TYPE3 , WheelEnum::Yellow);
//		break;
//	case 10:
//		animal = WheelEnum::AnimalItem(WheelEnum::TYPE2 , WheelEnum::Yellow);
//		break;
//	case 11:
//		animal = WheelEnum::AnimalItem(WheelEnum::TYPE1 , WheelEnum::Yellow);
//		break;
//	case 12:
//		animal = WheelEnum::AnimalItem(WheelEnum::TYPE0 , WheelEnum::Yellow);
//		break;
//	}
//	WinData::getInstance().push_back(animal, int(r));
//
//}

void MyHardwareEngineDecorator::readFromSCM(unsigned int id, unsigned char c)
{
	_handler.push(c);
	while(!_handler.empty())
	{
		HardwareMsg msg = _handler.pop();
		msg.id = id;
		dealMassage(msg);

	}

}
void MyHardwareEngineDecorator::dealMassage(HardwareMsg & msg)
{
	switch(msg.msg)
	{
	case WheelEnum::HW_BUTTON_UP:
		
		clickButton(msg.id, msg.data);
		
		std::cout<<"UP:"<<msg.data<<std::endl;
		break;
	case WheelEnum::HW_BUTTON_DOWN:
		std::cout<<"DOWN:"<<msg.data<<std::endl;

		break;
	
		

	}
}
//	void MyHardwareEngineDecorator::read(boost::circular_buffer<unsigned char> & data)
//{
//	boost::circular_buffer<unsigned char>::iterator it;
//	for(it = data.begin(); it != data.end(); ++ it)
//	{
//		//std::cout<<static_cast<int>(*it)<<std::endl;
//		_handler.push(static_cast<unsigned char>(*it));
//		/*while(!_handler.empty())
//		{
//			HardwareMsg msg = _handler.pop();
//			dealMassage(msg);
//	
//		}*/
//	}
//}


void MyHardwareEngineDecorator::doExecute(Event * evt)
{
	if(Orz::WheelEvents::in(evt))
	{
		
		if(WheelEvents::getMsg(evt) == WheelEvents::PROCESS_READY_ENABLE)
		{

			F6TableInterface * f6table = _f6table->queryInterface<F6TableInterface>();
			int time = f6table->getData(F6TableInterface::DaoShuShiJian);
			enableUpdate();
			_currTime = 0.f;
			startGame(time);
			
		}


	}
}



void MyHardwareEngineDecorator::doEnable(void)
{
	setChannel(EventChannel::create().addUserChannel<CHANNEL_PROCESS>());
	_currTime = 0.f;
}


void MyHardwareEngineDecorator::doDisable(void)
{

}



void MyHardwareEngineDecorator::doFrame(unsigned int step)
{
	
	_currTime+=step* WORLD_UPDATE_INTERVAL;
	if(_currTime >= getTime())
	{
		runGame();
		disableUpdate();
	}
}



