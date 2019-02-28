#include "musiccontrol.h"

MusicControl::MusicControl(QWidget *parent) : QWidget(parent)
{
    createUI();
}

void MusicControl::createUI()
{
    setAttribute(Qt::WA_TransparentForMouseEvents);
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    QGridLayout *grd_layout = new QGridLayout(this);

    setMinimumHeight(100);
    back_widget.setStyleSheet("background-color: rgb(41,41,41)");
    grd_layout->setMargin(0);
    grd_layout->addWidget(&back_widget);
}

