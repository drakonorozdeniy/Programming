#include "mathematics.h"
#include "ui_mathematics.h"

Mathematics::Mathematics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mathematics)
{
    ui->setupUi(this);
}

Mathematics::~Mathematics()
{
    delete ui;
}
