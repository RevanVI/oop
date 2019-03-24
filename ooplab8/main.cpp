#include <QCoreApplication>
#include "quadrangle.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    double s[4] = {14, 12, 9, 5};
    double an[4] = {80, 85, 110, 85};
    quadrangle qa(s, an);
    parallelogram par(2, 4, 90);
    rhomb rh(4, 60);
    rectangle rect(5, 6);
    square sq(5);

    quadrangle** arr = new quadrangle*[5];
    arr[0] = &qa;
    arr[1] = &par;
    arr[2] = &rh;
    arr[3] = &rect;
    arr[4] = &sq;

    for(int i = 0; i < 5; ++i)
    {
        cout << arr[i]->area() << endl;
        cout << arr[i]->perimeter() << endl;
        cout << endl;
    }
    return a.exec();
}
