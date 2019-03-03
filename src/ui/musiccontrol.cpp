#include "musiccontrol.h"

MusicControl::MusicControl(QWidget *parent) : QWidget(parent), is_play(false)
{
    createUI();

    connect(&btn_play, &QPushButton::clicked, this, [=](){changePlayStatus(!is_play);});
    connect(&slider_animation, &QPropertyAnimation::finished, this, [=](){changePlayStatus(false);});
}

void MusicControl::changePlayStatus(bool isPlay)
{
    is_play = isPlay;
    if(is_play){
        if(slider_animation.state() == QAbstractAnimation::State::Stopped)
            slider_animation.start();
        else if(slider_animation.state() == QAbstractAnimation::State::Paused)
            slider_animation.resume();
        btn_play.setIcon(QIcon(":/icons/pause.png"));
    }else{
        if(slider_animation.state() == QAbstractAnimation::State::Running)
            slider_animation.pause();
        btn_play.setIcon(QIcon(":/icons/play.png"));
    }
}

void MusicControl::createUI()
{
    setMouseTracking(true);
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    setFixedHeight(90);

    btn_play.setObjectName("btn_play");
    btn_play.setFixedSize(30,30);
    btn_play.setIcon(QIcon(":/icons/play.png"));
    btn_play.setIconSize(QSize(30,30));

    btn_next.setObjectName("btn_next");
    btn_next.setFixedSize(30,30);
    btn_next.setIcon(QIcon(":/icons/next.png"));
    btn_next.setIconSize(QSize(30,30));

    btn_prev.setObjectName("btn_prev");
    btn_prev.setFixedSize(30,30);
    btn_prev.setIcon(QIcon(":/icons/prev.png"));
    btn_prev.setIconSize(QSize(30,30));

    prog_slider.setFixedWidth(250);
    prog_slider.setOrientation(Qt::Horizontal);

    QSpacerItem* spacer_l = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    QSpacerItem* spacer_r = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

    QHBoxLayout *h_layout = new QHBoxLayout(&back_widget);
    h_layout->addWidget(&btn_prev);
    h_layout->addWidget(&btn_play);
    h_layout->addWidget(&btn_next);
    h_layout->addItem(spacer_l);
    h_layout->addWidget(&prog_slider);
    h_layout->addItem(spacer_r);
    h_layout->setSpacing(0);
    h_layout->setContentsMargins(20,0,0,0);

    QGridLayout *grd_layout = new QGridLayout(this);
    back_widget.setStyleSheet("QWidget{"
                              "background-color: rgb(41,41,41)"
                              "}"
                              "QPushButton#btn_play{"
                              "border-style: none;"
                              "border-radius: 15px"
                              "}"
                              "QPushButton#btn_play:hover{"
                              "background-color: rgb(50,50,50)"
                              "}"
                              "QPushButton#btn_next{"
                              "border-style: none;"
                              "border-radius: 15px"
                              "}"
                              "QPushButton#btn_next:hover{"
                              "background-color: rgb(50,50,50)"
                              "}"
                              "QPushButton#btn_prev{"
                              "border-style: none;"
                              "border-radius: 15px"
                              "}"
                              "QPushButton#btn_prev:hover{"
                              "background-color: rgb(50,50,50)"
                              "}");

    grd_layout->setMargin(0);
    grd_layout->addWidget(&back_widget);

    slider_animation.setTargetObject(&prog_slider);
    slider_animation.setPropertyName("value");
    slider_animation.setStartValue(0);
    slider_animation.setEndValue(100);
    slider_animation.setDuration(5000);
}

