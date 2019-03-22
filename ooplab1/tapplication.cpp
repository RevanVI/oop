#include "tapplication.h"

TApplication::TApplication(int argc, char **argv): QCoreApplication (argc, argv)
{
}

TApplication::~TApplication()
{

}

void TApplication::initSolution(TPolynom* polynom, number& xValue) {

    cout << "Enter x:";
    cin >> xValue;
    polynom->findSolution(xValue);
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
    cout << "2. Enter X value" << endl;
    cout << "3. Search polynom root " << endl;
    cout << "4. Print result" << endl;
    cout << "5. Print polynom and x value" << endl;
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
    bool xInited = false;
    number xValue;
    while (true)
    {
        ch = menu();
        if (ch == 0) break;
        switch (ch) {
        case 1:
            polyInited = initOrRedactCoefs(polynom);
            break;
        case 2:
            if (polyInited)
            {
                initSolution(polynom, xValue);
                xInited = true;
            }
            else
                cout << "Polynom is undefined" << endl;
            break;
        case 3:
            if (!polyInited) initOrRedactCoefs(polynom);
            initRoots(polynom);
            initShowRoots(polynom);
            break;
        case 4:
            if (polyInited) {
                if (xInited)
                    cout << "Polynom value for given X: " << polynom->get_solution() << endl;
                else
                    cout << "X value is undefined" << endl;
            }
            else cout << "Polynom is undefined" << endl;
            break;
        case 5:
            if (polyInited) {
                cout << "Polynom: " << *polynom << endl;
                if (xInited)
                    cout << "X value: " <<  xValue << endl;
                else
                    cout << "X value is undefined" << endl;
            }
            else cout << "Polynom is undefined" << endl;
            break;
        default:
            break;
        }
        system("pause");
    }
    return 0;
}
