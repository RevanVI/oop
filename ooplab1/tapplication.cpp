#include "tapplication.h"


TApplication::TApplication(int argc, char **argv): QApplication (argc, argv)
{
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::LocalHost, 6374);
    connect(socket, SIGNAL(readyRead()), this, SLOT(receive()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(onSocketError(QAbstractSocket::SocketError)));
    connect(this, SIGNAL(dataReceived()), this, SLOT(calculate()));
    connect(this, SIGNAL(calculated()), this, SLOT(send()));

}

TApplication::~TApplication()
{
    delete socket;
}

void TApplication::receive()
{
    while (socket->hasPendingDatagrams())
    {
        QByteArray* data = new QByteArray();
        QHostAddress addr;
        ushort port;
        data->resize(socket->pendingDatagramSize());
        socket->readDatagram(data->data(), data->size(), &addr, &port);

        QTime time = QTime::currentTime();
        QDataStream str(data, QIODevice::ReadOnly);
        str.setVersion(QDataStream::Qt_5_3);
        for (int i = 0; i < 4; ++i)
            str >> val[i];
        cout << time.toString().toStdString() << ": receive message, port " << port << endl;
        data->clear();
        delete data;
        emit dataReceived();
    }
}

void TApplication::calculate()
{
    TPolynom* polynom = new TPolynom(val[0], val[1], val[2]);
    polynom->findRoots();
    polynom->findSolution(val[3]);

    val[0] = polynom->get_roots()[0];
    val[1] = polynom->get_roots()[1];
    val[2] = polynom->get_solution();

    emit calculated();
}

void TApplication::send()
{
    QByteArray data;
    QDataStream str(&data, QIODevice::WriteOnly);
    str.setVersion(QDataStream::Qt_5_3);
    for (int i = 0; i < 3; ++i)
        str << val[i];
    QTime time = QTime::currentTime();
    socket->writeDatagram(data, QHostAddress::LocalHost, 22022);
    cout << time.toString().toStdString() << ": send message " << endl;
}

void TApplication::onSocketError(QAbstractSocket::SocketError err)
{
    qDebug()<<"socket error occured and the error is : " << err;
}
