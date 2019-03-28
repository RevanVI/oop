#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include "myscene.h"
#include <moveitem.h>




namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void giveRandomPositions();
    void startGame();
private slots:
    void on_pushButton_clicked();

private:
    QList<QPointF> takenPos;
    Ui::Widget *ui;
    MyScene *scene;

};

#endif // WIDGET_H
