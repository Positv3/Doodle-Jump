#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QGraphicsRectItem>
#include <QGraphicsProxyWidget>
#include <QLabel>
#include <QColor>
#include <QDir>

class Score: public QGraphicsProxyWidget
{
public:

    Score();
    Score(int,int);
    QGraphicsTextItem*createTextItem(QString text, int fontSize, QColor textColor, QGraphicsItem* parent = nullptr);

    void updateScore(int,bool);
    void changeColor();
    void setDefaultColor();

    static int points;
    static int points2;

    QLabel* score;
    QString scoreText;
    QColor  color;
    QFont   font;

private:

};


#endif // SCORE_H
