#include <iostream>
#include "MainWindow.h"
#include <QApplication>
using namespace std;
int main(int argc,char *argv[]) {
    QApplication app(argc,argv);
    MainWindow w;
    w.show();
    return QApplication::exec();
}

