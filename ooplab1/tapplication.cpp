#include "tapplication.h"

TApplication::TApplication(int argc, char **argv): QApplication (argc, argv)
{
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::LocalHost, 7755);
    connect(socket, SIGNAL(readyRead()), this, SLOT(received()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(onSocketError(QAbstractSocket::SocketError)));
}

TApplication::~TApplication()
{
    delete socket;
}

void TApplication::received()
{
    while (socket->hasPendingDatagrams())
    {
        QByteArray* data = new QByteArray();
        QHostAddress addr;
        ushort port;
        data->resize(socket->pendingDatagramSize());
        socket->readDatagram(data->data(), data->size(), &addr, &port);

        QTime time = QTime::currentTime();
        QDataStream str(data, QIODevice::ReadWrite);
        str.setVersion(QDataStream::Qt_5_3);

        number val1, val2;
        str >> val1 >> val2;
        //QString* addrStr = new QString(addr.toString());
        cout << time.toString().toStdString() << ": receive message " << val1 << " " << " " << port << endl;
        data->clear();
        delete data;
        //delete addrStr;
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
