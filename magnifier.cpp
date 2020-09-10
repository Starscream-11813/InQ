#include "magnifier.h"
#include "ui_magnifier.h"


Magnifier::Magnifier(QWidget *parent) : QDialog(parent), ui(new Ui::Magnifier)
{
    ui->setupUi(this);
    //ui->spinBox->setText(QString::number(100));
    //ui->spinBox->setValidator(new QIntValidator(10, 200, this));
}

Magnifier::~Magnifier()
{
    delete ui;
}

int Magnifier::getZoom() const
{
    return ui->spinBox->text().toInt();     //Returns the string converted to an int using base base, which is 10 by default.
}
