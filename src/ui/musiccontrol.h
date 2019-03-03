#pragma once

#include <QWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QPushButton>
#include <QMouseEvent>

class MusicControl : public QWidget
{
    Q_OBJECT
public:
    explicit MusicControl(QWidget *parent = nullptr);

signals:

public slots:
    void pauseClicked();

private:
    QWidget back_widget;
    QPushButton btn_play;
    QPushButton btn_next;
    QPushButton btn_prev;

    bool is_play;

    void createUI();
};
