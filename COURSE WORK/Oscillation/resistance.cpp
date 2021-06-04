#include "resistance.h"
#include "ui_resistance.h"

Resistance::Resistance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Resistance)
{
    ui->setupUi(this);
}

Resistance::~Resistance()
{
    delete ui;
}

void Resistance::on_pushButton_clicked()
{
    this->close();
    emit firstwindow();
}
