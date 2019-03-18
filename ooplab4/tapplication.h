#pragma once
#include <QCoreApplication>
#include <iostream>
#include "tinterface.h"

using namespace std;

class TApplication: public QCoreApplication
{
private:
    Tinterface interface;
public:
    TApplication(int argc, char **argv);
    ~TApplication();
    int run();
    //bool initOrRedactCoefs(TPolynom*);
    //void initShowRoots(TPolynom*);
    //void initSolution(TPolynom*);
    //void initRoots(TPolynom*);
};

