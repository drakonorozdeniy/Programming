/********************************************************************************
** Form generated from reading UI file 'resistance2.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESISTANCE2_H
#define UI_RESISTANCE2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Resistance2
{
public:
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QFrame *line;
    QPushButton *pushButton_4;
    QFrame *frame;
    QLabel *label;
    QSpinBox *spinBox_2;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QSlider *horizontalSlider_2;

    void setupUi(QDialog *Resistance2)
    {
        if (Resistance2->objectName().isEmpty())
            Resistance2->setObjectName(QString::fromUtf8("Resistance2"));
        Resistance2->resize(822, 510);
        Resistance2->setStyleSheet(QString::fromUtf8("background-color:qlineargradient(spread:pad, x1:0, y1:0, x2:0.994751, y2:1, stop:0 rgba(230, 250, 255, 255), stop:1 rgba(94, 193, 255, 255))"));
        pushButton_2 = new QPushButton(Resistance2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 20, 71, 51));
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
        pushButton_3 = new QPushButton(Resistance2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(110, 20, 71, 51));
        pushButton_3->setFont(font);
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{\n"
" background-color: rgb(255, 105, 105);\n"
" border-style: solid;\n"
"\n"
"\n"
"}"));
        pushButton = new QPushButton(Resistance2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(640, 0, 181, 31));
        QFont font1;
        font1.setPointSize(8);
        pushButton->setFont(font1);
        line = new QFrame(Resistance2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(350, 0, 16, 511));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(false);
        line->setFont(font2);
        line->setStyleSheet(QString::fromUtf8("color:rgb(85, 170, 0)"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        pushButton_4 = new QPushButton(Resistance2);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 80, 161, 41));
        pushButton_4->setFont(font);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton{\n"
" background-color: rgb(236, 143, 255);\n"
" border-style: solid;\n"
"\n"
"\n"
"}\n"
""));
        frame = new QFrame(Resistance2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(20, 140, 291, 351));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 211, 21));
        QFont font3;
        font3.setPointSize(12);
        label->setFont(font3);
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
" background-color: solid;\n"
"\n"
"\n"
"\n"
"}"));
        spinBox_2 = new QSpinBox(frame);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(10, 100, 61, 31));
        layoutWidget_2 = new QWidget(frame);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(100, 90, 181, 41));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSlider_2 = new QSlider(layoutWidget_2);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider_2);


        retranslateUi(Resistance2);
        QObject::connect(horizontalSlider_2, &QSlider::valueChanged, spinBox_2, &QSpinBox::setValue);
        QObject::connect(spinBox_2, &QSpinBox::valueChanged, horizontalSlider_2, &QSlider::setValue);

        QMetaObject::connectSlotsByName(Resistance2);
    } // setupUi

    void retranslateUi(QDialog *Resistance2)
    {
        Resistance2->setWindowTitle(QCoreApplication::translate("Resistance2", "Dialog", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Resistance2", "\320\237\321\203\321\201\320\272", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Resistance2", "\320\241\321\202\320\276\320\277", nullptr));
        pushButton->setText(QCoreApplication::translate("Resistance2", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217 \320\262 \320\263\320\273\320\260\320\262\320\275\320\276\320\265 \320\274\320\265\320\275\321\216", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Resistance2", "\320\237\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("Resistance2", "\320\222\320\262\320\276\320\264 \320\270\321\201\321\205\320\276\320\264\320\275\321\213\321\205 \320\264\320\260\320\275\320\275\321\213\321\205  ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Resistance2: public Ui_Resistance2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESISTANCE2_H
