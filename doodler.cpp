#include "doodler.h"
#include "doodleview.h"

extern DoodleView* view;

Doodler::Doodler(QGraphicsItem* parent): QGraphicsPixmapItem(parent)
{
    setFlag(QGraphicsItem::ItemIsFocusable);

    setDoodler(5);
    setPixmap(QPixmap(image));

    //X = 200;
    //Y = 300;

    //setPos(X,Y);
}

void Doodler::setDoodler(int a)
{
    switch(a)
    {
    case 0:
        image  = (":/Images/doodle_classic.png");
        image2 = (":/Images/doodle_classic2.png");
        break;
    case 1:
        image  = (":/Images/doodle_ninja.png");
        image2 = (":/Images/doodle_ninja2.png");
        break;
    case 2:
        image  = (":/Images/doodle_ghost.png");
        image2 = (":/Images/doodle_ghost2.png");
        break;
    case 3:
        image  = (":/Images/doodle_woman.png");
        image2 = (":/Images/doodle_woman2.png");
        break;
    case 4:
        image  = (":/Images/doodle_jungle.png");
        image2 = (":/Images/doodle_jungle2.png");
        break;
    case 5:
        image  = (":/Images/doodle_cosmonaut.png");
        image2 = (":/Images/doodle_cosmonaut2.png");
        break;
    default:
        break;
    }
}




