#ifndef FYKO_H
#define FYKO_H

#include <QDialog>

namespace Ui {
class Fyko;
}

class Fyko : public QDialog
{
    Q_OBJECT

signals :
    void firstwindow();

public:
    explicit Fyko(QWidget *parent = nullptr);
    ~Fyko();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::Fyko *ui;
};

#endif // FYKO_H
