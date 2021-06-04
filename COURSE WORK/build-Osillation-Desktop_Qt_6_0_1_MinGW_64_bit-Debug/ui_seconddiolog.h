/********************************************************************************
** Form generated from reading UI file 'seconddiolog.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDDIOLOG_H
#define UI_SECONDDIOLOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_SecondDiolog
{
public:
    QLabel *label;

    void setupUi(QDialog *SecondDiolog)
    {
        if (SecondDiolog->objectName().isEmpty())
            SecondDiolog->setObjectName(QString::fromUtf8("SecondDiolog"));
        SecondDiolog->resize(400, 300);
        label = new QLabel(SecondDiolog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 100, 55, 16));

        retranslateUi(SecondDiolog);

        QMetaObject::connectSlotsByName(SecondDiolog);
    } // setupUi

    void retranslateUi(QDialog *SecondDiolog)
    {
        SecondDiolog->setWindowTitle(QCoreApplication::translate("SecondDiolog", "Dialog", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SecondDiolog: public Ui_SecondDiolog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDDIOLOG_H
