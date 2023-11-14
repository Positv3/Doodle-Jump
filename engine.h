#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QObject>
#include <QTimer>
#include <QKeyEvent>
#include "point.h"
#include "platform.h"
#include "doodler.h"
#include "doodleview.h"
#include "title.h"
#include <QFont>

class Engine: public QGraphicsScene
{
public:

    explicit Engine(QObject* parent = nullptr);

    enum class State
    {
        Active,Paused,Restart
    };

    State st;

    const float delay;
    const float jump_force;
    const float jump_speed;
    const float iteration_value;
    const int number_of_platforms;

    void restart();
    void createDoo();
    void createCounter();
    bool checkPoints();
    void createPlatforms();
    void createFirstPlatforms();

    static int points;

    bool optionForCounter;

public slots:

    void move();

protected:

    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);

private:

    QPixmap pix = QPixmap(":/Images/bg_cells.png");

    QString plt;
    QString image;
    QString image2;

    Point platforms[20];

    Doodler* doo;
    Score* counter;
    Score* counter2;
    QTimer* timer;
    DoodleView* view;
    Platform* platform;
    Platform* platform2;

    float X;
    float Y;
    float H;

    float deltaX;
    float deltaY;
    float lastIteration;

    bool left_move;
    bool right_move;
    bool facingPlats;
    bool initJump;

};


#endif // GAME_H
