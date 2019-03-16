#pragma once
#include <QCoreApplication>
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QtNetwork>
#include <QDateTime>
#include <iostream>
#include <math.h>
#include <conio.h>
#include "polynom.h"
#include "number.h"

using namespace std;

class TApplication: public QCoreApplication
{
    Q_OBJECT
private:
    QUdpSocket* socket;
public:
    TApplication(int argc, char **argv);
    ~TApplication();
    bool calcRoots(TPolynom*);
public slots:
    void receive();
    void connected();
    void disconnected();
};

