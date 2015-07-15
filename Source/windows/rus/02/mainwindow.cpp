#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Главное окно");
    setLayout(&layout);
    slider.setRange(0, 100);
    spinBox.setRange(0, 100);
    slider.setOrientation(Qt::Horizontal);
    button.setText("Сообщение");
    layout.setMargin(5);
    layout.setSpacing(5);
    layout.addWidget(&spinBox);
    layout.addWidget(&slider);
    layout.addWidget(&button);

    connect(&button, SIGNAL(released()), this, SLOT(ShowMessage()));
    connect(&slider, SIGNAL(valueChanged(int)), &spinBox, SLOT(setValue(int)));
    connect(&spinBox, SIGNAL(valueChanged(int)), &slider, SLOT(setValue(int)));
}

void MainWindow::ShowMessage()
{
    int value = spinBox.value();
    QMessageBox::information(this, "Сообщение",
        "Вы выбрали " + QString::number(value));
}
