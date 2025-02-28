#include <QCoreApplication>
#include <windows.h>

#include "Singleton.h"
#include "SimpleFactory.h"
#include "Factory.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SetConsoleOutputCP(CP_UTF8);

    //单例模式
    Singleton::getInstance()->print();
    Singleton1::getInstance()->print();

    //简单工厂模式   一对多 适用于生产对象不多且不扩展
    AnimalSimpleFactory* factory = new AnimalSimpleFactory;    //建立工厂
    Simple_Animal* simple_monkey= factory->creatAnimal(Type::Monkey);//工厂生产指定动物
    simple_monkey->animalName();
    Simple_Animal* simple_lion = factory->creatAnimal(Type::Lion);
    simple_lion->animalName();
    Simple_Animal* simple_sheep = factory->creatAnimal(Type::Sheep);
    simple_sheep->animalName();

    //工厂模式   一对一 便于后续扩展
    AnimalFactory* lionFactory = new LionFactory; //建立特定动物工厂
    Animal* lion= lionFactory->creatAnimal();  //生产该动物
    lion->animalName();
    AnimalFactory* sheepFactory = new SheepFactory; //建立特定动物工厂
    Animal* sheep = sheepFactory->creatAnimal();  //生产该动物
    sheep->animalName();
    AnimalFactory* monkeyFactory = new MonkeyFactory; //建立特定动物工厂
    Animal* monkey = monkeyFactory->creatAnimal();  //生产该动物
    monkey->animalName();

    return a.exec();
}

