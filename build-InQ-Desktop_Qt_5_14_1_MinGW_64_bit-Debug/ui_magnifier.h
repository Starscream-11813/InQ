/********************************************************************************
** Form generated from reading UI file 'magnifier.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAGNIFIER_H
#define UI_MAGNIFIER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Magnifier
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QSpinBox *spinBox;
    QSlider *horizontalSlider;

    void setupUi(QDialog *Magnifier)
    {
        if (Magnifier->objectName().isEmpty())
            Magnifier->setObjectName(QString::fromUtf8("Magnifier"));
        Magnifier->resize(333, 168);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/img/zoom-in.png"), QSize(), QIcon::Normal, QIcon::Off);
        Magnifier->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(Magnifier);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 120, 301, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(Magnifier);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 221, 91));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        spinBox = new QSpinBox(layoutWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(10);
        spinBox->setMaximum(200);
        spinBox->setValue(10);

        verticalLayout_2->addWidget(spinBox);

        horizontalSlider = new QSlider(layoutWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMinimum(10);
        horizontalSlider->setMaximum(200);
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider);


        retranslateUi(Magnifier);
        QObject::connect(buttonBox, SIGNAL(accepted()), Magnifier, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Magnifier, SLOT(reject()));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(Magnifier);
    } // setupUi

    void retranslateUi(QDialog *Magnifier)
    {
        Magnifier->setWindowTitle(QCoreApplication::translate("Magnifier", "Magnifier", nullptr));
        label->setText(QCoreApplication::translate("Magnifier", "Zoom (in %)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Magnifier: public Ui_Magnifier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAGNIFIER_H
