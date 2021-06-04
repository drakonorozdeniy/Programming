#include "fyko.h"
#include "ui_fyko.h"

Fyko::Fyko(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Fyko)
{
    ui->setupUi(this);
}

Fyko::~Fyko()
{
    delete ui;
}


void Fyko::on_pushButton_clicked()
{

}
