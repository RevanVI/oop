#ifndef MOVEITEM_H
#define MOVEITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>


enum FigureType{
    bishop,knight,rook,abstract
};

class MoveItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit MoveItem(FigureType typeV=abstract,bool isWhiteV=true,QObject *parent = 0);
    ~MoveItem();

    QPointF position;
    QPointF countPosition(int,int,int);
    void fixCoords(int,int,int);

    //int posX;
    //int posY;
    //int countPosX(int);
    //int countPosY(int,int);
    //void fixX(int);
    //void fixY(int,int);

    FigureType type;
    QString fileUrl;
    bool isWhite;
    const int FIGURE_HEIGHT=66;
    const int FIGURE_WIDTH=66;
    bool moveIsValid(QPointF prev);

private:

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

public slots:
};

#endif // MOVEITEM_H
