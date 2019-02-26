#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QGraphicsDropShadowEffect>
#include <QGraphicsOpacityEffect>
#include "customheader.h"
#include "customwidget.h"

class CustomWindow : public QWidget
{
    Q_OBJECT
public:
    explicit CustomWindow(QWidget *parent = nullptr);
    void setContent(QLayout* layout);

signals:

public slots:

private:
    CustomHeader wgt_header;
    CustomWidget wgt_content;

    QGridLayout grd_main_layout;

    QGraphicsDropShadowEffect shadow;

    void move(int dx, int dy);
    void setCustomWindowState(Qt::WindowState state);
    void createUI();
    void windowResize(CustomWidget::Direction direct, int dx);
};