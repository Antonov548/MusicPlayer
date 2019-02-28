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
    QSpacerItem *spacer = new QSpacerItem(40, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    v_layout.addItem(spacer);
    v_layout.addWidget(&music_control);


    main_layout.setMargin(0);
    main_layout.addLayout(&v_layout, 0, 0, 1, 1);
}
