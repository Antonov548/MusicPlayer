#pragma once

#include <QObject>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QPushButton>

#include "musiccontrol.h"

class MainLayout : public QObject
{
    Q_OBJECT
public:
    MainLayout();
    QLayout *getLayout();

signals:

public slots:

private:
    QGridLayout main_layout;
    QVBoxLayout v_layout;
    MusicControl music_control;

    void createUI();
};

