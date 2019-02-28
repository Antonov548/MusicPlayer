#include "customwidget.h"

CustomWidget::CustomWidget(QWidget *parent) : QWidget(parent), curr_direction(None)
{
    createUI();
}

void CustomWidget::setMainLayout(QLayout *layout)
{
    back_widget.setLayout(layout);
}

CustomWidget::Direction CustomWidget::getDirection(QMouseEvent *event)
{
    QPointF position = event->pos();
    int x_rect = back_widget.x();
    int y_rect = back_widget.y();
    int width_rect = back_widget.width();
    int height_rect = back_widget.height();

    //rects for mouse arrows
    QRectF rectBottom(x_rect + 9, y_rect + height_rect - 8, width_rect - 18, 8);
    QRectF rectLeft(x_rect, y_rect + 8, 8, height_rect - 18);
    QRectF rectRight(x_rect + width_rect - 8, y_rect + 9, 8, height_rect - 18);

    if (rectBottom.contains(position)) {
        back_widget.setCursor(Qt::SizeVerCursor);
        return Bottom;
    } else if (rectLeft.contains(position)) {
        back_widget.setCursor(Qt::SizeHorCursor);
        return Left;
    } else if (rectRight.contains(position)) {
        back_widget.setCursor(Qt::SizeHorCursor);
        return Right;
    }
    back_widget.setCursor(Qt::ArrowCursor);
    return None;
}

void CustomWidget::createUI()
{
    //tracking mouse move on widget and backgroud
    setMouseTracking(true);
    back_widget.setStyleSheet("background-color: rgb(27, 27, 27)");
    back_widget.setMouseTracking(true);

    QGridLayout *grid_layout = new QGridLayout(this);
    grid_layout->setMargin(0);
    grid_layout->addWidget(&back_widget, 0, 0, 1, 1);
}

void CustomWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        is_pressed = true;
        press_position = event->pos();
        curr_direction = getDirection(event);
    }
}

void CustomWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        is_pressed = false;
        curr_direction = None;
    }
}

void CustomWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(is_pressed && curr_direction != None){
        int d_distance;
        switch (curr_direction) {
        case Right:
            d_distance = event->x() - press_position.x();
            if(d_distance > 0 && event->x() < width()){
                press_position = event->pos();
                break;
            }
            emit signalResize(curr_direction, d_distance);
            press_position = event->pos();
            break;
        case Left:
            d_distance = press_position.x() - event->x();
            if(d_distance > 0 && event->x() > 0){
                press_position = event->pos();
                break;
            }
            emit signalResize(curr_direction, d_distance);
            break;
        case Bottom:
            d_distance = event->y() - press_position.y();
            if(d_distance > 0 && event->y() < height()){
                press_position = event->pos();
                break;
            }
            emit signalResize(curr_direction, d_distance);
            press_position = event->pos();
            break;
        case None:
            break;
        }
    }
    else {
        getDirection(event);
    }
}
