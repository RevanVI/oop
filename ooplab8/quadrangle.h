#ifndef QUADRANGLE_H
#define QUADRANGLE_H

#include <cmath>

double findLen(double x1, double y1, double x2, double y2);

class quadrangle
{
protected:
    double coords[8];
public:
    quadrangle(const double[8]);
    quadrangle(double val = 0.0);
    quadrangle(const quadrangle& obj);
    virtual ~quadrangle();
    virtual double area();
    virtual double perimeter();
    virtual bool isReal(); //true if quadrangle is right, false if not
};

class parallelogram: public quadrangle
{
protected:
    double s1, s2;
    double angle;
public:
    parallelogram(double s1, double s2, double angle);
    virtual ~parallelogram() override;
    virtual double area() override;
    virtual double perimeter() override;
    virtual bool isReal() override;
};

class rhomb: virtual public parallelogram
{
public:
    rhomb(double s, double angle);
    virtual ~rhomb() override;
    virtual double area() override;
    virtual double perimeter() override;
};

class rectangle: virtual public parallelogram
{
public:

    virtual ~rectangle() override;
    virtual double area() override;
    virtual double perimeter() override;
};

class square: public rectangle, public rhomb
{
public:
    virtual ~square() override;
    virtual double area() override;
    virtual double perimeter() override;
};


#endif // QUADRANGLE_H
