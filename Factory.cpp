#include <iostream>
#include "Factory.h"


void Sheep::animalName()
{
	std::cout << "工厂模式-Sheep" << std::endl;
}

void Lion::animalName()
{
	std::cout << "工厂模式-Lion" << std::endl;
}

void Monkey::animalName()
{
	std::cout << "工厂模式-Monkey" << std::endl;
}



Animal* SheepFactory::creatAnimal()
{
	return new Sheep;
}

Animal* LionFactory::creatAnimal()
{
	return new Lion;
}

Animal* MonkeyFactory::creatAnimal()
{
	return new Monkey;
}
