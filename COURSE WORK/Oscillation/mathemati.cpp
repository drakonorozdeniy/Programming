#define _USE_MATH_DEFINES
#include "mathemati.h"
#include "ui_mathemati.h"
#include <iostream>
#include <QPainter>
#include <tgmath.h>
#include <math.h>
#include <QPixmap>
#include <QIcon>

Mathemati::Mathemati(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mathemati)
{
    ui->setupUi(this);

    ui->pushButton->setIcon(QIcon(":resourses/images/exit.png"));

    timer = new QTimer(this);
    ConnectSignalsWithSlots();

    h=0.1 ;
    xBegin=0;
    xEnd=20 ;

    tic=0.02;
    t=0;
    aAcc=0;
    aVel=0;


    g=9.81;
    len=0.2;


}



Mathemati::~Mathemati()
{
    delete ui;
}

void Mathemati::on_pushButton_clicked()
{
    this->close();
    emit firstwindow();
}

void Mathemati :: ConnectSignalsWithSlots()
{
  QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(on_pushButton_2_clicked()));
  connect(timer, SIGNAL(timeout()),this,SLOT(TimerSlot()));
}

void Mathemati::on_pushButton_2_clicked()
{
    t=0;
    tic=0.02;
    alpha_0=0;
    aAcc=0;
    aVel=0;
    alpha_0=ui->spinBox->value();
    alpha=alpha_0*(M_PI/180);
    w=sqrt(g/len);
    T=2*M_PI*(len/g);
    ui->label_2->setText(QString::number(2*M_PI*(sqrt(len/g))));

    ui->widget->clearGraphs();
    time = 0;
    if (alpha==0)
        timer->start(0);
    else
        timer->start(40);
    x.clear();
    y.clear();
    alpha_2=alpha;
    y.push_back(alpha_0);
    ui->widget->xAxis->setRange(0,20);
    ui->widget->yAxis->setRange(-alpha_0,alpha_0);
    N=(xEnd-xBegin)/h+3;
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x,y);
    ui->widget->replot();


}

void Mathemati::paintEvent(QPaintEvent *)
{
    l=180;
    x0 = 640;
    y0 = 280;
    x1=640;
    y1=460;
    x1 =-1*l * sin(alpha_2),
    y1 = l * cos(alpha_2);
    QPainter painter;
    painter.begin(this);
    QPen pen = painter.pen();
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawLine(x0, y0, x0 + x1, y0 + y1);
    painter.drawEllipse(QPoint(x0 + x1, y0 + y1), 10, 10);
    painter.end();

}

void Mathemati::TimerSlot()
{
    if(time <= 20*N){
        if( t <= xEnd){
            x.push_back(t);
            y.push_back(alpha_0*cos(w*tic+alpha));
            tic+=0.02;
            t +=0.1;
        }
        time +=20;
    }
    else {
        time=0;
        timer->stop();
    }
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x,y);
    ui->widget->replot();

    aAcc=(-1*(g/l)*sin(alpha_2));
    aVel +=aAcc;
    alpha_2+=aVel;

    this->repaint();
}



void Mathemati::on_pushButton_3_clicked()
{
    timer->stop();
}
