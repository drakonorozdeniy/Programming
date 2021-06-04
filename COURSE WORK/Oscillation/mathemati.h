#ifndef MATHEMATI_H
#define MATHEMATI_H

#include <QDialog>
#include <QSpinBox>
#include <QLineEdit>
#include <QVector>
#include <QTimer>
#include <QtMath>
#include <QPainter>
#include <QWidget>

namespace Ui {
class Mathemati;
}

class Mathemati : public QDialog
{
    Q_OBJECT


signals:
    void firstwindow();

public:
    explicit Mathemati(QWidget *parent = nullptr);
    ~Mathemati();
    double A,w,g,a,alpha_0,alpha_2,aAcc,aVel,l,T,x_1,y_1;

public slots:
    void on_pushButton_2_clicked();

private slots:
    void on_pushButton_clicked();

    void TimerSlot();


    void on_pushButton_3_clicked();


private:
    Ui::Mathemati *ui;
    QTimer *timer;
    double h,xBegin,xEnd,alpha,len,t,tic ;
    int N,time,x0,y0,x1,y1;

    void ConnectSignalsWithSlots();

protected:
    void paintEvent (QPaintEvent*) override;


    QVector <double> x,y;

};

#endif // MATHEMATI_H
