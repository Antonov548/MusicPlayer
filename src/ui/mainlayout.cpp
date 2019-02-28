#include "mainlayout.h"

MainLayout::MainLayout()
{
    createUI();
}

QLayout *MainLayout::getLayout()
{
    return &main_layout;
}

void MainLayout::createUI()
{
    QPushButton *btn = new QPushButton("hello world");
    btn->setStyleSheet("background-color: rgb(255,255,255)");
    main_layout.setMargin(9);
    main_layout.addWidget(btn, 0, 0, 1, 1, Qt::AlignBottom);
}
