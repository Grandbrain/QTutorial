#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QtSql>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();

private slots:
    void Connect();

private:
    QVBoxLayout layout;
    QPushButton button;
    QLineEdit login;
    QLineEdit password;
    QTableView view;
};

#endif