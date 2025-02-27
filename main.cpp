#include <QCoreApplication>
#include <windows.h>

#include "Singleton.h"
#include "SimpleFactory.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SetConsoleOutputCP(CP_UTF8);

    //单例模式
    Singleton::getInstance()->print();
    Singleton1::getInstance()->print();

    //简单工厂模式
    AnimalSimpleFactory* factory = new AnimalSimpleFactory;
    Animal* monkey= factory->creatAnimal(Type::Monkey);   //工厂生成Monkey对象
    monkey->animalName();
    Animal* lion = factory->creatAnimal(Type::Lion);
    lion->animalName();
    Animal* sheep = factory->creatAnimal(Type::Sheep);
    sheep->animalName();

    return a.exec();
}

