#include "widget.h"
#include <QApplication>
#include"mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow p;
    //p.show();

    Widget w;
    w.show();

    return a.exec();
}
