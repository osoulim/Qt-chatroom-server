//
// Created by mamzi on 4/18/17.
//

#ifndef QTSERVER_SERVER_H
#define QTSERVER_SERVER_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include <QTextEdit>
#include <QList>


class Server: public QWidget
{
    Q_OBJECT
    public:
        Server();
    private:
        QTcpServer *serv;
        QTextEdit *shell;
        QList<QTcpSocket*> *members;
        QHostAddress *addr;
        quint16 port;
    public slots:
        void mk_connection();
        void new_message();
};


#endif //QTSERVER_SERVER_H
