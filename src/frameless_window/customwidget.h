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
    void setMainLayout(QLayout* layout);

    enum Direction{
        Left,
        Bottom,
        Right,
        None
    };

signals:
    void signalResize(Direction direct, int dx);

public slots:

private:
    QWidget back_widget;
    bool is_pressed;
    QPoint press_position;
    Direction curr_direction;

    Direction getDirection(QMouseEvent* event);
    void createUI();

protected:
    virtual void mousePressEvent(QMouseEvent* event) override;
    virtual void mouseReleaseEvent(QMouseEvent* event) override;
    virtual void mouseMoveEvent(QMouseEvent* event) override;
};
