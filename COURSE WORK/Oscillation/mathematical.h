#ifndef MATHEMATICAL_H
#define MATHEMATICAL_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class MathematicalPendulum;
}

class MathematicalPendulum : public QDialog
{
    Q_OBJECT

public:
    explicit MathematicalPendulum(QWidget *parent = nullptr);
    ~MathematicalPendulum();

private slots:
    void on_pushButton_4_clicked();

private:
    Ui::MathematicalPendulum *ui;
    MainWindow *window_6;
};

#endif // MATHEMATICAL_H
