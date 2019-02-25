#pragma once

#include <QWidget>
#include <QPushButton>
#include <QSpacerItem>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QLabel>
#include <QFont>

#include <QDebug>

class CustomHeader : public QWidget
{
    Q_OBJECT
public:
    explicit CustomHeader(QWidget *parent = nullptr);

signals:
    void signalClose();
    void signalRelease();
    void signalMove(int dx, int dy);
    void changeWindowState(Qt::WindowState state);

public slots:

private:
    void createUI();

    QWidget back_widget;

    QPushButton btn_close;
    QPushButton btn_hide;
    QPushButton btn_fullscreen;

    bool is_pressed;
    QPoint press_position;

protected:
    virtual void mousePressEvent(QMouseEvent* event) override;
    virtual void mouseReleaseEvent(QMouseEvent* event) override;
    virtual void mouseMoveEvent(QMouseEvent* event) override;
};
