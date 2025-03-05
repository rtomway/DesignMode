#include <QCoreApplication>
#include <windows.h>
#include <memory>

#include "Singleton.h"
#include "SimpleFactory.h"
#include "Factory.h"
#include "AbstractFactory.h"
#include "Facade.h"


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

    //抽象工厂模式   对于复杂组成的类型  主体由各个部件类组成
    std::unique_ptr<AbstractFactory> basicFactory = std::make_unique<BasicFactory>();
    std::unique_ptr<Ship> basicShip = basicFactory->createShip();
    basicShip->getProperty();
    std::unique_ptr<AbstractFactory> standardFactory = std::make_unique<StandardFactory>();
    std::unique_ptr<Ship> standardShip = standardFactory->createShip();
    standardShip->getProperty();
    std::unique_ptr<AbstractFactory> ultimataFactory = std::make_unique<UltimataFactory>();
    std::unique_ptr<Ship> ultimataShip = ultimataFactory->createShip();
    ultimataShip->getProperty();

    //外观模式 为各个子系统提供高级接口 便于客户端调用
    HomeTheaterFacade facade;   //高级接口类
    facade.onKTVMode();    
    facade.offKTVMode();
    facade.onGameMode();
    facade.offGameMode();
    return a.exec();
}

