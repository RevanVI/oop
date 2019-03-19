#include "tinterface.h"
#include "ui_tinterface.h"


using namespace std;

Tinterface::Tinterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    valid = new QDoubleValidator(this);
    valid->setLocale(QLocale::English);
    ui->aReEdit->setValidator(valid);
    ui->bReEdit->setValidator(valid);
    ui->cReEdit->setValidator(valid);
    ui->xReEdit->setValidator(valid);
    ui->aImEdit->setValidator(valid);
    ui->bImEdit->setValidator(valid);
    ui->cImEdit->setValidator(valid);
    ui->xImEdit->setValidator(valid);
}

number* Tinterface::getData()
{
    number* data = new number[4];
    if(ui->aReEdit->text().isEmpty())
        ui->aReEdit->setText("1");

    data[0]=TComplex(ui->aReEdit->text().toDouble(),ui->aImEdit->text().toDouble());
    data[1]=TComplex(ui->bReEdit->text().toDouble(),ui->bImEdit->text().toDouble());
    data[2]=TComplex(ui->cReEdit->text().toDouble(),ui->cImEdit->text().toDouble());
    data[3]=TComplex(ui->xReEdit->text().toDouble(),ui->xImEdit->text().toDouble());

    return data;
}

void Tinterface::setData(number* val)
{
    QString resPoly="(" + ui->aReEdit->text();
        if(ui->aImEdit->text().toDouble() >=0)
            resPoly+="+";
        resPoly+= ui->aImEdit->text() + "i)x^2 + (";
        resPoly+= ui->bReEdit->text();
        if(ui->bImEdit->text().toDouble() >=0)
            resPoly+="+";
        resPoly+= ui->bImEdit->text() + "i)x + (";
        resPoly+= ui->cReEdit->text();
        if(ui->cImEdit->text().toDouble() >=0)
            resPoly+="+ ";
        resPoly+=ui->cImEdit->text() + "i)";
        ui->polynomShowLabel->setText(resPoly);

    QString resFirstRoot = "1. " + QString::number(val[0].getA());
    if(val[0].getB()>=0)
        resFirstRoot += "+";
    resFirstRoot += QString::number(val[0].getB()) + "i";
    ui->firstRootLabel->setText(resFirstRoot);

    QString resSecondRoot = "2. " +  QString::number(val[1].getA());
    if(val[1].getB()>=0)
        resSecondRoot += "+";
    resSecondRoot += QString::number(val[1].getB()) + "i";
    ui->secondRootLabel->setText(resSecondRoot);

    QString resSolution = QString::number(val[2].getA());
    if(!isEqual(val[2].getB(), 0.0))
    {
        if(val[2].getB() >= 0)
            resSolution += "+";
        resSolution += QString::number(val[2].getB()) + "i";
    }
    ui->solutionLabel->setText(resSolution);
}

Tinterface::~Tinterface()
{
    delete ui;
}

void Tinterface::on_solveButton_clicked()
{
    emit this->buttonClicked();
}
