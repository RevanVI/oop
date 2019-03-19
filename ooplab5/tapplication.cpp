#include "tapplication.h"

TApplication::TApplication(int argc, char **argv): QApplication (argc, argv)
{
    socket = new QUdpSocket(this);
    bool ok = socket->bind(QHostAddress::LocalHost, 22022);
    connect(socket, SIGNAL(readyRead()), this, SLOT(receive()));

    interface = new Tinterface();
    connect(interface, SIGNAL(buttonClicked()), this, SLOT(send()));
    interface->show();
}

TApplication::~TApplication()
{
    delete socket;
    delete interface;
}

void TApplication::send()
{
    number* val = interface->getData();

    QByteArray data;
    QDataStream str(&data, QIODevice::WriteOnly);
    str.setVersion(QDataStream::Qt_5_3);
    for (int i = 0; i < 4; ++i)
        str << val[i];
    int bytes = socket->writeDatagram(data, QHostAddress::LocalHost, 6374);
}

void TApplication::receive()
{
    number val[3];
    while (socket->hasPendingDatagrams())
    {
        QByteArray* data = new QByteArray();
        QHostAddress addr;
        ushort port;
        data->resize(socket->pendingDatagramSize());
        socket->readDatagram(data->data(), data->size(), &addr, &port);

        QDataStream str(data, QIODevice::ReadOnly);
        str.setVersion(QDataStream::Qt_5_3);
        for (int i = 0; i < 3; ++i)
            str >> val[i];
        data->clear();
        delete data;
    }
    interface->setData(val);
}



