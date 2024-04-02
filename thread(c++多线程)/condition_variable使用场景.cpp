﻿#include<iostream>
#include<mutex>
#include<thread>
#include<condition_variable>//��������
#include<queue>
std::queue<int> g_queue;
std::condition_variable g_cv;
std::mutex mtx;
void producer() {
	for (int i = 0;i < 10;i++) {
		{
			std::unique_lock<std::mutex>  lock(mtx);
			g_queue.push(i);
			g_cv.notify_one();//֪ͨ
			std::cout << "Producer:" << i << std::endl;
		}
		std::this_thread::sleep_for(std::chrono::microseconds(100));
	}
	
}
void consumer() {
	while (1) {
		std::unique_lock<std::mutex>  lock(mtx);
		//bool isf = !g_queue.empty();
		g_cv.wait(lock, []() {
			return !g_queue.empty();
			});//�ȴ������Ƿ�Ϊ�գ���ִ�У���ִ��
		int value = g_queue.front();
		g_queue.pop();
		std::cout << "Consumer:" << value << std::endl;
	}
}
int main() {
	std::thread t1(producer);
	std::thread t2(consumer);
	t1.join();
	t2.join();
	return 0;
}