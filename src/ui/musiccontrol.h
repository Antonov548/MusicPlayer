#pragma once

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QMouseEvent>

class MusicControl : public QWidget
{
    Q_OBJECT
public:
    explicit MusicControl(QWidget *parent = nullptr);

signals:

public slots:

private:
    QWidget back_widget;

    void createUI();
};
