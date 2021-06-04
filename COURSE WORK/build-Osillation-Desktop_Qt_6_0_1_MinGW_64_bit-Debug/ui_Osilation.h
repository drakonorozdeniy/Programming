/********************************************************************************
** Form generated from reading UI file 'Osilation.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OSILATION_H
#define UI_OSILATION_H

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
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(822, 521);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color:rgb(205, 246, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(60, 40, 271, 91));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
" font-size: 12pt;\n"
" background-color: white;\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius:20px;\n"
" border-color: rgb(65, 255, 211);\n"
"\n"
"}"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(60, 260, 271, 91));
        QFont font;
        font.setFamily(QString::fromUtf8("Magneto"));
        font.setPointSize(12);
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
" font-size: 12pt;\n"
" background-color: white;\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius:20px;\n"
" border-color: rgb(65, 255, 211);\n"
"\n"
"}"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(60, 150, 271, 91));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
" font-size: 12pt;\n"
" background-color: white;\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius:20px;\n"
" border-color: rgb(65, 255, 211);\n"
"\n"
"}"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(60, 370, 271, 91));
        QFont font1;
        font1.setPointSize(12);
        pushButton_4->setFont(font1);
        pushButton_4->setAutoFillBackground(false);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton{\n"
" font-size: 12pt;\n"
" background-color: white;\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius:20px;\n"
" border-color: rgb(65, 255, 211);\n"
"\n"
"}"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(380, 60, 361, 371));
        label->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/imgonline-com-ua-Resize-3QWka0LPios.gif")));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(360, 420, 441, 51));
        label_2->setMouseTracking(false);
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"font-size: 9pt ;\n"
"}"));
        label_2->setScaledContents(false);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(680, 470, 101, 21));
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"font-size: 9pt ;\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\202\320\265\320\274\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \320\274\320\260\321\217\321\202\320\275\320\270\320\272", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\244\320\270\320\267\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \320\274\320\260\321\217\321\202\320\275\320\270\320\272", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\217\321\202\320\275\320\270\320\272 \320\244\321\203\320\272\320\276", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\217\321\202\320\275\320\270\320\272 \320\262 \321\201\321\200\320\265\320\264\320\265 \321\201 \n"
" \321\201\320\276\320\277\321\200\320\276\321\202\320\270\320\262\320\273\320\265\320\275\320\270\320\265\320\274", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\257 \320\262\320\270\320\264\320\265\320\273 \320\264\320\260\320\273\321\214\321\210\320\265 \320\264\321\200\321\203\320\263\320\270\321\205 \320\277\320\276\321\202\320\276\320\274\321\203 \321\207\321\202\320\276 \321\201\321\202\320\276\321\217\320\273 \320\275\320\260 \320\277\320\273\320\265\321\207\320\260\321\205 \320\263\320\270\320\263\320\260\320\275\321\202\320\276\320\262", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "- \320\230\321\201\320\260\320\272 \320\235\321\214\321\216\321\202\320\276\320\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OSILATION_H
