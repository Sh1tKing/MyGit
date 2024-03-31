#include<iostream>
#include<thread>
#include<memory>
using namespace std;
void foo1(int& x) {
	x += 1;
}
void foo2(int* x) {
	*x += 1;
}
class stu {
	public:
		friend void test();
		void p() {
			cout << "HHHH" << endl;
		}
	private:
		void ppp() {
			cout << "asdfasdf" << endl;
		}
};
void test() {
	shared_ptr<stu> p2 = make_shared<stu>();
	thread t4(&stu::ppp, p2);
	bool is4 = t4.joinable();
	if (is4) t4.join();
}
int main() {
	int a = 1;
	thread t1(foo1,ref(a));//ref()传递引用参数,t1不知道你要传递引用类型参数所以要加ref()
	bool is = t1.joinable();
	if (is) t1.join();
	cout << a << endl;

	int* ptr = new int(10);
	thread t2(foo2, ptr);
	bool is2 = t2.joinable();
	//delete ptr;//子线程找不到ptr内存地址了，会报错，局部变量也一样.
	if (is2) t2.join();
	cout << *ptr;

	//智能指针<memory> 头文件,不需要时会自动释放
	shared_ptr<stu> p1 = make_shared<stu>();
	thread t3 (&stu::p, p1);
	bool is3 = t3.joinable();
	if (is3) t3.join();

	//访问私有
	test();
	/*shared_ptr<stu> p2 = make_shared<stu>();
	thread t4(&stu::ppp, p2);
	bool is4 = t4.joinable();
	if (is4) t4.join();*/
}