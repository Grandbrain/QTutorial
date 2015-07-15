#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();

private slots:
    void Connection();
    void SendToServer();
    void SendToClient();
    void ClientRead();

private:
    QVBoxLayout layout;
    QListWidget list;
    QPushButton button;
    QTcpServer server;
    QTcpSocket client;
};

#endif