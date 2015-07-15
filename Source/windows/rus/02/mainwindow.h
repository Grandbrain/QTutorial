#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QSlider>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QMessageBox>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget* = 0);

private slots:
    void ShowMessage();

private:
    QSpinBox spinBox;
    QSlider slider;
    QPushButton button;
    QHBoxLayout layout;
};

#endif