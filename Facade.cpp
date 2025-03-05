#include "Facade.h"
#include <iostream>


void Television::on()
{
	std::cout << "打开电视" << std::endl;
}

void Television::off()
{
	std::cout << "关闭电视" << std::endl;
}
void Light::on()
{
	std::cout << "打开灯" << std::endl;
}

void Light::off()
{
	std::cout << "关闭灯" << std::endl;
}
void Audio::on()
{
	std::cout << "打开音响" << std::endl;
}

void Audio::off()
{
	std::cout << "关闭音响" << std::endl;
}
void Gamemachine::on()
{
	std::cout << "打开游戏机" << std::endl;
}

void Gamemachine::off()
{
	std::cout << "关闭游戏机" << std::endl;
}

HomeTheaterFacade::HomeTheaterFacade()
	:m_tv(std::make_unique<Television>())
	,m_light(std::make_unique<Light>())
	,m_audio(std::make_unique<Audio>())
	,m_gameMachine(std::make_unique<Gamemachine>())
{

}

void HomeTheaterFacade::onKTVMode()
{
	std::cout << "外观模式-KTV模式:" << std::endl;
	m_tv->on();
	m_light->on();
	m_audio->on();
}

void HomeTheaterFacade::offKTVMode()
{
	std::cout << "外观模式-关闭KTV模式:" << std::endl;
	m_tv->off();
	m_light->off();
	m_audio->off();
}


void HomeTheaterFacade::onGameMode()
{
	std::cout << "外观模式-游戏模式:" << std::endl;
	m_tv->on();
	m_audio->on();
	m_gameMachine->on();
}

void HomeTheaterFacade::offGameMode()
{
	std::cout << "外观模式-关闭游戏模式:" << std::endl;
	m_tv->off();
	m_audio->off();
	m_gameMachine->off();
}


