#include "window/customwindow.h"
#include "ui/mainlayout.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CustomWindow w;
    MainLayout layout;

    w.setContent(layout.getLayout());
    w.show();

    return a.exec();
}
