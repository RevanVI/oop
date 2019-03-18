#include "tinterface.h"
#include "ui_tinterface.h"


using namespace std;

Tinterface::Tinterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QDoubleValidator* valid = new QDoubleValidator(this);
    valid->setLocale(QLocale::English);
    ui->aReEdit->setValidator(valid);
    ui->bReEdit->setValidator(valid);
    ui->cReEdit->setValidator(valid);
    ui->xReEdit->setValidator(valid);
    ui->aImEdit->setValidator(valid);
    ui->bImEdit->setValidator(valid);
    ui->cImEdit->setValidator(valid);
    ui->xImEdit->setValidator(valid);
    connect(ui->solveButton, SIGNAL (released()), this, SLOT (handleSolveButton()));
}

void Tinterface::handleSolveButton()
{
     TPolynom* polynom=new TPolynom;
     number xValue;
    if(ui->aReEdit->text().isEmpty())  polynom->setCoefA(TComplex(1,ui->aImEdit->text().toDouble()));

    polynom->setCoefA(TComplex(ui->aReEdit->text().toDouble(),ui->aImEdit->text().toDouble()));
    polynom->setCoefB(TComplex(ui->bReEdit->text().toDouble(),ui->bImEdit->text().toDouble()));
    polynom->setCoefC(TComplex(ui->cReEdit->text().toDouble(),ui->cImEdit->text().toDouble()));

    xValue=TComplex(ui->xReEdit->text().toDouble(),ui->xImEdit->text().toDouble());

    QString resPoly="(" + QString::number(polynom->getA().getA());
    if(polynom->getA().getB()>=0)
        resPoly+="+";
    resPoly+= QString::number(polynom->getA().getB()) + "i)x^2 + (";
    resPoly+= QString::number(polynom->getB().getA());
    if(polynom->getB().getB()>=0)
        resPoly+="+";
    resPoly+= QString::number(polynom->getB().getB()) + "i)x + (";
    resPoly+= QString::number(polynom->getC().getA());
    if(polynom->getC().getB()>=0)
        resPoly+="+ ";
    resPoly+=QString::number(polynom->getC().getB()) + "i)";
    ui->polynomShowLabel->setText(resPoly);

    polynom->findRoots();

    number root = polynom->get_roots()[0];
     QString resFirstRoot = "1. " + QString::number(root.getA());
    if(root.getB()>=0)
        resFirstRoot += "+";
    resFirstRoot += QString::number(root.getB()) + "i";
    ui->firstRootLabel->setText(resFirstRoot);

    root = polynom->get_roots()[1];
    QString resSecondRoot = "2. " +  QString::number(root.getA());
    if(root.getB()>=0)
        resSecondRoot += "+";
    resSecondRoot += QString::number(root.getB()) + "i";
    ui->secondRootLabel->setText(resSecondRoot);

    polynom->findSolution(xValue);

    number solution=polynom->get_solution();
    QString resSolution = QString::number(solution.getA());
    if(!isEqual(solution.getB(), 0.0))
    {
        if(solution.getB() >= 0)
            resSolution += "+";
        resSolution += QString::number(solution.getB()) + "i";
    }
    ui->solutionLabel->setText(resSolution);
}

Tinterface::~Tinterface()
{
    delete ui;
}
