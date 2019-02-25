#include "customheader.h"

CustomHeader::CustomHeader(QWidget *parent) : QWidget(parent), is_pressed(false)
{
    createUI();

    connect(&btn_close, &QPushButton::clicked, this, [=](){emit signalClose();});
    connect(&btn_hide, &QPushButton::clicked, this, [=](){emit changeWindowState(Qt::WindowState::WindowMinimized);});
}

void CustomHeader::createUI()
{
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);

    btn_hide.setObjectName("btnHide");
    btn_close.setObjectName("btnClose");
    btn_fullscreen.setObjectName("btnFullScreen");
    btn_hide.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    btn_close.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    btn_fullscreen.setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    setStyleSheet("QWidget{"
                  "background-color: rgb(45, 45, 45)"
                  "}"
                  "QPushButton{"
                  "border: none;"
                  "border-width: 0px;"
                  "}"
                  "QPushButton#btnHide:hover{"
                  "background-color: rgb(58,58,58)"
                  "}"
                  "QPushButton#btnFullScreen:hover{"
                  "background-color: rgb(58,58,58)"
                  "}"
                  "QPushButton#btnClose:hover{"
                  "background-color: rgb(171,34,48)"
                  "}");

    QSpacerItem* header_spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    QGridLayout* grd_header_layout = new QGridLayout(this);
    QHBoxLayout* hor_header_layout = new QHBoxLayout(&back_widget);

    //window header layout
    hor_header_layout->addItem(header_spacer);
    hor_header_layout->addWidget(&btn_hide);
    hor_header_layout->addWidget(&btn_fullscreen);
    hor_header_layout->addWidget(&btn_close);
    hor_header_layout->setMargin(0);
    hor_header_layout->setSpacing(0);

    grd_header_layout->setMargin(0);
    grd_header_layout->addWidget(&back_widget, 0, 0, 1, 1);
}

void CustomHeader::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        is_pressed = true;
        press_position = event->pos();
    }
}

void CustomHeader::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        is_pressed = false;
        signalRelease();
    }
}

void CustomHeader::mouseMoveEvent(QMouseEvent *event)
{
    if(is_pressed){
        emit signalMove(event->x() - press_position.x(), event->y() - press_position.y());
    }
}
