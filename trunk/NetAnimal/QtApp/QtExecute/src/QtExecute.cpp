#include "QtExecute.h"
#include "ControllerQt.h"
#include <QDir>
#include "JsInterface.h"
#include <QWebFrame>
#include <qevent.h>

//template<> QtExecute* Orz::Singleton<QtExecute>::_singleton = NULL;

QtExecute::QtExecute(QWidget *parent, Qt::WFlags flags)
: QMainWindow(parent, flags),_init(false)
{
	using namespace Orz;
	_pm.reset(new PluginsManager());

	ui.setupUi(this);
	/*QDir temDir("./html/panel.html");
	QString absDir = temDir.absolutePath();*/
	QUrl url(QString("http://host.7dgame.com/operators"));
	//QUrl url(QString("http://localhost/public/operators"));
	ui.panle->setUrl(url);
	connect(ui.panle->page()->mainFrame(), SIGNAL(javaScriptWindowObjectCleared()),
		this, SLOT(populateJavaScriptWindowObject()));

	_pm->loadPlugin("JsComponent");


	_keyMap[Qt::Key_1] = "A";
	_keyMap[Qt::Key_2] = "B";
	_keyMap[Qt::Key_3] = "C";
	_keyMap[Qt::Key_Q] = "D";
	_keyMap[Qt::Key_W] = "E";
	_keyMap[Qt::Key_E] = "F";
	_keyMap[Qt::Key_R] = "G";
	_keyMap[Qt::Key_A] = "H";
	_keyMap[Qt::Key_S] = "I";
	_keyMap[Qt::Key_D] = "J";
	_keyMap[Qt::Key_F] = "K";
	_keyMap[Qt::Key_Z] = "L";
	_keyMap[Qt::Key_X] = "M";
	_keyMap[Qt::Key_C] = "N";
	_keyMap[Qt::Key_V] = "O";

}

//消息响应
void QtExecute::keyPressEvent(QKeyEvent* evt)
{

	KeyMapType::iterator it = _keyMap.find(Qt::Key(evt->key()));
	if(it != _keyMap.end())
	{
		setMarkNum(it->second);
	}
	////bin.wang 2011.04.17
	////红色
	//if (evt->key()==Qt::Key_Q)
	//{
	//	setMarkNum("red_lion");		
	//}else if (evt->key()==Qt::Key_W)
	//{
	//	setMarkNum("red_panda");	
	//}else if (evt->key()==Qt::Key_E)
	//{
	//	setMarkNum("red_monkey");	
	//}else if (evt->key()==Qt::Key_R)
	//{
	//	setMarkNum("red_rabbit");	
	//}
	////黄色 
	//else if (evt->key()==Qt::Key_A)
	//{
	//	setMarkNum("yellow_lion");	
	//}else if (evt->key()==Qt::Key_S)
	//{
	//	setMarkNum("yellow_panda");	
	//}else if (evt->key()==Qt::Key_D)
	//{
	//	setMarkNum("yellow_monkey");	
	//}else if (evt->key()==Qt::Key_F)
	//{
	//	setMarkNum("yellow_rabbit");	
	//}
	////绿色
	//else if (evt->key()==Qt::Key_Z)
	//{
	//	setMarkNum("green_lion");	
	//}else if (evt->key()==Qt::Key_X)
	//{
	//	setMarkNum("green_panda");	
	//}else if (evt->key()==Qt::Key_C)
	//{
	//	setMarkNum("green_monkey");	
	//}else if (evt->key()==Qt::Key_V)
	//{
	//	setMarkNum("green_rabbit");	
	//}
}
void QtExecute::keyReleaseEvent(QKeyEvent* evt)
{

	//	std::cout<<evt->text().toStdString()<<std::endl;
}

//bin.wang 2011.04.17 
void QtExecute::setMarkNum(const std::string  &name)
{
	std::string str = "handleKey('" + name + "');";
	ui.panle->page()->mainFrame()->evaluateJavaScript(QString(str.c_str()));
}
//
//void QtExecute::setWinner(Orz::JsInterface::ButtonId id, int profit)
//{
//
//	using namespace Orz;
//
//	std::string str;
//	switch(id)
//	{
//	case JsInterface::ButtonZhuang:
//		str = "setWinner('zhuang' ,"+boost::lexical_cast<std::string>(profit)+");";
//		break;
//	case JsInterface::ButtonXian:
//		str = "setWinner('xian' ,"+boost::lexical_cast<std::string>(profit)+");";
//		break;
//	case JsInterface::ButtonHe:
//		str = "setWinner('he' ,"+boost::lexical_cast<std::string>(profit)+");";
//		break;
//
//
//	case JsInterface::ButtonRedRabbit:
//		str = "setWinner('red_rabbit' ,"+boost::lexical_cast<std::string>(profit)+");";
//		break;
//	case JsInterface::ButtonRedMonkey:
//		str = "setWinner('red_monkey' ,"+boost::lexical_cast<std::string>(profit)+");";
//		break;
//	case JsInterface::ButtonRedPanda:
//		str = "setWinner('red_panda' ,"+boost::lexical_cast<std::string>(profit)+");";
//		break;
//	case JsInterface::ButtonRedLoin:
//		str = "setWinner('red_lion' ,"+boost::lexical_cast<std::string>(profit)+");";
//		break;
//
//
//
//
//	case JsInterface::ButtonGreenRabbit:
//		str = "setWinner('green_rabbit' ,"+boost::lexical_cast<std::string>(profit)+");";
//		break;
//	case JsInterface::ButtonGreenMonkey:
//		str = "setWinner('green_monkey' ,"+boost::lexical_cast<std::string>(profit)+");";
//		break;
//	case JsInterface::ButtonGreenPanda:
//		str = "setWinner('green_panda' ,"+boost::lexical_cast<std::string>(profit)+");";
//		break;
//	case JsInterface::ButtonGreenLoin:
//		str = "setWinner('green_lion' ,"+boost::lexical_cast<std::string>(profit)+");";
//		break;
//
//
//
//	case JsInterface::ButtonYellowRabbit:
//		str = "setWinner('yellow_rabbit' ,"+boost::lexical_cast<std::string>(profit)+");";
//		break;
//	case JsInterface::ButtonYellowMonkey:
//		str = "setWinner('yellow_monkey' ,"+boost::lexical_cast<std::string>(profit)+");";
//		break;
//	case JsInterface::ButtonYellowPanda:
//		str = "setWinner('yellow_panda' ,"+boost::lexical_cast<std::string>(profit)+");";
//		break;
//	case JsInterface::ButtonYellowLoin:
//		str = "setWinner('yellow_lion' ,"+boost::lexical_cast<std::string>(profit)+");";
//		break;
//
//	}
//
//	ui.panle->page()->mainFrame()->evaluateJavaScript(QString(str.c_str()));
//
//}
bool QtExecute::init(void)
{
	using namespace Orz;
	_pm->init();

	_jsComponent = Orz::ComponentFactories::getInstance().create("Js");
	JsInterface * js = _jsComponent->queryInterface<JsInterface>();


	assert(js);

	//js->subscribeEnableButton(boost::bind(&QtExecute::enableButton,this, _1));
//	js->subscribeSetTime(boost::bind(&QtExecute::setTime,this, _1));
	js->subscribeAskPanelData(boost::bind(&QtExecute::askPanelData, this));
//	js->subscribeSetWinner(boost::bind(&QtExecute::setWinner, this, _1, _2));
	js->subscribeSetState(boost::bind(&QtExecute::setState, this, _1));

	ui._orzWindow->init();
	_init = true;
	return true;
}

void QtExecute::setState(Orz::JsInterface::State state)
{

	std::string str("setState("+boost::lexical_cast<std::string>(state)+");");
	ui.panle->page()->mainFrame()->evaluateJavaScript(QString(str.c_str()));
}
void QtExecute::shutdown(void)
{
	_init = false;
	_jsComponent.reset();
	ui._orzWindow->shutdown();
	_pm->shutdown();
	_pm.reset();
}
size_t QtExecute::getHandle()
{
	return (size_t)(HWND)ui._orzWindow->winId();
}

size_t QtExecute::getWidth() 
{
	return static_cast<size_t>(ui._orzWindow->width());
}
size_t QtExecute::getHeight()
{
	return static_cast<size_t>(ui._orzWindow->height());
}


void QtExecute::orzWindowResizeEvent(void)
{
	//	_sizeChange(getWidth(), getHeight());
}





QtExecute::~QtExecute()
{

	//	_system.reset();
}


void QtExecute::populateJavaScriptWindowObject(void)
{
	ui.panle->page()->mainFrame()->addToJavaScriptWindowObject("QtExecute", this);

}

void QtExecute::startGame(void)
{	
	if(_init)
	{
		using namespace Orz;
		JsInterface * js = _jsComponent->queryInterface<JsInterface>();
		assert(js);
		js->startGame();
	}
}
void QtExecute::answerPanelData(int id, int data)
{

	using namespace Orz;
	JsInterface * js = _jsComponent->queryInterface<JsInterface>();
	std::cout<<"!"<<id<<";"<<data<<std::endl;
	js->postPanelData(JsInterface::ButtonId(id), data);
}
//void QtExecute::enableButton(bool enable)
//{
//	if(enable)
//	{
//
//		ui.panle->page()->mainFrame()->evaluateJavaScript("enableButton();");
//	}else
//	{
//
//		ui.panle->page()->mainFrame()->evaluateJavaScript("disableButton();");
//	}
//}

void QtExecute::setTime(int time)
{
	if(_init)
	{
		using namespace Orz;
		JsInterface * js = _jsComponent->queryInterface<JsInterface>();
		assert(js);
		js->setTime(time);
	}
}

void QtExecute::askPanelData(void)
{
	std::cout<<"askPanelData"<<std::endl;
	//ui.panle->page()->mainFrame()->evaluateJavaScript("askPanelData();");
}

void QtExecute::setupPanel(void)
{
	/*ui.panle->page()->mainFrame()->evaluateJavaScript("disableButton();");
	ui.panle->page()->mainFrame()->evaluateJavaScript("setTheTime(30);");*/
}


//void QtExecute::setWinData(int type, int color, int animal)
//{
//	if(_init)
//	{
//		using namespace Orz;
//		//JsInterface * js = _jsComponent->queryInterface<JsInterface>();
//
//		//js->setWinData(type, color, animal);
//	}
//}



void QtExecute::setWinData(const QString & data)
{
	if(_init)
	{
		using namespace Orz;
		JsInterface * js = _jsComponent->queryInterface<JsInterface>();
		std::string str = std::string((const char *)data.toLocal8Bit());
		js->setWinData(str);
	}
}
