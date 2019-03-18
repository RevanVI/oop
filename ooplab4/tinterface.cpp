#include "tinterface.h"
#include "ui_tinterface.h"


using namespace std;

Tinterface::Tinterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
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

    //kill me
    QString resPoly="(";
    resPoly+= QString::number(polynom->getA().getA());
    if(polynom->getA().getB()>=0.0000000001)
        resPoly+="+";
    resPoly+= QString::number(polynom->getA().getB());
    resPoly+="i)x^2 ";

    //if (polynom->getB().getA() >= 0.0000001)
        resPoly+="+ (";
    resPoly+= QString::number(polynom->getB().getA());
    if(polynom->getB().getB()>=0.0000000001)
        resPoly+="+";
    resPoly+= QString::number(polynom->getB().getB());
    resPoly+= "i)x ";

    //if (polynom->getC().getA() >= 0.0000001)
        resPoly+="+ (";
    resPoly+= QString::number(polynom->getC().getA());
    //if(polynom->getC().getB()>=0.0000000001)
        resPoly+="+ ";
    resPoly+=QString::number(polynom->getC().getB());
    resPoly+= "i)";
    ui->polynomShowLabel->setText(resPoly);

    polynom->findRoots();

    QString resFirstRoot="1. ";
    number root;
    root = polynom->get_roots()[0];
    resFirstRoot += QString::number(root.getA());
    if(root.getB()>=0.00000000000001)
        resFirstRoot += "+";
    resFirstRoot += QString::number(root.getB());
    resFirstRoot +="i";
    ui->firstRootLabel->setText(resFirstRoot);

    QString resSecondRoot="2. ";
    root = polynom->get_roots()[1];
    resSecondRoot += QString::number(root.getA());
    if(root.getB()>=0.00000000000001)
        resSecondRoot += "+";
    resSecondRoot += QString::number(root.getB());
    resSecondRoot +="i";
    ui->secondRootLabel->setText(resSecondRoot);

    polynom->findSolution(xValue);

    number solution=polynom->get_solution();
    QString resSolution="";
    resSolution+=QString::number(solution.getA());
    if(solution.getB()>0.00000000001 || solution.getB()<-0.00000000001)
    {
        if(solution.getB() > 0.000000000001)
            resSolution += "+";
        resSolution += QString::number(solution.getB());
        resSolution +="i";
    }

    ui->solutionLabel->setText(resSolution);
}

Tinterface::~Tinterface()
{
    delete ui;
}
