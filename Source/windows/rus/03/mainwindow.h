#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* = 0);
    ~MainWindow();

public slots:
    void Start();
    void Stop();
    void Reset();
    void Time();

private:
    Ui::MainWindow *ui;
    QTime time;
    QTimer timer;
    QString format;
};
#endif