/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout_InQ;
    QAction *actionChange_Resolution;
    QAction *actionBrush_Color;
    QAction *actionExit;
    QAction *actionSave;
    QAction *actionMagnifier;
    QAction *actionEraser;
    QAction *actionBrush_Thickness;
    QAction *actionCircle;
    QAction *actionRectangle;
    QAction *actionTriangle;
    QAction *actionFloodfill_Selected_Shape;
    QAction *actionFloodfill_Color;
    QAction *actionOpen_File;
    QAction *actionNew_File;
    QAction *actionStraight_Line;
    QAction *actionPentagon;
    QAction *actionHexagon;
    QAction *actionFour_Point_Star;
    QAction *actionArrow;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuCredits;
    QMenu *menuCustomize;
    QMenu *menuExit;
    QMenu *menuTools;
    QMenu *menuShapes;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(906, 600);
        MainWindow->setTabletTracking(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/img/inqlogo.webp"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionAbout_InQ = new QAction(MainWindow);
        actionAbout_InQ->setObjectName(QString::fromUtf8("actionAbout_InQ"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/img/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout_InQ->setIcon(icon1);
        actionChange_Resolution = new QAction(MainWindow);
        actionChange_Resolution->setObjectName(QString::fromUtf8("actionChange_Resolution"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/img/resolution.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionChange_Resolution->setIcon(icon2);
        actionBrush_Color = new QAction(MainWindow);
        actionBrush_Color->setObjectName(QString::fromUtf8("actionBrush_Color"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/img/colorpalette4.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBrush_Color->setIcon(icon3);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/img/exiticon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon4);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/img/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon5);
        actionMagnifier = new QAction(MainWindow);
        actionMagnifier->setObjectName(QString::fromUtf8("actionMagnifier"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/img/img/zoom-in.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMagnifier->setIcon(icon6);
        actionEraser = new QAction(MainWindow);
        actionEraser->setObjectName(QString::fromUtf8("actionEraser"));
        actionEraser->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/img/img/eraser.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEraser->setIcon(icon7);
        actionBrush_Thickness = new QAction(MainWindow);
        actionBrush_Thickness->setObjectName(QString::fromUtf8("actionBrush_Thickness"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/img/img/brushthickness.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBrush_Thickness->setIcon(icon8);
        actionCircle = new QAction(MainWindow);
        actionCircle->setObjectName(QString::fromUtf8("actionCircle"));
        actionCircle->setCheckable(true);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/img/img/circle.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCircle->setIcon(icon9);
        actionRectangle = new QAction(MainWindow);
        actionRectangle->setObjectName(QString::fromUtf8("actionRectangle"));
        actionRectangle->setCheckable(true);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/img/img/rectangle.webp"), QSize(), QIcon::Normal, QIcon::Off);
        actionRectangle->setIcon(icon10);
        actionTriangle = new QAction(MainWindow);
        actionTriangle->setObjectName(QString::fromUtf8("actionTriangle"));
        actionTriangle->setCheckable(true);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/img/img/triangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTriangle->setIcon(icon11);
        actionFloodfill_Selected_Shape = new QAction(MainWindow);
        actionFloodfill_Selected_Shape->setObjectName(QString::fromUtf8("actionFloodfill_Selected_Shape"));
        actionFloodfill_Selected_Shape->setCheckable(true);
        actionFloodfill_Color = new QAction(MainWindow);
        actionFloodfill_Color->setObjectName(QString::fromUtf8("actionFloodfill_Color"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/img/img/floodfillicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFloodfill_Color->setIcon(icon12);
        actionOpen_File = new QAction(MainWindow);
        actionOpen_File->setObjectName(QString::fromUtf8("actionOpen_File"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/img/img/openfile.webp"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen_File->setIcon(icon13);
        actionNew_File = new QAction(MainWindow);
        actionNew_File->setObjectName(QString::fromUtf8("actionNew_File"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/img/img/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew_File->setIcon(icon14);
        actionStraight_Line = new QAction(MainWindow);
        actionStraight_Line->setObjectName(QString::fromUtf8("actionStraight_Line"));
        actionStraight_Line->setCheckable(true);
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/img/img/straightline.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStraight_Line->setIcon(icon15);
        actionPentagon = new QAction(MainWindow);
        actionPentagon->setObjectName(QString::fromUtf8("actionPentagon"));
        actionPentagon->setCheckable(true);
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/img/img/pentagon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPentagon->setIcon(icon16);
        actionHexagon = new QAction(MainWindow);
        actionHexagon->setObjectName(QString::fromUtf8("actionHexagon"));
        actionHexagon->setCheckable(true);
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/img/img/hexagon.webp"), QSize(), QIcon::Normal, QIcon::Off);
        actionHexagon->setIcon(icon17);
        actionFour_Point_Star = new QAction(MainWindow);
        actionFour_Point_Star->setObjectName(QString::fromUtf8("actionFour_Point_Star"));
        actionFour_Point_Star->setCheckable(true);
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/img/img/fourpointstar2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFour_Point_Star->setIcon(icon18);
        actionArrow = new QAction(MainWindow);
        actionArrow->setObjectName(QString::fromUtf8("actionArrow"));
        actionArrow->setCheckable(true);
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/img/img/arrow (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        actionArrow->setIcon(icon19);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 906, 26));
        menuCredits = new QMenu(menubar);
        menuCredits->setObjectName(QString::fromUtf8("menuCredits"));
        menuCustomize = new QMenu(menubar);
        menuCustomize->setObjectName(QString::fromUtf8("menuCustomize"));
        menuExit = new QMenu(menubar);
        menuExit->setObjectName(QString::fromUtf8("menuExit"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuShapes = new QMenu(menubar);
        menuShapes->setObjectName(QString::fromUtf8("menuShapes"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuExit->menuAction());
        menubar->addAction(menuCustomize->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuShapes->menuAction());
        menubar->addAction(menuCredits->menuAction());
        menuCredits->addAction(actionAbout_InQ);
        menuCustomize->addAction(actionChange_Resolution);
        menuCustomize->addAction(actionBrush_Color);
        menuCustomize->addAction(actionBrush_Thickness);
        menuExit->addAction(actionExit);
        menuExit->addAction(actionSave);
        menuExit->addAction(actionOpen_File);
        menuExit->addAction(actionNew_File);
        menuTools->addAction(actionMagnifier);
        menuTools->addAction(actionEraser);
        menuShapes->addAction(actionStraight_Line);
        menuShapes->addAction(actionCircle);
        menuShapes->addAction(actionRectangle);
        menuShapes->addAction(actionTriangle);
        menuShapes->addAction(actionPentagon);
        menuShapes->addAction(actionHexagon);
        menuShapes->addAction(actionFour_Point_Star);
        menuShapes->addAction(actionArrow);
        menuShapes->addSeparator();
        menuShapes->addAction(actionFloodfill_Color);
        toolBar->addAction(actionExit);
        toolBar->addAction(actionNew_File);
        toolBar->addAction(actionOpen_File);
        toolBar->addAction(actionSave);
        toolBar->addAction(actionChange_Resolution);
        toolBar->addSeparator();
        toolBar->addAction(actionBrush_Color);
        toolBar->addAction(actionBrush_Thickness);
        toolBar->addAction(actionFloodfill_Color);
        toolBar->addAction(actionEraser);
        toolBar->addSeparator();
        toolBar->addAction(actionStraight_Line);
        toolBar->addAction(actionCircle);
        toolBar->addAction(actionTriangle);
        toolBar->addAction(actionRectangle);
        toolBar->addAction(actionPentagon);
        toolBar->addAction(actionHexagon);
        toolBar->addAction(actionFour_Point_Star);
        toolBar->addAction(actionArrow);
        toolBar->addSeparator();
        toolBar->addAction(actionMagnifier);
        toolBar->addSeparator();
        toolBar->addAction(actionFloodfill_Selected_Shape);
        toolBar->addSeparator();
        toolBar->addAction(actionAbout_InQ);
        toolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "InQ: A Sketchbook Application", nullptr));
        actionAbout_InQ->setText(QCoreApplication::translate("MainWindow", "About InQ", nullptr));
        actionChange_Resolution->setText(QCoreApplication::translate("MainWindow", "Change Resolution", nullptr));
        actionBrush_Color->setText(QCoreApplication::translate("MainWindow", "Brush Color", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionMagnifier->setText(QCoreApplication::translate("MainWindow", "Magnifier", nullptr));
        actionEraser->setText(QCoreApplication::translate("MainWindow", "Eraser", nullptr));
        actionBrush_Thickness->setText(QCoreApplication::translate("MainWindow", "Brush Thickness", nullptr));
        actionCircle->setText(QCoreApplication::translate("MainWindow", "Circle", nullptr));
        actionRectangle->setText(QCoreApplication::translate("MainWindow", "Rectangle", nullptr));
        actionTriangle->setText(QCoreApplication::translate("MainWindow", "Triangle", nullptr));
        actionFloodfill_Selected_Shape->setText(QCoreApplication::translate("MainWindow", "Fill Shape", nullptr));
        actionFloodfill_Color->setText(QCoreApplication::translate("MainWindow", "Floodfill Color", nullptr));
        actionOpen_File->setText(QCoreApplication::translate("MainWindow", "Open File", nullptr));
        actionNew_File->setText(QCoreApplication::translate("MainWindow", "New File", nullptr));
        actionStraight_Line->setText(QCoreApplication::translate("MainWindow", "Straight Line", nullptr));
        actionPentagon->setText(QCoreApplication::translate("MainWindow", "Pentagon", nullptr));
        actionHexagon->setText(QCoreApplication::translate("MainWindow", "Hexagon", nullptr));
        actionFour_Point_Star->setText(QCoreApplication::translate("MainWindow", "Four Point Star", nullptr));
        actionArrow->setText(QCoreApplication::translate("MainWindow", "Arrow", nullptr));
        menuCredits->setTitle(QCoreApplication::translate("MainWindow", "Credits", nullptr));
        menuCustomize->setTitle(QCoreApplication::translate("MainWindow", "Customize", nullptr));
        menuExit->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
        menuShapes->setTitle(QCoreApplication::translate("MainWindow", "Shapes", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
