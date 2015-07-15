#include "player.h"

Player::Player() : player(0, QMediaPlayer::VideoSurface)
{
    i1 = style()->standardIcon(QStyle::SP_MediaPlay);
    i2 = style()->standardIcon(QStyle::SP_MediaPause);
    open.setText("Открыть файл");
    play.setIcon(i1);
    slider.setOrientation(Qt::Horizontal);
    controls.addWidget(&open);
    controls.addWidget(&play);
    controls.addWidget(&slider);
    common.addWidget(&video);
    common.addLayout(&controls);
    player.setVideoOutput(&video);
    setLayout(&common);
    connect(&open,SIGNAL(released()),SLOT(OpenFile()));
    connect(&play, SIGNAL(released()), SLOT(Play()));
    connect(&slider, SIGNAL(sliderMoved(int)), SLOT(Position(int)));
    connect(&player, SIGNAL(stateChanged(QMediaPlayer::State)),
            SLOT(StateChanged(QMediaPlayer::State)));
    connect(&player, SIGNAL(positionChanged(qint64)),
            SLOT(PositionChanged(qint64)));
    connect(&player, SIGNAL(durationChanged(qint64)),
            SLOT(DurationChanged(qint64)));
}

void Player::OpenFile()
{
    QString fileName = QFileDialog::getOpenFileName();
    player.setMedia(QUrl::fromLocalFile(fileName));
}

void Player::Play()
{
    if(player.state() == QMediaPlayer::PlayingState)
        player.pause();
    else player.play();
}

void Player::StateChanged(QMediaPlayer::State state)
{
    QIcon ico = state == QMediaPlayer::PlayingState ? i2 : i1;
    play.setIcon(ico);
}

void Player::PositionChanged(qint64 position)
{
    slider.setValue(position);
}

void Player::DurationChanged(qint64 duration)
{
    slider.setRange(0, duration);
}

void Player::Position(int position)
{
    player.setPosition(position);
}