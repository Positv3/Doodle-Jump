#ifndef DOODLEVIEW_H
#define DOODLEVIEW_H

#include "doodler.h"
#include "platform.h"
#include "title.h"
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsView>
#include <QIcon>

class Engine;

class DoodleView: public QGraphicsView
{
    Q_OBJECT

public:

    explicit DoodleView();

    Doodler* doodoo;

    Score* title;
    Score* title2;

    void displayMenu();

    static int widthSize;
    static int heightSize;

private:

    Engine* scene;
};


#endif // DOODLEVIEW_H
