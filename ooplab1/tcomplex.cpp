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
    return TComplex(left.a + right.a, left.b + left.b);
}

TComplex operator-(TComplex left, TComplex right)
{
    return TComplex(left.a - right.a, left.b - left.b);
}

TComplex operator*(TComplex left, TComplex right)
{
    return TComplex(left.a * right.a - left.b * right.b, left.a * right.b + left.b * right.a);
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

TComplex sqrt(TComplex val)
{
      double r = sqrt(val.a * val.a + val.b * val.b);
      double angle = atan(val.b / val.a);
      if ((val.a < 0 && val.b < 0 && angle > 0) || (val.a < 0 && val.b > 0 && angle < 0))
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

bool operator<(TComplex left, TComplex right)
{
    if (right.a < 0 && (right.b <= 0.000001 && right.b >= -0.000001))
        return false;
}
