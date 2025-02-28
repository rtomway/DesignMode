#ifndef SIMPLEFACTORY
#define SIMPLEFACTORY

//产品基类
class Simple_Animal
{
public:
	virtual void animalName() = 0;
	virtual ~Simple_Animal() {};   //虚析构函数 析构子类
};
//各种子类产品
class Simple_Sheep :public Simple_Animal
{
public:
	void animalName()override;
};
class Simple_Lion :public Simple_Animal
{
public:
	void animalName()override;
};
class Simple_Monkey :public Simple_Animal
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
	Simple_Animal* creatAnimal(Type type);
};

#endif // !SIMPLEFACTORY
