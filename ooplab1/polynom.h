#pragma once
#include <iostream>
#include <math.h>
#include "number.h"

using namespace std;

double roundPrec(double val, int prec);
bool isEqual(double left, double right);

class TPolynom {
private:
    number a;
    number b;
    number c;
    short num_of_roots;
    number roots[2];
    number solution;
public:
    TPolynom(number av = number(1), number bv = number(0), number cv = number(0));
    ~TPolynom();

    void setCoefA(number val);
    void setCoefB(number val);
    void setCoefC(number val);
    void setCoefs(number a, number b, number c);
    short get_num_of_roots();
    number get_solution();
    number* get_roots();
    number findSolution(number);
    void findRoots();
    void showRoots();

    friend ostream& operator<<(ostream&, TPolynom&);
};
