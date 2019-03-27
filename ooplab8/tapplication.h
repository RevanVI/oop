#ifndef TAPPLICATION_H
#define TAPPLICATION_H


#pragma once
#include <QCoreApplication>
#include <iostream>
#include <math.h>
#include <conio.h>
#include "quadrangle.h"

using namespace std;

class TApplication: public QCoreApplication
{
private:
public:
    TApplication(int argc, char **argv);
    ~TApplication();
    int menu();
    int run();
};
#endif // TAPPLICATION_H
