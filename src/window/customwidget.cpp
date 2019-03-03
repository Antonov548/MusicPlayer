#include "customwidget.h"

CustomWidget::CustomWidget(QWidget *parent) : QWidget(parent)
{
    createUI();
}

void CustomWidget::setMainLayout(QLayout *layout)
{
    back_widget.setLayout(layout);
}

void CustomWidget::createUI()
{
    //tracking mouse move on widget and backgroud
    setMouseTracking(true);
    back_widget.setStyleSheet("background-color: rgb(19, 19, 19)");
    back_widget.setMouseTracking(true);

    QGridLayout *grid_layout = new QGridLayout(this);
    grid_layout->setMargin(0);
    grid_layout->addWidget(&back_widget, 0, 0, 1, 1);

}
