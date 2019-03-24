#include "quadrangle.h"

double findLen(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

quadrangle::quadrangle(const double val[8])
{
    for (int i = 0; i < 8; ++i)
        coords[i] = val[i];
}

quadrangle::quadrangle(double val)
{
    for (int i = 0; i < 8; ++i)
        coords[i] = val;
}

quadrangle::quadrangle(const quadrangle& obj)
{
    for (int i = 0; i < 8; ++i)
        coords[i] = obj.coords[i];
}

quadrangle::~quadrangle()
{

}

double quadrangle::area()
{
    if (!isReal())
        return 0.0;
    //first line
    double k1 = (coords[1] - coords[5])/(coords[4] - coords[0]);
    double d1 = findLen(coords[0], coords[1], coords[4], coords[5]);
    //second line
    double k2 = (coords[3] - coords[7])/(coords[6] - coords[2]);
    double d2 = findLen(coords[2], coords[3], coords[6], coords[7]);

    double angle = atan((k2 - k1) / (1 + k1*k2));
    return d1 * d2 * sin(angle * 3.14 / 180) / 2;
}

double quadrangle::perimeter()
{
    if (!isReal())
        return 0.0;
    double len = 0.0;
    for(int i = 0; i < 4; ++i)
        len += sqrt(pow(coords[i * 2] - coords[(i * 2 + 2) % 8], 2) + pow(coords[i * 2 + 1] - coords[(i * 2 + 3) % 8], 2));
    return len;
}

bool quadrangle::isReal()
{
    bool xIsZero = false,
         yIsZero = false;
    for(int i = 0; i < 4; ++i)
    {
        double x = coords[i * 2] - coords[(i * 2 + 2) % 8];
        double y = coords[i * 2 + 1] - coords[(i * 2 + 3) % 8];
        double len = sqrt(pow(x, 2) + pow(y, 2));
        if (x < 0.001 || x > -0.001)
        {
            if (xIsZero == true)
                return false;
            xIsZero = true;
        }
        if (y < 0.001 || y > -0.001)
        {
            if (yIsZero == true)
                return false;
            yIsZero = true;
        }
        if (len < 0.001)
            return false;
    }
    return true;
}

parallelogram::parallelogram(double s1, double s2, double angle) : quadrangle (0.0)
{

}
virtual ~parallelogram() override;
virtual double area() override;
virtual double perimeter() override;
virtual bool isReal() override;
