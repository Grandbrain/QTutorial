#include "mainwindow.h"

MainWindow::MainWindow() : QWidget()
{
    quint16 port = 12002;
    button.setText("Новое сообщение");
    server.listen(QHostAddress::Any, port);
    client.connectToHost(QHostAddress::LocalHost, port);
    layout.addWidget(&button);
    layout.addWidget(&list);
    setLayout(&layout);
    resize(640, 480);
    connect(&button, SIGNAL(released()), SLOT(SendToServer()));
    connect(&server, SIGNAL(newConnection()), SLOT(Connection()));
    connect(&client, SIGNAL(readyRead()), SLOT(ClientRead()));
}

void MainWindow::Connection()
{
    QTcpSocket* s = server.nextPendingConnection();
    connect(s, SIGNAL(readyRead()), SLOT(SendToClient()));
}

void MainWindow::SendToServer()
{
    client.write(QString("Привет, сервер!").toUtf8());
}

void MainWindow::SendToClient()
{
    QTcpSocket* s = (QTcpSocket*)sender();
    QString t = QTime::currentTime().toString();
    QString m = s->readAll();
    list.addItem(t + " Клиент: " + m);
    s->write(QString("Привет, клиент!").toUtf8());
}

void MainWindow::ClientRead()
{
    QString t = QTime::currentTime().toString();
    list.addItem(t + " Сервер: " + client.readAll());
}