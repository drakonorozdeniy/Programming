/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *label2;
    QLabel *label;
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(510, 182);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 228, 224)"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setAutoFillBackground(false);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 40, 241, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("Gigi"));
        font.setPointSize(14);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
" font-size:14pt;\n"
" background-color: rgb(255,255,255);\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius:20px;\n"
" border-color: rgb(65, 255, 211);\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
" background-color: rgb(254, 222, 255)\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
" background-color:rgb(155, 232, 255)\n"
"}\n"
""));
        label2 = new QLabel(centralwidget);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setGeometry(QRect(0, 70, 121, 121));
        label2->setStyleSheet(QString::fromUtf8("background-color:solid"));
        label2->setScaledContents(true);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(380, -6, 111, 121));
        label->setStyleSheet(QString::fromUtf8("background-color:solid"));
        label->setScaledContents(true);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(450, 130, 51, 51));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:black;\n"
" border-style: solid;\n"
" border-width:2px;\n"
" border-radius:25px;\n"
" border-color: red;\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
" border-color: black;\n"
"background-color:balck;\n"
"\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
" border-color:rgb(155, 232, 255)\n"
"}\n"
""));
        pushButton_2->setIconSize(QSize(40, 40));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\202\320\265\320\274\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \320\274\320\260\321\217\321\202\320\275\320\270\320\272", nullptr));
        label2->setText(QString());
        label->setText(QString());
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
