#ifndef CREDITS_H
#define CREDITS_H

#include<QDialog>

namespace Ui
{
    class Credits;
}

class Credits : public QDialog
{
    Q_OBJECT

private:
    Ui::Credits *ui;

public:
    Credits(QWidget *parent=nullptr);
    ~Credits();
};

#endif // CREDITS_H
