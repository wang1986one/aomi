#include "MyWheelControllerStableHeaders.h"
#include <orz/View_SingleChip/SingleChipManager.h>

#include "GSMInterface.h"
#include "F5TableInterface.h"
#include "WheelGame.h"
#include "WheelUIInterface.h"
#include "WheelEngineInterface.h"
#include "PoolInterface.h"
#include "DataServerInterface.h"
#include "LockInterface.h"
#include "CommunicateInterface.h"
#include "GameGSMInterface.h"
#include "GSMInterface.h"
using namespace Orz;


class _SMSHandler :public SMSHandler
{
	enum DataIndex
	{
		SUCCESS = 0,
		NEXT,
		EXECUTE,
		AUTH,
		TEXT,
	};
private:

	typedef  boost::tuple<std::string, std::string, ExecuteFunction, GSMSpace::Auth, std::string> 
		Success_Next_Execute_Auth_Text;

	typedef std::map<int, Success_Next_Execute_Auth_Text> Map;
	Map _data;
	std::string _start;
	std::string _fail;
public:
	void addItem(int index, GSMSpace::Auth auth,  const std::string & text, const std::string & sucess, const::std::string & next, SMSHandler::ExecuteFunction execute = SMSHandler::ExecuteFunction())
	{
		_data[index] = Success_Next_Execute_Auth_Text(sucess, next, execute, auth, text);
	}
	_SMSHandler()
	{


	}
	virtual ~_SMSHandler(void)
	{

	}
	int getIndex(int index) const
	{
		Map::const_iterator it = _data.find(index);
		if(it == _data.end())//没有此项操作
		{
			return -1;
		}
		return index;
	}

	virtual bool receive(int index, GSMSpace::Auth auth)
	{
		index = getIndex(index);
		Map::iterator it = _data.find(index);
		if(it == _data.end())//没有此项操作
		{
			return false;
		}
		if(auth > it->second.get<AUTH>())//权限不够
		{
			return false;
		}

		return true;
	}
	virtual const std::string & next(int index, GSMSpace::Auth auth)
	{
		index = getIndex(index);
		Map::iterator it = _data.find(index);
		if(it != _data.end())
		{
			return it->second.get<NEXT>();
		}
		return Orz::IDManager::BLANK;
	}
	virtual bool fail(GSMSpace::Auth auth, std::string & result)
	{
		result += _fail;
		return true;
	}
	virtual bool start(GSMSpace::Auth auth, std::string & result)
	{
		result += _start;
		BOOST_FOREACH(Map::value_type & it, _data)
		{
			if( it.first != -1 && it.second.get<AUTH>() >= auth)
			{
				result += boost::lexical_cast<std::string>(it.first) +"." +it.second.get<TEXT>() +";";
			}
		}
		return true;
	}


	virtual bool success(int index, GSMSpace::Auth auth, std::string & result)
	{

		index = getIndex(index);
		Map::iterator it = _data.find(index);
		if(it != _data.end())
		{
			result += it->second.get<SUCCESS>();
		}
		return false;
	}
	virtual ExecuteFunction execute(int index, GSMSpace::Auth auth) 
	{
		Map::iterator it = _data.find(index);
		if(it != _data.end())
		{
			return it->second.get<EXECUTE>();
		}
		return ExecuteFunction();
	}

	void start(const std::string & text)
	{
		_start = text;
	}
	void fail(const std::string & text)
	{
		_fail = text;
	}
};

WheelGame::~WheelGame(void)
{

	CommunicateInterface * communicate = _hardware->queryInterface<CommunicateInterface>();
	communicate->disconnection();
	GSMInterface * gsm = _gsmComp->queryInterface<GSMInterface>();
	gsm->disconnection();
	gsm->shutdown();
	_gsmConnection.disconnect();
}


WheelGame::WheelGame(EventWorld * world,  WheelEngineInterfacePtr engine, WheelClockPtr clock, EnableSceneFunction  enableSceneFunction):
_world(world), 
_engine(engine), 
_clock(clock), 
_enableSceneFunction(enableSceneFunction),
_select(NULL)
{
	_hardware = Orz::ComponentFactories::getInstance().create("WMHardware");
	_pool = Orz::ComponentFactories::getInstance().create("Pool");
	_table = Orz::ComponentFactories::getInstance().create("Table");
	_gsmComp = Orz::ComponentFactories::getInstance().create("GSM");
	_gameGsmComp = Orz::ComponentFactories::getInstance().create("GameGSM");
	_gameLevel = Orz::ComponentFactories::getInstance().create("GameLevel");

	_clock->setListener(this);
	_dataServer =  Orz::ComponentFactories::getInstance().create("DataServer");
	Ogre::OverlayManager& om = Ogre::OverlayManager::getSingleton();

	_select = (Ogre::OverlayContainer*)om.createOverlayElement( "Panel", "3in1");
#ifdef _GAME1
	_select->setMaterialName("Material_3in12");
#else
	_select->setMaterialName("Material_3in1");
#endif
	_select->setMetricsMode(Ogre::GMM_RELATIVE);
	_select->setWidth(1);
	_select->setHeight(1);
	_select->hide();
	getOverlay()->add2D(_select);


	CommunicateInterface * communicate = _hardware->queryInterface<CommunicateInterface>();

	GSMInterface * gsm = _gsmComp->queryInterface<GSMInterface>();
	_gsmConnection = gsm->subscribeSMS(boost::bind(&WheelGame::getSms, this, _1));
	gsm->init();

	int n = SingleChipManager::getSingleton().getSCMAmount();
	if(n >= 1)
	{
		communicate->connection(0);
	}else
	{
		communicate->connection(-1);
	}
	if(n >= 2)
	{
		gsm->connection(1);
	}else
	{
		gsm->connection(-1);
	}


	GameGSMInterface * game = _gameGsmComp->queryInterface<GameGSMInterface>();


	std::string text;
	report(text);
	gsm->send(game->getRobot(), text);
	boost::shared_ptr<_SMSHandler> report(new _SMSHandler());
	report->start("是否进行查账:");
	report->fail("查账失败。");
	report->addItem(1, GSMSpace::GUEST, "是", "查账结果。", "start" ,boost::bind(&WheelGame::report, this, _1)) ;
	report->addItem(2, GSMSpace::GUEST, "否", "取消查账。", "start");
	game->addHandler("chazhang",report);



	boost::shared_ptr<_SMSHandler> extend(new _SMSHandler());
	extend->start("选择增加额度:");
	extend->fail("额度增加失败。");
	extend->addItem(1, GSMSpace::GUEST, "100", "额度增加。", "start" ,boost::bind(&WheelGame::extend, this, 100, _1)) ;
	extend->addItem(2, GSMSpace::GUEST, "300", "额度增加。", "start" ,boost::bind(&WheelGame::extend, this, 300, _1)) ;
	extend->addItem(3, GSMSpace::GUEST, "500", "额度增加。", "start" ,boost::bind(&WheelGame::extend, this, 500, _1)) ;
	extend->addItem(4, GSMSpace::GUEST, "1000", "额度增加。", "start" ,boost::bind(&WheelGame::extend, this, 1000, _1)) ;
	extend->addItem(5, GSMSpace::GUEST, "3000", "额度增加。", "start" ,boost::bind(&WheelGame::extend, this, 3000, _1)) ;
	extend->addItem(6, GSMSpace::GUEST, "5000", "额度增加。", "start" ,boost::bind(&WheelGame::extend, this, 5000, _1)) ;
	extend->addItem(7, GSMSpace::GUEST, "10000", "额度增加。", "start" ,boost::bind(&WheelGame::extend, this, 10000, _1)) ;
	game->addHandler("baozhang",extend);

	//
	boost::shared_ptr<_SMSHandler> qingling(new _SMSHandler());
	qingling->start("清零:");
	qingling->fail("清零失败。");
	qingling->addItem(1, GSMSpace::GUEST, "是", "执行。", "start" ,boost::bind(&WheelGame::clearData, this, _1)) ;
	qingling->addItem(2, GSMSpace::GUEST, "否", "放弃。", "start");
	game->addHandler("qingling",qingling);

}

ComponentPtr WheelGame::getGSM(void) const
{
	return _gsmComp;
}
ComponentPtr WheelGame::getGameLevel(void) const
{
	return _gameLevel;
}


void WheelGame::getSms(const SMS & sms)
{

	GSMInterface * gsm = _gsmComp->queryInterface<GSMInterface>();
	GameGSMInterface * game = _gameGsmComp->queryInterface<GameGSMInterface>();
	std::string text;
	
	game->handle(sms, text);
	if(!text.empty())
		gsm->send(sms.tel, text);
}
void WheelGame::addBottomToUI(void)
{
	_ui->addBottom();
}
void WheelGame::setSelectVisible(bool visible)
{
	if(visible)
		_select->show();
	else
		_select->hide();
}

void WheelGame::setLogoShow(bool show)
{
	_ui->setLogoShow(show);
}
void WheelGame::setAllSecond(int second)
{
	_clock->setAllSecond(second);
}

void WheelGame::clockChanged(int second)
{

	_ui->setTheTime(second);
	answerTime();

}

bool WheelGame::report(std::string & result)
{
	F5TableInterface * table = _table->queryInterface<F5TableInterface>();
	std::string zhang;
	zhang += "台面数:"+boost::lexical_cast<std::string>(table->getData(F5TableInterface::_all, F5TableInterface::TMS));
	zhang += ";总中分:"+boost::lexical_cast<std::string>(table->getData(F5TableInterface::_all, F5TableInterface::ZZF));
	zhang += ";总压分:"+boost::lexical_cast<std::string>(table->getData(F5TableInterface::_all, F5TableInterface::ZYF));
	result +=( zhang+";查账完成");
	return true;
}
bool WheelGame::extend(int profits, std::string & result)
{
	DataServerInterface * data = _dataServer->queryInterface<DataServerInterface>();

	unsigned int levings = data->getLevingsProfits();
	int all  = levings + profits;
	data->setLevingsProfits(all);
	data->cleanCostBackTimeCode2();
	data->save();
	result += "报账成功,当前额度为:"+boost::lexical_cast<std::string>(all)+"。";
	return true;
}

bool WheelGame::clearData(std::string & result)
{
	F5TableInterface * table = _table->queryInterface<F5TableInterface>();
	table->clear();
	table->save();
	result+= "完成清零。";
	return true;
}
void WheelGame::reportEarnings(void)
{


	//PoolInterface * pool = _pool->queryInterface<PoolInterface>();

	//unsigned int earnings = pool->getEarnings();
	/*if(earnings != 0)
	{*/

		DataServerInterface * data = _dataServer->queryInterface<DataServerInterface>();
		unsigned int levings = data->getLevingsProfits();
		if(1 >= levings)
		{
			data->setLevingsProfits(0);
		}else
		{
			data->setLevingsProfits(levings - 1);
		}

		data->save();
		//pool->clearEarnings();

	//}

}



void WheelGame::resetClock(void)
{
	_clock->reset();

}

void WheelGame::updateClock(TimeType interval)
{
	_clock->update(interval);
}


void WheelGame::update(TimeType interval)
{
	GSMInterface * gsm = _gsmComp->queryInterface<GSMInterface>();
	gsm->update(interval);
	_ui->update(interval);
}
int WheelGame::answerTime(void)
{
	return _clock->getLastSecond();
}

Ogre::Overlay * WheelGame::getOverlay(void)
{
	Ogre::Overlay *  overlay = NULL;
	static std::string overlayName("getOverlay");
	Ogre::OverlayManager& om = Ogre::OverlayManager::getSingleton();
	overlay = om.getByName(overlayName);

	if(!overlay)
	{
		overlay = om.create(overlayName);
		overlay->setZOrder(0);
		overlay->show();
	}
	return overlay;
}


ComponentPtr WheelGame::getDataServer(void)
{
	return _dataServer;
}
//
//LockInterface * lock = _dataServer->queryInterface<LockInterface>();
//		DataServerInterface * data = _dataServer->queryInterface<DataServerInterface>();
//
//		std::string code = lock->getLockCode2();
//		format->decode10(code, 60);
//		unsigned int oCheck = format->getCheck8(60);
//
//
//		if(data->loadCodingData())
//		{
//
//			CodingFormatInterface * lockData = _dataServer->queryInterface<CodingFormatInterface>();
//			unsigned int oId = lockData->getLockID();
//			if(format->decode10(std::string(text.c_str()),28))
//			{
//				if(format->getBackCheck() != oCheck ||format->getBackID() != (oId%128))
//				{
//					warning(L"开机码和报账码不匹配，请重新报账");
//				}else
//				{
//					lockData->setLockLeavings(format->getBackLeavingsIndex());
//					data->saveCodingData();
//					unsigned int index = format->getBackLeavingsIndex();
//					unsigned int profits = format->index2Profits(index);
//					unsigned int levings = data->getLevingsProfits();
//
//					data->setLevingsProfits(levings + profits);
//					data->cleanCostBackTimeCode2();
//					data->save();


void  WheelGame::setEndUIVisible(bool visible)
{
	_ui->setEndUIVisible(visible);
}
void WheelGame::setStartUIVisible(bool visible)
{
	_ui->setStartUIVisible(visible);
}
EventWorld * WheelGame::getWorld(void) const
{
	return _world;
}


ComponentPtr WheelGame::getHardware(void) const
{
	return _hardware;
}
void WheelGame::runWinner(void)
{
	_ui->runWinner();
}

#ifdef _GAME1
	void WheelGame::enableScene(int i)
	{
		if(_enableSceneFunction)
			_enableSceneFunction(i);
	}
#else
	
	void WheelGame::enableScene(const std::string & name, bool second)
	{
		if(_enableSceneFunction)
			_enableSceneFunction(name, second);
	}
#endif
