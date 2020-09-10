#include "mainwindow.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);   //The QApplication class manages the
                                    //GUI application's control flow and main settings.

    MainWindow window;
    window.show();                  //Shows the widget and its child widgets.


    return app.exec();              //Enters the main event loop and waits until quit() is called.
}
