/********************************************************************************
** Form generated from reading UI file 'canvasdimension.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANVASDIMENSION_H
#define UI_CANVASDIMENSION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CanvasDimension
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *height;
    QLabel *label_2;
    QLineEdit *width;

    void setupUi(QDialog *CanvasDimension)
    {
        if (CanvasDimension->objectName().isEmpty())
            CanvasDimension->setObjectName(QString::fromUtf8("CanvasDimension"));
        CanvasDimension->resize(307, 164);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/img/resolution.png"), QSize(), QIcon::Normal, QIcon::Off);
        CanvasDimension->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(CanvasDimension);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(-10, 120, 301, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget = new QWidget(CanvasDimension);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 9, 281, 101));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        height = new QLineEdit(verticalLayoutWidget);
        height->setObjectName(QString::fromUtf8("height"));

        verticalLayout->addWidget(height);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        width = new QLineEdit(verticalLayoutWidget);
        width->setObjectName(QString::fromUtf8("width"));

        verticalLayout->addWidget(width);


        retranslateUi(CanvasDimension);
        QObject::connect(buttonBox, SIGNAL(accepted()), CanvasDimension, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CanvasDimension, SLOT(reject()));

        QMetaObject::connectSlotsByName(CanvasDimension);
    } // setupUi

    void retranslateUi(QDialog *CanvasDimension)
    {
        CanvasDimension->setWindowTitle(QCoreApplication::translate("CanvasDimension", "Set Custom Resolution", nullptr));
        label->setText(QCoreApplication::translate("CanvasDimension", "Height:", nullptr));
        height->setText(QCoreApplication::translate("CanvasDimension", "1001", nullptr));
        label_2->setText(QCoreApplication::translate("CanvasDimension", "Width:", nullptr));
        width->setText(QCoreApplication::translate("CanvasDimension", "1001", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CanvasDimension: public Ui_CanvasDimension {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANVASDIMENSION_H
