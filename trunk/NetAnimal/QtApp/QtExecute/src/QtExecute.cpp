#include "QtExecute.h"
#include "ControllerQt.h"
#include <QDir>

#include <QWebFrame>

//template<> QtExecute* Orz::Singleton<QtExecute>::_singleton = NULL;

QtExecute::QtExecute(QWidget *parent, Qt::WFlags flags)
: QMainWindow(parent, flags)
{
	using namespace Orz;
	_pm.reset(new PluginsManager());
	PluginsManager pm;
	
	ui.setupUi(this);
	QDir temDir("../html/panel.html");
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
	_pm->init();
	
	_jsComponent = Orz::ComponentFactories::getInstance().create("Js");
	return ui._orzWindow->init();
}
void QtExecute::shutdown(void)
{
	_pm->shutdown();
	return ui._orzWindow->shutdown();
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


void QtExecute::setupPanel(void)
{
	ui.panle->page()->mainFrame()->evaluateJavaScript("disableButton();");
}