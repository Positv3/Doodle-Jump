#include "doodleview.h"
#include "engine.h"

int DoodleView::widthSize  = 700;
int DoodleView::heightSize = 900;

DoodleView::DoodleView(): QGraphicsView(), scene(new Engine(this))
{
    setWindowTitle("Doodle Jump");
    setWindowIcon(QIcon(":/Images/doodle_icon.png"));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(widthSize,heightSize);

    setScene(scene);
    //init_game();
}

void DoodleView::displayMenu()
{

}


