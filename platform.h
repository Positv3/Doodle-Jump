#ifndef PLATFORM_H
#define PLATFORM_H

#include <QGraphicsObject>
#include <QGraphicsPixmapItem>
#include <QLabel>
#include "point.h"

class Platform:  public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:

    Platform(QString,QGraphicsItem* parent = 0);
    Platform(QString plt,int,int);
    void createPlat(int,int);
    Point getPosition();

    void setImage(QString path);
    void upperPlat(int, int);
    QString image(QString);
    QList<Point*>plats;

    int xPos;
    int yPos;

private:

    QPixmap plat;
    QLabel* imageLabel;
    Point position;
    Point platform[20];
};


#endif // PLATFORM_H
