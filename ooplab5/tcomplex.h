#ifndef TCOMPLEX_H
#define TCOMPLEX_H
#include <iostream>
#include <QDataStream>

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
    friend TComplex operator*(double, TComplex);
    friend TComplex operator*(TComplex, double);
    friend TComplex operator/(TComplex, TComplex);
    friend TComplex operator-(TComplex);
    friend TComplex sqrt(TComplex);
    friend ostream& operator<<(ostream&, TComplex&);
    friend istream& operator>>(istream&, TComplex&);
    friend bool operator<(TComplex, TComplex);
    friend bool operator>(TComplex, TComplex);
    friend bool operator<=(TComplex, TComplex);
    friend bool operator>=(TComplex, TComplex);
    friend bool operator==(TComplex, double);
    friend TComplex roundPrec(TComplex val, int prec);
    friend bool isEqual(TComplex left, double right);
    friend QDataStream &operator<<(QDataStream &out, const TComplex&);
    friend QDataStream &operator>>(QDataStream &out, TComplex&);
};

#endif // TCOMPLEX_H
