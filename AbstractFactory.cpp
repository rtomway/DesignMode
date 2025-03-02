#include "AbstractFactory.h"

//船体
void WoodBody::getBody()
{
	std::cout << "船体:木头" << std::endl;
}

void IronBody::getBody()
{
	std::cout << "船体:钢铁" << std::endl;
}

void MetalBody::getBody()
{
	std::cout << "船体:合金" << std::endl;
}

//引擎
void ManualEngine::getEngine()
{
	std::cout << "引擎:手动" << std::endl;
}

void DieselEngine::getEngine()
{
	std::cout << "引擎:内燃机" << std::endl;
}

void NuclearEngine::getEngine()
{
	std::cout << "引擎:核反应堆" << std::endl;
}
//武器

void Gun::getWeapon()
{
	std::cout << "武器:枪" << std::endl;
}

void Cannon::getWeapon()
{
	std::cout << "武器:加农炮" << std::endl;
}

void Laser::getWeapon()
{
	std::cout << "武器:激光" << std::endl;
}

//船
Ship::Ship(
	std::unique_ptr<ShipBody>&& shipBody,  //&& 右值引用 
	std::unique_ptr<Engine>&& engine,      //避免了局部变量的创建和移动的开销
	std::unique_ptr<Weapon>&& weapon)
	:m_shipBody(std::move(shipBody))
	, m_engine(std::move(engine))
	, m_weapon(std::move(weapon))
{

}


void Ship::getProperty()
{
	std::cout << "该船属性:" << std::endl;
	m_shipBody->getBody();
	m_engine->getEngine();
	m_weapon->getWeapon();
}

//不同等级的船
std::unique_ptr<Ship> BasicFactory::createShip()
{
	std::unique_ptr<Ship> ship = std::make_unique<Ship>
		(
			std::make_unique<WoodBody>(),
			std::make_unique<ManualEngine>(),
			std::make_unique <Gun>()
		);
	std::cout << "抽象工厂-基础船建造完成!" << std::endl;
	return ship;
}

std::unique_ptr<Ship> StandardFactory::createShip()
{
	std::unique_ptr<Ship> ship = std::make_unique<Ship>
		(
			std::make_unique<IronBody>(),
			std::make_unique<DieselEngine>(),
			std::make_unique <Cannon>()
		);
	std::cout << "抽象工厂-标准船建造完成!" << std::endl;
	return ship;
}

std::unique_ptr<Ship> UltimataFactory::createShip()
{
	std::unique_ptr<Ship> ship = std::make_unique<Ship>
		(
			std::make_unique<MetalBody>(),
			std::make_unique<NuclearEngine>(),
			std::make_unique <Laser>()
		);
	std::cout << "抽象工厂-旗舰船建造完成!" << std::endl;
	return ship;
}
