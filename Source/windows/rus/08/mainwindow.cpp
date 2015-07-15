#include "mainwindow.h"

MainWindow::MainWindow() : QWidget()
{
    button.setText("Подключить");
    password.setEchoMode(QLineEdit::Password);
    password.setPlaceholderText("Введите пароль");
    password.setAlignment(Qt::AlignCenter);
    login.setPlaceholderText("Введите логин");
    login.setAlignment(Qt::AlignCenter);
    setLayout(&layout);
    resize(640, 480);
    connect(&button, SIGNAL(released()), SLOT(Connect()));
    layout.addWidget(&login);
    layout.addWidget(&password);
    layout.addWidget(&button);
    layout.addWidget(&view);
}

void MainWindow::Connect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("postgres");
    db.setUserName(login.text());
    db.setPassword(password.text());
    db.open();
    QSqlTableModel* m = new QSqlTableModel;
    m->setTable("books");
    m->select();
    view.setModel(m);
}