#include "polynom.h"

TPolynom::TPolynom(number av , number bv, number cv)
{
    a = av;
    b = bv;
    c = cv;
    short num_of_root = 0;
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
    solution = a*pow(xValue, 2) + b*xValue + c;
    return solution;
}

void TPolynom::findRoots() {
    number discr = pow(b, 2) - 4 * a * c;
    if (discr < 0)
    {
        num_of_roots = 0;
        return;
    }
    else if (discr <= number(0.000001) && discr >= number(0.000001))
    {
        num_of_roots = 1;
        roots[0] = (-b) / (2 * a);
    }
    else
    {
        num_of_roots = 2;
        roots[0] = (-b + sqrt(discr)) / (2 * a);
        roots[1] = (-b - sqrt(discr)) / (2 * a);
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
        cout << "+ ";
    cout << pol.b << "x ";
    if (pol.c >= number(0))
        cout << "+ ";
    cout << pol.c;
    return out;
}

