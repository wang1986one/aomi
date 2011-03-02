#include "coding.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{

	std::cout<<"1111"<<std::endl;
	
	QApplication a(argc, argv);
	std::cout<<"1112"<<std::endl;
	Coding w;
	std::cout<<"1113"<<std::endl;
	w.show();
	std::cout<<"1114"<<std::endl;
	return a.exec();
}
