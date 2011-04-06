#include "QtExecute.h"
#include "ControllerQt.h"
#include <QDir>
#include "JsInterface.h"
#include <QWebFrame>

//template<> QtExecute* Orz::Singleton<QtExecute>::_singleton = NULL;

QtExecute::QtExecute(QWidget *parent, Qt::WFlags flags)
: QMainWindow(parent, flags)
{
	using namespace Orz;
	_pm.reset(new PluginsManager());
	
	ui.setupUi(this);
	QDir temDir("./html/panel.html");
	QString absDir = temDir.absolutePath();
	QUrl url(QString("file:///")+ absDir);
	ui.panle->setUrl(url);
	connect(ui.panle->page()->mainFrame(), SIGNAL(javaScriptWindowObjectCleared()),
		this, SLOT(populateJavaScriptWindowObject()));

	_pm->loadPlugin("JsComponent");
	
}

//ÏûÏ¢ÏìÓ¦
void QtExecute::keyPressEvent(QKeyEvent* evt)
{
}
void QtExecute::keyReleaseEvent(QKeyEvent* evt)
{
}


bool QtExecute::init(void)
{
	using namespace Orz;
	_pm->init();
	
	_jsComponent = Orz::ComponentFactories::getInstance().create("Js");
	JsInterface * js = _jsComponent->queryInterface<JsInterface>();


	assert(js);

	js->subscribeEnableButton(boost::bind(&QtExecute::enableButton,this, _1));
	js->subscribeSetTime(boost::bind(&QtExecute::setTime,this, _1));
	js->subscribeAskPanelData(boost::bind(&QtExecute::askPanelData, this));

	return ui._orzWindow->init();
}
void QtExecute::shutdown(void)
{
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

void QtExecute::answerPanelData(int id, int data)
{
		
	using namespace Orz;
	JsInterface * js = _jsComponent->queryInterface<JsInterface>();
	js->postPanelData(JsInterface::ButtonId(id), data);
}
void QtExecute::enableButton(bool enable)
{
	if(enable)
	{
		
		ui.panle->page()->mainFrame()->evaluateJavaScript("enableButton();");
	}else
	{
		
		ui.panle->page()->mainFrame()->evaluateJavaScript("disableButton();");
	}
}

void QtExecute::setTime(int time)
{
	std::cout<<".."<<time<<std::endl;
	std::string str("setTheTime("+boost::lexical_cast<std::string>(time)+");");
	ui.panle->page()->mainFrame()->evaluateJavaScript(QString(str.c_str()));
}

void QtExecute::askPanelData(void)
{
	std::cout<<"askPanelData"<<std::endl;
	ui.panle->page()->mainFrame()->evaluateJavaScript("askPanelData();");
}

void QtExecute::setupPanel(void)
{
	ui.panle->page()->mainFrame()->evaluateJavaScript("disableButton();");
	ui.panle->page()->mainFrame()->evaluateJavaScript("setTheTime(30);");
}