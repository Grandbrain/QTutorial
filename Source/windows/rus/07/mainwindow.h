#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGridLayout>
#include <QApplication>
#include <QLCDNumber>
#include <QWidget>
#include <QThread>
#include <QTimer>

class Thread : public QThread
{
    Q_OBJECT

signals:
    void Finished();
    void CurrentValue(int);

private slots:
    void run();
    void NextValue();

private:
    int value;
};

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();

private:
    QLCDNumber lcd;
    QGridLayout layout;
    Thread thread;
};

#endif