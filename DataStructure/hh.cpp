#include<iostream>
#include<stdio.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[1000] = { 0 };
	int x;
	while (scanf("%d", &x) != EOF) {
		cin >> x;
		a[x]++;
	}
	for (int i = 0; i <= n; i++) {
		if (a[i] == 0) {
			cout << i;
			if (i <= n - 1) cout << " ";
		}
	}
}