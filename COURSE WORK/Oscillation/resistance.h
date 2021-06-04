#ifndef RESISTANCE_H
#define RESISTANCE_H

#include <QDialog>

namespace Ui {
class Resistance;
}

class Resistance : public QDialog
{
    Q_OBJECT

signals :
    void firstwindow();

public:
    explicit Resistance(QWidget *parent = nullptr);
    ~Resistance();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::Resistance *ui;
};

#endif // RESISTANCE_H
