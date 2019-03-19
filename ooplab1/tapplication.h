#pragma once
#include <QCoreApplication>
#include <QtWidgets/QApplication>
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

class TApplication: public QApplication
{
    Q_OBJECT
private:
    QUdpSocket* socket;
    number val[4];
public:
    TApplication(int argc, char **argv);
    ~TApplication();
public slots:
    void receive();
    void onSocketError(QAbstractSocket::SocketError);
    void calculate();
    void send();
signals:
    void dataReceived();
    void calculated();
};

