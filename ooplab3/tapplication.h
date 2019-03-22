#pragma once
#include <QCoreApplication>
#include <iostream>
#include <math.h>
#include <conio.h>
#include "polynom.h"

using namespace std;

class TApplication: public QCoreApplication
{
private:
	bool polyInited;
	bool xValueInited;
public:
    TApplication(int argc, char **argv);
    ~TApplication();
	int menu();
    int menuRealOrComplex();
	int run();
    template <class number>
    void initXValue(number &xValue);
    template<class number>
    void initOrRedactCoefs(TPolynom<number> &polynom);
    template<class number>
    void initShowRoots(TPolynom<number> &polynom);
    template<class number>
    void initSolution(TPolynom<number> &polynom, number xValue);
    template<class number>
    void initRoots(TPolynom<number> &polynom);
};

