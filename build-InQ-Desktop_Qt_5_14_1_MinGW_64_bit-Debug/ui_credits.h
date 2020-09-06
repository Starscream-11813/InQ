/********************************************************************************
** Form generated from reading UI file 'credits.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDITS_H
#define UI_CREDITS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QPlainTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Credits
{
public:
    QDialogButtonBox *buttonBox;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QDialog *Credits)
    {
        if (Credits->objectName().isEmpty())
            Credits->setObjectName(QString::fromUtf8("Credits"));
        Credits->resize(497, 344);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/img/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        Credits->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(Credits);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(390, 10, 81, 621));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);
        plainTextEdit = new QPlainTextEdit(Credits);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(23, 20, 341, 271));
        plainTextEdit->setStyleSheet(QString::fromUtf8("background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 69), stop:0.375 rgba(255, 255, 0, 69), stop:0.423533 rgba(251, 255, 0, 145), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69));"));

        retranslateUi(Credits);
        QObject::connect(buttonBox, SIGNAL(accepted()), Credits, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Credits, SLOT(reject()));

        QMetaObject::connectSlotsByName(Credits);
    } // setupUi

    void retranslateUi(QDialog *Credits)
    {
        Credits->setWindowTitle(QCoreApplication::translate("Credits", "About Us", nullptr));
        plainTextEdit->setPlainText(QCoreApplication::translate("Credits", "InQ is our project for CSE 4302: Object Oriented Programming. It will be a basic sketching app with a multitude of functions related to painting. Its UI (User Interface) will bear a resemblance to the Microsoft Paint application of the Microsoft Windows OS. \n"
"\n"
"Group Members:\n"
"Syed Rifat Raiyan\n"
"Syed Mohammad Sartaj Ekram\n"
"Sarfaraz Maheen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Credits: public Ui_Credits {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDITS_H
