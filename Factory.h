#ifndef FACTORY
#define FACTORY

//产品基类
class Animal
{
public:
	virtual void animalName() = 0;
	virtual ~Animal() {};   //虚析构函数 析构子类
};
//产品
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


//工厂基类
class AnimalFactory
{
public:
	virtual Animal* creatAnimal()=0;
	virtual ~AnimalFactory() {};
};
//各种工厂子类
class SheepFactory:public AnimalFactory
{
public:
	 Animal* creatAnimal();
	 ~SheepFactory() {};
};
class LionFactory :public AnimalFactory
{
public:
	Animal* creatAnimal();
	~LionFactory() {};
};
class MonkeyFactory :public AnimalFactory
{
public:
	Animal* creatAnimal();
	~MonkeyFactory() {};
};

#endif // !FACTORY
