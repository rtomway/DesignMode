#include "SimpleFactory.h"
#include <iostream>


void Simple_Sheep::animalName()
{
	std::cout << "简单工厂-Sheep" << std::endl;
}

void Simple_Lion::animalName()
{
	std::cout << "简单工厂-Lion" << std::endl;
}

void Simple_Monkey::animalName()
{
	std::cout << "简单工厂-Monkey" << std::endl;
}

Simple_Animal* AnimalSimpleFactory::creatAnimal(Type type)
{
	Simple_Animal* ptr = nullptr;
	switch (type)
	{
	case Type::Sheep:
		ptr = new Simple_Sheep;
		break;
	case Type::Lion:
		ptr = new Simple_Lion;
		break;
	case Type::Monkey:
		ptr = new Simple_Monkey;
		break;
	default:
		break;
	}
	return ptr;
}
