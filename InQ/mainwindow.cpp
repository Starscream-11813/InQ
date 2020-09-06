#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "canvas.h"
#include <QColorDialog>
#include <QScrollArea>


// Opens a Dialog box. (When Exit, New File, Open File buttons are clicked.)

int MainWindow::openDialog()
{
    QMessageBox dialog(QMessageBox::Question, tr("InQ"), tr("Do you want to save changes?"), QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, this);
    dialog.setButtonText(QMessageBox::Yes, tr("Yes"));
    dialog.setButtonText(QMessageBox::No, tr("No"));
    dialog.setButtonText(QMessageBox::Cancel, tr("Cancel"));
    dialog.setDefaultButton(QMessageBox::Yes);

    return dialog.exec();
}


// Setting all the ui checked to false. (For modularity and management.)

void MainWindow::setUiAllSetCheckedFalse()
{
    ui->actionRectangle->setChecked(false);
    ui->actionCircle->setChecked(false);
    ui->actionPentagon->setChecked(false);
    ui->actionTriangle->setChecked(false);
    ui->actionHexagon->setChecked(false);
    ui->actionFour_Point_Star->setChecked(false);
    ui->actionArrow->setChecked(false);
    ui->actionStraight_Line->setChecked(false);
    ui->actionFloodfill_Selected_Shape->setChecked(false);
}


// Setting all the canvas checked to false. (For modularity and management.)

void MainWindow::setCanvasAllsetCheckedFalse()
{
    canvas->setIsRectangle(false);
    canvas->setIsCircle(false);
    canvas->setIsTriangle(false);
    canvas->setIsPentagon(false);
    canvas->setIsHexagon(false);
    canvas->setIsFourPointStar(false);
    canvas->setIsLine(false);
    canvas->setIsArrow(false);
    canvas->setIsStraightLine(false);
    canvas->setIsFilling(false);
}


// MainWindow constructor

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow),canvas(new Canvas(this))
{
    ui->setupUi(this);                  //Sets up the user interface for the specified widget.
    //QMainWindow::showFullScreen();
    setCentralWidget(canvas);           //Setting the canvas pointer as the Central Widget of the MainWindow.
    //canvas->resize(500,500);
}


// MainWindow Destructor.

MainWindow::~MainWindow()
{
    delete ui;
    delete canvas;
}


// When Exit button is clicked.

void MainWindow::on_actionExit_triggered()
{
    int dialog = openDialog();
    if(dialog == QMessageBox::Yes)
    {
       on_actionSave_triggered();
       QApplication::quit();
    }
    else if(dialog == QMessageBox::No)
    {
        QApplication::quit();
    }
    else if(dialog == QMessageBox::Cancel)
    {
        return;
    }
}


// When Save button is clicked.

void MainWindow::on_actionSave_triggered()
{
    QImage saveDrawing=canvas->getImage();


    //getSaveFileName(QWidget *parent,QString Caption, QString Default_Directory,QString FileFormats(*.extension))

    QString filePath=QFileDialog::getSaveFileName(this,"Save Sketch","C:/Users/Raiyan/Desktop/untitled.png","PNG (*.png);;JPEG (*.jpg *.jpeg);;BMP (*.bmp)");


    saveDrawing.save(filePath);
}


// When Open File button is clicked.

void MainWindow::on_actionOpen_File_triggered()
{
    int dialog=openDialog();
    if(dialog==QMessageBox::Yes)
    {
        on_actionSave_triggered();
        canvas->openImage();
    }
    else if(dialog==QMessageBox::No)
    {
        canvas->openImage();
    }
    else if(dialog==QMessageBox::Cancel)
    {
        return;
    }
}


// When New file button is clicked.

void MainWindow::on_actionNew_File_triggered()
{
    int dialog=openDialog();
    if(dialog==QMessageBox::Yes)
    {
        on_actionSave_triggered();
        canvas->init();
        update();                   //It schedules a paint event for processing when Qt returns to the main event loop.
    }
    else if(dialog==QMessageBox::No)
    {
        canvas->init();
        update();
    }
    else if(dialog==QMessageBox::Cancel)
    {
        return;
    }
}


// When Change Resolution button is clicked.

void MainWindow::on_actionChange_Resolution_triggered()
{
    CanvasDimension dim;
    dim.setWidth(canvas->getImage().width());
    dim.setHeight(canvas->getImage().height());
    if(dim.exec() == QDialog::Accepted)
    {
        int nWidth = dim.getWidth();
        int nHeight = dim.getHeight();

        canvas->resize(nWidth, nHeight);
    }
}


// When Brush Color button is clicked.

void MainWindow::on_actionBrush_Color_triggered()
{
    //Pops up a modal color dialog and lets the user choose a color, and returns that color.
    QColor customColor = QColorDialog::getColor(Qt::black, this, QString("Pick a color"), QColorDialog::ShowAlphaChannel);
    //Allow the user to select the alpha component of a color.

    canvas->setColor(customColor);
}


// When Brush Thickness button is clicked.

void MainWindow::on_actionBrush_Thickness_triggered()
{
    bool thicknessChanged=false;

    //Static convenience function to get an integer input from the user.
    int size=QInputDialog::getInt(this,"Set Brush Thickness","Thickness",1,1,70,1,&thicknessChanged);

    if(thicknessChanged)
    {
        canvas->setBrushWidth(size);
    }
}


// When Magnifier button is clicked.

void MainWindow::on_actionMagnifier_triggered()
{
    Magnifier magnifierDialog;
    if(magnifierDialog.exec()==QDialog::Accepted)
    {
        int zoom=magnifierDialog.getZoom();
        int newWidth=(canvas->getImage().width()*zoom)/100;
        int newHeight=(canvas->getImage().height()*zoom)/100;
        QImage magnifiedImage=canvas->getImage();
        canvas->clear();
        canvas->resize(newWidth,newHeight);

        //IgnoreAspectRatio- The size is scaled freely. The aspect ratio is not preserved.
        //SmoothTransformation- The resulting image is transformed using bilinear filtering.
        canvas->setImage(magnifiedImage.scaled(newWidth,newHeight,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    }
}


// When Eraser button is toggled.

void MainWindow::on_actionEraser_triggered()
{
    if(ui->actionEraser->isChecked())
    {
        canvas->setPrevColor(canvas->getColor());
        canvas->setColor(Qt::white);

        setCanvasAllsetCheckedFalse();
        canvas->setIsLine(true);

        setUiAllSetCheckedFalse();
    }
    else
    {
        canvas->setColor(canvas->getPrevColor());
    }
}


// When Straight line button is toggled.

void MainWindow::on_actionStraight_Line_triggered()
{
    if(ui->actionStraight_Line->isChecked())
    {
        setUiAllSetCheckedFalse();
        ui->actionStraight_Line->setChecked(true);

        setCanvasAllsetCheckedFalse();
        canvas->setIsStraightLine(true);
    }
    else
    {
        setCanvasAllsetCheckedFalse();
        canvas->setIsLine(true);
    }
}


// When Circle button is toggled

void MainWindow::on_actionCircle_triggered()
{
    if(ui->actionCircle->isChecked())
    {
        setUiAllSetCheckedFalse();
        ui->actionCircle->setChecked(true);

        setCanvasAllsetCheckedFalse();
        canvas->setIsCircle(true);
    }
    else
    {
        setCanvasAllsetCheckedFalse();
        canvas->setIsLine(true);
    }
}


// When Triangle button is toggled

void MainWindow::on_actionTriangle_triggered()
{
    if(ui->actionTriangle->isChecked())
    {
        setUiAllSetCheckedFalse();
        ui->actionTriangle->setChecked(true);

        setCanvasAllsetCheckedFalse();
        canvas->setIsTriangle(true);
    }
    else
    {
        setCanvasAllsetCheckedFalse();
        canvas->setIsLine(true);
    }
}

// When Rectangle buttton is toggled

void MainWindow::on_actionRectangle_triggered()
{
    if(ui->actionRectangle->isChecked())
    {
        setUiAllSetCheckedFalse();
        ui->actionRectangle->setChecked(true);

        setCanvasAllsetCheckedFalse();
        canvas->setIsRectangle(true);
    }
    else
    {
        setCanvasAllsetCheckedFalse();
        canvas->setIsLine(true);
    }
}


// When Pentagon button is toggled

void MainWindow::on_actionPentagon_triggered()
{
    if(ui->actionPentagon->isChecked())
    {
        setUiAllSetCheckedFalse();
        ui->actionPentagon->setChecked(true);

        setCanvasAllsetCheckedFalse();
        canvas->setIsPentagon(true);
    }
    else
    {
        setCanvasAllsetCheckedFalse();
        canvas->setIsLine(true);
    }
}


// When Hexagon button is toggled

void MainWindow::on_actionHexagon_triggered()
{
    if(ui->actionHexagon->isChecked())
    {
        setUiAllSetCheckedFalse();
        ui->actionHexagon->setChecked(true);

        setCanvasAllsetCheckedFalse();
        canvas->setIsHexagon(true);
    }
    else
    {
        setCanvasAllsetCheckedFalse();
        canvas->setIsLine(true);
    }
}


// When Four Point Star button is toggled

void MainWindow::on_actionFour_Point_Star_triggered()
{
    if(ui->actionFour_Point_Star->isChecked())
    {
        setUiAllSetCheckedFalse();
        ui->actionFour_Point_Star->setChecked(true);

        setCanvasAllsetCheckedFalse();
        canvas->setIsFourPointStar(true);
    }
    else
    {
        setCanvasAllsetCheckedFalse();
        canvas->setIsLine(true);
    }
}


// When Arrow button is toggled

void MainWindow::on_actionArrow_triggered()
{
    if(ui->actionArrow->isChecked())
    {
        setUiAllSetCheckedFalse();
        ui->actionArrow->setChecked(true);

        setCanvasAllsetCheckedFalse();
        canvas->setIsArrow(true);
    }
    else
    {
        setCanvasAllsetCheckedFalse();
        canvas->setIsLine(true);
    }
}


// When Floodfill Color button is clicked.

void MainWindow::on_actionFloodfill_Color_triggered()
{
    QColor customColor = QColorDialog::getColor(Qt::white, this, QString("Pick a fill color"), QColorDialog::ShowAlphaChannel);
    canvas->setFillColor(customColor);
}


// When Floodfill Shape button is toggled.

void MainWindow::on_actionFloodfill_Selected_Shape_triggered()
{
    if(ui->actionFloodfill_Selected_Shape->isChecked())
    {
        setUiAllSetCheckedFalse();
        ui->actionFloodfill_Selected_Shape->setChecked(true);

        setCanvasAllsetCheckedFalse();
        canvas->setIsFilling(true);
    }
    else
    {
        canvas->setIsFilling(false);
    }
}


// When about button is clicked

void MainWindow::on_actionAbout_InQ_triggered()
{
    Credits creditsDialogBox;
    creditsDialogBox.exec();
}
