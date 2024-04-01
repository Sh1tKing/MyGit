#include<iostream>
#include<thread>
#include<memory>
#include<mutex>
#include<Windows.h>
using namespace std;
int a = 0;
mutex mtx;
mutex m1, m2;
void f() {
	mtx.lock();//互斥锁，加了后只允许一个进程访问
	for (int i = 0; i < 100000; i++) {
		a++;
	}
	mtx.unlock();//解锁
}
void f1() {
	m1.lock();
	Sleep(1);
	m2.lock();
	m1.unlock();
	m2.unlock();
}
void f2() {
	//m2.lock();
	//m1.lock();
	m1.lock();//调换顺序可以解决
	m2.lock();
	m1.unlock();
	m2.unlock();
}
int main() {
	thread t1(f);
	thread t2(f);
	bool i1 = t1.joinable();
	bool i2 = t2.joinable();
	if (i1)t1.join();
	if (i2)t2.join();//两个线程同时占用a，a输出值每次都可能不同，调用重复了（不使用互斥锁时）
	cout << a << endl;
	
	
	//互斥死锁，两锁相互等待
	thread t3(f1);
	thread t4(f2);
	t3.join();
	t4.join();
	cout << "done";
	

}