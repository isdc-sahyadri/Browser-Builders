#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;
    a.setWindowIcon(QIcon(":/resources/images/browser_icon.png"));
    window.setWindowTitle("Matrix Web Browser");
    window.show();
    return a.exec();
}
