#ifndef PHYSICALPENDULUM_H
#define PHYSICALPENDULUM_H

#include <QDialog>


namespace Ui {
class PhysicalPendulum;
}

class PhysicalPendulum : public QDialog
{
    Q_OBJECT

public:
    explicit PhysicalPendulum(QWidget *parent = nullptr);
    ~PhysicalPendulum();

private:
    Ui::PhysicalPendulum *ui;

};

#endif // PHYSICALPENDULUM_H
