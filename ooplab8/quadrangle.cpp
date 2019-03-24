#include "quadrangle.h"

double findLen(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

quadrangle::quadrangle(const double s[4], const double a[4])
{
    for (int i = 0; i < 4; ++i)
        side[i] = s[i];
    for (int i = 0; i < 4; ++i)
        angle[i] = a[i];
}

quadrangle::quadrangle(double s, double a)
{
    for (int i = 0; i < 4; ++i)
        side[i] = s;
    for (int i = 0; i < 4; ++i)
        angle[i] = a;
}

quadrangle::quadrangle(const quadrangle& obj)
{
    for (int i = 0; i < 4; ++i)
        side[i] = obj.side[i];
    for (int i = 0; i < 4; ++i)
        angle[i] = obj.angle[i];
}

quadrangle::~quadrangle()
{

}

double quadrangle::findDiag(int s1, int s2)
{
    return sqrt(pow(side[s1], 2) + pow(side[s2], 2) - 2 * side[s1] * side[s2] * cos(angle[s1] * PI / 180));
}

double quadrangle::area()
{
    cout << "Quadrangle area\n";
    if (!isReal())
        return 0.0;
    /*
    double d1 = findDiag(0, 1);
    double d2 = findDiag(1, 2);

    double a1 = acos((pow(side[1], 2) + d1*d1 - pow(side[0], 2))/(2*pow(side[1], 2)*d1)) / PI * 180;
    double a2 = acos((pow(side[1], 2) + d2*d2 - pow(side[2], 2))/(2*pow(side[1], 2)*d2)) / PI * 180;

    double a = 180 - a1 - a2;
    return 0.5 * d1 * d2 * sin(a * PI / 180);
    */
    return 0.5 * (side[0] * side[1] * sin(angle[0] * PI / 180) + side[2] * side[3] * sin(angle[2] * PI / 180));
}

double quadrangle::perimeter()
{
    cout << "Quadrangle perimeter\n";
    if (!isReal())
        return 0.0;
    double len = 0.0;
    for(int i = 0; i < 4; ++i)
        len += side[i];
    return len;
}

bool quadrangle::isReal()
{
    double sum = 0.0;
    for(int i = 0; i < 4; ++i)
    {
        if ((side[i] < 0))
            return false;
        sum += angle[i];
    }
    if (sum > 360.2 || sum < 359.8)
        return false;
    return true;
}



parallelogram::parallelogram(double s1, double s2, double ang) : quadrangle (s1, ang)
{
    side[1] = side[3] = s2;
    angle[1] = angle[3] = 180 - ang;
}

parallelogram::~parallelogram()
{

}

double parallelogram::area()
{
    cout << "Parallelogram area\n";
    if (!isReal())
        return 0.0;
    return side[0] * side[1] * sin(angle[0] * PI / 180);
}



rhomb::rhomb(double s, double ang): parallelogram (s, s, ang)
{

}

rhomb::~rhomb()
{

}


rectangle::rectangle(double s1, double s2): parallelogram (s1, s2, 90)
{

}

rectangle::~rectangle()
{

}

double rectangle::area()
{
    cout << "Rectangle area\n";
    if(!isReal())
        return 0.0;
    return side[0] * side[1];
}



square::square(double s): parallelogram (s, s, 90), rectangle (s, s), rhomb (s, 90)
{

}

square::~square()
{

}

double square::area()
{
    cout << "Square area\n";
    return rectangle::area();
}

double square::perimeter()
{
    cout << "Square perimeter\n";
    if (!isReal())
        return 0.0;
    return 4 * side[0];
}
