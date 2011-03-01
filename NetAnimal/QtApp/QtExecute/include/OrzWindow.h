#ifndef __Orz_ControllerQt_OrzWindow_h__
#define __Orz_ControllerQt_OrzWindow_h__
#include <orz/Toolkit_Base/ToolkitBaseAllInclude.h>
#include <orz/Framework_Base/FrameworkBaseAllInclude.h>
#include <QWidget>
#include <QtOpenGL/QGLWidget>
namespace Orz
{
	class TheWindow;
}
class OrzWindow :public QWidget
{
	Q_OBJECT
public:
	OrzWindow(QWidget *parent = 0, Qt::WFlags flags = 0);
	~OrzWindow();

	
	void mousePressEvent(QMouseEvent* evt);
	void mouseReleaseEvent(QMouseEvent* evt);
	void mouseMoveEvent(QMouseEvent* evt);
	void wheelEvent(QWheelEvent* evt);
 
	//void resizeEvent(QResizeEvent* evt);
	
	QPaintEngine *paintEngine() const;
	void paintEvent(QPaintEvent* evt);
	void resizeEvent(QResizeEvent* evt);

	bool init(void);
	void shutdown(void);

protected:

	
	  //virtual void initializeGL(void);
	  //virtual void resizeGL( int, int );
	  //virtual void paintGL(void);
	 
	/*void createLogic();
	LogicConfiger::ConfigerPtr getLogic()
	bool init(void);
	void shutdown(void);*/
private:
	Orz::SystemPtr _system;
	Orz::LogicConfiger::LogicFacadePtr  _logic;//(new LogicConfiger::LogicFacade());
	boost::shared_ptr<Orz::TheWindow> _window;
	bool _init;
	
	QTimer* _autoUpdateTimer;
		//SystemPtr system(new SystemList<boost::mpl::list</*QtLogManager,*/ SimpleTimerManager,OgreGraphicsManager,/* CEGUIManager,*/ QtInputManager, PluginsManager> >());
	//SystemInterface::getSingleton().setParame("w32_mouse",Orz::Variant(true));
	//(new LogicConfiger::Configer());
};


#endif
