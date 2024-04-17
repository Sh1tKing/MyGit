#include <iostream>
using namespace std;
int main()
{
	int a = 0;
	cout << a << endl;
	int* p = &a;
	*p = 5;
	cout << a << endl;
	int& r = a;
	r = 3;
	cout << a << endl;
	return 0;
}