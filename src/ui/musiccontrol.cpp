#include "musiccontrol.h"

MusicControl::MusicControl(QWidget *parent) : QWidget(parent), is_play(false)
{
    createUI();

    connect(&btn_play, &QPushButton::clicked, this, &MusicControl::pauseClicked);
}

void MusicControl::pauseClicked()
{
    is_play = !is_play;
    if(is_play){
        btn_play.setIcon(QIcon(":/icons/play.png"));
    }else{
        btn_play.setIcon(QIcon(":/icons/pause.png"));
    }
}

void MusicControl::createUI()
{
    setMouseTracking(true);
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    setMinimumHeight(100);

    btn_play.setObjectName("btn_play");
    btn_play.setFixedSize(44,44);
    btn_play.setIcon(QIcon(":/icons/pause.png"));
    btn_play.setIconSize(QSize(30,30));
    btn_next.setObjectName("btn_next");
    btn_next.setFixedSize(44,44);
    btn_next.setIcon(QIcon(":/icons/next.png"));
    btn_next.setIconSize(QSize(30,30));
    btn_prev.setObjectName("btn_prev");
    btn_prev.setFixedSize(44,44);
    btn_prev.setIcon(QIcon(":/icons/prev.png"));
    btn_prev.setIconSize(QSize(30,30));

    QSpacerItem* spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    QHBoxLayout *h_layout = new QHBoxLayout(&back_widget);
    h_layout->addWidget(&btn_prev);
    h_layout->addWidget(&btn_play);
    h_layout->addWidget(&btn_next);
    h_layout->addItem(spacer);
    h_layout->setSpacing(0);
    h_layout->setContentsMargins(20,0,0,0);

    QGridLayout *grd_layout = new QGridLayout(this);
    back_widget.setStyleSheet("QWidget{"
                              "background-color: rgb(41,41,41)"
                              "}"
                              "QPushButton#btn_play{"
                              "border-style: none;"
                              "border-radius: 22px"
                              "}"
                              "QPushButton#btn_play:hover{"
                              "background-color: rgb(50,50,50)"
                              "}"
                              "QPushButton#btn_next{"
                              "border-style: none;"
                              "border-radius: 22px"
                              "}"
                              "QPushButton#btn_next:hover{"
                              "background-color: rgb(50,50,50)"
                              "}"
                              "QPushButton#btn_prev{"
                              "border-style: none;"
                              "border-radius: 22px"
                              "}"
                              "QPushButton#btn_prev:hover{"
                              "background-color: rgb(50,50,50)"
                              "}");

    grd_layout->setMargin(0);
    grd_layout->addWidget(&back_widget);
}

