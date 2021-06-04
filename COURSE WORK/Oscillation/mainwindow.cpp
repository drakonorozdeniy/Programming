#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QIcon>
#include <QDir>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    myProcess = new QProcess(this);
    SpiderProcess = new QProcess(this);
    ui->setupUi(this);
    QPixmap pix (":resourses/images/pendulum.png");
    ui->label->setPixmap(pix);

    QPixmap image (":resourses/images/wave.png");
    ui->label2->setPixmap(image);

    QPixmap foto (":resourses/images/spider_man5.png");
    ui->pushButton_2->setIcon(QIcon(foto));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
   hide();
   window = new Mathemati(this);
   connect(window, &Mathemati::firstwindow,this, &MainWindow::show);
   window ->show();
}

void MainWindow::on_pushButton_2_clicked()

{
    myProcess->setProgram(QDir::currentPath() + "/Server/Server.exe");
    myProcess->start();

    SpiderProcess->setProgram(QDir::currentPath() + "/Swing/dist/main.exe");
    SpiderProcess->start();
}

