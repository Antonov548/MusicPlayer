#include "musicslider.h"

MusicSlider::MusicSlider()
{
    createUI();

    connect(this, &QSlider::sliderMoved, this, [=](int value){qDebug() << value;});
}

void MusicSlider::createUI()
{
    setStyleSheet("QSlider{"
                  "background: transparent;"
                  "height: 18px"
                  "}"
                  "QSlider::groove:horizontal{"
                  "height: 3px;"
                  "background-color: rgb(83,83,83);"
                  "border-radius: 1px;"
                  "}"
                  "QSlider::handle:horizontal{"
                  "width: 12px;"
                  "background-color: rgb(27,162,228);"
                  "margin-top: -5px;"
                  "margin-bottom: -5px;"
                  "border-radius: 5px;"
                  "}"
                  "QSlider::sub-page:horizontal {"
                  "background: qlineargradient(x1: 0, y1: 0.2, x2: 1, y2: 1,"
                  "stop: 0 rgb(78,193,249) stop: 1 rgb(27,162,228));"
                  "border-radius: 1px;"
                  "}");
}

void MusicSlider::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        setValue(int((float(e->x())/float(width()))*100));
    }
    QSlider::mousePressEvent(e);
}
