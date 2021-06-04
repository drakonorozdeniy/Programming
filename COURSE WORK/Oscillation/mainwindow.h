#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mathemati.h"
#include <QProcess>
#include <QString>
#include <QObject>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Mathemati *window;
    QProcess *myProcess;
    QProcess *SpiderProcess;



};
#endif // MAINWINDOW_H
