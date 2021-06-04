#include "physical.h"
#include "ui_physicalpendulum.h"

PhysicalPendulum::PhysicalPendulum(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PhysicalPendulum)
{
    ui->setupUi(this);
}

PhysicalPendulum::~PhysicalPendulum()
{
    delete ui;
}
