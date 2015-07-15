#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>

class GLWidget : public QGLWidget
{
    Q_OBJECT

protected:
    void initializeGL();
    void paintGL();
    void resizeGL (int, int);
};

#endif