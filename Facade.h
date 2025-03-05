#ifndef FACADE_H_
#define FACADE_H_

#include <memory>

//各个子系统
class Television
{
public:
	void on();
	void off();
};
class Light
{
public:
	void on();
	void off();
};
class Audio
{
public:
	void on();
	void off();
};
class Gamemachine
{
public:
	void on();
	void off();
};

//提供接口类
class HomeTheaterFacade
{
public:
	HomeTheaterFacade();
	void onKTVMode();
	void offKTVMode();
	void onGameMode();
	void offGameMode();
private:
	std::unique_ptr<Television>m_tv;
	std::unique_ptr<Light>m_light;
	std::unique_ptr<Audio>m_audio;
	std::unique_ptr<Gamemachine>m_gameMachine;
};

#endif // !FACADE_H_
