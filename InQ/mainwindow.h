#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QMessageBox>
#include <QColorDialog>
#include <QScrollArea>
#include <QFileDialog>
#include <QInputDialog>
#include <credits.h>
#include <canvas.h>
#include <canvasdimension.h>
#include <QDebug>
#include <magnifier.h>

//All code that is not a preprocessor directive or a comment must be wrapped in QT_BEGIN_NAMESPACE and QT_END_NAMESPACE.
QT_BEGIN_NAMESPACE
namespace Ui        //Used to group the mainwindow and ui_mainwindow together.
{
class MainWindow;
}
QT_END_NAMESPACE


class Canvas;       //Declaraing the Canvas class. Canvas is the Central Widget.
class MainWindow : public QMainWindow //MainWindow class inherits the QMainWindow class.
                                      //The QMainWindow class provides a main application window.
{
    // Declares our class as a QObject which is the base class
    // for all Qt objects
    // QObjects handle events
    Q_OBJECT


public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int openDialog();


private slots:

    // File button

    void on_actionExit_triggered();
    void on_actionSave_triggered();
    void on_actionOpen_File_triggered();
    void on_actionNew_File_triggered();



    // Customize button

    void on_actionChange_Resolution_triggered();
    void on_actionBrush_Color_triggered();
    void on_actionBrush_Thickness_triggered();



    // Tools button

    void on_actionMagnifier_triggered();
    void on_actionEraser_triggered();



    // Shape button


    void on_actionStraight_Line_triggered();
    void on_actionCircle_triggered();
    void on_actionTriangle_triggered();
    void on_actionRectangle_triggered();
    void on_actionPentagon_triggered();
    void on_actionHexagon_triggered();
    void on_actionFour_Point_Star_triggered();
    void on_actionArrow_triggered();
    void on_actionFloodfill_Color_triggered();



    // Credits button

    void on_actionAbout_InQ_triggered();



    // Fill Shape button

    void on_actionFloodfill_Selected_Shape_triggered();



    // Setting all the ui checked button to false

    void setUiAllSetCheckedFalse();



    // Setting all the canvas checked button to false

    void setCanvasAllsetCheckedFalse();


private:

    Ui::MainWindow *ui; //Recursive declaration of MainWindow object pointer in the MainWidnow class
                        //from Ui namespace.

    Canvas *canvas;     //The central widget's pointer. (Aggregation)
};


#endif // MAINWINDOW_H

