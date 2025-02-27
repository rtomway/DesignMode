#ifndef SIMPLEFACTORY
#define SIMPLEFACTORY

class Animal
{
public:
	virtual void animalName() = 0;
	virtual ~Animal() {};   //虚析构函数 析构子类
};
class Sheep :public Animal
{
public:
	void animalName()override;
};
class Lion :public Animal
{
public:
	void animalName()override;
};
class Monkey :public Animal
{
public:
	void animalName()override;
};

//强类型枚举 所有动物
enum class Type :char {
	Sheep,
	Lion,
	Monkey
};
//工厂类
class AnimalSimpleFactory
{
public:
	Animal* creatAnimal(Type type);
};

#endif // !SIMPLEFACTORY
