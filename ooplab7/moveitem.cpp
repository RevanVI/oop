#include "moveitem.h"
#include <iostream>

using namespace  std;

MoveItem::MoveItem( FigureType typeV,bool isWhiteV,QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    isWhite=isWhiteV;
    type=typeV;
    switch (type) {
    case bishop:
        if(isWhite)
            fileUrl=":/images/slonWhite.png";
        else
            fileUrl=":/images/slonBlack.png";
        break;
    case knight:
        if(isWhite)
            fileUrl=":/images/konWhite.png";
        else
            fileUrl=":/images/konBlack.png";
        break;
    case rook:
        if(isWhite)
            fileUrl=":/images/ladyaWhite.png";
        else
            fileUrl=":/images/ladyaBlackpng.png";
        break;
    default:
        break;
    }
}

MoveItem::~MoveItem()
{

}

bool MoveItem::moveIsValid(QPointF prev)
{
    switch (type) {
    case bishop:
        if(position.x() == prev.x() || position.y() == prev.y()) return true;
        return false;
    case knight:
        if((abs(position.x()-prev.x()) == 1 && abs(position.y()-prev.y()) == 2)||
                (abs(position.x()-prev.x()) == 2 && abs(position.y()-prev.y()) == 1)) return true;
        return false;
    case rook:
        if(abs(position.x()-prev.x()) == abs(position.y()-prev.y())) return true;
        return false;
    default:
        break;
    }
}

QRectF MoveItem::boundingRect() const
{
    return QRectF (-FIGURE_WIDTH/2,-FIGURE_HEIGHT/2,FIGURE_WIDTH,FIGURE_HEIGHT);
}

QPointF MoveItem::countPosition(int offsetX, int offsetY, int height)
{
    int cx = (x()+FIGURE_WIDTH/2 - offsetX)/FIGURE_WIDTH;
    cx = cx<0 ? 0 : cx;
    cx = cx>7 ? 7 : cx;
    position.setX(cx);

    int cy=(height - y() + FIGURE_HEIGHT/2 - offsetY)/FIGURE_HEIGHT;
    cy = cy<0 ? 0 : cy;
    cy = cy>7 ? 7 : cy;
    position.setY(cy);

    cout<<position.x()<<" "<<position.y()<<endl;
    return position;
}

void MoveItem::fixCoords(int offsetX, int offsetY, int height)
{
    setX(offsetX+position.x()*FIGURE_WIDTH);
    setY(height-(offsetY+position.y()*FIGURE_HEIGHT));
}

/*int MoveItem::countPosX(int offset)
{
    posX=(x()+FIGURE_WIDTH/2-offset)/FIGURE_WIDTH;
    posX = posX<0 ? 0 : posX;
    posX = posX>7 ? 7 : posX;
    return posX;
}

int MoveItem::countPosY(int offset,int height)
{
    posY=(height-y()+FIGURE_HEIGHT/2-offset)/FIGURE_HEIGHT;
    posY = posY<0 ? 0 : posY;
    posY = posY>7 ? 7 : posY;
    return posY;
}




void MoveItem::fixX(int offset)
{

    setX(offset+posX*FIGURE_WIDTH);
}

void MoveItem::fixY(int offset,int height)
{

    setY(height-(offset+posY*FIGURE_HEIGHT));
}*/



void MoveItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->drawRect(-FIGURE_WIDTH/2,-FIGURE_HEIGHT/2,FIGURE_WIDTH,FIGURE_HEIGHT);
    painter->drawImage(-FIGURE_WIDTH/2,-FIGURE_HEIGHT/2,QImage(fileUrl));
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void MoveItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void MoveItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}
