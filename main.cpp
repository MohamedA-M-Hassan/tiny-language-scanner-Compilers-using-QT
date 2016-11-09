#include "mainwindow.h"
#include <QApplication>
#include <QMap>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //QMap  (int x1,int y1);
   /* int x, y;
    cin >> x;
    cin >> y;
    cout<< "hi";
    */
    return a.exec();
}
