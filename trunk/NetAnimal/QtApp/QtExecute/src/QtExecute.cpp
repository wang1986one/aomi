#include "QtExecute.h"
#include "ControllerQt.h"


//template<> QtExecute* Orz::Singleton<QtExecute>::_singleton = NULL;

QtExecute::QtExecute(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	using namespace Orz;
	ui.setupUi(this);
	
}

//ÏûÏ¢ÏìÓ¦
void QtExecute::keyPressEvent(QKeyEvent* evt)
{
	//QtInputManager::getSingleton().keyPressEvent(evt);
}
void QtExecute::keyReleaseEvent(QKeyEvent* evt)
{
	//QtInputManager::getSingleton().keyReleaseEvent(evt);
}


bool QtExecute::init(void)
{
	return ui._orzWindow->init();
}
void QtExecute::shutdown(void)
{
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
