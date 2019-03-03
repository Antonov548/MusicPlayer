#pragma once

#include <QWidget>
#include <QGridLayout>
#include <QMouseEvent>
#include <QDebug>

class CustomWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CustomWidget(QWidget *parent = nullptr);
    void setMainLayout(QLayout *layout);

public slots:

private:
    QWidget back_widget;

    void createUI();
};
