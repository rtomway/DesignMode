#include <QCoreApplication>
#include "Singleton.h"
#include <windows.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SetConsoleOutputCP(CP_UTF8);

    //单例模式
    Singleton::getInstance()->print();
    Singleton1::getInstance()->print();


    return a.exec();
}

