/********************************************************************************
** Form generated from reading UI file 'mathemati.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATHEMATI_H
#define UI_MATHEMATI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Mathemati
{
public:
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QFrame *line;
    QFrame *frame;
    QLabel *label;
    QSpinBox *spinBox;
    QSlider *horizontalSlider;
    QLabel *label_4;
    QFrame *line_2;
    QCustomPlot *widget;
    QFrame *frame_2;
    QLabel *label_3;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QDialog *Mathemati)
    {
        if (Mathemati->objectName().isEmpty())
            Mathemati->setObjectName(QString::fromUtf8("Mathemati"));
        Mathemati->resize(877, 480);
        QFont font;
        font.setPointSize(11);
        Mathemati->setFont(font);
        Mathemati->setStyleSheet(QString::fromUtf8("background-color:rgb(228, 241, 255)"));
        pushButton_2 = new QPushButton(Mathemati);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 20, 101, 61));
        QFont font1;
        font1.setPointSize(13);
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
" font-size:13pt;\n"
" background-color:rgb(96, 255, 109);\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius:10px;\n"
" border-color: rgb(65, 255, 211);\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
" background-color: rgb(67, 255, 64)\n"
"\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
" background-color:rgb(155, 232, 255)\n"
"}\n"
"\n"
"\n"
""));
        pushButton_3 = new QPushButton(Mathemati);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(170, 20, 101, 61));
        pushButton_3->setFont(font1);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
" font-size:13pt;\n"
" background-color: rgb(255, 103, 106);\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius:10px;\n"
" border-color: rgb(255, 94, 204);\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
" background-color: rgb(255, 62, 65)\n"
"\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
" background-color:rgb(255, 84, 224)\n"
"}\n"
"\n"
""));
        line = new QFrame(Mathemati);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(320, -20, 16, 501));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(false);
        line->setFont(font2);
        line->setStyleSheet(QString::fromUtf8("background-color: solid"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        frame = new QFrame(Mathemati);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 110, 291, 171));
        frame->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background-color:rgb(197, 220, 255)\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 10, 231, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Sitka Heading"));
        font3.setPointSize(13);
        label->setFont(font3);
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
" background-color: solid;\n"
"\n"
"\n"
"\n"
"}"));
        spinBox = new QSpinBox(frame);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(20, 120, 61, 31));
        spinBox->setStyleSheet(QString::fromUtf8("background-color: solid"));
        spinBox->setMaximum(90);
        spinBox->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        spinBox->setValue(0);
        horizontalSlider = new QSlider(frame);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(100, 126, 179, 21));
        horizontalSlider->setStyleSheet(QString::fromUtf8("background-color: solid"));
        horizontalSlider->setMaximum(90);
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 70, 261, 31));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Sitka Display"));
        font4.setPointSize(12);
        label_4->setFont(font4);
        label_4->setStyleSheet(QString::fromUtf8("background-color: solid"));
        line_2 = new QFrame(frame);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(30, 40, 231, 20));
        line_2->setStyleSheet(QString::fromUtf8("Line {\n"
"background-color:solid\n"
"\n"
"}"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        widget = new QCustomPlot(Mathemati);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(370, 20, 441, 241));
        widget->setStyleSheet(QString::fromUtf8(" background-color: solid"));
        frame_2 = new QFrame(Mathemati);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(10, 300, 291, 111));
        frame_2->setStyleSheet(QString::fromUtf8("background-color:rgb(213, 255, 245)"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 40, 131, 31));
        label_3->setFont(font4);
        label_3->setStyleSheet(QString::fromUtf8("background-color: solid"));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(160, 38, 111, 41));
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
" background-color: solid;\n"
" border-style: solid;\n"
" border-width:1px;\n"
" border-radius:20px;\n"
" border-color: rgb(65, 255, 211);\n"
"\n"
"}"));
        pushButton = new QPushButton(Mathemati);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(823, 0, 51, 51));
        QFont font5;
        font5.setFamily(QString::fromUtf8("MT Extra"));
        font5.setPointSize(8);
        pushButton->setFont(font5);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color:solid;\n"
" border-style: solid;\n"
" border-width:2px;\n"
" border-radius:10px;\n"
" border-color: rgb(253, 255, 162);\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"\n"
" border-color: rgb(255, 164, 84);\n"
"\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
" border-color:rgb(155, 232, 255)\n"
"}\n"
""));
        pushButton->setIconSize(QSize(40, 40));

        retranslateUi(Mathemati);
        QObject::connect(horizontalSlider, &QSlider::valueChanged, spinBox, &QSpinBox::setValue);
        QObject::connect(spinBox, &QSpinBox::valueChanged, horizontalSlider, &QSlider::setValue);

        QMetaObject::connectSlotsByName(Mathemati);
    } // setupUi

    void retranslateUi(QDialog *Mathemati)
    {
        Mathemati->setWindowTitle(QCoreApplication::translate("Mathemati", "Dialog", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Mathemati", "\320\237\321\203\321\201\320\272", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Mathemati", "\320\241\321\202\320\276\320\277", nullptr));
        label->setText(QCoreApplication::translate("Mathemati", "\320\222\320\262\320\276\320\264 \320\270\321\201\321\205\320\276\320\264\320\275\321\213\321\205 \320\264\320\260\320\275\320\275\321\213\321\205  ", nullptr));
        label_4->setText(QCoreApplication::translate("Mathemati", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\320\276\320\265 \320\276\321\202\320\272\320\273\320\276\320\275\320\265\320\275\320\270\320\265(\320\263\321\200\320\260\320\264):", nullptr));
        label_3->setText(QCoreApplication::translate("Mathemati", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 T(\321\201):", nullptr));
        label_2->setText(QString());
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Mathemati: public Ui_Mathemati {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATHEMATI_H
