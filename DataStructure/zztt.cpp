#include<iostream>
using namespace std;
class Counter {
private:
	int key;
public:
	Counter(int key):key(key){}
	Counter(){}
	int getkey() {
		return key;
	}
	Counter operator+(Counter& b) {
		Counter tmp;
		tmp.key = this->key + b.key;
		return tmp;
	}
};
int main() {
	Counter a(4);
	Counter b(8);
	Counter c = a + b;
	cout << c.getkey();
}