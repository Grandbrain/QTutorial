#include "mainwindow.h"

void Thread::run()
{
    value = 10;
    QTimer timer;
    connect(&timer, SIGNAL(timeout()),SLOT(NextValue()));
    timer.start(1000);
    exec();
}

void Thread::NextValue()
{
    emit CurrentValue(--value);
    if(!value) emit Finished();
}

MainWindow::MainWindow() : QWidget()
{
    connect(&thread, SIGNAL(CurrentValue(int)), &lcd, SLOT(display(int)));
    connect(&thread, SIGNAL(Finished()), qApp, SLOT(quit()));
    lcd.display(10);
    lcd.setSegmentStyle(QLCDNumber::Filled);
    layout.addWidget(&lcd);
    setLayout(&layout);
    resize(640, 480);
    thread.start();
}