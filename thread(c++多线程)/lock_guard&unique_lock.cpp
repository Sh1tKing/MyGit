#include<iostream>
#include<thread>
#include<mutex>
int a = 0;
std::mutex m1;
std::timed_mutex m2;
void f() {
	for (int i = 0; i <= 10000; i++) {
		std::lock_guard<std::mutex>  lg1(m1);//自动加锁自动解锁
		a++;
	} 
}
void f1() {
	for (int i = 0; i < 2; i++) {
		std::unique_lock<std::timed_mutex> ul(m2, std::defer_lock);//与自动加锁一样，但可以自己进行锁的操作
		if (ul.try_lock_for(std::chrono::seconds(2))) {//锁等待2s，有权限就执行，没权限就跳过
			std::this_thread::sleep_for(std::chrono::seconds(1));
			a++;
		}
	}
}
int main() {
	std::thread t1(f1);
	std::thread t2(f1);
	t1.join();
	t2.join();
	std::cout << a << std::endl;
}