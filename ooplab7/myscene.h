#ifndef MYSCENE_H
#define MYSCENE_H


#include "QGraphicsScene"
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include <QGraphicsView>
#include "moveitem.h"
#include "player.h"

class MyScene : public QGraphicsScene
{
public:
    MyScene(QObject* parent=0);
    MoveItem* buffItem;
    const int WIDTH=580;
    const int HEIGHT=575;
    const int OFFSET_X=59;
    const int OFFSET_Y=57;
    QPointF buffPos;
    Player* playerWhite;
    Player* playerBlack;
    MoveItem* checkCollidingWhite();
    MoveItem* checkCollidingBlack();
    bool whiteTurn;
private:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // MYSCENE_H
