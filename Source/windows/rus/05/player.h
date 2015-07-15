#ifndef PLAYER_H
#define PLAYER_H

#include <QtGui>
#include <QtWidgets>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget>

class Player : public QWidget
{
    Q_OBJECT

public:
    Player();

private slots:
    void OpenFile();
    void Play();
    void StateChanged(QMediaPlayer::State);
    void PositionChanged(qint64);
    void DurationChanged(qint64);
    void Position(int);

private:
    QMediaPlayer player;
    QSlider slider;
    QPushButton play;
    QPushButton open;
    QVideoWidget video;
    QHBoxLayout controls;
    QVBoxLayout common;
    QIcon i1;
    QIcon i2;
};

#endif