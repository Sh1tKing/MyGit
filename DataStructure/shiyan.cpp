#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
class intSet {
private:
	vector<int> arr;
public:
	intSet() {}
	intSet(vector<int> p) {
		arr = p;
	}
	void Clear() {
		arr.clear();
	}
	bool IsEmpty() {
		return arr.empty();
	}
	bool IsMemberOf(int tar) {
		for (auto it = arr.begin(); it != arr.end(); it++) {
			if (*it == tar) return true;
		}
		return false;
	}
	void operator+ (int num) {
		if (!IsMemberOf(num)) arr.push_back(num);
	}
	void operator- (int num) {
		for (auto it = arr.begin(); it != arr.end(); it++) {
			if (*it == num) {
				arr.erase(it);
				break;
			}
		}
	} 
	friend ostream& operator<<(ostream& cout, intSet& a);
	bool operator== (intSet &AnotherSet) {
		if (this->arr.size() != AnotherSet.arr.size()) return false;
		vector<int> newA = this->arr;
		vector<int> newB = AnotherSet.arr;
		sort(newA.begin(), newA.end());
		sort(newB.begin(), newB.end());
		for (int i = 0; i < newA.size(); i++) {
			if (newA[i] != newB[i]) return false;
		}
		return true;
	}
	intSet operator+ (intSet& AnotherSet) {
		intSet newSet = intSet(this->arr);
		for (auto it = AnotherSet.arr.begin(); it != AnotherSet.arr.end(); it++) {
			if (this->IsMemberOf(*it)) continue;
			else newSet + *it;
		}
		return newSet;
	}
	intSet operator* (intSet& AnotherSet) {
		intSet newSet;
		for (auto it = AnotherSet.arr.begin(); it != AnotherSet.arr.end(); it++) {
			if (this->IsMemberOf(*it)) newSet + *it;
		}
		return newSet;
	}
	void operator= (intSet& AnotherSet) {
		this->arr = AnotherSet.arr;
	}
};
ostream& operator<<(ostream& cout,intSet &a) {
	for (auto it = a.arr.begin(); it != a.arr.end(); it++) {
		cout << *it << " ";
	}
	return cout;
}
int main() {
	intSet p1 = intSet({ 1,2,34 });
	p1 + 54;
	p1 + 989;
	p1 - 2;
	//cout << p1.IsMemberOf(2);
	intSet p2;
	p2 + 54;
	p2 + 1;
	p2 + 34;
	p2 + 2;
	p2 + 1354;
	p2 + 87675;
	cout << (p1 == p2)<<endl;
	cout << p1 << endl << p2<<endl;
	intSet p3 = p1 + p2;
	cout << p3<<endl;
	intSet p4 = p1 * p2;
	cout << p4 << endl;
	intSet p5 = p4;
	cout << p5;
}