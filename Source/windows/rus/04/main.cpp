#include "glwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GLWidget w;
    w.resize(640, 480);
    w.show();
    return a.exec();
}
