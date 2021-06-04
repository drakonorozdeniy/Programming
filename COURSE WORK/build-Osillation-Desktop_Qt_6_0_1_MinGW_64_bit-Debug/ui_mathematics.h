/********************************************************************************
** Form generated from reading UI file 'mathematics.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATHEMATICS_H
#define UI_MATHEMATICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_mathematics
{
public:
    QPushButton *pushButton;

    void setupUi(QDialog *mathematics)
    {
        if (mathematics->objectName().isEmpty())
            mathematics->setObjectName(QString::fromUtf8("mathematics"));
        mathematics->resize(604, 472);
        pushButton = new QPushButton(mathematics);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(330, 90, 93, 28));

        retranslateUi(mathematics);

        QMetaObject::connectSlotsByName(mathematics);
    } // setupUi

    void retranslateUi(QDialog *mathematics)
    {
        mathematics->setWindowTitle(QCoreApplication::translate("mathematics", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("mathematics", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mathematics: public Ui_mathematics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATHEMATICS_H
