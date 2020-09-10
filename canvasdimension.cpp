#include "canvasdimension.h"
#include "ui_canvasdimension.h"

CanvasDimension::CanvasDimension(QWidget *parent) : QDialog(parent), ui(new Ui::CanvasDimension)
{
    ui->setupUi(this);
    ui->height->setValidator(new QIntValidator(1, 5000, this));
    ui->width->setValidator(new QIntValidator(1, 5000, this));
}

CanvasDimension::~CanvasDimension()
{
    delete ui;
}

void CanvasDimension::setHeight(int value)
{
    ui->height->setText(QString::number(value)); //This function holds the line edit's text.
                                                 //number(n)- Returns a string equivalent of the number n according to the specified base.
}

void CanvasDimension::setWidth(int value)
{
    ui->width->setText(QString::number(value));
}

int CanvasDimension::getHeight() const
{
    return ui->height->text().toInt();
}

int CanvasDimension::getWidth() const
{
    return ui->width->text().toInt();
}
