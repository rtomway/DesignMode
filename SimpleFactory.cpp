#include "SimpleFactory.h"
#include <iostream>


void Sheep::animalName()
{
	std::cout << "简单工厂-Sheep" << std::endl;
}

void Lion::animalName()
{
	std::cout << "简单工厂-Lion" << std::endl;
}

void Monkey::animalName()
{
	std::cout << "简单工厂-Monkey" << std::endl;
}

Animal* AnimalSimpleFactory::creatAnimal(Type type)
{
	Animal* ptr = nullptr;
	switch (type)
	{
	case Type::Sheep:
		ptr = new Sheep;
		break;
	case Type::Lion:
		ptr = new Lion;
		break;
	case Type::Monkey:
		ptr = new Monkey;
		break;
	default:
		break;
	}
	return ptr;
}
