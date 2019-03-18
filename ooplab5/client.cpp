#include "client.h"
#include "ui_client.h"

client::client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);
    socket = new QUdpSocket(this);
    //socket->bind(QHostAddress::LocalHost, 7755);
    //if (socket->state() == socket->BoundState)
    //connect(socket, SIGNAL(readyRead()), this, SLOT(receive()));

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(send()));
    //QTimer* timer = new QTimer(this);
    //timer->setInterval(1000);
    //timer->start();
    //connect(timer, SIGNAL(timeout()), this, SLOT(send()));
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
        qDebug() << "read\n";
    } while(socket->hasPendingDatagrams());

    QDataStream str(&data, QIODevice::ReadOnly);
    str.setVersion(QDataStream::Qt_5_3);
    number* roots = new number[2];
    str >> roots[0] >> roots[1];
    ui->label->setText(QString::number(roots[0]));
    qDebug() << roots[0];
}

void client::send()
{
    QByteArray data;
    QDataStream str(&data, QIODevice::WriteOnly);
    str.setVersion(QDataStream::Qt_5_3);
    number* roots = new number[2];
    roots[0] = 2;
    roots[1] = 2;
    str << roots[0] << roots[1];
    int byres = socket->writeDatagram(data, QHostAddress("127.0.0.1"), 7755);
    ++roots[0];
}

