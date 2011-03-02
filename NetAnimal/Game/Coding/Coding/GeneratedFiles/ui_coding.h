/********************************************************************************
** Form generated from reading UI file 'coding.ui'
**
** Created: Fri Dec 31 22:52:15 2010
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CODING_H
#define UI_CODING_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CodingClass
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLabel *label_8;
    QLineEdit *lineEdit_7;
    QLabel *label_9;
    QLineEdit *lineEdit_8;
    QLabel *label_10;
    QLabel *label_6;
    QComboBox *comboBox;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_6;
    QLabel *label_7;
    QFrame *line;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CodingClass)
    {
        if (CodingClass->objectName().isEmpty())
            CodingClass->setObjectName(QString::fromUtf8("CodingClass"));
        CodingClass->resize(640, 480);
        CodingClass->setMinimumSize(QSize(640, 480));
        CodingClass->setMaximumSize(QSize(640, 480));
        centralWidget = new QWidget(CodingClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 611, 241));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 20, 71, 21));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setInputMethodHints(Qt::ImhNone);
        lineEdit->setMaxLength(5);
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(120, 20, 71, 21));
        lineEdit_2->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_2->setMaxLength(5);
        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(220, 20, 71, 21));
        lineEdit_3->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_3->setMaxLength(5);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 10, 16, 31));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(200, 10, 16, 31));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(280, 110, 311, 91));
        QFont font;
        font.setPointSize(16);
        pushButton->setFont(font);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 60, 54, 12));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 90, 54, 12));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 160, 61, 16));
        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(80, 50, 113, 20));
        lineEdit_4->setReadOnly(true);
        lineEdit_5 = new QLineEdit(groupBox);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(80, 80, 113, 20));
        lineEdit_5->setReadOnly(true);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(90, 160, 54, 12));
        lineEdit_7 = new QLineEdit(groupBox);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(320, 20, 71, 21));
        lineEdit_7->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEdit_7->setMaxLength(5);
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(300, 10, 16, 31));
        lineEdit_8 = new QLineEdit(groupBox);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(80, 110, 113, 20));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 109, 71, 31));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(70, 280, 61, 16));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(150, 280, 69, 22));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 280, 311, 91));
        pushButton_2->setFont(font);
        lineEdit_6 = new QLineEdit(centralWidget);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(60, 340, 201, 21));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 410, 551, 16));
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 400, 631, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        CodingClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CodingClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 640, 19));
        CodingClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CodingClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        CodingClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CodingClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        CodingClass->setStatusBar(statusBar);

        retranslateUi(CodingClass);

        QMetaObject::connectSlotsByName(CodingClass);
    } // setupUi

    void retranslateUi(QMainWindow *CodingClass)
    {
        CodingClass->setWindowTitle(QApplication::translate("CodingClass", "\345\244\232\345\220\210\344\270\200\346\211\223\347\240\201\346\234\272\345\231\250\357\274\210http://www.duoheyi.com\357\274\211", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CodingClass", "\345\234\272\345\234\260\347\240\201", 0, QApplication::UnicodeUTF8));
        lineEdit->setInputMask(QString());
        label->setText(QApplication::translate("CodingClass", "__", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CodingClass", "__", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("CodingClass", "\350\247\243\347\240\201", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CodingClass", "\346\200\273\347\233\210\345\210\251\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("CodingClass", "\346\200\273\345\216\213\345\210\206\357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("CodingClass", "\346\212\245\347\240\201\346\254\241\346\225\260\357\274\232", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("CodingClass", "0", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("CodingClass", "__", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("CodingClass", "\346\200\273\350\277\220\350\241\214\346\227\266\351\227\264\357\274\232", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("CodingClass", "\345\274\200\345\245\226\345\261\200\346\225\260\357\274\232", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("CodingClass", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CodingClass", "15", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CodingClass", "30", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CodingClass", "45", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CodingClass", "90", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CodingClass", "120", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CodingClass", "240", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CodingClass", "480", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CodingClass", "960", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CodingClass", "1500", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CodingClass", "3000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CodingClass", "5000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CodingClass", "10000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CodingClass", "20000", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("CodingClass", "50000", 0, QApplication::UnicodeUTF8)
        );
        pushButton_2->setText(QApplication::translate("CodingClass", "\347\224\237\346\210\220\345\274\200\345\261\200\347\240\201", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("CodingClass", "http://www.duoheyi.com", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CodingClass: public Ui_CodingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CODING_H
