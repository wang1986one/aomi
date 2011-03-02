#include "coding.h"
#include <QTextCodec>
#include "CodingInterface.h"
#include "LockInterface.h"
#include "DataServerInterface.h"
#include "CodingFormatInterface.h"
Coding::Coding(QWidget *parent, Qt::WFlags flags)
: QMainWindow(parent, flags)
{

	std::cout<<"a"<<std::endl;
	ui.setupUi(this);
	std::cout<<"b"<<std::endl;
	using namespace Orz;
	std::cout<<"c"<<std::endl;
	_system.reset(new SystemByFunctor<>());

	std::cout<<"d"<<std::endl;
	_system->push<PluginsManager, true, false, true>();
	std::cout<<"e"<<std::endl;
	_system->init();
	std::cout<<"f"<<std::endl;
	PluginsManager::getSingleton().loadPlugin("CodingComponent");


	std::cout<<"g"<<std::endl;
	_coding = Orz::ComponentFactories::getInstance().create("Format");
	std::cout<<"h"<<std::endl;
	_lock = Orz::ComponentFactories::getInstance().create("DataServer");
	std::cout<<"i"<<std::endl;

	LockInterface * lock = _lock->queryInterface<LockInterface>();
	std::cout<<"j"<<std::endl;

	CodingFormatInterface * format = _coding->queryInterface<CodingFormatInterface>();
	std::cout<<"k"<<std::endl;

	format->_key = lock->key;
	std::cout<<"l"<<std::endl;


	QObject::connect(ui.pushButton, SIGNAL(clicked(bool)), this, SLOT(dirui()));
	std::cout<<"m"<<std::endl;
	QObject::connect(ui.pushButton_2, SIGNAL(clicked(bool)), this, SLOT(dirui2()));
	std::cout<<"n"<<std::endl;

	QObject::connect(ui.lineEdit, SIGNAL(textChanged(QString)), this, SLOT(textChange1(QString)));
	std::cout<<"o"<<std::endl;
	QObject::connect(ui.lineEdit_2, SIGNAL(textChanged(QString)), this, SLOT(textChange2(QString)));
	std::cout<<"p"<<std::endl;
	QObject::connect(ui.lineEdit_3, SIGNAL(textChanged(QString)), this, SLOT(textChange3(QString)));
	std::cout<<"q"<<std::endl;
	QObject::connect(ui.lineEdit_7, SIGNAL(textChanged(QString)), this, SLOT(textChange4(QString)));
	std::cout<<"r"<<std::endl;
	/*
	QValidator *validator = new QIntValidator(this);

	ui.lineEdit->setValidator(validator);	
	ui.lineEdit_2->setValidator(validator);	
	ui.lineEdit_3->setValidator(validator);	
	ui.lineEdit_7->setValidator(validator);*/


	QObject::connect(ui.comboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(textChange(QString)));
	std::cout<<"s"<<std::endl;
	ui.pushButton_2->setEnabled(false);
	std::cout<<"t"<<std::endl;
	//ui.comboBox->setCurrentIndex(7);
	std::cout<<"u"<<std::endl;
	std::cout<<"v"<<std::endl;
	_text = ui.comboBox->currentText().toUtf8(); 
	std::cout<<"w"<<std::endl;

}

void Coding::textChange1(const QString & text)
{

	//QTextCodec *code = QTextCodec::codecForName("gb18030");
	//if(code)
	//{
	//	_text1 = code->fromUnicode(text).data(); // pathname 为QString的中文路径名
	//	std::cout<<_text1<<std::endl;
	//}

	_text1 = text.toUtf8();
	std::cout<<_text1<<std::endl;
	/*{
		text.
	}*/
	//std::cout<<"nono"<<code<<std::endl;
}
void Coding::textChange2(const QString & text)
{


	
	_text2 = text.toUtf8();
	std::cout<<_text2<<std::endl;
}
void Coding::textChange3(const QString & text)
{

	
	_text3 = text.toUtf8();
	std::cout<<_text3<<std::endl;
}

void Coding::textChange4(const QString & text)
{

	
	_text4 = text.toUtf8();
	std::cout<<_text4<<std::endl;
}
void Coding::textChange(const QString & text)
{

	_text = text.toUtf8();
	std::cout<<_text<<std::endl;
}
void Coding::dirui()
{

	using namespace Orz;

	QTextCodec *codec = QTextCodec::codecForLocale();
	LockInterface * lock = _lock->queryInterface<LockInterface>();
	if(!lock->check())
	{	
		ui.label_7->setText(codec->toUnicode("请查看加密狗是否配置正确！"));
		ui.pushButton_2->setEnabled(false);
		return;
	}

	std::string all = _text1 + _text2 +_text3 + _text4;
	CodingFormatInterface * format = _coding->queryInterface<CodingFormatInterface>();
	if(format)
	{
		try{
			if(format->decode10(all, 60))
			{
				ui.lineEdit_4->setText(boost::lexical_cast<std::string>(format->getCost()).c_str());
				ui.lineEdit_5->setText(boost::lexical_cast<std::string>(format->getEarn()).c_str());
				ui.lineEdit_8->setText(boost::lexical_cast<std::string>(format->getID()).c_str());
				ui.label_8->setText(boost::lexical_cast<std::string>(format->getPass()).c_str());

				ui.label_7->setText(codec->toUnicode("场地号码解码成功"));

				ui.pushButton_2->setEnabled(true);

			}else
			{
				ui.lineEdit_4->setText("?");
				ui.lineEdit_5->setText("?");
				ui.lineEdit_8->setText("?");
				ui.label_8->setText("?");

				ui.label_7->setText(codec->toUnicode("请检查场地码"));
				ui.pushButton_2->setEnabled(false);
			}
		}
		catch(...)
		{

			ui.lineEdit_4->setText("?");
			ui.lineEdit_5->setText("?");
			ui.lineEdit_8->setText("?");
			ui.label_8->setText("?");



			ui.label_7->setText(codec->toUnicode("请检查场地码"));
			ui.pushButton_2->setEnabled(false);
		}
	}


}


void Coding::dirui2()
{
	using namespace Orz;
	CodingFormatInterface * format = _coding->queryInterface<CodingFormatInterface>();
	CodingInterface * coding = _coding->queryInterface<CodingInterface>();
	unsigned int check = format->getCheck8(60);
	unsigned int id = format->getID();

	std::cout<<"Times:"<<format->getTimes()<<std::endl;
	std::cout<<"id:"<<format->getLockID()<<std::endl;
	std::cout<<"pass:"<<format->getPass()<<std::endl;
	coding->clear();
	unsigned int num = boost::lexical_cast<unsigned int>(_text);
	std::cout<<num<<std::endl;

	unsigned int index  = format->profits2Index(num);

	format->setBackCheck(check);
	format->setBackID(id);
	format->setBackLeavingsIndex(index);


	std::cout<<"check:"<<format->getBackCheck()<<std::endl;
	std::cout<<"id:"<<format->getBackID()<<std::endl;
	std::cout<<"Leavings:"<<format->getBackLeavingsIndex()<<std::endl;
	//DataServerInterface * data = _lock->queryInterface<DataServerInterface>();
	//format->set10(num);
	std::string str = format->encode10(28, 10);
	ui.pushButton_2->setEnabled(false);
	ui.lineEdit_6->setText(str.c_str());
	format->clear();
	format->decode10(str, 28);



	std::cout<<"check:"<<format->getBackCheck()<<std::endl;
	std::cout<<"id:"<<format->getBackID()<<std::endl;
	std::cout<<"Leavings:"<<format->getBackLeavingsIndex()<<std::endl;

	QTextCodec *codec = QTextCodec::codecForLocale();

	ui.label_7->setText(codec->toUnicode("开局码生成成功"));


}
Coding::~Coding()
{
	_coding.reset();
	_lock.reset();
	_system->shutdown();
}
