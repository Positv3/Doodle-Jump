#include "engine.h"

int Engine::points = 0;

Engine::Engine(QObject *parent):QGraphicsScene(parent),iteration_value(1000.0f/60.0f), facingPlats(true),
    number_of_platforms(20),jump_speed(0.3f),jump_force(-13.0f),delay(0.2f),deltaX(3.0f),deltaY(0.2f),
    X(200),Y(400),H(500)
{
    srand(time(0));

    setSceneRect(0,0,view->widthSize,view->heightSize);
    setBackgroundBrush(pix);

    plt = (":/Images/platform.png");

    timer = new QTimer(this);

    connect(timer,&QTimer::timeout,this,&Engine::move);
    timer->start(iteration_value);

    for(int i = 0; i < number_of_platforms; ++i)
    {
        platforms[i].x = rand()%view->widthSize;
        platforms[i].y = rand()%view->heightSize;//rand()%view->heightSize
    }
}

void Engine::createDoo()
{
    doo = new Doodler;

    doo->setPos(X,Y);

    addItem(doo);
}

void Engine::createCounter()
{
    counter  = new Score;
    counter2 = new Score(350,40);

    counter->updateScore(points, optionForCounter);

    counter2->updateScore(points,!optionForCounter);

    if(checkPoints()) counter2->changeColor();

    addItem(counter);
    addItem(counter2);
}

bool Engine::checkPoints()
{
    return (points == 10 || points > 10) ? (true) : (false);
}

void Engine::createPlatforms()
{
    for(int i = 0; i < number_of_platforms; ++i)
    {
        platform = new Platform(plt);

        platform->setPos(platforms[i].x,platforms[i].y);

        addItem(platform);
    }
}

void Engine::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Left:
    case Qt::Key_A:
        left_move = true;
        break;

    case Qt::Key_Right:
    case Qt::Key_D:
        right_move = true;
        break;

    case Qt::Key_R:
        restart();
        break;

    case Qt::Key_Escape:
        QApplication::quit(); //QApplication::instance()->quit();
        break;
    }
}

void Engine::keyReleaseEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_Left:
        case Qt::Key_Right:
        case Qt::Key_A:
        case Qt::Key_D:
        left_move = false;
        right_move = false;
        break;
    }
}

void Engine::restart()
{
    X = 200;
    Y = 400;
    H = 500;

    st = State::Restart;

    points = 0;

    counter2->updateScore(points,!optionForCounter);

    if(Y == 400 && initJump) deltaY = jump_force;

    for(int i = 0; i < number_of_platforms; ++i)
    {
        platforms[i].x = rand()%view->widthSize;
        platforms[i].y = rand()%view->heightSize;
    }
}

void Engine::move()
{
    clear();

    lastIteration += iteration_value;
    initJump = true;

    while(lastIteration > delay)
    {
        lastIteration = -delay;

        if (left_move)
        {
            X -= deltaX;
            facingPlats = true;
        }

        if (right_move)
        {
            X += deltaX;
            facingPlats = true;
        }

        if (Y == 400 && initJump) deltaY = jump_force;

        deltaY += jump_speed;
        Y += deltaY;

        if(X > 700) X = 0;
        else if(X < 0) X = 700;

        if(Y < H)
        {
            for(int i = 0; i < number_of_platforms; ++i)
            {
                Y = H;
                platforms[i].y -= deltaY;

                if(platforms[i].y > view->heightSize)
                {                   
                    points++;
                    platforms[i].y = 0;
                    platforms[i].x = rand()%view->widthSize;
                }
            }
        }

        for (int i = 0; i < number_of_platforms; ++i) //Соприкосновение с платформами
        {
            if(facingPlats)
            {
                initJump = false;

                if ((X + 20 > platforms[i].x) && (X + 20 < (platforms[i].x + 60)) &&
                    (Y + 50 > platforms[i].y) && (Y + 50 < (platforms[i].y + 20)) &&
                    (deltaY > 0))
                {
                    deltaY = jump_force;
                }
            }
            else
            {
                initJump = false;

                if ((X - 20 > platforms[i].x) && (X - 20 < (platforms[i].x + 60)) &&
                    (Y + 50 > platforms[i].y) && (Y + 50 < (platforms[i].y + 20)) &&
                    (deltaY > 0))
                {
                    deltaY = jump_force;
                }
            }
        }

        createPlatforms();
        createCounter();
    }

       createDoo();
}
