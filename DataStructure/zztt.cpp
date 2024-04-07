#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;
int n, a[10], maxn = -1;
string s;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		a[s[s.size() - 1] - '0'] = max(a[s[0] - '0'] + 1, a[s[s.size() - 1] - '0']);
	}
	for (int i = 0; i < 10; i++) maxn = max(maxn, a[i]);
	cout << n - maxn;
	
}