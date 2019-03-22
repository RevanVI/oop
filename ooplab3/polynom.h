#pragma once
#include <iostream>
#include <math.h>
#include "number.h"
#include <cfenv>

using namespace std;
template <class number>
class TPolynom {
private:
    number a;
    number b;
    number c;
    short num_of_roots;
    number roots[2];//TComplex
    number solution;
public:
    TPolynom(number av = number(1), number bv = number(0), number cv = number(0))
    {
        a = av;
        b = bv;
        c = cv;
        num_of_roots = 0;
        solution = number(0);//number solution  = number(0);
    }
    //~TPolynom();

    void setCoefA(number val)
    {
        a = val;
    }
    void setCoefB(number val)
    {
        b = val;
    }
    void setCoefC(number val)
    {
        c = val;
    }
    void setCoefs(number av, number bv, number cv)
    {
        a = av;
        b = bv;
        a = cv;
    }
    short get_num_of_roots()
    {
        return num_of_roots;
    }
    number get_solution()
    {
        return solution;
    }
    number* get_roots()//TComplex
    {
        return roots;
    }
    number findSolution(number xValue)
    {
        solution = a*xValue*xValue + b*xValue + c;
        return solution;
    }
    //вычисление корней
    void findRoots()
    {
        number val = sqrt(b*b - 4 * a * c);//TComplex val
        if (fetestexcept(FE_INVALID))
        {
            num_of_roots = 0;
            return;
        }
        else
        {
            num_of_roots = 2;
            roots[0] = roundPrec((-b + val) / (2 * a), 2);
            roots[1] = roundPrec((-b - val) / (2 * a), 2);

        }
    }
    //вывод корней
    void showRoots()
    {
        if (num_of_roots == 0)
            cout << "No roots";
        else
            for (int i = 0; i < num_of_roots; ++i)
                cout << roots[i] << " ";
    }

    friend ostream& operator<<(ostream& out, TPolynom<number>& pol)
    {
        out << pol.a << "x^2 ";
        if (pol.b >= number(0))
            out << "+ ";
        out << pol.b << "x ";
        if (pol.c >= number(0))
            out << "+ ";
        out << pol.c;
        return out;
    }
};
bool isEqual(double left, double right);
double roundPrec(double val, int prec);
