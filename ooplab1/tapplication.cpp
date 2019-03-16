#include "tapplication.h"

TApplication::TApplication(int argc, char **argv): QCoreApplication (argc, argv)
{
    socket = new QUdpSocket();
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(receive()));
    receive();
}

TApplication::~TApplication()
{
    delete socket;
}

void TApplication::receive()
{

    QByteArray data;
    /*
    do {
        data.resize(socket->pendingDatagramSize());
        socket->readDatagram(data.data(), data.size());
    } while (socket->hasPendingDatagrams());
    */
    QDateTime time = QDateTime::currentDateTime();
    //cout << time.toString().toStdString() << ": receive message" << endl;
    QDataStream str(&data, QIODevice::ReadWrite);
    str.setVersion(QDataStream::Qt_5_9);

    number* vals = new number[3];
    number x;
    vals[0] = 2;
    vals[1] = 2;
    vals[2] = 2;
    //str >> vals[0] >> vals[1] >> vals[2] >> x;
    TPolynom polynom(vals[0], vals[1], vals[2]);
    polynom.findRoots();
    delete[] vals;
    vals = polynom.get_roots();

    str << vals[0] << vals[1];
    time = QDateTime::currentDateTime();
    cout << time.toString().toStdString() << ": send answer" << endl;
    socket->writeDatagram(data, QHostAddress::LocalHost, 6374);
}

void TApplication::connected()
{
    QDateTime time = QDateTime::currentDateTime();
    cout << time.toString().toStdString() << ": client connected" << endl;
}

void TApplication::disconnected()
{
    QDateTime time = QDateTime::currentDateTime();
    cout << time.toString().toStdString() << ": client disconnected" << endl;
}

