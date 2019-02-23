#include "polynom.h"
#include <cfenv>

double roundPrec(double val, int prec)
{
    return round(val * pow(10, prec)) / pow(10, prec);
}

TPolynom::TPolynom(number av , number bv, number cv)
{
    a = av;
    b = bv;
    c = cv;
    num_of_roots = 0;
    number solution = number(0);
}

TPolynom::~TPolynom()
{

}

void TPolynom::setCoefA(number val)
{
    a = val;
}

void TPolynom::setCoefB(number val)
{
    b = val;
}

void TPolynom::setCoefC(number val)
{
    c = val;
}

void TPolynom::setCoefs(number av, number bv, number cv)
{
    a = av;
    b = bv;
    a = cv;
}

short TPolynom::get_num_of_roots()
{
    return num_of_roots;
}

number TPolynom::get_solution()
{
    return solution;
}

number* TPolynom::get_roots()
{
    return roots;
}

number TPolynom::findSolution(number xValue) {
    solution = a*xValue*xValue + b*xValue + c;
    return solution;
}

void TPolynom::findRoots() {
    number val = sqrt(b*b - 4 * a * c);
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


void TPolynom::showRoots()
{
    if (num_of_roots == 0)
        cout << "No roots";
    else
        for (int i = 0; i < num_of_roots; ++i)
            cout << roots[i] << " ";
}

ostream& operator<<(ostream& out , TPolynom& pol) {
    out << pol.a << "x^2 ";
    if (pol.b >= number(0))
        out << "+ ";
    out << pol.b << "x ";
    if (pol.c >= number(0))
        out << "+ ";
    out << pol.c;
    return out;
}

