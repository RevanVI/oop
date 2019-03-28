#include "myscene.h"
#include <iostream>
using namespace  std;

MyScene::MyScene(QObject* parent):QGraphicsScene (parent)
{
    whiteTurn=true;
    playerWhite=new Player(true);
    playerBlack=new Player(false);
}

bool clicked=false;

MoveItem* MyScene::checkCollidingWhite()
{
    for(int i=0;i<playerWhite->figures.count();i++)
    {
        if(playerWhite->figures[i] != buffItem && playerWhite->figures[i]->position == buffItem->position)
            return playerWhite->figures[i];
    }
    return 0x00;
}

MoveItem* MyScene::checkCollidingBlack()
{
    for(int i=0;i<playerBlack->figures.count();i++)
    {
        if(playerBlack->figures[i]!=buffItem && playerBlack->figures[i]->position==buffItem->position)
            return playerBlack->figures[i];
    }
    return 0x00;
}

void MyScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    if(clicked && itemAt(event->scenePos(),QTransform()))
    {

        buffItem->setPos(event->scenePos());
    }

}

void MyScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //если нажали на фигуру
    if(itemAt(event->scenePos(),QTransform())){
        buffItem = dynamic_cast<MoveItem*>(itemAt(event->scenePos(),QTransform())); //преобразование к MoveItem
        if(buffItem->isWhite == whiteTurn)
        {
            buffItem->countPosition(OFFSET_X,OFFSET_Y,HEIGHT);
            buffPos = buffItem->position;
            //cout<<"buffpos "<<buffPos.x()<<" "<<buffPos.y()<<endl;
            clicked=true;
            sendEvent(buffItem,event);
        }
    }

}

void MyScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(buffItem->isWhite == whiteTurn)
    {
        clicked=false;

        buffItem->countPosition(OFFSET_X,OFFSET_Y,HEIGHT);
        if(itemAt(event->scenePos(),QTransform()))
            sendEvent(buffItem,event);
        //фигура моменяла положение
        if(buffItem->position == buffPos)
        {
            buffItem->fixCoords(OFFSET_X,OFFSET_Y,HEIGHT);
            return;
        }

        //ход выполнен правильно относительно фигуры
        if(!buffItem->moveIsValid(buffPos))
        {
            buffItem->position=buffPos;
            buffItem->fixCoords(OFFSET_X,OFFSET_Y,HEIGHT);
            return;
        }

        //поиск совпадающей по позиции фигуры
        MoveItem* whiteCallid=checkCollidingWhite();
        if(whiteCallid)
        {
            if(buffItem->isWhite==true)//white
            {
               //если белой фигурой наступаем на белую
               buffItem->position=buffPos;
               buffItem->fixCoords(OFFSET_X,OFFSET_Y,HEIGHT);
               return;
            }else{//black
                //если черной фигурой наступаем на белую
                playerWhite->figures.removeOne(whiteCallid);
                removeItem(whiteCallid);
            }
        }else{
            MoveItem* blackCallid=checkCollidingBlack();
            if(blackCallid)
            {
                if(buffItem->isWhite==false)//black
                {
                   //если черной фигурой наступаем на черной
                   buffItem->position=buffPos;
                   buffItem->fixCoords(OFFSET_X,OFFSET_Y,HEIGHT);
                   return;
                }else{//white
                    //если черной фигурой наступаем на белую
                    playerWhite->figures.removeOne(whiteCallid);
                    removeItem(blackCallid);
                }
            }
        }

        buffItem->fixCoords(OFFSET_X,OFFSET_Y,HEIGHT);
        whiteTurn = !whiteTurn;
        update();
    }
}
