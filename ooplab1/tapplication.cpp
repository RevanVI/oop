#include "tapplication.h"

TApplication::TApplication(int argc, char **argv): QCoreApplication (argc, argv)
{
    socket = new QUdpSocket();
    bool state = socket->bind(QHostAddress::LocalHost, 7755);
    //connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    //connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    //if (socket->state() == socket->BoundState)
    //   connect(socket, SIGNAL(readyRead()), this, SLOT(received()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(onSocketError(QAbstractSocket::SocketError)));
    QTimer* timer = new QTimer(this);
    timer->setInterval(500);
    timer->start();
    connect(timer, SIGNAL(timeout()), this, SLOT(received()));
    //received();
}

TApplication::~TApplication()
{
    delete socket;
}

void TApplication::received()
{
    if (socket->hasPendingDatagrams())
    {
        QByteArray* data = new QByteArray();
        QHostAddress addr;
        ushort port;
        data->resize(socket->pendingDatagramSize());
        socket->readDatagram(data->data(), data->size(), &addr, &port);

        //QDateTime time = QDateTime::currentDateTime();
        QDataStream str(data, QIODevice::ReadWrite);
        str.setVersion(QDataStream::Qt_5_3);

        number val1, val2;
        str >> val1 >> val2;
        QString addrStr = addr.toString();
        cout << "receive message " << val1 << port << endl;
        delete data;
    }
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

void TApplication::onSocketError(QAbstractSocket::SocketError err)
{
    qDebug()<<"socket error occured and the error is : " << err;
}
