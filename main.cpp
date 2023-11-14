//#include "mainwindow.h"
#include "doodleview.h"
#include <QApplication>

DoodleView* view;

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    view = new DoodleView();

    view->show();

    return app.exec();
}
