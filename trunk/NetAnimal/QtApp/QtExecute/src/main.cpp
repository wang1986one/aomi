#include <QtGui/QApplication>

#include <QApplication>
#include <QPainterPath>
#include <QPainter>
#include <QTextEdit>
#include <QMap>
#include <qdebug.h>

#include <orz/Framework_Base/System.h>
#include <orz/Toolkit_Base/LogManager.h>
#include <orz/Framework_Base/Logic/GameFactories.h>
#include <orz/Framework_Base/Logic.h>
#include <orz/Toolkit_Base/TimerManager.h>
//#include "QtEditorEvents.h"

#include "QtExecute.h"
//#include "QtEditorTheater.h"
//#include "AvatarEditorDirector.h"

int main(int argc, char *argv[])
{
	using namespace Orz;



	int ret = 0;
	//
	try
	{
		QApplication app(argc, argv);

		boost::shared_ptr<QtExecute> window(new QtExecute());
		if(window->init())
		{
			window->show();
			window->showMaximized();
			ret = app.exec();
			window->shutdown();
		}
	}catch(std::exception & e)
	{
		std::cout<<e.what()<<std::endl;
	}

	return true;
}
