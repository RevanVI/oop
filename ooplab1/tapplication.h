#pragma once
#include <QCoreApplication>
#include <iostream>
#include <math.h>
#include <conio.h>
#include "polynom.h"
#include "tcomplex.h"

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
	int run();
    bool initOrRedactCoefs(TPolynom*);
    void initShowRoots(TPolynom*);
    void initSolution(TPolynom*);
    void initRoots(TPolynom*);
};

