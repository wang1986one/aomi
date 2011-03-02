#include "WheelGobalStableHeaders.h"

#include "WheelGameInterface.h"
#include "WheelUIInterface.h"
using namespace Orz;
template<> WheelGameInterface* Singleton<WheelGameInterface>::_singleton = NULL;
WheelGameInterface::~WheelGameInterface(void)
{

}

		
//WheelGame & WheelGame::getInstance(void)
//{
//	return *(getInstancePtr());
//}
//WheelGame * WheelGame::getInstancePtr(void)
//{
//	static WheelGame instance;
//	return &instance;
//}

		
WheelGameInterface::WheelGameInterface(void):_ui(new WheelNullUI())
{/*
	WheelUIInterfacePtr ui();
	active(ui);*/
}

//void WheelGameInterface::active(WheelEngineInterfacePtr engine)
//{
//	deactive(_engine);
//
//	_engine = engine;
//
//	if(_engine)
//		_engine->addListener(this);
//}

void WheelGameInterface::active(WheelUIInterfacePtr ui)
{

	deactive(_ui);
	if(!ui)
	{
		ui.reset(new WheelNullUI());
	}
	_ui = ui;
	
}
//void WheelGame::active(WheelGameInterfacePtr game)
//{
//	deactive(_game);
//	_game = game;
//}
//
//
//void WheelGame::clockChanged(int second)
//{
//
//}
//
//void WheelGameInterface::deactive(WheelEngineInterfacePtr engine)
//{
//	if(engine)
//		if(_engine == engine)
//		{
//			_engine->removeListener(this);
//			_engine.reset();
//		}
//}
void WheelGameInterface::deactive(WheelUIInterfacePtr ui)
{

	if(_ui == ui)
	{
		//_ui->removeListener(this);
		_ui.reset();
	}
}
//void WheelGame::deactive(WheelGameInterfacePtr game)
//{
//	if(game)
//		if(_game == game)
//		{
//			_game.reset();
//		}
//}