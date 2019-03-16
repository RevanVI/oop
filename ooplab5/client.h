#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <QtNetwork/QtNetwork>
#include <QDataStream>
#include <QtWidgets>
#include "number.h"

namespace Ui {
class client;
}

class client : public QWidget
{
    Q_OBJECT
private:
    Ui::client *ui;
    QUdpSocket* socket;

public:
    explicit client(QWidget *parent = nullptr);
    ~client();

public slots:
    void receive();
    void send();

};

#endif // CLIENT_H
