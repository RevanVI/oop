#include "tapplication.h"

TApplication::TApplication(int argc, char **argv): QCoreApplication (argc, argv)
{
    run();
}

TApplication::~TApplication()
{

}

int TApplication::run()
{
    interface.show();
    return 0;
}

/*void TApplication::initSolution(TPolynom* polynom) {

    cout << "Enter x:";
    number xValue;
    cin >> xValue;
    cout << "Result: ";
    number val = polynom->findSolution(xValue);
    cout << val << endl;
}

void TApplication::initRoots(TPolynom* polynom) {
    polynom->findRoots();
}

bool TApplication::initOrRedactCoefs(TPolynom* polynom) {
    number val;
    cout << "Enter polynom coefficients." << endl;
    cout << "The coefficient of the 2nd degree (!= 0): ";
    cin >> val;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (isEqual(val, 0))
    {
        cout << "Error! Entered 0. Repeat input: ";
        cin >> val;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    polynom->setCoefA(val);
    cout << "The coefficient of the 1st degree: ";
    cin >> val;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    polynom->setCoefB(val);
    cout << "The coefficient of the free member: ";
    cin >> val;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    polynom->setCoefC(val);
    return true;
}

void TApplication::initShowRoots(TPolynom* polynom) {
    cout << "Root(-s): ";
    polynom->showRoots();
    cout << endl;
}*/


