#include "tapplication.h"

TApplication::TApplication(int argc, char **argv): QCoreApplication (argc, argv)
{
}

TApplication::~TApplication()
{

}

int TApplication::menu() {
    system("cls");
    cout << "Menu:" << endl;
    cout << "1. Quadrangle" << endl;
    cout << "2. Parallelogram" << endl;
    cout << "3. Rhomb" << endl;
    cout << "4. Rectangle" << endl;
    cout << "5. Square" << endl;
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
    while (true)
    {
        ch = menu();
        quadrangle* par;
        if (ch == 0) break;
        switch (ch) {
        case 1:
            {
                double side[4];
                cout << "Enter 4  side values: ";
                for (int i = 0; i < 4; ++i)
                {
                    cin >> side[i];
                }
                double angle[4];
                cout << "Enter 4 angle values: ";
                for (int i = 0; i < 4; ++i)
                    cin >> angle[i];
                par = new quadrangle(side, angle);
            }
            break;
        case 2:
            {
                double s1, s2, angle;
                cout << "Enter first side value: ";
                cin >> s1;
                cout << "Enter second side value: ";
                cin >> s2;
                cout << "Enter angle value: ";
                cin >> angle;
                par = new parallelogram(s1, s2, angle);
            }
            break;
        case 3:
            {
                double s, angle;
                cout << "Enter first side value: ";
                cin >> s;
                cout << "Enter angle value: ";
                cin >> angle;
                par = new rhomb(s, angle);
            }
            break;
        case 4:
            {
                double s1, s2;
                cout << "Enter first side value: ";
                cin >> s1;
                cout << "Enter second side value: ";
                cin >> s2;
                par = new rectangle(s1, s2);
            }
            break;
        case 5:
            {
                double s;
                cout << "Enter side value: ";
                cin >> s;
                par = new square(s);
            }
            break;
        default:
            break;
        }
        cout << "Area: " << par->area() << endl;
        cout << "Perimeter: " << par->perimeter() << endl;
        delete par;
        system("pause");
    }
    return 0;
}
