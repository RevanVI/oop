#ifndef TINTERFACE_H
#define TINTERFACE_H

#include <QtWidgets/QWidget>
#include <QDoubleValidator>
#include "polynom.h"
#include "QtDebug"

namespace Ui {
class Widget;
}

class Tinterface : public QWidget
{
    Q_OBJECT

public:
    Tinterface(QWidget *parent = nullptr);
    ~Tinterface();
    number* getData();
    void setData(number * val);
private:
    Ui::Widget *ui;
    QDoubleValidator* valid;
public slots:
    void on_solveButton_clicked();
signals:
    void buttonClicked();
};

#endif // TINTERFACE_H
