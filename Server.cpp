//
// Created by mamzi on 4/18/17.
//

#include "Server.h"

Server::Server()
{
    addr = new QHostAddress("127,0,0,1");
    port = 8000;
    serv = new QTcpServer();
    serv->listen(*addr, port);
    shell = new QTextEdit;
    shell->show();
    shell->append("Server Started listening at localhost:8000");
    members = new QList<QTcpSocket*>();
    connect(serv, SIGNAL(newConnection()), this, SLOT(mk_connection()));
}

void Server::mk_connection()
{
    QTcpSocket *member = serv->nextPendingConnection();
    members->append(member);
    connect(member, SIGNAL(readyRead()), this, SLOT(new_message()));
    shell->append("New Connection");
}

void Server::new_message()
{
    for(QTcpSocket* sender : *members)
    {
        if(sender->bytesAvailable() == 0)
            continue;
        QByteArray data = sender->readAll();
        shell->append("New Message");
        for(QTcpSocket* receiver : *members)
            if(sender != receiver)
                receiver->write(data);
    }
}