#include "tcomplex.h"
#include "cmath"

TComplex::TComplex(double av , double bv)
{
    a = av;
    b = bv;
}

TComplex::~TComplex()
{

}

TComplex operator+(TComplex left, TComplex right)
{
    return TComplex(left.a + right.a, left.b + right.b);
}

TComplex operator-(TComplex left, TComplex right)
{
    return TComplex(left.a - right.a, left.b - right.b);
}

TComplex operator*(TComplex left, TComplex right)
{
    return TComplex(left.a * right.a - left.b * right.b, left.a * right.b + left.b * right.a);
}

TComplex operator*(double left, TComplex right)
{
    return TComplex(left * right.a, left * right.b);
}

TComplex operator*(TComplex left, double right)
{
    return TComplex(left.a * right, left.b * right);
}

TComplex operator/(TComplex left, TComplex right)
{
    double leftOper=(left.a*right.a+left.b*right.b)/(right.b*right.b+right.a*right.a);
    double rightOper=(left.b*right.a-left.a*right.b)/(right.b*right.b+right.a*right.a);

    return TComplex(leftOper,rightOper);
}

TComplex operator-(TComplex val)
{
    return TComplex(-val.a, -val.b);
}

TComplex sqrt(TComplex val) //возвращает только один корень, второй можно получить умножением на -1
{
    if (val.b <= 0.000001 && val.b >= -0.000001 && val.a < 0)
        return TComplex(0, sqrt(-val.a));
      double r = sqrt(val.a * val.a + val.b * val.b);
      double angle = atan(val.b / val.a);
      if ((val.a < 0 && val.b < 0) || (val.a < 0 && val.b > 0))
          angle += 3.14;
      double a = sqrt(r) * cos(angle / 2); //phi / 2
      double b = sqrt(r) * sin(angle / 2);
      return TComplex(a, b);
}

ostream& operator<<(ostream& out, TComplex& v)
{
    out << v.a;
    if (v.b >= 0)
        out << " + ";
    out << v.b << "i";
    return out;
}

istream& operator>>(istream& in, TComplex& val)
{
    in >> val.a >> val.b;
    return in;
}

bool operator<(TComplex left, TComplex right)
{
    return (left.a < right.a);
}

bool operator>(TComplex left, TComplex right)
{
    return (left.a > right.a);
}

bool operator<=(TComplex left, TComplex right)
{
    return (left.a <= right.a);
}

bool operator>=(TComplex left, TComplex right)
{
    return (left.a >= right.a);
}

TComplex roundPrec(TComplex val, int prec)
{
    double a = round(val.a * pow(10, prec)) / pow(10, prec);
    double b = round(val.b * pow(10, prec)) / pow(10, prec);
    return TComplex(a, b);
}

bool isEqual(TComplex left, double right)
{
    double err = 0.000001;
    return ((left.a <= (right + err) && left.a >= (right - err)) && (left.b <= (err) && left.a >= (- err)));
}
