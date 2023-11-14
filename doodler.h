#ifndef DOODLER_H
#define DOODLER_H

#include "platform.h"
#include "point.h"
#include <QObject>
#include <QApplication>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QTimer>
#include <QKeyEvent>
#include <QGraphicsScene>


class Doodler: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:

    Doodler(QGraphicsItem* parent = 0);

    void setDoodler(int a);

    float X;
    float Y;

private:

    QPixmap doo;

    QString plt;
    QString image;
    QString image2;

    QTimer* timer;
    Platform* platform;

};


#endif // DOODLER_H
