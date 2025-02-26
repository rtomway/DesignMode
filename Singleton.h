#ifndef SINGLETON_H_
#define SINGLETON_H_

#include <atomic>
#include <mutex>

class Singleton
{
public:
	//禁止拷贝构造函数和 =操作符
	Singleton(const Singleton& instance) = delete;
	Singleton& operator=(const Singleton& instance) = delete;
	static Singleton* getInstance();
	void print();
private:
	Singleton() = default;

	//静态方法只能调用静态成员
	static std::mutex m_mutex;
	static std::atomic<Singleton*>m_instance;
};
class Singleton1
{
public:
	//禁止拷贝构造函数和 =操作符
	Singleton1(const Singleton1& instance) = delete;
	Singleton1& operator=(const Singleton1& instance) = delete;
	static Singleton1* getInstance();
	void print();
private:
	Singleton1() = default;

	//静态方法只能调用静态成员
	static Singleton1* m_instance;
};


#endif // !SINGLETON_H_
