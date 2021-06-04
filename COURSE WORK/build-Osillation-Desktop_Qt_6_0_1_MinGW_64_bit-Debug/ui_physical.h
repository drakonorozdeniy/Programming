/********************************************************************************
** Form generated from reading UI file 'physical.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHYSICAL_H
#define UI_PHYSICAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PhysicalPendulum
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QDialog *PhysicalPendulum)
    {
        if (PhysicalPendulum->objectName().isEmpty())
            PhysicalPendulum->setObjectName(QString::fromUtf8("PhysicalPendulum"));
        PhysicalPendulum->resize(613, 469);
        pushButton = new QPushButton(PhysicalPendulum);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 60, 93, 28));
        pushButton_2 = new QPushButton(PhysicalPendulum);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(190, 60, 93, 28));
        pushButton_3 = new QPushButton(PhysicalPendulum);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(72, 130, 211, 28));
        pushButton_4 = new QPushButton(PhysicalPendulum);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(490, 0, 121, 31));
        QFont font;
        font.setPointSize(5);
        pushButton_4->setFont(font);

        retranslateUi(PhysicalPendulum);

        QMetaObject::connectSlotsByName(PhysicalPendulum);
    } // setupUi

    void retranslateUi(QDialog *PhysicalPendulum)
    {
        PhysicalPendulum->setWindowTitle(QCoreApplication::translate("PhysicalPendulum", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("PhysicalPendulum", "\320\237\321\203\321\201\320\272", nullptr));
        pushButton_2->setText(QCoreApplication::translate("PhysicalPendulum", "\320\241\321\202\320\276\320\277", nullptr));
        pushButton_3->setText(QCoreApplication::translate("PhysicalPendulum", "\320\237\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\321\214", nullptr));
        pushButton_4->setText(QCoreApplication::translate("PhysicalPendulum", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217 \320\262 \320\263\320\273\320\260\320\262\320\275\320\276\320\265 \320\274\320\265\320\275\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PhysicalPendulum: public Ui_PhysicalPendulum {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHYSICAL_H
