#include "mainwindow.h"

#include <QApplication>
#include <iostream>
#include "question.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    std::cout << "Hello Test Integration" <<std::endl;

    return a.exec();


}
