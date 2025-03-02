#ifndef ABSTRACTFACTORY_H_
#define ABSTRACTFACTORY_H_

#include <iostream>
#include <memory>
//各个部件类	
class ShipBody
{
public:
	virtual void getBody() = 0;
	virtual ~ShipBody() {};
};
class Engine
{
public:
	virtual void getEngine() = 0;
	virtual ~Engine() {};
};
class Weapon
{
public:
	virtual void getWeapon() = 0;
	virtual ~Weapon() {};
};

//部件子类
//船体
class WoodBody :public ShipBody
{
public:
	void getBody()override;
};
class IronBody :public ShipBody
{
public:
	void getBody()override;
};
class MetalBody :public ShipBody
{
public:
	void getBody()override;
};
//引擎
class ManualEngine :public Engine
{
public:
	void getEngine()override;
};
class DieselEngine :public Engine
{
public:
	void getEngine()override;
};
class NuclearEngine :public Engine
{
public:
	void getEngine()override;
};
//武器
class Gun :public Weapon
{
public:
	void getWeapon()override;
};
class Cannon :public Weapon
{
public:
	void getWeapon()override;
};
class Laser :public Weapon
{
public:
	void getWeapon()override;
};
//主体 船
class Ship
{
public:
	Ship(std::unique_ptr<ShipBody>&& shipBody, std::unique_ptr<Engine>&& engine, std::unique_ptr<Weapon>&& weapon);
	~Ship() {};
	void getProperty();
private:
	std::unique_ptr<ShipBody> m_shipBody;
	std::unique_ptr<Engine> m_engine;
	std::unique_ptr<Weapon> m_weapon;
};

//抽象工厂
class AbstractFactory
{
public:
	virtual std::unique_ptr<Ship> createShip() = 0;
	virtual ~AbstractFactory() {};
};
//工厂子类
class BasicFactory :public AbstractFactory
{
public:
	std::unique_ptr<Ship>createShip()override;
};
class StandardFactory :public AbstractFactory
{
public:
	std::unique_ptr<Ship> createShip()override;
};
class UltimataFactory :public AbstractFactory
{
public:
	std::unique_ptr<Ship> createShip()override;
};

#endif // !ABSTRACTFACTORY_H_


