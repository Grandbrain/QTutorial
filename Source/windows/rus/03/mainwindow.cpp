#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Reset();
    connect(ui->start, SIGNAL(released()), SLOT(Start()));
    connect(ui->stop, SIGNAL(released()), SLOT(Stop()));
    connect(ui->reset, SIGNAL(released()), SLOT(Reset()));
    connect(&timer, SIGNAL(timeout()), SLOT(Time ()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Start()
{
    timer.start();
}

void MainWindow::Stop()
{
    timer.stop();
}

void MainWindow::Reset()
{
    format = "hh:mm:ss:zzz";
    time = QTime(0, 0);
    QString text;
    text = time.toString(format);
    ui->lcd->display(text);
}

void MainWindow::Time()
{
    time = time.addMSecs(1);
    QString text;
    text = time.toString(format);
    ui->lcd->display(text);
}