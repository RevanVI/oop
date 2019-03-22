#include "tapplication.h"

TApplication::TApplication(int argc, char **argv): QCoreApplication (argc, argv)
{
    polyInited = false;
    xValueInited = false;
}

TApplication::~TApplication()
{

}

void TApplication::initSolution(TPolynom* polynom) {

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
}

int TApplication::menu() {
    system("cls");
    cout << "Menu:" << endl;
    cout << "1. Enter/change polynom's coefficients" << endl;
    cout << "2. Calculate polynom value for a given X" << endl;
    cout << "3. Search polynom root " << endl;
    cout << "4. Print polynom and x value" << endl;
    cout << "0. Exit" << endl;
    int choice;
    cout<< endl << "Input field: ";
    cin >> choice;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return 	choice;
}

int TApplication::run()
{
    int ch = 0;
    TPolynom* polynom = new TPolynom;
    bool polyInited = false;
    while (true)
    {
        ch = menu();
        if (ch == 0) break;
        switch (ch) {
        case 1:
            polyInited = initOrRedactCoefs(polynom);
            break;
        case 2:
            initSolution(polynom);
            break;
        case 3:
            if (!polyInited) initOrRedactCoefs(polynom);
            initRoots(polynom);
            initShowRoots(polynom);
            break;
        case 4:
            if (polyInited) {
                cout << polynom << endl;
            }else cout << "Polynom is undefined" << endl;
            break;
        default:
            break;
        }
        system("pause");
    }
    return 0;
}
