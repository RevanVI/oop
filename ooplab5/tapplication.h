#pragma once
#include <QtWidgets/QApplication>
#include <iostream>
#include <QtNetwork/QUdpSocket>
#include "tinterface.h"

using namespace std;

class TApplication: public QApplication
{
    Q_OBJECT
private:
    Tinterface* interface;
    QUdpSocket* socket;
public:
    TApplication(int argc, char **argv);
    ~TApplication();

private slots:
    void receive();
    void send();
};

