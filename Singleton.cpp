#include "singleton.h"
#include <iostream>

//类外初始化静态成员
std::mutex Singleton::m_mutex;
std::atomic<Singleton*> Singleton::m_instance = nullptr;

//单例-懒汉模式(懒加载第一次使用时才初始化)
Singleton* Singleton::getInstance()
{
#if 0     //运用静态局部变量 保证线程安全
	static Singleton instance;
	return &instance;
#else   //运用双重检查锁定和atomic原子操作 保证线程安全
	Singleton* ins = m_instance.load();
	if (ins == nullptr)
	{
		m_mutex.lock();
		ins = m_instance.load();
		if (ins == nullptr)
		{                              //atomic原子操作控制执行顺序 更安全
			ins = new Singleton;      //机器指令为三步 执行顺序可能改变 底层造成bug
			m_instance.store(ins);
		}
		m_mutex.unlock();
	}
	return ins;
#endif
}

void Singleton::print()
{
	std::cout << "单例-懒汉模式"<<std::endl;
}


//类外初始化静态成员
Singleton1* Singleton1::m_instance = new Singleton1;
//单例-饿汉模式(类加载时就初始化，线程安全)
Singleton1* Singleton1::getInstance()
{
	return m_instance;
}

void Singleton1::print()
{
	std::cout << "单例-饿汉模式" << std::endl;
}
