#include "tapplication.h"

TApplication::TApplication(int argc, char **argv): QCoreApplication (argc, argv)
{
    polyInited = false;
    xValueInited = false;
}

TApplication::~TApplication()
{

}

void TApplication::initXValue() {
    cout << "Enter x:";
    cin >> xValue;
    xValueInited = true;
}

void TApplication::initSolution() {
    polynom.findSolution(xValue);
}

void TApplication::initRoots() {
    polynom.findRoots();
}

void TApplication::initOrRedactCoefs() {
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
    polynom.setCoefA(val);
    cout << "The coefficient of the 1st degree: ";
    cin >> val;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    polynom.setCoefB(val);
    cout << "The coefficient of the free member: ";
    cin >> val;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    polynom.setCoefC(val);
    polyInited = true;
}

void TApplication::initShowRoots() {
    cout << "Root(-s): ";
    polynom.showRoots();
    cout << endl;
}

int TApplication::menu() {
    system("cls");
    cout << "Menu:" << endl;
    cout << "1. Enter/change polynom's coefficients" << endl;
    cout << "2. Enter value x" << endl;
    cout << "3. Search polynom root " << endl;
    cout << "4. Calculate polynom value for a given X" << endl;
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
    int ch;
    while (true)
    {
        ch = menu();
        if (ch == 0) break;
        switch (ch) {
        case 1:
            initOrRedactCoefs();
            break;
        case 2:
            initXValue();
            break;
        case 3:
            if (!polyInited) initOrRedactCoefs();
            initRoots();
            initShowRoots();
            break;
        case 4:
            {
                if (!polyInited) initOrRedactCoefs();
                if (!xValueInited) initXValue();
                initSolution();
                number buf = polynom.get_solution();
                cout << "Value for x = " << xValue << ": " << buf;
            }
            break;
        case 5:
            if (polyInited) {
                cout << polynom << endl;
            }else cout << "Polynom is undefined" << endl;
            if (xValueInited) {
                cout << "x = " << xValue << endl;
            }else cout << "x is undefined" << endl;
            break;
        default:
            break;
        }
        system("pause");
    }
    return 0;
}
