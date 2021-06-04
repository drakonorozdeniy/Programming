/********************************************************************************
** Form generated from reading UI file 'fyko.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FYKO_H
#define UI_FYKO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Fyko
{
public:
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QFrame *line;
    QPushButton *pushButton_4;

    void setupUi(QDialog *Fyko)
    {
        if (Fyko->objectName().isEmpty())
            Fyko->setObjectName(QString::fromUtf8("Fyko"));
        Fyko->resize(625, 460);
        Fyko->setStyleSheet(QString::fromUtf8("background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:0.994751, y2:1, stop:0 rgba(230, 250, 255, 255), stop:1 rgba(94, 193, 255, 255))"));
        pushButton_2 = new QPushButton(Fyko);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 20, 71, 51));
        QFont font;
        font.setPointSize(11);
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
" background-color: rgb(105, 255, 120);\n"
" border-style: solid;\n"
"\n"
"}\n"
"\n"
""));
        pushButton_3 = new QPushButton(Fyko);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(120, 20, 71, 51));
        pushButton_3->setFont(font);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
" background-color: rgb(255, 105, 105);\n"
" border-style: solid;\n"
"\n"
"\n"
"}"));
        pushButton = new QPushButton(Fyko);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(450, 0, 181, 31));
        QFont font1;
        font1.setPointSize(8);
        pushButton->setFont(font1);
        line = new QFrame(Fyko);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(226, 0, 16, 461));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(false);
        line->setFont(font2);
        line->setStyleSheet(QString::fromUtf8("color:rgb(85, 170, 0)"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        pushButton_4 = new QPushButton(Fyko);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(30, 80, 161, 41));
        pushButton_4->setFont(font);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton{\n"
" background-color: rgb(236, 143, 255);\n"
" border-style: solid;\n"
"\n"
"\n"
"}\n"
""));

        retranslateUi(Fyko);

        QMetaObject::connectSlotsByName(Fyko);
    } // setupUi

    void retranslateUi(QDialog *Fyko)
    {
        Fyko->setWindowTitle(QCoreApplication::translate("Fyko", "Dialog", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Fyko", "\320\237\321\203\321\201\320\272", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Fyko", "\320\241\321\202\320\276\320\277", nullptr));
        pushButton->setText(QCoreApplication::translate("Fyko", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217 \320\262 \320\263\320\273\320\260\320\262\320\275\320\276\320\265 \320\274\320\265\320\275\321\216", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Fyko", "\320\237\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Fyko: public Ui_Fyko {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FYKO_H
