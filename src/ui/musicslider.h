#pragma once

#include <QSlider>
#include <QDebug>
#include <QMouseEvent>

class MusicSlider : public QSlider
{
    Q_OBJECT
public:
    MusicSlider();

private:
    void createUI();

protected:
    virtual void mousePressEvent(QMouseEvent *e) override;
};

