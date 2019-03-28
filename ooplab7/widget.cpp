#include "widget.h"
#include "ui_widget.h"
#include <iostream>

using namespace std;

/* Функция для получения рандомного числа
 * в диапазоне от минимального до максимального
 * */
static int randomBetween(int low, int high)
{
    return (qrand() % ((high + 1) - low) + low);
}

QPointF getRand()
{
    return QPointF(qrand()%8,qrand()%8);
}

void Widget::giveRandomPositions()
{
    for(int i=0;i<scene->playerWhite->figures.count();i++)
    {
        bool replicate;
        QPointF currPos = getRand();
        cout<<i<<": "<<currPos.x()<<" "<<currPos.y()<<" "<<takenPos.count()<<endl;
        do{
            if(takenPos.count()==0) break;
            for(int j=0;j<takenPos.count();j++)
            {
                if(currPos==takenPos[j])
                {
                    replicate=true;
                    currPos = getRand();
                    break;
                }
                replicate=false;
            }
        }while(replicate);

        scene->playerWhite->figures[i]->position=currPos;
        scene->playerWhite->figures[i]->fixCoords(scene->OFFSET_X,scene->OFFSET_Y,scene->HEIGHT);

        takenPos.append(currPos);
        //player1->figures[i]->setPos(currPos);
        scene->addItem(scene->playerWhite->figures[i]);
    }
    for(int i=0;i<scene->playerBlack->figures.count();i++)
    {
        bool replicate;
        QPointF currPos = getRand();

        do{
            if(takenPos.count()==0) break;
            for(int j=0;j<takenPos.count();j++)
            {
                if(currPos==takenPos[j])
                {
                    cout<<"taken "<<takenPos[j].x()<<" "<<takenPos[j].y()<<endl;
                    cout<<"curr "<<currPos.x()<<" "<<currPos.y()<<endl;
                    replicate=true;
                    currPos = getRand();
                    break;
                }
                replicate=false;
            }
        }while(replicate);
        cout<<i<<": "<<currPos.x()<<" "<<currPos.y()<<endl;
        scene->playerBlack->figures[i]->position=currPos;
        scene->playerBlack->figures[i]->fixCoords(scene->OFFSET_X,scene->OFFSET_Y,scene->HEIGHT);

        takenPos.append(currPos);
        //player1->figures[i]->setPos(currPos);
        scene->addItem(scene->playerBlack->figures[i]);
    }
}

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    scene = new MyScene(this);

    this->resize(640,640);
    this->setFixedSize(640,640);

    scene = new MyScene(this);
    scene->setSceneRect(0,0,scene->WIDTH,scene->HEIGHT);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/images/chessBack.png")));


    giveRandomPositions();
    scene->buffItem=new MoveItem(abstract);


    ui->graphicsView->setFixedSize(scene->WIDTH,scene->HEIGHT);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    // Настраиваем рендер
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground); // Кэш фона
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    scene->clear();
    delete scene->playerBlack;
    delete scene->playerWhite;
    scene->playerWhite=new Player(true);
    scene->playerBlack=new Player(false);
    giveRandomPositions();
    scene->whiteTurn=true;
}
