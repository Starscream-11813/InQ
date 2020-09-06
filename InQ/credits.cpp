#include "credits.h"
#include "ui_credits.h"


Credits::Credits(QWidget *parent):QDialog(parent),ui(new Ui::Credits)
{
    ui->setupUi(this);
    //ui->plainTextEdit->document()->setPlainText("Project for CSE 4302: Object Oriented Programming\nGroup Members:\nSyed Rifat Raiyan\nSyed Mohammad Sartaj Ekram\nSarfaraz Maheen\n");
}
Credits::~Credits()
{
    delete ui;
}

