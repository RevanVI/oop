#include "client.h"
#include "ui_client.h"

client::client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);
    socket = new QUdpSocket(this);
    socket->bind(6374);
}

client::~client()
{
    delete ui;
    delete socket;
}


void client::receive()
{
    QByteArray data;
    do {
        data.resize(socket->pendingDatagramSize());
        socket->readDatagram(data.data(), data.size());
    } while(socket->hasPendingDatagrams());

    QDataStream str(&data, QIODevice::ReadOnly);
    str.setVersion(QDataStream::Qt_5_9);
    number* roots = new number[2];
    str >> roots[0] >> roots[1];
    QLabel* lbl1 = findChild<QLabel*>("label");
    lbl1->setText(QString::number(roots[0]));
}
void client::send()
{

}
