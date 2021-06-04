#include "mathematical.h"
#include "ui_mathematicalpendulum.h"

MathematicalPendulum::MathematicalPendulum(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MathematicalPendulum)
{
    ui->setupUi(this);
}

MathematicalPendulum::~MathematicalPendulum()
{
    delete ui;
}

void MathematicalPendulum::on_pushButton_4_clicked()
{

}
