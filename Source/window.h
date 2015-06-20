#ifndef WINDOW_H
#define WINDOW_H

#include <QtWebEngineWidgets>
#include <QMainWindow>

namespace Ui
{
    class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window(QWidget* = 0);
    ~Window();

private:
    Ui::Window *ui;
    QWebEngineView* view;
};

#endif
