#ifndef CODING_H
#define CODING_H

#include <QtGui/QMainWindow>
#include "ui_coding.h"
#include <orz/Framework_Component/FrameworkComponentAllInclude.h>
#include <orz/Framework_Base/FrameworkBase.h>
#include <orz/Toolkit_Base/DynLibManager.h>

class Coding : public QMainWindow
{
	Q_OBJECT

public:
	Coding(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Coding();
private:
	Ui::CodingClass ui;
	boost::shared_ptr<Orz::SystemByFunctor<> >  _system;
	std::string _text1;
	std::string _text2;
	std::string _text3;
	std::string _text4;
	std::string _text;

	Orz::ComponentPtr _coding;
	Orz::ComponentPtr _lock;
public slots:
	void dirui();
	void dirui2();
	void textChange1(const QString & text);
	void textChange2(const QString & text);
	void textChange3(const QString & text);
	void textChange4(const QString & text);
	void textChange(const QString & text);

};

#endif // CODING_H
