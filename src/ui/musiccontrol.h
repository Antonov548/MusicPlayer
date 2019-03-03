#pragma once

#include <QWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QPushButton>
#include <QMouseEvent>
#include <QSlider>
#include <QPropertyAnimation>

class MusicControl : public QWidget
{
    Q_OBJECT
public:
    explicit MusicControl(QWidget *parent = nullptr);

signals:

public slots:
    void changePlayStatus(bool isPlay);

private:
    QWidget back_widget;
    QPushButton btn_play;
    QPushButton btn_next;
    QPushButton btn_prev;
    QSlider prog_slider;
    QPropertyAnimation slider_animation;

    bool is_play;

    void createUI();
};
