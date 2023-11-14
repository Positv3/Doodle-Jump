#include "title.h"
#include "engine.h"

extern Engine* view;

int Score::points = 0;
int Score::points2 = 0;

Score::Score()
{
    scoreText = QString::number(points);

    font = (QFont("avenir",15));

    color = (QColor(135,135,248));

    score = new QLabel();
    score->setText(scoreText);
    score->setFont(font);
    score->setStyleSheet(QString("color: %1").arg(color.name()));
    score->setAttribute(Qt::WA_TranslucentBackground);

    setWidget(score);
    setPos(350,10);
}

Score::Score(int x, int y)
{
    scoreText = QString::number(points2);

    font  = (QFont("avenir",15));

    color = (QColor(135,135,248));

    score = new QLabel();
    score->setText(scoreText);
    score->setFont(font);
    score->setStyleSheet(QString("color: %1").arg(color.name()));
    score->setAttribute(Qt::WA_TranslucentBackground);

    setWidget(score);
    setPos(x,y);//350,40
}

void Score::updateScore(int pts, bool option)
{
    if(option)

        if(points < pts) points = pts;

    else
         points2 = pts;

}

void Score::changeColor()
{
    color = QColor(255,111,111);
    score->setStyleSheet(QString("color: %1").arg(color.name()));
    setWidget(score);
}

void Score::setDefaultColor()
{
    color = QColor(135,135,248);
    score->setStyleSheet(QString("color: %1").arg(color.name()));
    setWidget(score);
}

QGraphicsTextItem *Score::createTextItem(QString text, int fontSize, QColor textColor, QGraphicsItem *parent)
{
    QGraphicsTextItem* textItem = new QGraphicsTextItem(text,parent);
    QFont titleFont("avenir", fontSize);

    textItem->setDefaultTextColor(textColor);
    textItem->setFont(titleFont);

    return textItem;
}

