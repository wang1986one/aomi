#include "NetWheelDirectorStableHeaders.h"
#include "DUI/Dan.h"
#include "F5TableInterface.h"
#include "LockInterface.h"
#include "CodingFormatInterface.h"
#include "DataServerInterface.h"
#include "GSMInterface.h"
using namespace Orz;

DanLine::DanLine(void)
{
}
DanLine::~DanLine(void)
{
}
void DanLine::push_back(CEGUI::Window * win)
{
	_windows.push_back(win);
}
void DanLine::write(int i, const std::string & text)
{
	_windows[i]->setText(text);
}

bool Dan::textAccepted(const CEGUI::EventArgs&) 
{
	if(!check())
		return false;
	
//	CodingFormatInterface * format = _coding->queryInterface<CodingFormatInterface>();
	CEGUI::String text = CEGUI::WindowManager::getSingleton().getWindow("Dan/Bg/Text/Putin")->getText();

	if(text.empty())
		return true;
	if(text.size() <= 9)
	{
		this->warning(L"输入未满9位");

	}else
	{	
	//	format->clear();
	/*	LockInterface * lock = _dataServer->queryInterface<LockInterface>();
		DataServerInterface * data = _dataServer->queryInterface<DataServerInterface>();*/

		//std::string code = lock->getLockCode2();
		//format->decode10(code, 60);
		//unsigned int oCheck = format->getCheck8(60);


		//if(data->loadCodingData())
		//{

		//	CodingFormatInterface * lockData = _dataServer->queryInterface<CodingFormatInterface>();
		//	unsigned int oId = lockData->getLockID();
		//	if(format->decode10(std::string(text.c_str()),28))
		//	{
		//		if(format->getBackCheck() != oCheck ||format->getBackID() != (oId%128))
		//		{
		//			warning(L"开机码和报账码不匹配，请重新报账");
		//		}else
		//		{
		//		/*	lockData->setLockLeavings(format->getBackLeavingsIndex());
		//			data->saveCodingData();
		//			unsigned int index = format->getBackLeavingsIndex();
		//			unsigned int profits = format->index2Profits(index);
		//			unsigned int levings = data->getLevingsProfits();*/

		//			//data->setLevingsProfits(levings + profits);
		//			//data->cleanCostBackTimeCode2();
		//			//data->save();
		//			if(check())
		//			{
		//				warning(L"报账成功");
		//			}
		//		}

		//	}
		//	else
		//	{
		//		warning(L"无效开机码");
		//	}
		//}else
		//	{
		//		warning(L"内部数据错误，请联系开发商！");
		//	}
	
	}
	CEGUI::WindowManager::getSingleton().getWindow("Dan/Bg/Text/Putin")->setText("");
	return true;
}

Dan::Dan(DanListener * listener/*, ComponentPtr dataServer, GSMInterface * gsm*/):_time(-1.f),_callback(listener)//, _gsm(gsm)
{

	//_dataServer = dataServer;

	//_table = Orz::ComponentFactories::getInstance().create("Table");
	//_coding = Orz::ComponentFactories::getInstance().create("Format");
	/*_lockCoding = Orz::ComponentFactories::getInstance().create("Format");
	_lock = Orz::ComponentFactories::getInstance().create("Senselock");*/

	//LockInterface * lock = _dataServer->queryInterface<LockInterface>();

	//CodingFormatInterface * format = _coding->queryInterface<CodingFormatInterface>();
	//
	//DataServerInterface * data = _dataServer->queryInterface<DataServerInterface>();
	//format->_key = lock->key;


	_win= CEGUI::WindowManager::getSingleton().loadWindowLayout("dan.layout");
	_win->setAlwaysOnTop(true);
	_win->hide();
	//CEGUI::Window * f = CEGUI::WindowManager::getSingleton().getWindow("AnimalUI");
	//f->addChildWindow(_win);



	for(int i = 0; i < 9; i++)
	{
		std::string n = boost::lexical_cast<std::string>(i);
		LinePtr line(new DanLine());
		for(int j=0;j<9; ++j)
		{
			//std::cout<<"Dan/Bg/Line0/Tt" + n + boost::lexical_cast<std::string>(j)<<std::endl;
			line->push_back(CEGUI::WindowManager::getSingleton().getWindow("Dan/Bg/Line0/Tt" + n + boost::lexical_cast<std::string>(j)));

		}
		_lines.push_back(line);

	}

	
	

	
}
bool Dan::check(void)
{
	
	//LockInterface * lock = _dataServer->queryInterface<LockInterface>();
	
	/*CodingFormatInterface * lockFormat =  _dataServer->queryInterface<CodingFormatInterface>();
	CodingFormatInterface * format = _coding->queryInterface<CodingFormatInterface>();
	DataServerInterface * data = _dataServer->queryInterface<DataServerInterface>();

	if(_gsm->failsOver(3))
	{
		
		warning(L"请检查短信猫是否配置正确！",2.0);
		return false;
	}*/

	//bool right = true;
	//if(!lock->check())
	//{
	//	warning(L"请检查加密狗是否配置正确！",2.0);
	//	right = false;
	//}

	//if(right)
	//{
	//	
	//	lock->update();
	//	std::string code = lock->getLockCode();

	//	if(!lockFormat->decode10(code, 60))
	//	{
	//		srand(time(NULL));
	//		lockFormat->clear();
	//		lockFormat->setLockTimes(0);
	//		lockFormat->setLockID(rand()%128);
	//		lockFormat->setLockLeavings(0);
	//		lockFormat->setLockPass(0);
	//		right = false;
	//	}

	//	if(!data->hasLevings())
	//	{
	//		warning(L"游戏额度已经用光，请重新打码！", 5.0f );
	//		right = false;
	//	}

	//	
	//}
	//	

	//std::wstringstream wss;

	//if(!right)
	//{
	//	setText("Dan/Bg/Text/BzmText", L"?????,?????,?????,?????");
	//	wss<<L"无法读取游戏额度";
	//}else
	//{
	//	std::string code = lock->getLockCode2();
	//	if(lockFormat->decode10(code, 60))
	//	{
	//	
	//		std::wstring wstr;
	//		for(int i=0;i<20; i++)
	//		{
	//			if(i%5 == 0 && i != 0)
	//				wstr.push_back(',');
	//			wstr.push_back(code.at(i));
	//		}
	//		setText("Dan/Bg/Text/BzmText", wstr);
	//	}
	//	wss<<L"距离下次报账还有"<<data->getLevingsProfits()<<L" 个游戏额度";
	//	warning(L"运行正常！", 1.0f);
	//}
	//
	//setText("Dan/Bg/Text/ed", wss.str());
	return true;
}



void Dan::setText(const std::string & window, const std::wstring & str)
{
	CEGUI::WindowManager::getSingleton().getWindow(window.c_str())->setText((CEGUI::utf8*)Ogre::UTFString(str.c_str()).asUTF8_c_str());
}
void Dan::setText(const std::string & window, const std::string & str)
{
	CEGUI::WindowManager::getSingleton().getWindow(window.c_str())->setText((CEGUI::utf8*)Ogre::UTFString(str.c_str()).asUTF8_c_str());
}
void Dan::warning(const std::wstring & text, TimeType time)
{
	setText("Dan/Bg/W", text);
	_time =time;
}
void Dan::write(int i, int j, const std::string & text)
{
	_lines[j]->write(i, text);
}
void Dan::show(void)
{

	Orz::IInputManager::getSingleton().addKeyListener(this);
	check();
	refresh();
	F5TableInterface * table = _table->queryInterface<F5TableInterface>();
	_connection = table->refreshSigConnection(boost::bind(&Dan::refresh,this));
	CEGUI::Window * win = CEGUI::System::getSingleton().getGUISheet();
	if(win)
	{
		win->addChildWindow(_win);
	}
	_win->show();
	CEGUI::WindowManager::getSingleton().getWindow("Dan/Bg/Text/Putin")->activate();
	static_cast<CEGUI::Editbox*>(CEGUI::WindowManager::getSingleton().getWindow("Dan/Bg/Text/Putin"))->setValidationString("[0-9Xx]*");
	static_cast<CEGUI::Editbox*>(CEGUI::WindowManager::getSingleton().getWindow("Dan/Bg/Text/Putin"))->setMaxTextLength(10);

	CEGUI::WindowManager::getSingleton().getWindow("Dan/Bg/Text/Putin")->
		subscribeEvent(CEGUI::Editbox::EventTextAccepted, CEGUI::Event::Subscriber(&Dan::textAccepted, this));

}
void Dan::hide(void)
{
	Orz::IInputManager::getSingleton().removeKeyListener(this);
	CEGUI::WindowManager::getSingleton().getWindow("Dan/Bg/Text/Putin")->removeAllEvents();
	_win->hide();
	//_connection.disconnect();
	CEGUI::Window * win = CEGUI::System::getSingleton().getGUISheet();
	if(win)
	{
		win->removeChildWindow(_win);
	}
	_time = -1.0;
}
Dan::~Dan(void)
{
		
	

	hide();
	
}

//void Dan::refresh(F5TableInterface::ID id, F5TableInterface::ACCOUNTS_ITEM item)
//{
//
//
//	F5TableInterface * table = _table->queryInterface<F5TableInterface>();
//	int allData = 0;
//	for(int i = 0; i<F5TableInterface::_end; ++i)
//	{
//		int data = table->getData(F5TableInterface::ID(i), item);
//
//		if(i == id)
//			write(item, id, boost::lexical_cast<std::string>(data));
//		allData+= data;
//
//	}
//	write(item, F5TableInterface::_all, boost::lexical_cast<std::string>(allData));
//
//}
void Dan::refresh(void)
{
	F5TableInterface * table = _table->queryInterface<F5TableInterface>();

	for(int j = 0; j<F5TableInterface::END; ++j)
	{
		int allData = 0;
		for(int i = 0; i<F5TableInterface::_end; ++i)
		{

			int data = table->getData(F5TableInterface::ID(i), F5TableInterface::ACCOUNTS_ITEM(j));
			write(j,i,boost::lexical_cast<std::string>(data));
			allData+= data;

		}


		//write(j, F5TableInterface::_all, boost::lexical_cast<std::string>(allData));
	}

}


bool Dan::onKeyPressed(const KeyEvent & evt)
{



	//if(evt.getKey() == Orz::KC_B)
	//{
	//	LockInterface * lock = _dataServer->queryInterface<LockInterface>();
	//	DataServerInterface * data = _dataServer->queryInterface<DataServerInterface>();
	//	
	//	if(check())
	//	{


	//		CodingFormatInterface * format = _coding->queryInterface<CodingFormatInterface>();

	//	

	//		format->clear();
	//		format->setCost(data->getCost());
	//		format->setEarn(data->getEarn());
	//		format->setPass(data->getSeconds()/ 3600);

	//		{
	//			if(!data->loadCodingData())
	//			{
	//				data->reset();
	//			}

	//			CodingFormatInterface * lockData = _dataServer->queryInterface<CodingFormatInterface>();
	//			unsigned int times = lockData->getLockTimes();
	//			format->setTimes(times);
	//			lockData->setLockTimes(times +1);
	//			format->setID(lockData->getLockID());
	//			data->saveCodingData();

	//		}
	//		
	//		std::string str = format->encode10(60 ,20);
	//		
	//		std::wstring wstr;
	//		for(int i=0;i<20; i++)
	//		{
	//			if(i%5 == 0 && i != 0)
	//				wstr.push_back(',');
	//			wstr.push_back(str.at(i));
	//		}
	//		lock->setLockCode2(str);
	//			
	//		data->save();
	//		warning(L"报账码生成，成功！");
	//		setText("Dan/Bg/Text/BzmText", wstr);
	//	}/*else
	//	{
	//		setText("Dan/Bg/Text/BzmText", L"?????,?????,?????,?????");
	//	}*/

	//}
	return false;
}
bool Dan::onKeyReleased(const KeyEvent & evt)
{
	return false;
}
void Dan::update(TimeType time)
{
	if(_time > 0.f)
	{
		_time -= time;
		if( _time <= 0.f)
		{

			check();
		}
	}
}

void Dan::result(bool ret)
{
	if(ret)
	{
		this->warning(L"成功");
	}
	else
		this->warning(L"失败");
	_time = 1.0;
}