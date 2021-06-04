/********************************************************************************
** Form generated from reading UI file 'mathematical.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATHEMATICAL_H
#define UI_MATHEMATICAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MathematicalPendulum
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QDialog *MathematicalPendulum)
    {
        if (MathematicalPendulum->objectName().isEmpty())
            MathematicalPendulum->setObjectName(QString::fromUtf8("MathematicalPendulum"));
        MathematicalPendulum->resize(601, 471);
        MathematicalPendulum->setStyleSheet(QString::fromUtf8("background-color:rgb(170, 170, 255)"));
        pushButton = new QPushButton(MathematicalPendulum);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 20, 93, 28));
        pushButton_2 = new QPushButton(MathematicalPendulum);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(140, 20, 93, 28));
        pushButton_3 = new QPushButton(MathematicalPendulum);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 70, 211, 28));
        pushButton_4 = new QPushButton(MathematicalPendulum);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(480, 0, 121, 31));
        QFont font;
        font.setPointSize(5);
        pushButton_4->setFont(font);

        retranslateUi(MathematicalPendulum);

        QMetaObject::connectSlotsByName(MathematicalPendulum);
    } // setupUi

    void retranslateUi(QDialog *MathematicalPendulum)
    {
        MathematicalPendulum->setWindowTitle(QCoreApplication::translate("MathematicalPendulum", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("MathematicalPendulum", "\320\237\321\203\321\201\320\272", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MathematicalPendulum", "\320\241\321\202\320\276\320\277 ", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MathematicalPendulum", "\320\237\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\321\214", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MathematicalPendulum", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217 \320\262 \320\263\320\273\320\260\320\262\320\275\320\276\320\265 \320\274\320\265\320\275\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MathematicalPendulum: public Ui_MathematicalPendulum {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATHEMATICAL_H
