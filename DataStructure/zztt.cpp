#include <iostream>
#include <stdio.h>
using namespace std;
void solution_1(long long n) {
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += i;
	}
	cout << "第一种解法:" << sum << endl;
}
void solution_2(long long n) {
	long long sum = (1 + n) * n / 2;
	cout << "第二种解法:" << sum << endl;
}
int main() {
	long long n;
	cin >> n;
	solution_1(n);
	solution_2(n);
}