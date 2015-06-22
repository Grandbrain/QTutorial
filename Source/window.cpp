#include "window.h"
#include "ui_window.h"

Window::Window(QWidget *parent) : QMainWindow(parent), ui(new Ui::Window)
{
    ui->setupUi(this);

    QUrl url = QUrl::fromLocalFile("D:\\viewer\\viewer.html");
    view = new QWebEngineView(this);
    view->load(url);
    ui->gridLayout_3->setMargin(0);
    ui->gridLayout_3->addWidget(view);
}

Window::~Window()
{
    delete ui;
}