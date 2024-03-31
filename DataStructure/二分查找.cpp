#include<iostream>
#include<vector>
using namespace std;
int bs(vector<int>& b, int l, int r, int tar) {
	if (l > r) return -1;
	int mid = (l + r) / 2;
	if (b[mid] == tar) return mid;
	if (b[mid] > tar) return bs(b, l, mid - 1, tar);
	if (b[mid] < tar) return bs(b, mid + 1, r, tar);
}
int main() {
	vector<int> a = { 0,1,2,3,4,5,6,7,87,91 };
	int tar;
	while (cin >> tar) {
		cout << bs(a,0,a.size()-1,tar)<<endl;
	}
}