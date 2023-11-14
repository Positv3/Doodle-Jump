#include "platform.h"
#include <QPainter>
#include <QTimer>
#include <ctime>
#include <QGraphicsProxyWidget>

Platform::Platform(QString plt, QGraphicsItem* parent): QObject(),QGraphicsPixmapItem(parent)
{    
    setPixmap(QPixmap(plt));

    //setPos(pos.x,pos.y);
}

Platform::Platform(QString plt, int x, int y)
{
    setPixmap(QPixmap(plt));
    setPos(x,y);
}

Point Platform::getPosition()
{
    return position;
}

QString Platform::image(QString img)
{
    return img = ":/Images/platform.png";
}

void Platform::createPlat(int width,int height)
{
    //srand(time(NULL));

    for(int i = 0; i < 20; ++i)
    {
        xPos = rand() % width;
        yPos = rand() % height;

        position = {xPos,yPos};

        plats.append(&position);
    }
}

void Platform::upperPlat(int width, int i)
{
    //QGraphicsPixmapItem* platform_item = new QGraphicsPixmapItem(plat.scaled(width/2, height/2));
    platform[i].x = rand() % width;
    platform[i].y = platform[i].y - 0.2f;
}



