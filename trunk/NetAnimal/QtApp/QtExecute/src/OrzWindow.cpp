#include "OrzWindow.h"
#include "QtExecute.h"
#include "QtInputManager.h"
#include "QTimer.h"
#include <orz/View_OGRE3D/OgreGraphicsManager.h>

namespace Orz
{



	class TheWindow:public WindowInterface
	{
	public:
		TheWindow(OrzWindow * window):_window(window)
		{

		}
		/** 得到窗口句柄
		*/
		virtual size_t getHandle()
		{

			return (size_t)(HWND)_window->winId();
		}

		/** 得到窗口宽度
		*/
		virtual size_t getWidth()
		{
			return static_cast<size_t>(_window->width());
		}

		/** 得到窗口高度
		*/
		virtual size_t getHeight()
		{

			return static_cast<size_t>(_window->height());
		}
		void resize(int width, int height)
		{
			_width = width;
			_height = height;
			_sizeChange(width, height);
		}
	private:
		int _width;
		int _height;
		OrzWindow * _window;
	};
}
OrzWindow::OrzWindow(QWidget *parent, Qt::WFlags flags):QWidget(parent, flags | Qt::MSWindowsOwnDC),_init(false)
{

	QPalette colourPalette = palette();
	colourPalette.setColor(QPalette::Active, QPalette::WindowText, Qt::black);
	colourPalette.setColor(QPalette::Active, QPalette::Window, Qt::black);
	setPalette(colourPalette);



}
OrzWindow::~OrzWindow()
{

	//	_logic->unload();
}


void OrzWindow::mousePressEvent(QMouseEvent* evt)
{
	
	QtInputManager::getSingleton().mousePressEvent(evt);
}
void OrzWindow::mouseReleaseEvent(QMouseEvent* evt)
{
	QtInputManager::getSingleton().mouseReleaseEvent(evt);
}
void OrzWindow::mouseMoveEvent(QMouseEvent* evt)
{
	QtInputManager::getSingleton().mouseMoveEvent(evt);
}
void OrzWindow::wheelEvent(QWheelEvent* evt)
{
	QtInputManager::getSingleton().wheelEvent(evt);
}

//void OrzWindow::resizeEvent(QResizeEvent* evt)
//{
//	//QtExecute::getSingleton().orzWindowResizeEvent();	
//}

//void OrzWindow::initializeGL(void)
//{
//	if(!_init)
//	{
//		_init = true;
//		_logic->load();
//
//	}
//}
QPaintEngine *OrzWindow:: paintEngine() const
{
	return 0;
}

void OrzWindow::paintEvent(QPaintEvent* evt)
{
	
	if(_init)
	{
		_system->update(0.015f);

	}
}

bool OrzWindow::init(void)
{
	if(!_init)
	{

		//These attributes are the same as those use in a QGLWidget
		setAttribute(Qt::WA_PaintOnScreen);
		setAttribute(Qt::WA_NoSystemBackground);
		using namespace Orz;
		_system.reset(new SystemList<boost::mpl::list</*QtLogManager,*/ SimpleTimerManager,OgreGraphicsManager,/* CEGUIManager,*/ QtInputManager, PluginsManager> >());
		//SystemPtr system();
		_system->setParame("w32_mouse",Orz::Variant(true));
		_logic.reset(new LogicConfiger::LogicFacade());
		LogicConfiger::ManualBuilder builder;
		//
		////loader->addPlugin("");

		builder.addPlugin("Model_Base");
		builder.setTheater("TheaterBase", "main");
		////builder.addDirector("AvatarEditorDirector", "avatar_editor");
		////builder.setActiveDirector("avatar_editor");
		//
		_logic->building(builder);

		setMouseTracking(true);
		_window.reset(new Orz::TheWindow(this));
		Orz::WeakWindowPtr win = Orz::WindowPtr(_window);
		_system->setParame<Orz::WeakWindowPtr>("WINDOW", win);

		_system->init();
		_autoUpdateTimer = new QTimer;
		QObject::connect(_autoUpdateTimer, SIGNAL(timeout()), this, SLOT(update()));
		_autoUpdateTimer->setInterval(1);
		_init = true;
		bool ret = _logic->load();
		_autoUpdateTimer->start();
		return ret;

	}
	return false;
}
void OrzWindow::shutdown(void)
{
	_logic->unload();
	_autoUpdateTimer->stop();
	
	_system->shutdown();
}
void OrzWindow::resizeEvent(QResizeEvent* evt)
{

	if(width() == 0 || height() == 0)
		return;

	
	this->setVisible(false);
	_window->resize(width(), height());

	this->setVisible(true);
	//if(m_pOgreRenderWindow)
	//{
	//	m_pOgreRenderWindow->resize(width(), height());
	//	m_pOgreRenderWindow->windowMovedOrResized();

	//	for(int ct = 0; ct < m_pOgreRenderWindow->getNumViewports(); ++ct)
	//	{
	//		Ogre::Viewport* pViewport = m_pOgreRenderWindow->getViewport(ct);
	//		Ogre::Camera* pCamera = pViewport->getCamera();
	//		pCamera->setAspectRatio(static_cast<Ogre::Real>(pViewport->getActualWidth()) / static_cast<Ogre::Real>(pViewport->getActualHeight()));
	//	}
	//}
}

//void OrzWindow::resizeGL( int width, int height  )
//{
//	_window->resize(width, height);
//}
//void OrzWindow::paintGL(void)
//{
//	_system->update(0.015f);
//}