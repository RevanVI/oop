#pragma once
#include <QCoreApplication>
#include <iostream>
#include <math.h>
#include <conio.h>
#include "polynom.h"
#include "number.h"

using namespace std;

class TApplication: public QCoreApplication
{
private:
public:
    TApplication(int argc, char **argv);
    ~TApplication();
	int menu();
	int run();
    bool initOrRedactCoefs(TPolynom*);
    void initShowRoots(TPolynom*);
    void initSolution(TPolynom*, number&);
    void initRoots(TPolynom*);
};

