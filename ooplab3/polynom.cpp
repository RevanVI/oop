#include "polynom.h"
//#include <cfenv>

double roundPrec(double val, int prec)
{
    return round(val * pow(10, prec)) / pow(10, prec);
}

bool isEqual(double left, double right)
{
    double err = 0.000001;
    return (left <= (right + err) && left >= (right - err));
}

/*template<class number>
TPolynom<number>::TPolynom(number av , number bv, number cv)
{
    a = av;
    b = bv;
    c = cv;
    num_of_roots = 0;
    number solution = number(0);
}*/

/*template<class number>
TPolynom<number>::~TPolynom()
{

}*/

/*template<class number>
void TPolynom<number>::setCoefA(number val)
{
    a = val;
}*/

/*template<class number>
void TPolynom<number>::setCoefB(number val)
{
    b = val;
}*/

/*template<class number>
void TPolynom<number>::setCoefC(number val)
{
    c = val;
}*/

/*template<class number>
void TPolynom<number>::setCoefs(number av, number bv, number cv)
{
    a = av;
    b = bv;
    a = cv;
}*/

/*template<class number>
short TPolynom<number>::get_num_of_roots()
{
    return num_of_roots;
}*/

/*template<class number>
number TPolynom<number>::get_solution()
{
    return solution;
}*/

/*template<class number>
TComplex* TPolynom<number>::get_roots()
{
    return roots;
}*/

/*template<class number>
number TPolynom<number>::findSolution(number xValue)
{
    solution = a*xValue*xValue + b*xValue + c;
    return solution;
}*/

/*template<class number>
void TPolynom<number>::findRoots()
{
    TComplex val = sqrt(b*b - 4 * a * c);
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
}*/

/*template<class number>
void TPolynom<number>::showRoots()
{
    if (num_of_roots == 0)
        cout << "No roots";
    else
        for (int i = 0; i < num_of_roots; ++i)
            cout << roots[i] << " ";
}*/

/*template<class number>
ostream& operator<<(ostream& out , TPolynom<number>& pol)
{
    out << pol.a << "x^2 ";
    if (pol.b >= number(0))
        out << "+ ";
    out << pol.b << "x ";
    if (pol.c >= number(0))
        out << "+ ";
    out << pol.c;
    return out;
}*/

