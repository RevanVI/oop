#include "tapplication.h"

TApplication::TApplication(int argc, char **argv): QCoreApplication (argc, argv)
{
    polyInited = false;
    xValueInited = false;
}

TApplication::~TApplication()
{

}

template <class number>
void TApplication::initXValue(number &xValue)
{
    cout << "Enter x:";
    cin >> xValue;
    xValueInited = true;
}

template<class number>
void TApplication::initSolution(TPolynom<number> &polynom, number xValue) {
    polynom.findSolution(xValue);
}

template <class number>
void TApplication::initRoots(TPolynom<number> &polynom) {
    polynom.findRoots();
}

template <class number>
void TApplication::initOrRedactCoefs(TPolynom<number> &polynom) {
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

template <class number>
void TApplication::initShowRoots(TPolynom<number> &polynom) {
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

int TApplication::menuRealOrComplex()
{
    system("cls");
    cout << "1. Double" << endl;
    cout << "2. Complex" << endl;
    cout << "0. Exit" << endl;
    int pick;
    cout<< endl << "Input field: ";
    cin >> pick;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return 	pick;
}

int TApplication::run()
{
    int ch;
    while (true)
    {
        ch = menuRealOrComplex();
        if (ch == 0) break;
        switch (ch)
        {
        case 1:
        {
            TPolynom<double> *doublePolynom = new TPolynom<double>;
            TPolynom<double> &refOnDoublePolynom = *doublePolynom;
            double *X = new double;
            double &refOnDoubleX = *X;
            while (true)
            {
            ch = menu();
            if (ch == 0)
            {
                delete doublePolynom;
                delete X;
                break;
            }
                switch (ch)
                {
                case 1:
                initOrRedactCoefs(refOnDoublePolynom);
                break;
                case 2:
                initXValue(refOnDoubleX);
                break;
                case 3:
                {
                if (!polyInited)
                    initOrRedactCoefs(refOnDoublePolynom);
                initRoots(refOnDoublePolynom);
                initShowRoots(refOnDoublePolynom);
                system("PAUSE");
                }
                break;
                case 4:
                {
                    if (!polyInited) initOrRedactCoefs(refOnDoublePolynom);
                    if (!xValueInited) initXValue(refOnDoubleX);
                    initSolution(refOnDoublePolynom, refOnDoubleX);
                    double buf = refOnDoublePolynom.get_solution();
                    cout << "Value for x = " << refOnDoubleX << ": " << buf;
                    system("PAUSE");
                }
                break;
                case 5:
                {
                if (polyInited)
                    cout << refOnDoublePolynom << endl;
                else
                    cout << "Polynom is undefined" << endl;
                if (xValueInited)
                    cout << "x = " << refOnDoubleX << endl;
                else
                    cout << "x is undefined" << endl;
                system("PAUSE");
                }
                break;
                default:
                break;
                }
            }
            break;
        }
        case 2:
        {
            TPolynom<TComplex> *complexPolynom = new TPolynom<TComplex>;
            TPolynom<TComplex> &refOnComplexPolynom = *complexPolynom;
            TComplex *X = new TComplex;
            TComplex &refOnComplexX = *X;
            while (true)
            {
            ch = menu();
            if (ch == 0)
            {
                delete complexPolynom;
                delete X;
                break;
            }
                switch (ch)
                {
                case 1:
                initOrRedactCoefs(refOnComplexPolynom);
                break;
                case 2:
                initXValue(refOnComplexX);
                break;
                case 3:
                {
                if (!polyInited) initOrRedactCoefs(refOnComplexPolynom);
                initRoots(refOnComplexPolynom);
                initShowRoots(refOnComplexPolynom);
                system("PAUSE");
                }
                break;
                case 4:
                {
                    if (!polyInited) initOrRedactCoefs(refOnComplexPolynom);
                    if (!xValueInited) initXValue(refOnComplexX);
                    initSolution(refOnComplexPolynom, refOnComplexX);
                    TComplex buf = refOnComplexPolynom.get_solution();
                    cout << "Value for x = " << refOnComplexX << ": " << buf;
                    system("PAUSE");
                }
                break;
                case 5:
                {
                if (polyInited)
                    cout << refOnComplexPolynom << endl;
                else
                    cout << "Polynom is undefined" << endl;
                if (xValueInited)
                    cout << "x = " << refOnComplexX << endl;
                else
                    cout << "x is undefined" << endl;
                system("PAUSE");
                }
                break;
                default:
                break;
                }
            }
            break;
        }
        }
            system("pause");
    }
    return 0;
}
