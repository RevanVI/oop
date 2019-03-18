#ifndef TINTERFACE_H
#define TINTERFACE_H

#include <QWidget>
#include "polynom.h"
#include "QtDebug"

namespace Ui {
class Widget;
}

class Tinterface : public QWidget
{
    Q_OBJECT

public:
    explicit Tinterface(QWidget *parent = nullptr);
    ~Tinterface();

private:
    Ui::Widget *ui;
private slots:
    void handleSolveButton();
};

#endif // TINTERFACE_H
