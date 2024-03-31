#include<iostream>
#include<thread>
#include<string>
using namespace std;
void print(string s) {
	for (int i = 0; i <= 1000; i++) {
		cout << i;
	}
}
int main() {
	//1.create thread
	thread thread1(print,"dnmgb");
	//thread1.join();//等待子线程完成
//	thread1.detach();//分离子线程和主线程
	bool isjohn = thread1.joinable();
	if (isjohn) thread1.join();//
	cout << endl<<"over";

	return 0;
}