#ifndef QUADRANGLE_H
#define QUADRANGLE_H

#include <cmath>
#include <iostream>

using std::cout;

const double PI = 3.14;

double findLen(double x1, double y1, double x2, double y2);

class quadrangle
{
protected:
    double side[4];
    double angle[4];
    double findDiag(int s1, int s2);

public:
    quadrangle(const double[4], const double[4]);
    quadrangle(double s = 0.0, double a = 0.0);
    quadrangle(const quadrangle& obj);
    virtual ~quadrangle();
    virtual double area();
    virtual double perimeter();
    virtual bool isReal(); //true if quadrangle is right, false if not
};

class parallelogram: public quadrangle
{
protected:
public:
    parallelogram(double s1, double s2, double angle);
    virtual ~parallelogram() override;
    virtual double area() override;
};

class rhomb: virtual public parallelogram
{
public:
    rhomb(double s, double angle);
    virtual ~rhomb() override;
};

class rectangle: virtual public parallelogram
{
public:
    rectangle(double s1, double s2);
    virtual ~rectangle() override;
    virtual double area() override;
};

class square: public rectangle, public rhomb
{
public:
    square(double s);
    virtual ~square() override;
    virtual double area() override;
    virtual double perimeter() override;
};


#endif // QUADRANGLE_H
