#pragma once

#include <QObject>
#include <QGridLayout>
#include <QPushButton>

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

    void createUI();
};

