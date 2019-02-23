#ifndef TCOMPLEX_H
#define TCOMPLEX_H
#include <iostream>

using namespace std;

class TComplex
{
private:
    double a, b;
public:
    TComplex(double av = 0, double bv = 0);
    ~TComplex();

    friend TComplex operator+(TComplex, TComplex);
    friend TComplex operator-(TComplex, TComplex);
    friend TComplex operator*(TComplex, TComplex);
    friend TComplex operator/(TComplex, TComplex);
    friend TComplex operator-(TComplex);
    friend TComplex sqrt(TComplex);
    friend ostream& operator<<(ostream&, TComplex&);
    friend bool operator<(TComplex, TComplex);
    friend bool operator>(TComplex, TComplex);
    friend bool operator<=(TComplex, TComplex);
    friend bool operator>=(TComplex, TComplex);
};

#endif // TCOMPLEX_H
