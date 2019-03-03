#include "customwindow.h"

CustomWindow::CustomWindow(QWidget *parent) : QWidget(parent), curr_direction(None)
{
    createUI();

    connect(&wgt_header, &CustomHeader::signalClose, this, &QWidget::close);
    connect(&wgt_header, &CustomHeader::changeWindowState, this, &CustomWindow::setCustomWindowState);
    connect(&wgt_header, &CustomHeader::signalMove, this, &CustomWindow::move);
    connect(&opacity_animation, &QPropertyAnimation::finished, this, [=](){setWindowState(Qt::WindowState::WindowMinimized); opacity.setOpacity(1);});
}

void CustomWindow::setContent(QLayout *layout)
{
    wgt_content.setMainLayout(layout);
}

void CustomWindow::move(int dx, int dy)
{
    setGeometry(x() + dx, y() + dy, width(), height());
}

void CustomWindow::setCustomWindowState(Qt::WindowState state)
{
    switch (state) {
    case Qt::WindowState::WindowMinimized:
        opacity_animation.start();
        break;
    default:
        break;
    }
}

void CustomWindow::createUI()
{
    setMouseTracking(true);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setMinimumSize(500,500);
    setObjectName("custom_window");

    //main widget + header widget
    //QGridLayout* grd_custom_layout = new QGridLayout(this);
    grd_layout.setMargin(0);
    QVBoxLayout* ver_main_layout = new QVBoxLayout;
    ver_main_layout->addWidget(&wgt_header);
    ver_main_layout->addWidget(&wgt_content);
    ver_main_layout->setMargin(0);
    ver_main_layout->setSpacing(0);
    grd_layout.addLayout(ver_main_layout, 0, 0, 1, 1);

    setLayout(&grd_layout);

    //add opacity
    opacity.setOpacity(1.0);
    setGraphicsEffect(&opacity);

    //animation for minimize
    opacity_animation.setTargetObject(&opacity);
    opacity_animation.setPropertyName("opacity");
    opacity_animation.setDuration(200);
    opacity_animation.setStartValue(1);
    opacity_animation.setEndValue(0);
}
