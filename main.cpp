#include "mainwindow.h"
#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("MyNotePad");
    QIcon *icon = new QIcon(":/new/prefix1/notepad");
    w.setWindowIcon(*icon);
    w.show();

    return a.exec();
}
